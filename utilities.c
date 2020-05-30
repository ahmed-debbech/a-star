#include "utilities.h"
#include "graph.h"
#include <stdio.h>
#include <stdlib.h>

void addAjacentVertecies(Vertex * head){
    int numberOfVertecies = 1;
    int done =0;
    Vertex * hold = NULL;
    do{
        Vertex * v = malloc(sizeof(Vertex));
        printf("Adding vertex number %d as adjacent to vertex '%c'\n", numberOfVertecies, head->letter);
        printf("Give vertex letter\n");
        scanf(" %c", &v->letter);
        printf("Give next adjacent vertex distance number from '%c' vertex\n", head->letter);
        scanf("%d", &v->distanceToNext);
        if(numberOfVertecies == 1){
            head->next = v;
        }else{
            hold->next = v;
        }
        v->next = NULL;
        printf("Do you want to add more vertecies to vertex number '%c' y:yes n:no?\n", head->letter );
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
    map.size = 0;
    int numberOfVertecies = 1;
    int done = 0;
    map.graph = NULL;
    printf("===== New Graph =======\n");
    do{
        Vertex * v = malloc(sizeof(Vertex)); 
        map.graph = realloc(map.graph, sizeof(Vertex*) * numberOfVertecies);
        printf("Vertex number %d\n", numberOfVertecies);
        printf("Give vertex letter\n");
        scanf(" %c", &v->letter);
        v->distanceToNext = 0;
        v->next = NULL;
        map.graph[map.size] = v;
        map.size++;
        printf("Does the vertex '%c' has adjacent nodes? y: yes n: no\n", v->letter);
        char choice;
        scanf(" %c", &choice);
        if(choice == 'y'){
            addAjacentVertecies(v);
        }
        printf("Want to add another vertex? y: yes n: no\n");
        char x;
        scanf(" %c", &x);
        if(x == 'n'){
            done = 1;
        }
        numberOfVertecies++;
    }while(numberOfVertecies <= 100 && done == 0);
    return map;
}
void showMap(Map m){
    int i=0;
    for(i=0; i<m.size; i++){
        Vertex * walk = m.graph[i];
        while(walk != NULL){
            printf("(%c, %d)", walk->letter, walk->distanceToNext);
            walk = walk->next;
        }
        printf("\n");
    }
}
char * pushVertecies(char * unvisited, Map map){
    int i;
    unvisited = NULL;
    for(i=1; i<=map.size; i++){
        unvisited = realloc(unvisited, sizeof(char)*i);
        unvisited[i-1] = map.graph[i-1]->letter;
    }
    return unvisited;
}