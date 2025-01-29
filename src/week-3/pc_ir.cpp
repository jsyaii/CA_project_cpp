#include <iostream>
#include <string>

using namespace std;

// Program Counter Class
class ProgramCounter
{
public:
    int value = 0; // The current value of the PC

    // Increment the PC by 1
    void increment()
    {
        ++value;
    }

    // Set the PC to a specific value
    void set_value(int new_value)
    {
        value = new_value;
    }
};

// Instruction Register Class
class InstructionRegister
{
public:
    string current_instruction = ""; // Stores the current instruction

    // Load a new instruction into the IR
    void load(const string &instruction)
    {
        current_instruction = instruction;
    }
};

int main()
{
    // Create a Program Counter and Instruction Register
    ProgramCounter pc;
    InstructionRegister ir;

    // Load an instruction into the IR
    string instruction = "ADD R1, R2, R3";
    ir.load(instruction);

    // Display the current instruction
    cout << "Instruction Register: " << ir.current_instruction << endl;

    // Increment the Program Counter
    pc.increment();
    cout << "Program Counter: " << pc.value << endl;

    // Set the PC to a specific value
    pc.set_value(10);
    cout << "Program Counter (after setting): " << pc.value << endl;

    return 0;
}