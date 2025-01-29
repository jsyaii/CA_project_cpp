#include <iostream>
#include <vector>

using namespace std;

class VirtualMemory
{
    vector<int> memory; // Memory represented as a vector of integers

public:
    // Constructor to initialize memory size
    VirtualMemory(size_t size) : memory(size, 0) {}

    // Function to read value from a specific address
    int read(int address)
    {
        if (address < 0 || address >= memory.size())
        {
            cout << "Error: Invalid address!" << endl;
            return -1; // Invalid address
        }
        return memory[address];
    }

    // Function to write value to a specific address
    void write(int address, int value)
    {
        if (address < 0 || address >= memory.size())
        {
            cout << "Error: Invalid address!" << endl;
            return; // Invalid address
        }
        memory[address] = value;
    }

    // Function to display all memory content
    void displayMemory()
    {
        for (int i = 0; i < memory.size(); i++)
        {
            cout << "Address " << i << ": " << memory[i] << endl;
        }
    }
};

int main()
{
    VirtualMemory memory(10); // Create a virtual memory of size 10

    memory.write(3, 50);  // Write value 50 to memory address 3
    memory.write(7, 100); // Write value 100 to memory address 7

    cout << "Reading value at address 3: " << memory.read(3) << endl; // Read value at address 3
    cout << "Reading value at address 7: " << memory.read(7) << endl; // Read value at address 7

    cout << "Current memory state:" << endl;
    memory.displayMemory(); // Display all memory contents

    return 0;
}
