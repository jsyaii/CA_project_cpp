#include <iostream>
#include <unordered_map>
#include <bitset>
#include <string>
#include <sstream>

using namespace std;

// Define the instruction opcodes
enum Opcodes
{
    ADD = 0x01,   // Add
    SUB = 0x02,   // Subtract
    LOAD = 0x03,  // Load
    STORE = 0x04, // Store
    MOV = 0x05,   // Move
    JMP = 0x06,   // Jump
    CMP = 0x07,   // Compare
    NOP = 0x00    // No operation
};

// Registers
enum Registers
{
    R0 = 0,
    R1,
    R2,
    R3,
    R4,
    R5,
    R6,
    R7
};

// Simple Optimized Instruction Format
struct Instruction
{
    Opcodes opcode;
    Registers reg1;
    Registers reg2;
    int immediate;
};

// Function to convert an integer to a binary string (for machine code)
string toBinary(int num, int bits)
{
    return bitset<16>(num).to_string().substr(16 - bits);
}

// Function to assemble an instruction to machine code
string assembleInstruction(Instruction instruction)
{
    string binaryInstruction = toBinary(instruction.opcode, 8); // 8 bits for opcode
    binaryInstruction += toBinary(instruction.reg1, 3);         // 3 bits for first register
    binaryInstruction += toBinary(instruction.reg2, 3);         // 3 bits for second register
    binaryInstruction += toBinary(instruction.immediate, 16);   // 16 bits for immediate value (if any)

    return binaryInstruction;
}

// Optimized Assembler Function
void assembler(const string &code)
{
    // Example assembly input
    Instruction instr;
    if (code == "ADD R1, R2, R3")
    {
        instr = {ADD, R1, R2, R3}; // Adding R2 to R3 and storing in R1
    }
    else if (code == "MOV R1, R5")
    {
        instr = {MOV, R1, R5, 0}; // Moving R5 to R1
    }
    else if (code == "LOAD R1, 100")
    {
        instr = {LOAD, R1, R0, 100}; // Loading value 100 into R1
    }
    else
    {
        cerr << "Invalid instruction" << endl;
        return;
    }

    string machineCode = assembleInstruction(instr);
    cout << "Assembly Code: " << code << endl;
    cout << "Machine Code: " << machineCode << endl;
}

int main()
{
    // Sample code that we are going to assemble
    string code1 = "ADD R1, R2, R3";
    string code2 = "MOV R1, R5";
    string code3 = "LOAD R1, 100";

    // Run the assembler for each example
    assembler(code1);
    assembler(code2);
    assembler(code3);

    return 0;
}
