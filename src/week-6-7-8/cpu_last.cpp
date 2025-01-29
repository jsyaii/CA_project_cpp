#include <iostream>
#include <vector>
#include <chrono>
#include <iomanip>

using namespace std;

// Constant
constexpr int REGISTER_COUNT = 8;
constexpr int MEMORY_SIZE = 256;
constexpr int WORD_SIZE = 8; // 8-bit words

// Custom function to convert integer to binary string
string customIntToBinary(int num, int size = WORD_SIZE)
{
    string binary = "";
    for (int i = size - 1; i >= 0; i--)
    {
        binary += ((num >> i) & 1) ? '1' : '0';
    }
    return binary;
}

// Simulated I/O Devices-6
struct IODevice
{
    int inputBuffer;
    int outputBuffer;

    IODevice() : inputBuffer(0), outputBuffer(0) {}

    void writeToOutput(int value)
    {
        outputBuffer = value;
        cout << "Output: " << outputBuffer << endl;
    }

    int readFromInput()
    {
        cout << "Enter input: ";
        cin >> inputBuffer;
        return inputBuffer;
    }
};

// CPU Components
struct CPU
{
    vector<int> registers;
    vector<int> memory;
    int programCounter;
    IODevice ioDevice; // Integrated I/O device

    // Pipeline stages
    int fetchedInstruction;
    int decodedOpcode;
    int decodedReg1;
    int decodedReg2;

    // Performance metrics--888
    size_t instructionCount;
    chrono::high_resolution_clock::time_point startTime;
    chrono::high_resolution_clock::time_point endTime;

    // Constructor
    CPU() : registers(REGISTER_COUNT, 0), memory(MEMORY_SIZE, 0), programCounter(0), fetchedInstruction(0), decodedOpcode(0), decodedReg1(0), decodedReg2(0), instructionCount(0) {}

    // Start performance profiling-8
    void startProfiling()
    {
        startTime = chrono::high_resolution_clock::now();
    }

    // End performance profiling-8
    void endProfiling()
    {
        endTime = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::microseconds>(endTime - startTime).count();
        cout << "\nPerformance Metrics:" << endl;
        cout << "Total Instructions Executed: " << instructionCount << endl;
        cout << "Execution Time: " << duration << " microseconds" << endl;
        cout << "Instructions Per Microsecond: " << fixed << setprecision(2) << (double)instructionCount / duration << endl;
    }

    // Fetch instruction
    void fetch()
    {
        if (programCounter >= MEMORY_SIZE)
        {
            cerr << "Error: Program Counter out of range!" << endl;
            throw runtime_error("Program Counter out of range");
        }

        fetchedInstruction = memory[programCounter++];
        cout << "Fetched Instruction: " << customIntToBinary(fetchedInstruction) << " at address " << programCounter - 1 << endl;
    }

    // Decode instruction
    void decode()
    {
        decodedOpcode = (fetchedInstruction >> 6) & 0x03; // Top 2 bits as opcode
        decodedReg1 = (fetchedInstruction >> 3) & 0x07;   // Middle 3 bits for register 1
        decodedReg2 = fetchedInstruction & 0x07;          // Last 3 bits for register 2
        cout << "Decoded Opcode: " << decodedOpcode << ", Reg1: " << decodedReg1 << ", Reg2: " << decodedReg2 << endl;
    }

    // Execute instruction
    void execute()
    {
        cout << "Executing Opcode: " << decodedOpcode << endl;
        instructionCount++;
        switch (decodedOpcode)
        {
        case 0x08: // IN (input from I/O)-6
            registers[decodedReg1] = ioDevice.readFromInput();
            cout << "IN: R" << decodedReg1 << " <- " << registers[decodedReg1] << endl;
            break;
        case 0x09: // OUT (output to I/O)-6
            ioDevice.writeToOutput(registers[decodedReg1]);
            break;
        case 0x0A: // CALL (subroutine call)-7
            memory[--programCounter] = programCounter + 1;
            programCounter = registers[decodedReg1];
            cout << "CALL: Subroutine at address " << registers[decodedReg1] << " saved PC = " << memory[programCounter] << endl;
            break;
        case 0x0B: // RET (subroutine return)-7
            programCounter = memory[programCounter++];
            cout << "RET: Returning to address " << programCounter << endl;
            break;
        case 0x0C: // Branching Instruction (e.g., conditional jump)-7
            if (registers[decodedReg1] == decodedReg2)
            {
                programCounter = memory[programCounter++];
                cout << "Branch taken to address " << programCounter << endl;
            }
            else
            {
                cout << "Branch not taken" << endl;
            }
            break;
        case 0x0D: // Interrupt handling (simple simulation)-7
            cout << "Interrupt triggered. Halting execution." << endl;
            throw runtime_error("Interrupt occurred");
        default:
            throw runtime_error("Unknown instruction");
        }
    }

    // Load a program into memory
    void loadProgram(const vector<int> &program)
    {
        for (size_t i = 0; i < program.size() && i < MEMORY_SIZE; ++i)
        {
            memory[i] = program[i];
            cout << "Memory[" << i << "] <- " << program[i] << endl;
        }
    }

    // Run the CPU with pipelining
    void run()
    {
        startProfiling();
        try
        {
            while (programCounter < MEMORY_SIZE)
            {
                fetch();
                decode();
                execute();
                debugState();
            }
        }
        catch (const exception &e)
        {
            cerr << "Execution halted: " << e.what() << endl;
        }
        endProfiling();
    }

    // Debug - Print CPU state
    void debugState() const
    {
        cout << "Registers: ";
        for (const auto &reg : registers)
        {
            cout << reg << " ";
        }
        cout << "\nProgram Counter: " << programCounter << endl;
    }
};

int main()
{
    CPU cpu;

    // Example program (machine code):
    vector<int> program = {
        0b10000000, // IN R0-66
        0b10010000, // OUT R0-6
        0b00001010, // CALL Subroutine-7
        0b00001011, // RET-7
        0b00001100, // Conditional Branch
        0b00001101  // Interrupt-7
    };

    cpu.loadProgram(program);
    cpu.run();

    return 0;
}