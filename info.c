#include <stdio.h>
#include <stdlib.h>
#include "info.h"

Info * make_info_list( Map map, char entryVertex){
    int i=0,j=0;
    Info * head = NULL;
    Info * hold = NULL;
    int found = 0;
    do{
        if(map.graph[j]->letter == entryVertex){
            found = 1;
        }
        j++;
    }while(j<map.size && found == 0);
    Info * node = (Info*)malloc(sizeof(Info));
    node->letter = map.graph[j-1]->letter;
    node->distanceFromStart = 0; // zero because this is the starting node
    node->via = '-';
    node->next = NULL;
    head = node;
    hold = head;
    for(i=0; i<map.size; i++){
        if(map.graph[i]->letter != entryVertex){
            Info * node = (Info*)malloc(sizeof(Info));
            node->letter = map.graph[i]->letter;
            node->distanceFromStart = -1; // means Infinity (INF)
            node->via = '-';
            node->next = NULL;
            hold->next = node;
            hold = node;
        }
    }
    return head;
}
void showList(Info * list){
    while(list != NULL){
        printf("%c , %d, %c\n", list->letter, list->distanceFromStart, list->via);
        list = list->next;
    }
}