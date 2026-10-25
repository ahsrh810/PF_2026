#include <stdio.h>

void swapValues(int *a, int *b) {
    *a = *a + *b;
    *b = *a - *b; 
    *a = *a - *b; 
}

int main() {
    int priceA, priceB;

    printf("Enter price A: ");
    scanf("%d", &priceA);
    printf("Enter price B: ");
    scanf("%d", &priceB);

    printf("Before swap: A = %d, B = %d\n", priceA, priceB);

    swapValues(&priceA, &priceB);

    printf("After swap:\nA = %d, B = %d\n", priceA, priceB);

    return 0;
}