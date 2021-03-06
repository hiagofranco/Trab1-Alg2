#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

#define LCHILD(x) 2 * x + 1
#define RCHILD(x) 2 * x + 2
#define PARENT(x) (x - 1) / 2

int isEmpty(minHeap *hp){
    if(hp->size == 0) return 1;
    else return 0;
}

minHeap initMinHeap(int size) {
    minHeap hp ;
    hp.size = 0 ;
    return hp ;
}

void swap(taresta *n1, taresta *n2) {
    taresta temp = *n1 ;
    *n1 = *n2 ;
    *n2 = temp ;
}

void heapify(minHeap *hp, int i) {
    int smallest = (LCHILD(i) < hp->size && hp->elem[LCHILD(i)].peso < hp->elem[i].peso) ? LCHILD(i) : i ;
    if(RCHILD(i) < hp->size && hp->elem[RCHILD(i)].peso < hp->elem[smallest].peso) {
        smallest = RCHILD(i) ;
    }
    if(smallest != i) {
        swap(&(hp->elem[i]), &(hp->elem[smallest])) ;
        heapify(hp, smallest) ;
    }
}
/*
void buildMinHeap(minHeap *hp, int *arr, int size) {
    int i ;

    // Insertion into the heap without violating the shape property
    for(i = 0; i < size; i++) {
        if(hp->size) {
            hp->elem = realloc(hp->elem, (hp->size + 1) * sizeof(node)) ;
        } else {
            hp->elem = malloc(sizeof(node)) ;
        }
        node nd ;
        nd.pesoaresta = arr[i] ;
        hp->elem[(hp->size)++] = nd ;
    }

    // Making sure that heap property is also satisfied
    for(i = (hp->size - 1) / 2; i >= 0; i--) {
        heapify(hp, i) ;
    }
}
*/

void insertNode(minHeap *hp, taresta *u) {
    if(hp->size) {
        hp->elem = realloc(hp->elem, (hp->size + 1) * sizeof(taresta)) ;
    } else {
        hp->elem = malloc(sizeof(taresta)) ;
    }

    taresta nd ;
    nd.id = u.id;
    nd.peso = u.peso;

    int i = (hp->size)++ ;
    while(i && nd.peso < hp->elem[PARENT(i)].peso) {
        hp->elem[i] = hp->elem[PARENT(i)] ;
        i = PARENT(i) ;
    }
    hp->elem[i] = nd ;
}

void deleteNode(minHeap *hp) {
    if(hp->size) {
        printf("Deleting node %d\n\n", hp->elem[0].id) ;
        hp->elem[0] = hp->elem[--(hp->size)] ;
        hp->elem = realloc(hp->elem, hp->size * sizeof(taresta)) ;
        heapify(hp, 0) ;
    } else {
        printf("\nMin Heap is empty!\n") ;
        free(hp->elem) ;
    }
}

void deleteMinHeap(minHeap *hp) {
    free(hp->elem) ;
}

taresta retirar_Min(minHeap* minHeap)
{
    // Gurdar a raiz do n�
    taresta raiz = minHeap->elem[0];

    // Troca o n� raiz com o ult�mo n�
    taresta ultimo_Node = minHeap->elem[minHeap->size-1];
    minHeap->elem[0] = ultimo_Node;

    // Reduz tamanho atual  heap e da raiz heapify
    minHeap->size = minHeap->size-1;
    heapify(minHeap,0);

    return raiz;
}
