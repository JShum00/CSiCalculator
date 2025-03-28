# CSiCalculator

A simple console calculator built in C using MinGW and Code::Blocks. This calculator performs basic arithmetic operations (+, -, *, /) on two operands entered by the user.

## Features

- Support for four basic operations: addition, subtraction, multiplication, and division.
- User-friendly prompts for entering operands and selecting operators.
- Handles division by zero with an error message.
- Displays results with precision.

## Requirements

- MinGW (GCC)
- Code::Blocks (or any IDE that supports C and MinGW)

## How I Setup Code::Blocks
- Go to [Code::Blocks](https://www.codeblocks.org/downloads/binaries/) and select the appropriate downloadable binary. For Example, being on Windows 10, I used: codeblocks-20.03mingw-setup.exe. It's important to grab one with MinGw, otherwise you won't have a compiler...
- Install with the installer, ensure you install everything in the installer.
- Open the CBP file in Code::Blocks.
- Click on the Build and run button. It looks like a yellow gear/cog with a green triangle in-front of it near the top toolbar.

## How to Use

1. Clone this repository to your local machine.
2. Open the project in Code::Blocks or any C IDE.
3. Build and run the program.
4. Follow the on-screen prompts to input operands and an operator.
5. The program will display the result after performing the calculation.

## Compilation

To compile the program, you can use the following command (if using MinGW from the terminal):

```bash
gcc -o calculator main.c -lm
```

## License
The project is licensed under the MIT License - see the LICENSE file for details.

## Author
Johnny Shumway

## Acknowledgments
Thanks to Code::Blocks and MinGW for providing an excellent lightweight development environment.
