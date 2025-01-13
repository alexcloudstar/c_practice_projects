#include <stdio.h>

void printInitMessage();
int getUserInput(const char *prompt);
int calculate(int op, int num1, int num2, int *result);

int main() {
    int op, num1, num2, res;
    char choice;

    do {
        printInitMessage();

        op = getUserInput("Select an operation (1-4): ");

        if(op < 1 || op > 4) {
            printf("Invalid operation selected. Please try again.\n");
            continue;
        };

        num1 = getUserInput("Enter Num 1: ");
        num2 = getUserInput("Enter Num 2: ");

        if(calculate(op, num1, num2, &res)) {
            printf("Calculation failed\n");
            continue;
        }

        printf("Your result is %d\n", res);

        printf("Do you want to perform another calculation? (y/n): ");

        while (getchar() != '\n');

        scanf("%c", &choice);


    } while (choice == 'y' || choice == 'Y');

    printf("Thank you for using the Calculator App. Goodbye!\n");


    return 0;
}

void printInitMessage() {
    printf("\n-------------- Calculator App --------------\n");
    printf("Select an operation:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("--------------------------------------------\n");
}

int getUserInput(const char *prompt) {
    int input;

    while (1) {
        printf("%s", prompt);

        if(scanf("%d", &input) == -1) {
            printf("Invalid input. Please enter a valid number.\n");
            while (getchar() != '\n');
        }

        break;
    }

    return input;
};

int calculate(int op, int num1, int num2, int *result) {
    if((num1 == 0 || num2 == 0) && op == 4) {
        printf("Error: Division by zero is not allowed.\n");

        return 1;
    };

    switch (op) {
        case 1: *result = num1 + num2; break; 
        case 2: *result = num1 - num2; break; 
        case 3: *result = num1 * num2; break; 
        case 4: *result = num1 / num2; break; 
        default:
            printf("Error: Invalid operation.\n");
            return 1;
    };

    return 0;
}
