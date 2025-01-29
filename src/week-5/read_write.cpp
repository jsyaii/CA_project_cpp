#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

class Memory
{
    vector<int> memory;

public:
    Memory(size_t size) : memory(size, 0) {}
    int read(int address)
    {
        if (address < 0 || address >= memory.size())
            throw out_of_range("Invalid address");
        return memory[address];
    }
    void write(int address, int value)
    {
        if (address < 0 || address >= memory.size())
            throw out_of_range("Invalid address");
        memory[address] = value;
    }
};

int main()
{
    Memory memory(1024);

    memory.write(100, 42);
    cout << memory.read(100) << endl;

    memory.write(200, 55);
    cout << memory.read(200) << endl;

    return 0;
}
