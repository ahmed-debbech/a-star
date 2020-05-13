#include "utilities.h"
#include "graph.h"
#include <stdio.h>
#include <stdlib.h>

void addAjacentVertecies(Vertex * head, int numberOfVertex){
    int numberOfVertecies = 1;
    int done =0;
    Vertex * hold = NULL;
    do{
        Vertex * v = malloc(sizeof(Vertex));
        printf("Adding vertex number %d as adjacent to vertex number %d\n", numberOfVertecies, numberOfVertex);
        printf("Give vertex letter\n");
        scanf(" %c", &v->letter);
        printf("Give next adjacent vertex distance number\n");
        scanf("%d", &v->distanceToNext);
        if(numberOfVertecies == 1){
            head->next = v;
        }else{
            hold->next = v;
        }
        v->next = NULL;
        printf("Do you want to add more vertecies to vertex number %d y:yes n:no?\n", numberOfVertex );
        char x;
        scanf(" %c", &x);
        if(x == 'n'){
            done = 1;
        }
        hold = v;
        numberOfVertecies++;
    }while(numberOfVertecies <= 100 && done == 0);
}
Map createGraphMap(){
    Map map;
    int numberOfVertecies = 1;
    int done = 0;
    printf("===== New Graph =======\n");
    do{
        Vertex * v = malloc(sizeof(Vertex));
        map.graph = realloc(map.graph, sizeof(Vertex) * numberOfVertecies);
        *map.graph = v;
        printf("Vertex number %d\n", numberOfVertecies);
        printf("Give vertex letter\n");
        scanf(" %c", &v->letter);
        printf("Give next adjacent vertex distance number\n");
        scanf("%d", &v->distanceToNext);
        v->next = NULL;
        printf("Does the vertex number %d has adjacent nodes? y: yes n: no\n", numberOfVertecies);
        char choice;
        scanf(" %c", &choice);
        if(choice == 'y'){
            addAjacentVertecies(v, numberOfVertecies);
        }
        printf("Want to add another vertex? y: yes n: no\n");
        char x;
        scanf(" %c", &x);
        if(choice == 'n'){
            done = 1;
        }
        numberOfVertecies++;
    }while(numberOfVertecies <= 100 && done == 0);
    return map;
}
void showMap(){
}