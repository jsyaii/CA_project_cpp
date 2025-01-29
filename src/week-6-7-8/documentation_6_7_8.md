# Virtual CPU Emulator

This project is a Virtual CPU Emulator developed in C++ that simulates the core functionality of a basic CPU. It includes essential components like registers, memory, I/O devices, and instruction handling with performance metrics for analysis.

## Features

### 1. CPU Architecture

- **Registers**: 8 general-purpose registers (R0 to R7).
- **Memory**: 256 bytes of memory, with 8-bit word size.
- **Program Counter**: Keeps track of the next instruction to execute.

### 2. Instruction Set

The emulator supports the following instructions:

- **IN**: Reads input from an I/O device into a register.
- **OUT**: Outputs the value of a register to an I/O device.
- **CALL**: Performs a subroutine call and saves the return address.
- **RET**: Returns control to the saved address after a subroutine.
- **BRANCH**: Executes conditional branching based on register values.
- **INTERRUPT**: Simulates an interrupt, halting execution.

### 3. Simulated I/O Devices

- **Input Buffer**: Reads data from the user during execution.
- **Output Buffer**: Displays output to the console.

### 4. Pipeline Stages

The emulator implements a three-stage pipeline:

- **Fetch**: Retrieves the next instruction from memory.
- **Decode**: Deciphers the opcode and operands.
- **Execute**: Carries out the decoded instruction.

### 5. Debugging

- Displays the current state of registers and the program counter after each instruction.
- Helps track memory and execution flow for debugging purposes.

### 6. Performance Profiling

The emulator includes performance metrics:

- **Total Instructions Executed**: Counts the number of executed instructions.
- **Execution Time**: Measures the runtime of the program in microseconds.
- **Instructions Per Microsecond**: Evaluates efficiency.

## How It Works

1. **Program Loading**: The emulator loads a sequence of instructions (machine code) into the memory.
2. **Execution Loop**: Instructions are fetched, decoded, and executed sequentially, unless branching or interrupts alter the flow.
3. **I/O Interaction**: The program interacts with the user via input and output operations.
4. **Debugging Information**: After each instruction, the internal state (registers and program counter) is printed for clarity.
5. **Performance Summary**: At the end of execution, the emulator outputs detailed performance metrics.

## Use Cases

- **Education**: A tool for students to learn the basics of CPU operations, including registers, memory, and instruction handling.
- **Debugging and Testing**: Simulates instruction execution to test machine code logic.
- **Performance Analysis**: Evaluates execution time and efficiency for programs.

## Performance Metrics

At the end of execution, the emulator provides the following data:

- **Total Instructions Executed**: The number of instructions processed.
- **Execution Time**: The runtime of the program, measured in microseconds.
- **Efficiency**: Calculates the average number of instructions executed per microsecond.
