#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int numJewelsInStones(char *jewels, char *stones) {
    int count = 0;
    for (int i = 0; stones[i] != '\0'; i++) {
        if (strchr(jewels, stones[i]) != NULL) {
            count++;
        }
    }
    return count;
}

int main() {
    char jewels[100], stones[100];
    printf("Enter the jewels string: ");
    scanf("%s", jewels);
    printf("Enter the stones string: ");
    scanf("%s", stones);

    int count = numJewelsInStones(jewels, stones);
    printf("Number of jewels in stones: %d\n", count);

    return 0;
}

