#include "linkedList.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


void afficheString(Element e) {
    printf("%s ", (char*)e); 
}

void detruireString(Element e) {
    free(e); 
}

bool equalsString(Element e1, Element e2) {
    return strcmp((char*)e1, (char*)e2) == 0;
}

int main() {
    Liste list = NULL;

    list = ajoutTete(strdup("chainee"), list);
    list = ajoutTete(strdup("list"), list);

    afficheListe(list, afficheString); 

    Liste found = cherche(list, "chainee", equalsString);
    if (found) {
        printf("Found: %s\n", (char*)found->data);
    }else {
        printf("Not found\n");
    }

    detruireListe(list, detruireString);
    return 0;
}
