#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

struct Segment
{
    int base;  // Base address of the segment in physical memory
    int limit; // Size of the segment
};

class VirtualCPU
{
private:
    vector<Segment> segmentTable; // Table of segments

public:
    // Add a segment with base address and limit
    void addSegment(int base, int limit)
    {
        segmentTable.push_back({base, limit});
    }

    // Map a logical address to a physical address
    int mapAddress(int segmentSelector, int offset)
    {
        if (segmentSelector < 0 || segmentSelector >= segmentTable.size())
            throw out_of_range("Invalid segment selector!");

        Segment segment = segmentTable[segmentSelector];

        if (offset < 0 || offset >= segment.limit)
            throw out_of_range("Offset out of segment bounds!");

        return segment.base + offset;
    }
};

int main()
{
    VirtualCPU cpu;

    // Define segments
    cpu.addSegment(0, 100);   // Segment 0: Base 0, Limit 100
    cpu.addSegment(200, 150); // Segment 1: Base 200, Limit 150

    try
    {
        // Map logical addresses
        int physicalAddress1 = cpu.mapAddress(0, 50);  // Segment 0, Offset 50
        int physicalAddress2 = cpu.mapAddress(1, 100); // Segment 1, Offset 100

        // Print results
        cout << "Physical Address for Segment 0, Offset 50: " << physicalAddress1 << endl;
        cout << "Physical Address for Segment 1, Offset 100: " << physicalAddress2 << endl;
    }
    catch (const exception &e)
    {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
