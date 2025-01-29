# Virtual CPU Emulators Documentation week-four

## Code 1: Basic Fetch-Decode-Execute Cycle

### Overview:

Simulates a simple CPU with a fetch-decode-execute cycle.

### Key Features:

- **Memory**: `{0x1A, 0x2B, 0x3C}`.
- **PC** (Program Counter) starts at `0`.
- **IR** (Instruction Register) holds the fetched instruction.
- Cycle continues until all instructions are executed.

### How it Works:

1. **Fetch**: Get the instruction from memory.
2. **Decode**: Convert and print the instruction in hexadecimal format.
3. **Execute**: Print the executed instruction.

---

## Code 2: Virtual CPU with Simple Instruction Set

### Overview:

Simulates a CPU that executes basic arithmetic and data manipulation operations.

### Key Features:

- **Memory**: 256 bytes.
- **Registers**: 8 registers.
- **Opcodes**:
  - `MOV`: Move a value into a register.
  - `ADD`: Add values from two registers and store the result in another register.
  - `SUB`: Subtract values from two registers and store the result in another register.
  - `HLT`: Halt the program.
- Program loads and modifies registers based on instructions.

### How it Works:

1. **CPU** manages memory, registers, and the Program Counter (PC).
2. **Run method** fetches and decodes instructions until `HLT` is encountered.
3. **Prints the final register state** after execution.

---

## Code 3: Simple CPU with Load, Add, and Store Instructions

### Overview:

Simulates a CPU with basic LOAD, ADD, and STORE operations.

### Key Features:

- **Memory**: 10 bytes.
- **Registers**: 4 registers.
- **Instructions**:
  - `LOAD`: Load a value into a register.
  - `ADD`: Add values from two registers and store the result in another register.
  - `STORE`: Store the value of a register into a memory address.
  - `NOP`: No operation (used as a placeholder).

### How it Works:

1. Load the program into memory with `LOAD`, `ADD`, and `STORE` instructions.
2. **Fetch and execute** instructions in a loop.
3. **Output** the final state of registers and memory.
