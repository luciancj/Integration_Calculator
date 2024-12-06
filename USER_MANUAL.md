# Integration Calculator: User Manual

## Table of Contents
- [Introduction](#introduction)
- [System Requirements](#system-requirements)
- [Installation Guide](#installation-guide)
- [Getting Started](#getting-started)
    - [Launching the Program](#launching-the-program)
    - [Modes of Operation](#modes-of-operation)
- [Interactive Mode](#interactive-mode)
    - [Usage](#usage)
    - [Integration Methods Available](#integration-methods-available)
- [Parameter Mode](#parameter-mode)
    - [Loading Input from a File](#loading-input-from-a-file)
    - [Output File](#output-file)
- [Error Handling](#error-handling)
- [Troubleshooting](#troubleshooting)
- [Contact Information](#contact-information)

## Introduction
The **Integration Calculator** is a versatile tool designed for numerically integrating user-defined functions. It is capable of handling various types of functions such as polynomials, trigonometric functions, logarithms, and combinations thereof. The program offers two modes of interaction: **Interactive Mode** for manually entering parameters and **Parameter Mode** for reading inputs from a file.

## System Requirements
- **Operating System**: Works on Linux, macOS, or Windows.
- **C Compiler**: Requires GCC, Clang, or another C99 compatible compiler.
- **Additional Tools**: CMake for building the project.

## Installation Guide
1. **Clone the Repository**:
   ```bash
   git clone https://github.com/yourusername/integration-calculator.git
   ```
2. **Build the Project**:
   ```bash
   cd integration-calculator
   mkdir build && cd build
   cmake ..
   make
   ```
3. **Run the Program**:
   ```bash
   ./Integration_Calculator
   ```

## Getting Started

### Launching the Program
Once installed, navigate to the build directory and launch the executable:
```bash
./Integration_Calculator
```
The program will open with a welcome menu, providing options to select the mode of operation.

### Modes of Operation
The Integration Calculator offers two main modes:
- **Interactive Mode**: Users manually input parameters for integration.
- **Parameter Mode**: Users can load multiple functions and integration parameters from a CSV file.

## Interactive Mode
Interactive Mode allows users to manually specify the function and parameters.

### Usage
1. Start the program.
2. Choose **Interactive Mode** by typing `/i` when prompted.
3. Enter the function you want to integrate. Use `x` as the variable.
4. Enter integration bounds (`a` and `b`), tolerance, and the number of subintervals (for Riemann sums).
5. The program will calculate and display the result.

### Integration Methods Available
- **Regula Falsi** (`/rf`): Finds the root of a function using the Regula Falsi method.
- **Right Riemann Sum** (`/rr`): Calculates the integral using right-endpoint approximations.
- **Left Riemann Sum** (`/lr`): Uses left-endpoint approximations.
- **Midpoint Riemann Sum** (`/mr`): Uses the midpoint for each subinterval.
- **Trapezoidal Rule** (`/tr`): Approximates the integral using trapezoids.
- **Secant Method** (`/sm`): Finds the root using the Secant Method.

## Parameter Mode
Parameter Mode is designed for users who wish to input parameters in bulk using a file.

### Loading Input from a File
1. Choose **Parameter Mode** by typing `/p` when prompted.
2. You will be prompted to enter the filename (e.g., `input.csv`). Ensure the CSV file is formatted as follows:
    - **First column**: Function to integrate (e.g., `x^2 + 3*x`).
    - **Second column**: Lower bound (`a`).
    - **Third column**: Upper bound (`b`).
3. The program will read the file, process each function, and output the results.

### Output File
After successfully reading the file, the program will create an output file named `output.txt` with the following text:
```
File successfully read
```
This file serves as a confirmation that the input file was processed correctly.

## Error Handling
The program includes built-in checks to help users avoid common mistakes. If incorrect input is detected, an error message will be printed to guide the user:
- **Invalid function input**: Ensure the function is written using `x` as the variable.
- **Division by zero**: Ensure that the functions do not lead to division by zero within the interval bounds.

## Troubleshooting
- **Program crashes when entering a variable other than `x`**:
    - Ensure that the variable used in the function is always `x`.
- **File not found error when using Parameter Mode**:
    - Ensure the input CSV file is in the correct directory and named correctly.
- **Incorrect integration result**:
    - Double-check the bounds (`a` and `b`) and the function entered.

## Contact Information
For any issues or feature requests, please reach out to the developers:
- **Email**: lucian.cojocaru@edu.bme.hu
- **GitHub Issues**: [Integration Calculator GitHub Issues](https://github.com/yourusername/integration-calculator/issues)

---
This manual serves as a guide for using the **Integration Calculator** effectively, covering both manual and automated inputs, and providing users with the information they need to get accurate integration results.

