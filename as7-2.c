#include <stdio.h>

// Define a union
typedef union {
    int x;
    int y;
} test;

int main() {
    test t; // Create an instance of the union

    // Prompt the user to input an integer value for x
    printf("Enter the value of x: ");
    scanf("%d", &t.x);

    // Display the current values of x and y after setting x
    printf("After making x = %d:\n", t.x);
    printf("x = %d\n", t.x);
    printf("y = %d\n", t.y);

    // Prompt the user to input an integer value for y
    printf("Enter the value of y: ");
    scanf("%d", &t.y);

    // Display the updated values of x and y after setting y
    printf("After making y = %d:\n", t.y);
    printf("x = %d\n", t.x);
    printf("y = %d\n", t.y);

    return 0;
}

