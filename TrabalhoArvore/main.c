#include <stdio.h>
#include <stdlib.h>
#include "arvore_n_aria.h"
#include "FilaGenerica.h"
#include "Matriz.h"

#define N m.lin

int main(){

    Matriz m;
    FilaGenerica f;
    Arvore a;
    int i, v, x;
    int *vetorStatus; 
	vetorStatus = malloc(N * sizeof(int));
	for(i = 0; i < N; i++){
		vetorStatus[i] = 0;
	}

    printf("Digite o vertice inicial do percurso:\n");
    scanf("%d", &v);

    if(v < 0 || v > N){
    	printf("Insira vertices validos.\n");
	    return 0;
	}
    
    inicializa_Arvore(&a, v);
    inicializa_fila(&f, N, sizeof(int));
    carrega_arquivo("entrada.txt", &m);

    vetorStatus[v] = 1;
    inserir(&f, &v);

    while(!fila_vazia(f)){
		remover(&f, &x);
		for(i = 0; i < N; i++){
			if(vetorStatus[i] == 0){
				vetorStatus[i] = 1;
                insere_filho(a, x, i);
				inserir(&f, &i);
			}
		}
	}
    gera_xml(a);
    desaloca_arvore(&a);
    desaloca_fila(&f);
    desaloca_matriz(&m);
    free(vetorStatus);

return 0;
}