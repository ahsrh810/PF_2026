#include <stdio.h>

int add(int a, int b, int *result) {
    *result = a + b;
    return 1;
}

int subtract(int a, int b, int *result) {
    *result = a - b;
    return 1;
}

int multiply(int a, int b, int *result) {
    *result = a * b;
    return 1;
}

int divide(int a, int b, int *result) {
    if (b == 0) {
        return 0;
    }
    *result = a / b;
    return 1;
}

int main() {
    int (*ops[])(int, int, int *) = {add, subtract, multiply, divide};
    const char *names[] = {"Add", "Subtract", "Multiply", "Divide"};

    int choice, a, b, res;

    do {
        printf("Choice (1-5): ");
        scanf("%d", &choice);

        if (choice >= 1 && choice <= 4) {
            printf("Enter a and b: ");
            scanf("%d %d", &a, &b);

            if (ops[choice - 1](a, b, &res)) {
                printf("%s result: %d\n", names[choice - 1], res);
            } else {
                printf("Error: division by zero\n");
            }
        } else if (choice == 5) {
            printf("Goodbye.\n");
        } else {
            printf("Invalid choice\n");
        }
    } while (choice != 5);

    return 0;
}