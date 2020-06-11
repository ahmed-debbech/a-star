#include <stdio.h>
#include <stdlib.h>
#include "info.h"

Queue make_info_queue( Map map, char entryVertex){
    int i=0,j=0;
    Queue queue;
    queue.head = NULL;
    queue.tail = NULL;
    int found = 0;
    do{
        if(map.graph[j]->letter == entryVertex){
            found = 1;
        }
        j++;
    }while(j<map.size && found == 0);
    Info * node = (Info*)malloc(sizeof(Info));
    node->data.letter = map.graph[j-1]->letter;
    node->data.distanceFromStart = 0; // zero because this is the starting node
    node->data.via = '-';
    node->next = NULL;
    queue.head = node;
    queue.tail = node;
    for(i=0; i<map.size; i++){
        if(map.graph[i]->letter != entryVertex){
            Info * node = (Info*)malloc(sizeof(Info));
            node->data.letter = map.graph[i]->letter;
            node->data.distanceFromStart = 9999; // means Infinity (INF)
            node->data.via = '-';
            node->next = NULL;
            queue.tail->next = node;
            queue.tail = node;
        }
    }
    return queue;
}
void showQueue(Queue queue){
    while(queue.head != NULL){
        printf("%c , %d, %c\n", queue.head->data.letter, queue.head->data.distanceFromStart, queue.head->data.via);
        queue.head = queue.head->next;
    }
}
/*Queue enqueue(Queue queue, Info * list, Map map){
    int i=0;
    Info * inf = NULL;
    for(i=0; i<map.size; i++){
        if(queue.head == NULL && queue.tail == NULL){
            inf = (Info*)malloc(sizeof(Info));
            
        }
    }
}*/