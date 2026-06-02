#include <ctype.h>
#include <math.h>
#include <stdio.h>

#define RESULT_PRECISION 9

// Function Prototypes:
void programLoop(void);
void printIntroduction(void);
int readDouble(const char *prompt, double *value);
int readOperator(char *operatorSymbol);
int shouldContinue(void);
void clearInputBuffer(void);
void clearScreen(void);
double operation(double operand1, double operand2, char opSymbol);

int main(void)
{
    // Start the main program loop:
    programLoop();

    return 0;
}

// Loop Program:
void programLoop(void)
{
    printIntroduction();

    while (1)
    {
        double leftOperand;
        double rightOperand;
        double result;
        char operatorSymbol;

        // Ask for Left Operand:
        if (!readDouble("Let's begin, tell me the first operand in the equation: ", &leftOperand))
        {
            printf("ERROR: Invalid first operand. Please enter a valid number.\n\n");
            continue;
        }

        // Ask for Right Operand:
        printf("Understood, the first operand is %.*lf\n", RESULT_PRECISION, leftOperand);
        if (!readDouble("Now I need the second operand, please type below: ", &rightOperand))
        {
            printf("ERROR: Invalid second operand. Please enter a valid number.\n\n");
            continue;
        }

        // Ask for Operator Symbol:
        printf("Understood, the second operand is %.*lf\n", RESULT_PRECISION, rightOperand);
        printf("So, just a recap, %.*lf and %.*lf are our operands.\n",
               RESULT_PRECISION,
               leftOperand,
               RESULT_PRECISION,
               rightOperand);

        if (!readOperator(&operatorSymbol))
        {
            printf("ERROR: Invalid operator. Please enter one of these operators: +, -, *, /.\n\n");
            continue;
        }

        // Recap All:
        printf("Okay, very good. So, %.*lf %c %.*lf.\n",
               RESULT_PRECISION,
               leftOperand,
               operatorSymbol,
               RESULT_PRECISION,
               rightOperand);

        // Send Operands and Operator:
        result = operation(leftOperand, rightOperand, operatorSymbol);
        if (!isnan(result))
        {
            // Print Result:
            printf("Now, to answer the question, the result is: %.*lf!\n\n", RESULT_PRECISION, result);
        }
        else
        {
            printf("Unable to calculate a result for that equation.\n\n");
        }

        if (!shouldContinue())
        {
            printf("Goodbye!\n");
            break;
        }

        clearScreen();
    }
}

void printIntroduction(void)
{
    // Introduction:
    printf(
        "_________   _________.__  _________        .__               .__          __                 \n"
        "\\_   ___ \\ /   _____/|__| \\_   ___ \\_____  |  |   ____  __ __|  | _____ _/  |_  ___________  \n"
        "/    \\  \\/ \\_____  \\ |  | /    \\  \\/\\__  \\ |  | _/ ___\\|  |  \\  | \\__  \\\\   __\\/  _ \\_  __ \\ \n"
        "\\     \\____/        \\|  | \\     \\____/ __ \\|  |_\\  \\___|  |  /  |__/ __ \\|  | (  <_> )  | \\/ \n"
        " \\______  /_______  /|__|  \\______  (____  /____/\\___  >____/|____(____  /__|  \\____/|__|    \n"
        "        \\/        \\/              \\/     \\/          \\/                \\/                    \n");
    printf("By: Johnny Shumway\n\n");

    printf("NOTICE: ");
    printf("All input data will be stored as doubles for precise calculations.\n");
    printf("Currently the program supports these operators: (+, -, *, /)\n\n");
}

int readDouble(const char *prompt, double *value)
{
    int fieldsRead;

    printf("%s", prompt);
    fieldsRead = scanf("%lf", value);
    clearInputBuffer();

    return fieldsRead == 1 && !isnan(*value);
}

int readOperator(char *operatorSymbol)
{
    int fieldsRead;

    printf("Now, with that in mind, what operator? (+, -, *, /): ");
    fieldsRead = scanf(" %c", operatorSymbol);
    clearInputBuffer();

    return fieldsRead == 1
        && (*operatorSymbol == '+' || *operatorSymbol == '-' || *operatorSymbol == '*' || *operatorSymbol == '/');
}

int shouldContinue(void)
{
    while (1)
    {
        char answer;
        int fieldsRead;

        printf("Would you like to calculate another equation? (y/n): ");
        fieldsRead = scanf(" %c", &answer);
        clearInputBuffer();

        if (fieldsRead != 1)
        {
            return 0;
        }

        answer = (char)tolower((unsigned char)answer);
        if (answer == 'y')
        {
            return 1;
        }

        if (answer == 'n')
        {
            return 0;
        }

        printf("Please enter 'y' to continue or 'n' to exit.\n");
    }
}

void clearInputBuffer(void)
{
    int currentCharacter;

    while ((currentCharacter = getchar()) != '\n' && currentCharacter != EOF)
    {
        // Discard characters left in the input buffer.
    }
}

// Handle clearing screen, depending on platform:
void clearScreen(void)
{
    // Print newlines instead of shelling out to system("clear") or system("cls").
    printf("\n\n");
}

// Handles calculations:
double operation(double operand1, double operand2, char opSymbol)
{
    switch (opSymbol)
    {
        case '+':
            return operand1 + operand2;
        case '-':
            return operand1 - operand2;
        case '*':
            return operand1 * operand2;
        case '/':
            // Check for division by zero:
            if (operand2 != 0)
            {
                return operand1 / operand2;
            }

            // Prevent divide by zero:
            fprintf(stderr, "ERROR: Division by zero is not allowed.\n");
            return NAN;
        default:
            // Check if the symbol is valid:
            fprintf(stderr, "INVALID OPERATOR: %c\n", opSymbol);
            return NAN;
    }
}
