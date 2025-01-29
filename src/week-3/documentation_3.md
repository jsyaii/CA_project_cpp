# CPU Simulation

This simulation models the core components of a CPU, including the Arithmetic Logic Unit (ALU), CPU Core, and Program Counter (PC) & Instruction Register (IR). These components work together to perform basic operations such as arithmetic calculations, data movement, and instruction execution flow tracking.

## Components

### 1. Arithmetic Logic Unit (ALU)

The ALU handles basic arithmetic and logical operations like addition, subtraction, AND, OR, XOR, and NOT.

#### Key Methods:

- **`perform(Operation op, int32_t a, int32_t b = 0)`**  
  Executes the specified operation.  
  Supports the following operations:
  - `ADD`: Adds `a` and `b`.
  - `SUB`: Subtracts `b` from `a`.
  - `AND`: Performs a bitwise AND between `a` and `b`.
  - `OR`: Performs a bitwise OR between `a` and `b`.
  - `XOR`: Performs a bitwise XOR between `a` and `b`.
  - `NOT`: Performs a bitwise NOT on `a` (only `a` is used in this operation).

---

### 2. CPU Core

The CPU Core simulates basic CPU operations such as data movement between registers and arithmetic operations.

#### Key Methods:

- **`load(const string& reg, int value)`**  
  Loads a value into the specified register.
- **`move(const string& src, const string& dest)`**  
  Copies the value from one register to another.
- **`add(const string& r1, const string& r2, const string& result)`**  
  Adds the values from two registers and stores the result in a target register.

- **`print_registers()`**  
  Prints the current state of all registers.

---

### 3. Program Counter (PC) & Instruction Register (IR)

These components track the execution flow:

#### Program Counter (PC)

- **`increment()`**  
  Advances the program counter by 1.

- **`set_value(int new_value)`**  
  Sets the program counter to a specified value.

#### Instruction Register (IR)

- **`load(const string& instruction)`**  
  Loads a new instruction into the instruction register.

---

## Example Usage

```cpp
// Example code for simulating a CPU operation

// ALU Example
ALU alu;
alu.perform(ADD, 5, 3);  // Performs 5 + 3

// CPU Core Example
CPUCore core;
core.load("R1", 10);  // Load 10 into register R1
core.load("R2", 20);  // Load 20 into register R2
core.add("R1", "R2", "R3");  // Add values from R1 and R2 and store the result in R3
core.print_registers();  // Prints the current state of registers

// PC & IR Example
ProgramCounter pc;
pc.increment();  // Increment the program counter
pc.set_value(100);  // Set the program counter to 100

InstructionRegister ir;
ir.load("ADD R1, R2, R3");  // Load a new instruction into the instruction register
```
