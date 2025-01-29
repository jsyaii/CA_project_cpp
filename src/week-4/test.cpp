#include <iostream>
using namespace std;

const int MEMORY_SIZE = 10;
const int NUM_REGISTERS = 4;

// Memory and Registers
int memory[MEMORY_SIZE] = {0};      // Initialize memory to 0
int registers[NUM_REGISTERS] = {0}; // Initialize registers to 0
int PC = 0;
int IR = 0;

enum Instructions
{
    NOP = 0,  // No operation
    LOAD = 1, // LOAD reg, value
    ADD = 2,  // ADD reg1, reg2, result_reg
    STORE = 3 // STORE reg, addr
};

// Fetch instruction
void fetch()
{
    IR = memory[PC++]; // Fetch instruction from memory and increment PC
}

// Decode and execute instruction
void decodeAndExecute()
{
    switch (IR)
    {
    case NOP:
        cout << "NOP: No operation.\n";
        break;

    case LOAD:
    {
        int reg = memory[PC++];   // Register index
        int value = memory[PC++]; // Value to load
        registers[reg] = value;
        cout << "LOAD: R" << reg << " = " << value << endl;
        break;
    }

    case ADD:
    {
        int reg1 = memory[PC++];       // First register
        int reg2 = memory[PC++];       // Second register
        int result_reg = memory[PC++]; // Result register
        registers[result_reg] = registers[reg1] + registers[reg2];
        cout << "ADD: R" << result_reg << " = R" << reg1 << " + R" << reg2 << endl;
        break;
    }

    case STORE:
    {
        int reg = memory[PC++];  // Register index
        int addr = memory[PC++]; // Memory address
        memory[addr] = registers[reg];
        cout << "STORE: Memory[" << addr << "] = R" << reg << " (" << registers[reg] << ")\n";
        break;
    }

    default:
        cout << "Unknown instruction: " << IR << endl;
    }
}

int main()
{
    // Load a simple program into memory
    memory[0] = LOAD;
    memory[1] = 0;
    memory[2] = 10; // LOAD R0, 10
    memory[3] = LOAD;
    memory[4] = 1;
    memory[5] = 20; // LOAD R1, 20
    memory[6] = ADD;
    memory[7] = 0;
    memory[8] = 1;
    memory[9] = 2; // ADD R0, R1, R2

    // Execute the program
    while (PC < MEMORY_SIZE && memory[PC] != 0)
    {
        fetch();
        decodeAndExecute();
    }

    // Output final state
    cout << "\nFinal State of Registers:\n";
    for (int i = 0; i < NUM_REGISTERS; i++)
    {
        cout << "R" << i << " = " << registers[i] << endl;
    }

    cout << "\nFinal State of Memory:\n";
    cout << "Memory[2] = " << memory[2] << endl;

    return 0;
}
