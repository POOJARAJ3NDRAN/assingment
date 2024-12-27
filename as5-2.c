#include <stdio.h>

#define PI 3.14

struct Rectangle {
    int length;
    int breadth;
    int area;
};

struct Circle {
    int radius;
    float area;
};

struct Triangle {
    float base;
    float height;
    float area;
};

void calculateRectangleArea(struct Rectangle *rect) {
    rect->area = rect->length * rect->breadth;
}

void calculateCircleArea(struct Circle *circle) {
    circle->area = PI * circle->radius * circle->radius;
}

void calculateTriangleArea(struct Triangle *triangle) {
    triangle->area = 0.5 * triangle->base * triangle->height;
}

int main() {
    int choice;

    printf("Menu:\n");
    printf("1. Rectangle\n");
    printf("2. Circle\n");
    printf("3. Triangle\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1: {
            struct Rectangle rect;
            printf("Enter the length and breadth: ");
            scanf("%d %d", &rect.length, &rect.breadth);
            calculateRectangleArea(&rect);
            printf("Rectangle area: %d\n", rect.area);
            break;
        }
        case 2: {
            struct Circle circle;
            printf("Enter the radius: ");
            scanf("%d", &circle.radius);
            calculateCircleArea(&circle);
            printf("Circle area: %.2f\n", circle.area);
            break;
        }
        case 3: {
            struct Triangle triangle;
            printf("Enter the base and height: ");
            scanf("%f %f", &triangle.base, &triangle.height);
            calculateTriangleArea(&triangle);
            printf("Triangle area: %.2f\n", triangle.area);
            break;
        }
        default:
            printf("Invalid choice\n");
            break;
    }

    return 0;
}

