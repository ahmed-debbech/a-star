#include "utilities.h"
#include "graph.h"
#include <stdio.h>
#include <stdlib.h>

void addAjacentVrtecies(Vertex * head, int numberOfVertex){
    int numberOfVertecies = 0;
    int done =0;
    do{
        Vertex * v = malloc(sizeof(Vertex));
        printf("Adding vertex number %d as adjacent to vertex number %d", numberOfVertecies, numberOfVertex);
        printf("Give vertex letter");
        scanf(" %c", &v->letter);
        printf("Give next adjacent vertex distance number");
        scanf("%d", &v->distanceToNext);
        v->next = NULL;
        printf("Do you want to add more vertecies to vertex number %d y:yes n:no?", numberOfVertex );
        char x;
        scanf(" %c", &x);
        if(x == 'y'){
            done = 1;
        }
        numberOfVertecies++;
    }while(numberOfVertecies <= 100 && done == 0);
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
        char choice;
        scanf(" %c", &choice);
        if(choice == 'y'){
            addAjacentVertecies(v, numberOfVertecies);
        }
        numberOfVertecies++;
    }while(1);
}