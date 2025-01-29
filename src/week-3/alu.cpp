#include <iostream>
#include <cstdint>

using namespace std;

class ALU
{
public:
    enum Operation
    {
        ADD,
        SUB,
        AND,
        OR,
        XOR,
        NOT
    };

    int32_t perform(Operation op, int32_t a, int32_t b = 0)
    {
        switch (op)
        {
        case ADD:
            return a + b;
        case SUB:
            return a - b;
        case AND:
            return a & b;
        case OR:
            return a | b;
        case XOR:
            return a ^ b;
        case NOT:
            return ~a;
        default:
            throw invalid_argument("Invalid operation");
        }
    }
};

int main()
{
    ALU alu;
    int32_t a = 10, b = 3;

    cout << alu.perform(ALU::ADD, a, b) << " "
         << alu.perform(ALU::SUB, a, b) << " "
         << alu.perform(ALU::AND, a, b) << " "
         << alu.perform(ALU::OR, a, b) << " "
         << alu.perform(ALU::XOR, a, b) << " "
         << alu.perform(ALU::NOT, a) << " ";

    return 0;
}