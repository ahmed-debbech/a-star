#include "utilities.h"
#include "graph.h"
#include <stdio.h>
#include <stdlib.h>

void addAjacentVrtecies(Vertex * head){
    int numberOfVertecies = 0;
    Vertex * v = malloc(sizeof(Vertex));
    printf()
}
void createGraphMap(){
    Vertex * graph[100];
    int numberOfVertecies = 0;
    printf("===== New Graph =======");
    do{
        Vertex * v = malloc(sizeof(Vertex));
        graph[numberOfVertecies] = v;
        printf("Vertex number %d", numberOfVertecies);
        printf("Give vertex letter");
        scanf(" %c", &v->letter);
        printf("Give next adjacent vertex distance number");
        scanf("%d", &v->distanceToNext);
        v->next = NULL;
        printf("Does the vertex number %d has adjacent nodes? y: yes n: no", numberOfVertecies);
        int choice;
        scanf(" %c", &choice);
        if(choice == 'y'){
            addAdjacentVertecies(v);
        }
        numberOfVertecies++;
    }while(1);
}