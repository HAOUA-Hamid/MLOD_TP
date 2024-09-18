#include <stdio.h>
#include <stdlib.h>

int *repeat(int *t1, int *t2, int size, int *total_size) {
    *total_size = 0;
    for (int i = 0; i < size; i++) {
        *total_size += t1[i];
    }
    int *t = (int *)malloc(*total_size * sizeof(int));
    int k = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < t1[i]; j++) {
            t[k] = t2[i];
            k++;
        }
    }

    return t;
}

int main() {
    int size;
    printf("Enter the size of the arrays: ");
    scanf("%d", &size);
    int *t1 = (int *)malloc(size * sizeof(int));
    int *t2 = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        if((i+1)%10==1){
            printf("Enter the %d st elements of t1: ",i+1);
        }else if((i+1)%10==2){
            printf("Enter the %d nd elements of t1: ",i+1);
        }else if((i+1)%10==3){
            printf("Enter the %d rd elements of t1: ",i+1);
        }else{
             printf("Enter the %d th elements of t1: ",i+1);
        }
        scanf("%d", &t1[i]);
    }
    for (int i = 0; i < size; i++) {
        if(((i+1)!=11) && ((i+1)%10==1)){
            printf("Enter the %d st elements of t2: ",i+1);
        }else if(((i+1)!=12) && (i+1)%10==2){
            printf("Enter the %d nd elements of t2: ",i+1);
        }else if(((i+1)!=13) && (i+1)%10==3){
            printf("Enter the %d rd elements of t2: ",i+1);
        }else{
             printf("Enter the %d th elements of t2: ",i+1);
        }
        scanf("%d", &t2[i]);
    }
    int total_size;
    int *t = repeat(t1, t2, size, &total_size);
    printf("Result array: ");
    for (int i = 0; i < total_size; i++) {
        printf("%d ", t[i]);
    }
    printf("\n");
    free(t);
    free(t1);
    free(t2);

    return 0;
}
