#include <iostream>
#include <iomanip>
#include <cstdint>
using namespace std;

uint8_t memory[] = {0x1A, 0x2B, 0x3C};
uint16_t PC = 0;
uint8_t IR = 0;

void fetch() { IR = memory[PC++]; }
void decode() { cout << "Decoded: 0x" << hex << (int)IR << endl; }
void execute() { cout << "Executed: 0x" << hex << (int)IR << endl; }

int main()
{
    while (PC < sizeof(memory))
    {
        fetch();
        decode();
        execute();
    }
    return 0;
}