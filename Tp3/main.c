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

void printWinners(FILE *outputFile, TuringWinner *winners, int count) {
    for (int i = 0; i < count; i++) {
        fprintf(outputFile, "%d;%s;%s\n", winners[i].year, winners[i].winners, winners[i].work);
    }
}

void freeWinners(TuringWinner *winners, int count) {
    for (int i = 0; i < count; i++) {
        free(winners[i].winners);
        free(winners[i].work);
    }
}

void infosAnnee(TuringWinner *winners, int count, int year) {
    for (int i = 0; i < count; i++) {
        if (winners[i].year == year) {
            printf("L'annee %d, le(s) gagnant(s) ont été : %s\n", year, winners[i].winners);
            printf("Nature des travaux : %s\n", winners[i].work);
            return;
        }
    }
    printf("Aucun gagnant trouvé pour l'année %d.\n", year);
}

void sortTuringWinnersByYear(TuringWinner *winners, int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (winners[j].year > winners[j + 1].year) {
                TuringWinner temp = winners[j];
                winners[j] = winners[j + 1];
                winners[j + 1] = temp;
            }
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: ./prixTuring [options]\n");
        return 1;
    }

    if (strcmp(argv[1], "--info") == 0 && argc == 4) {
        int year = atoi(argv[2]);
        char *inputFileName = argv[3];

        FILE *inputFile = fopen(inputFileName, "r");
        if (inputFile == NULL) {
            printf("Error: Could not open input file %s.\n", inputFileName);
            return 1;
        }

        int count = numberOfWinners(inputFile);
        TuringWinner *winners = malloc(count * sizeof(TuringWinner));
        readWinners(inputFile, winners, count);

        fclose(inputFile);
        infosAnnee(winners, count, year);
        freeWinners(winners, count);
        free(winners);

        return 0;
    }

    if (strcmp(argv[1], "--sort") == 0 && argc >= 5) {
        char *outputFileName = argv[3];
        char *inputFileName = argv[4];

        FILE *inputFile = fopen(inputFileName, "r");
        if (inputFile == NULL) {
            printf("Error: Could not open input file %s.\n", inputFileName);
            return 1;
        }

        int count = numberOfWinners(inputFile);
        TuringWinner *winners = malloc(count * sizeof(TuringWinner));
        readWinners(inputFile, winners, count);
        fclose(inputFile);
        sortTuringWinnersByYear(winners, count);
        FILE *outputFile = fopen(outputFileName, "w");
        if (outputFile == NULL) {
            printf("Error: Could not open output file %s.\n", outputFileName);
            freeWinners(winners, count);
            free(winners);
            return 1;
        }


        printWinners(outputFile, winners, count);
        printf("Data sorted and written to %s successfully.\n", outputFileName);

        fclose(outputFile);
        freeWinners(winners, count);
        free(winners);

        return 0;
    }

    if (strcmp(argv[1], "-o") == 0 && argc == 4) {
        char *outputFileName = argv[2];
        char *inputFileName = argv[3];

        FILE *inputFile = fopen(inputFileName, "r");
        if (inputFile == NULL) {
            printf("Error: Could not open input file %s.\n", inputFileName);
            return 1;
        }

        int count = numberOfWinners(inputFile);
        TuringWinner *winners = malloc(count * sizeof(TuringWinner));
        readWinners(inputFile, winners, count);

        fclose(inputFile);


        FILE *outputFile = fopen(outputFileName, "w");
        if (outputFile == NULL) {
            printf("Error: Could not open output file %s.\n", outputFileName);
            freeWinners(winners, count);
            free(winners);
            return 1;
        }

        printWinners(outputFile, winners, count);
        printf("Data written to %s successfully.\n", outputFileName);


        fclose(outputFile);
        freeWinners(winners, count);
        free(winners);

        return 0;
    }


    printf("Error: Unrecognized command.\n");
    return 1;
}
