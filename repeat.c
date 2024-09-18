#include <stdio.h>
#include <stdlib.h>

int *repeat(int *t1, int *t2,int *total_size) {
    *total_size = 0;
    for (int i = 0; i < 3; i++) {
        *total_size += t1[i];
    }
    int *t = (int *)malloc(*total_size * sizeof(int));
    int k = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < t1[i]; j++) {
            t[k] = t2[i];
            k++;
        }
    }

    return t;
}

int main() {
    int t1[]={1,2,4};
    int t2[]={10,3,8};
    int total_size;
    int *t = repeat(t1, t2,&total_size);
    for (int i = 0; i < total_size; i++) {
        printf("%d ", t[i]);
    }
    free(t);
    return 0;
}
