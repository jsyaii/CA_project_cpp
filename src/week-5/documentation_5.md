# Virtual Memory Management

---

## Code 1: Basic Memory Management with a Vector

### Key Features:

- **Memory Initialization**: Memory is initialized using a vector with a size defined by the user.
- **Reading and Writing**: Allows reading from and writing to specific memory addresses.
- **Memory State Display**: Provides a function to display the current contents of all memory addresses.

### Usage:

- Initialize a virtual memory space with a specified size.
- Write data to specific addresses and read data from them.
- Display the entire memory state.

---

## Code 2: Memory Management with Error Handling

### Key Features:

- **Error Handling**: Uses exception handling (`throw` and `try-catch` blocks) to handle invalid memory access attempts.
- **Vector-based Memory Management**: Memory is represented as a vector, similar to the first example.
- **Bounds Checking**: Ensures that addresses outside the valid range are not accessed.

### Usage:

- Create a memory system and perform memory read/write operations.
- Handle errors for invalid memory accesses using exceptions.

---

## Code 3: Virtual Memory with Segment Address Mapping

### Key Features:

- **Memory Segmentation**: The memory is divided into segments, each with a base and limit.
- **Address Mapping**: Logical addresses are mapped to physical addresses using the base and offset within segments.
- **Error Handling**: Ensures that invalid segment selectors or offsets are properly handled.

### Usage:

- Define segments with base addresses and limits.
- Map logical addresses (with offsets) to physical addresses.
- Handle errors when an invalid segment or offset is used.

---
