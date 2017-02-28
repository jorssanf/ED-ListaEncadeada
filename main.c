#include <stdio.h>
#include <stdlib.h>
#include "listaenc.h"

int main(){
    lista l1;
    int dado;

    criar(&l1);
    inserir(&l1, 1, 10);
    inserir(&l1, 2, 20);
    inserir(&l1, 3, 30);
    imprime(l1);
    
    
return 0;
}
