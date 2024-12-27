# employee_transpose.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100
#define MAX_LEN 100

// Function to transpose data
void transpose_data(char rows[MAX_ROWS][MAX_COLS][MAX_LEN], int row_count, int col_count) {
    for (int j = 0; j < col_count; j++) {
        for (int i = 0; i < row_count; i++) {
            printf("%s ", rows[i][j]);
        }
        printf("\n");
    }
}

int main() {
    FILE *fp;
    char rows[MAX_ROWS][MAX_COLS][MAX_LEN];
    int row_count = 0, col_count = 0;

    // Open file for reading
    fp = fopen("employee_data.txt", "r");
    if (fp == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    // Read file line by line
    char line[MAX_LEN];
    while (fgets(line, sizeof(line), fp)) {
        // Split line into attributes
        char *token = strtok(line, " \n");
        int col = 0;
        while (token != NULL) {
            strcpy(rows[row_count][col], token);
            token = strtok(NULL, " \n");
            col++;
        }
        row_count++;
        if (col > col_count) col_count = col;
    }

    // Close file
    fclose(fp);

    // Print header
    printf("Transposed Employee Data:\n");

    // Print transposed data
    transpose_data(rows, row_count, col_count);

    return EXIT_SUCCESS;
}
