#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int year;
    char *winners;
    char *work;
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


void readWinners(FILE *file, TuringWinner *winners, int count) {
    char line[1024];
    int i = 0;
    while (fgets(line, sizeof(line), file) && i < count) {
        char *token = strtok(line, ";");
        winners[i].year = atoi(token);
        token = strtok(NULL, ";");
        winners[i].winners = malloc(strlen(token) + 1);
        strcpy(winners[i].winners, token);
        token = strtok(NULL, "\n");
        winners[i].work = malloc(strlen(token) + 1);
        strcpy(winners[i].work, token);
        i++;
    }
}

void freeWinners(TuringWinner *winners, int count) {
    for (int i = 0; i < count; i++) {
        free(winners[i].winners);
        free(winners[i].work);
    }
}
void printWinners(FILE *outputFile, TuringWinner *winners, int count) {
    for (int i = 0; i < count; i++) {
        fprintf(outputFile, "%d;%s;%s\n", winners[i].year, winners[i].winners, winners[i].work);
    }
}


int main() {
    FILE *file = fopen("turingWinners.csv", "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }
    int count = numberOfWinners(file);
    printf("Number of winners: %d\n", count);
    TuringWinner *winners = malloc(count * sizeof(TuringWinner));
    readWinners(file, winners, count);
    for (int i = 0; i < count; i++) {
        printf("Year: %d, Winners: %s, Work: %s\n", winners[i].year, winners[i].winners, winners[i].work);
    }
    FILE *outputFile = fopen("out.csv", "w");
    if (outputFile == NULL) {
        printf("Error: Could not open output file.\n");
        free(winners);
        return 1;
    }

    printWinners(outputFile, winners, count);

    printf("Done.\n");
    freeWinners(winners, count);
    free(winners);
    fclose(file);
    fclose(outputFile);

    return 0;
}
