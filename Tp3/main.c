#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 256
#define MAX_WORK_LENGTH 512


typedef struct {
    int year;
    char winners[MAX_NAME_LENGTH];
    char work[MAX_WORK_LENGTH];
} TuringWinner;


int numberOfWinners(FILE *file) {
    int count = 0;
    char ch;
    while ((ch = fgetc(file)) != EOF) {
        if (ch == '\n') {
            count++;
        }
    }
    rewind(file);

    return count;
}



int main() {
    FILE *file = fopen("turingWinners.csv", "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    int count = numberOfWinners(file);
    printf("Number of winners: %d\n", count);

    fclose(file);
    return 0;
}

