#include <iostream>
#include <vector>
#include <chrono>
#include <iomanip>
#include <limits>

using namespace std;

// ---- Constants ----
constexpr int REGISTER_COUNT = 8;
constexpr int MEMORY_SIZE = 256;
constexpr int WORD_SIZE = 8;
constexpr int HALT_OPCODE = 0b11111111;

// ========= Bit manipulation constants =======
constexpr int OPCODE_SHIFT = 4;
constexpr int OPCODE_MASK = 0b1111;
constexpr int REG1_SHIFT = 2;
constexpr int REG_MASK = 0b11;

// ----- Conversion -----
string formatBinary(int value, int bits = WORD_SIZE)
{
    string str;
    for (int i = bits - 1; i >= 0; i--)
    {
        str += ((value >> i) & 1) ? '1' : '0';
    }
    return str;
}

// ================== I/O Device ==========
class IOController
{
    int input_buffer;
    int output_buffer;

public:
    IOController() : input_buffer(0), output_buffer(0) {}

    void writeOutput(int value)
    {
        output_buffer = value;
        cout << "[OUT] Value " << formatBinary(output_buffer)
             << " (" << output_buffer << ") written\n";
    }

    int readInput()
    {
        cout << "Enter 8-bit value (0-255): ";
        int value;
        while (!(cin >> value) || value < 0 || value > 255)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid! Enter 0-255: ";
        }
        return value;
    }
};

// ========== CPU Components ==========
struct Processor
{
    vector<int> reg;
    vector<int> ram;
    IOController io;
    int pc;
    size_t instructions_executed;
    chrono::high_resolution_clock::time_point clock_start;

    Processor() : reg(REGISTER_COUNT, 0),
                  ram(MEMORY_SIZE, 0),
                  pc(0),
                  instructions_executed(0) {}

    void loadProgram(const vector<int> &program)
    {
        cout << "\n==== Loading Program ====\n";
        for (size_t addr = 0; addr < program.size() && addr < MEMORY_SIZE; ++addr)
        {
            ram[addr] = program[addr];
            cout << "MEM[" << addr << "] = " << formatBinary(program[addr]) << "\n";
        }
        cout << "----------------\n";
    }

    void startExecution()
    {
        clock_start = chrono::high_resolution_clock::now();
        try
        {
            while (pc < MEMORY_SIZE)
            {
                fetch();
                if (ram[pc - 1] == HALT_OPCODE)
                    break;
                decodeExecute();
            }
        }
        catch (const exception &e)
        {
            cerr << "\n! Execution Error: " << e.what() << endl;
        }
        showStatistics();
    }

private:
    void fetch()
    {
        if (pc >= MEMORY_SIZE)
            throw runtime_error("PC overflow");
        cout << "\n[FETCH] PC:" << pc << " -> " << formatBinary(ram[pc]) << endl;
        pc++;
    }

    void decodeExecute()
    {
        const int instruction = ram[pc - 1];
        if (instruction == HALT_OPCODE)
            return;

        const int opcode = (instruction >> OPCODE_SHIFT) & OPCODE_MASK;
        const int reg1 = (instruction >> REG1_SHIFT) & REG_MASK;
        const int reg2 = instruction & REG_MASK;

        cout << "[DECODE] Op: " << formatBinary(opcode, 4)
             << " | R" << reg1 << " | R" << reg2 << endl;

        executeInstruction(opcode, reg1, reg2);
        dumpRegisters();
        instructions_executed++;
    }

    void executeInstruction(int opcode, int reg1, int reg2)
    {
        cout << "[EXECUTE] ";
        switch (opcode)
        {
        case 0b0000:
            if (reg[reg2] >= 0 && reg[reg2] < MEMORY_SIZE)
            {
                reg[reg1] = ram[reg[reg2]];
                cout << "LOAD R" << reg1 << " <- MEM[R" << reg2 << "]";
            }
            break;

        case 0b0001:
            if (reg[reg2] >= 0 && reg[reg2] < MEMORY_SIZE)
            {
                ram[reg[reg2]] = reg[reg1];
                cout << "STORE R" << reg1 << " -> MEM[R" << reg2 << "]";
            }
            break;

        case 0b1110:
            reg[reg1] = io.readInput();
            cout << "READ R" << reg1 << " <- IO";
            break;

        case 0b1111:
            io.writeOutput(reg[reg1]);
            cout << "WRITE R" << reg1 << " -> IO";
            break;

        default:
            throw runtime_error("Unknown opcode: " + to_string(opcode));
        }
        cout << endl;
    }

    void dumpRegisters() const
    {
        cout << "--- REGISTERS ---\n";
        for (size_t i = 0; i < REGISTER_COUNT; ++i)
        {
            cout << "R" << i << ": " << formatBinary(reg[i])
                 << " (" << setw(3) << reg[i] << ")\n";
        }
    }

    void showStatistics() const
    {
        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::microseconds>(end - clock_start);

        cout << "\n==== Execution Report ====\n"
             << "Instructions executed: " << instructions_executed << "\n"
             << "Execution Time: " << duration.count() << " Microseconds\n"
             << "Performance: " << fixed << setprecision(2)
             << (double)instructions_executed / duration.count()
             << " Microseconds\n";
    }
};

// ========= Main Program =============
int main()
{
    Processor cpu;
    vector<int> program = {
        0b11100000,
        0b11110000,
        0b00001100,
        0b00010110,
        HALT_OPCODE};
    cpu.ram[4] = 42;
    cpu.loadProgram(program);
    cpu.startExecution();
    return 0;
}
