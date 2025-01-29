#include <iostream>
#include <vector>
#include <cstdint>
using namespace std;

const int MEMORY_SIZE = 256;
const int NUM_REGISTERS = 8;

enum Opcodes
{
    NOP = 0,
    ADD = 1,
    SUB = 2,
    MOV = 3,
    HLT = 255
};

class CPU
{
private:
    uint8_t memory[MEMORY_SIZE] = {0};
    int32_t registers[NUM_REGISTERS] = {0};
    uint8_t PC = 0;
    bool running = true;

public:
    void loadProgram(const vector<uint8_t> &program)
    {
        for (size_t i = 0; i < program.size() && i < MEMORY_SIZE; ++i)
            memory[i] = program[i];
    }

    void run()
    {
        while (running)
        {
            uint8_t opcode = memory[PC++];
            uint8_t op1 = memory[PC++], op2 = memory[PC++], op3 = memory[PC++];
            switch (opcode)
            {
            case ADD:
                registers[op3] = registers[op1] + registers[op2];
                break;
            case SUB:
                registers[op3] = registers[op1] - registers[op2];
                break;
            case MOV:
                registers[op1] = op2;
                break;
            case HLT:
                running = false;
                break;
            default:
                running = false;
                break;
            }
        }
    }

    void printRegisters() const
    {
        for (int i = 0; i < NUM_REGISTERS; ++i)
            cout << "R" << i << ": " << registers[i] << endl;
    }
};

int main()
{
    CPU cpu;
    vector<uint8_t> program = {
        MOV, 0, 10, 0,
        MOV, 1, 20, 0,
        ADD, 0, 1, 2,
        HLT, 0, 0, 0};

    cpu.loadProgram(program);
    cpu.run();
    cpu.printRegisters();
    return 0;
}