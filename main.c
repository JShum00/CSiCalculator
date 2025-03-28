#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

// Function Prototypes:
double operation(double operand1, double operand2, char opSymbol);
void clearScreen();
void programLoop();

int main()
{
    // Start the main program loop:
    programLoop();

    return 0;
}

// Loop Program:
void programLoop()
{
    // Declare Variables:
    double leftOperand;
    double rightOperand;
    double result;

    // Symbol Variable:
    char operatorSymbol;

    // Introduction:
    printf(
        "_________   _________.__  _________        .__               .__          __                 \n"
        "\\_   ___ \\ /   _____/|__| \\_   ___ \\_____  |  |   ____  __ __|  | _____ _/  |_  ___________  \n"
        "/    \\  \\/ \\_____  \\ |  | /    \\  \\/\\__  \\ |  | _/ ___\\|  |  \\  | \\__  \\\\   __\\/  _ \\_  __ \\ \n"
        "\\     \\____/        \\|  | \\     \\____/ __ \\|  |_\\  \\___|  |  /  |__/ __ \\|  | (  <_> )  | \\/ \n"
        " \\______  /_______  /|__|  \\______  (____  /____/\\___  >____/|____(____  /__|  \\____/|__|    \n"
        "        \\/        \\/              \\/     \\/          \\/                \\/                    \n"
    );
    printf("By: Johnny Shumway\n\n");

    printf("NOTICE: ");
    printf("All inputed date will be stored as doubles. Therefore this will be very precise!\n");
    printf("Currently the program supports these operators: \(+, -, *, /\)\n");
    sleep(10);
    clearScreen();

    // Ask for Left Operand:
    printf("Let's begin, tell me the first operand in the equation.\n");
    scanf("%lf", &leftOperand);
    sleep(1);
    clearScreen();

    // Ask for Right Operand:
    printf("Understood, the first operand is %.2lf\n", leftOperand);
    printf("Now I need the second operand, please type below:\n");
    scanf("%lf", &rightOperand);
    sleep(1);
    clearScreen();

    // Recap equation:
    printf("Understood, the second operand is %.2lf\n", rightOperand);
    printf("So, just a recap, %.2lf, and %.2lf are our operands.\n", leftOperand, rightOperand);
    sleep(6);
    clearScreen();

    // Ask for Operator Symbol:
    printf("Now, with that in mind, what operator? \(+, -, *, /\)?\n");
    scanf(" %c", &operatorSymbol);
    sleep(1);
    clearScreen();

    // Recap All:
    printf("Okay, very good. So, %.2lf %c %.2lf.\n", leftOperand, operatorSymbol, rightOperand);

    // Send Operands and Operators:
    if (!isnan(leftOperand) && !isnan(rightOperand) && (operatorSymbol == '+' || operatorSymbol == '-' || operatorSymbol == '*' || operatorSymbol == '/')) {
        result = operation(leftOperand, rightOperand, operatorSymbol);
    }
    else{
        printf("ERROR: Invalid operator or operands!\n");
    }
    sleep(6);
    clearScreen();

    // Print Result:
    printf("Now, to answer the question, the result is: %lf! The program will wait 10 seconds, then restart.\n", result);
    sleep(10);
    clearScreen();

    programLoop();
    return;
}

// Handle clearing screen, depending on platform:
void clearScreen()
{
    #ifdef _WIN32
        system("cls");  // Windows
    #elif defined(__linux__)
        system("clear"); // Linux
    #else
        printf("Clear screen not supported on this platform.\n");
    #endif
}

// Handles calculations:
double operation(double operand1, double operand2, char opSymbol)
{
    // If user sent add symbol:
    if (opSymbol == '+')
    {
        return operand1 + operand2;
    }
    // If user sent subtract symbol:
    else if (opSymbol == '-')
    {
        return operand1 - operand2;
    }
    // If user sent multiply symbol:
    else if (opSymbol == '*')
    {
        return operand1 * operand2;
    }
    // If user sent divide symbol symbol:
    else if (opSymbol == '/')
    {
        // Check for division by zero:
        if (operand2 != 0)
        {
            return operand1 / operand2;
        }
        else
        {
            // Prevent divide by zero:
            printf("ERROR: Division by zero is not allowed.\n");
            return 0;
        }
    }
    else
    {
        // Check if the symbol is valid:
        printf("INVALID OPERATOR: %c\n", opSymbol);
        return 0;
    }
}
