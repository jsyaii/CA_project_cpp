# Virtual CPU Emulator: Instruction Set Architecture (ISA)

## Overview

This project simulates a simple virtual CPU emulator that processes a basic set of instructions (ADD, MOV, LOAD, etc.) and converts them into machine code. The emulator defines an Instruction Set Architecture (ISA) that specifies the format of each instruction, including the operation (opcode), the registers involved, and any immediate values.

## Components

### 1. Opcodes

The **Opcodes** represent the various operations that the virtual CPU can execute. Each opcode corresponds to a specific operation, such as addition, subtraction, loading values, or moving data between registers.

Here are the available Opcodes:

- **ADD**: Addition
- **SUB**: Subtraction
- **LOAD**: Load data into a register
- **STORE**: Store data from a register
- **MOV**: Move data between registers
- **JMP**: Jump to a different instruction
- **CMP**: Compare values
- **NOP**: No operation (used for timing or placeholders)

Each opcode is assigned a unique identifier, typically represented in hexadecimal form.

### 2. Registers

The virtual CPU includes a set of registers used to temporarily store data during computation. The registers are indexed, and each one can hold a value. In this project, there are eight registers:

- **R0 to R7**: These are the general-purpose registers used for various operations like arithmetic, storing data, or serving as operands in instructions.

### 3. Instruction Structure

Each instruction consists of:

- **Opcode**: The operation to be performed (e.g., ADD, MOV).
- **Registers**: Two registers are involved in the operation (e.g., R1 and R2).
- **Immediate Value**: Some instructions, like LOAD, require an immediate value, which is a constant provided directly in the instruction (e.g., 100).

The instruction format specifies how each component (opcode, registers, immediate value) is encoded into machine-readable binary format.

---

## Functions in the Emulator

### 1. Binary Conversion

The instructions are translated into machine code by converting each part (opcode, registers, immediate values) into binary strings. This is done by breaking each part of the instruction into smaller chunks (e.g., 8 bits for the opcode, 3 bits for the registers) and converting those chunks to their binary equivalents.

### 2. Assembling the Instruction

Once the individual components are converted to binary, they are concatenated to form the full machine code instruction. The resulting binary string represents the operation in a form that the virtual CPU can execute.

### 3. Assembler Function

The assembler function takes a line of assembly code (e.g., "ADD R1, R2, R3") and maps it to a specific opcode and set of registers. It then assembles the instruction into machine code and outputs the result. The assembler is designed to support a limited set of instructions for simplicity.

---
