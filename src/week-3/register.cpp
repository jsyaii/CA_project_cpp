#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

class CPU
{
public:
    CPU()
    {
        for (int i = 0; i < 8; ++i)
        {
            registers["R" + to_string(i)] = 0;
        }
    }

    void load(const string &reg, int value)
    {
        registers[reg] = value;
    }

    void move(const string &src, const string &dest)
    {
        registers[dest] = registers[src];
    }

    void add(const string &r1, const string &r2, const string &result)
    {
        registers[result] = registers[r1] + registers[r2];
    }

    void subtract(const string &r1, const string &r2, const string &result)
    {
        registers[result] = registers[r1] - registers[r2];
    }

    void print_registers() const
    {
        for (const auto &reg : registers)
        {
            cout << reg.first << ": " << reg.second << endl;
        }
    }

private:
    unordered_map<string, int> registers;
};

int main()
{
    CPU cpu;
    cpu.load("R0", 10);
    cpu.load("R1", 5);
    cpu.load("R2", 20);
    cpu.add("R0", "R1", "R3");
    cpu.subtract("R2", "R1", "R4");
    cpu.move("R3", "R5");
    cpu.print_registers();
    return 0;
}