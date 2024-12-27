# keyword_frequency.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to count keyword frequency
int count_keyword(char *filename, char *keyword) {
    FILE *fp;
    int count = 0;
    char word[100];

    // Open file for reading
    fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        return -1;
    }

    // Read file word by word
    while (fscanf(fp, "%s", word) == 1) {
        // Convert word to lowercase
        for (int i = 0; word[i]; i++) {
            word[i] = tolower(word[i]);
        }

        // Check if word matches keyword
        if (strcmp(word, keyword) == 0) {
            count++;
        }
    }

    // Close file
    fclose(fp);
    return count;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <filename> <keyword>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *filename = argv[1];
    char *keyword = argv[2];

    // Convert keyword to lowercase
    for (int i = 0; keyword[i]; i++) {
        keyword[i] = tolower(keyword[i]);
    }

    int frequency = count_keyword(filename, keyword);

    if (frequency != -1) {
        printf("The word \"%s\" appears %d times.\n", keyword, frequency);
    }

    return EXIT_SUCCESS;
}

