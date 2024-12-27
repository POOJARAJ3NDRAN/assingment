# orders.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ORDERS 100
#define CITY_LEN 3

// Structure to store city order count
typedef struct {
    char city[CITY_LEN + 1];
    int count;
} CityOrders;

int compare(const void *a, const void *b) {
    CityOrders *city1 = (CityOrders *)a;
    CityOrders *city2 = (CityOrders *)b;
    return strcmp(city1->city, city2->city);
}

int main() {
    FILE *fp;
    char order[MAX_ORDERS][MAX_ORDERS];
    CityOrders cities[MAX_ORDERS];
    int order_count = 0, city_count = 0;

    // Open file for reading
    fp = fopen("orders.txt", "r");
    if (fp == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    // Read file line by line
    char line[MAX_ORDERS];
    while (fgets(line, sizeof(line), fp)) {
        // Extract order IDs
        char *token = strtok(line, ",\n");
        while (token != NULL) {
            strcpy(order[order_count], token);
            order_count++;
            token = strtok(NULL, ",\n");
        }
    }

    // Close file
    fclose(fp);

    // Count city orders
    for (int i = 0; i < order_count; i++) {
        char city[CITY_LEN + 1];
        strncpy(city, order[i], CITY_LEN);
        city[CITY_LEN] = '\0';

        int found = 0;
        for (int j = 0; j < city_count; j++) {
            if (strcmp(cities[j].city, city) == 0) {
                cities[j].count++;
                found = 1;
                break;
            }
        }

        if (!found) {
            strcpy(cities[city_count].city, city);
            cities[city_count].count = 1;
            city_count++;
        }
    }

    // Sort cities by order count
    qsort(cities, city_count, sizeof(CityOrders), compare);

    // Find city with first 5 orders
    for (int i = city_count - 1; i >= 0; i--) {
        if (cities[i].count >= 5) {
            printf("%s\n", cities[i].city);
            return EXIT_SUCCESS;
        }
    }

    printf("-1\n");
    return EXIT_SUCCESS;
}

