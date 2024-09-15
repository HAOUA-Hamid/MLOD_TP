#include <stdio.h>
#include <stdbool.h>

typedef unsigned long long TypeEntier;


TypeEntier factorielle(TypeEntier n)
{
    TypeEntier fact = 1;
    for (TypeEntier i = 1; i <= n; i++)
    {
        fact *= i;
    }
    return fact;
}


bool estParfait(int nbr)
{
    int somme = 0;
    for (int i = 1; i < nbr; i++)
    {
        if (nbr % i == 0)
        {
            somme += i;
        }
    }
    return somme == nbr;
}

int main()
{
    int choice;
    int nbr;

    printf("Choose an option:\n");
    printf("1. Calculate factorial of numbers from 1 to 15\n");
    printf("2. Check if a number is perfect\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);

    if (choice == 1)
    {
        for (TypeEntier i = 1; i <= 15; i++)
        {
            printf("Factorial of %llu = %llu\n", i, factorielle(i));
        }
    }
    else if (choice == 2)
    {
        printf("Enter a number: ");
        scanf("%d", &nbr);
        for(int i=1;i<nbr;i++)
        {
            if (estParfait(i))
            {
            printf("%d ",i);
            }
        }
    }
    else
    {
        printf("Invalid choice\n");
    }

    return 0;
}
