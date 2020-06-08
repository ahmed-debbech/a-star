#include "algo.h"

Queue fill_distance(Map map, Queue queue){
    Vertex * list = NULL;
    char target = queue.head->data.letter; //the vertex we look its adjacent vertecies (usually the first in queue)
    // now get target vertex from map
    int i=0;
    for(i=0; i<map.size; i++){
        if(map.graph[i]->letter == target){
           list = map.graph[i]; 
           break;
        }
    }
    //now we fill the adjacent vertecies of the queue
    Info * walk = queue.head->next;
    while(walk != NULL){
        Vertex * walkList = list;
        while(walkList != NULL){
            if(walkList->letter == walk->data.letter){
                //we check if it is infinit distance before we add the new one
                if(walk->data.distanceFromStart == -1){
                    walk->data.distanceFromStart = walkList->distanceToNext;
                    walk->data.via = queue.head->data.letter;
                }else{
                    if(walkList->distanceToNext < walk->data.distanceFromStart){
                        walkList->distanceToNext = walkList->distanceToNext + walk->data.distanceFromStart;
                        walk->data.via = queue.head->data.letter;
                    }
                }
                break;
            }
            walkList = walkList->next;
        }
        walk = walk->next;
    }
    return queue;
}
Queue sort_distance(Queue queue){
    // we use selection sort algorithm here
    Info * walk = queue.head->next;
    Info * walk1;
    Data swap;
    while(walk != NULL){
        walk1 = walk->next;
        while(walk1 != NULL){
            if(walk1->data.distanceFromStart < walk->data.distanceFromStart){
                swap = walk1->data;
                walk1->data = walk->data;
                walk->data = swap;
            }
            walk1 = walk1->next;
        }
        walk = walk->next;
    }
    return queue;
}