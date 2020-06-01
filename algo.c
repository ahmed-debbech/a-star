#include "algo.h"

Queue fill_distance(Map map, Queue queue){
    Vertex * list = NULL;
    char target = queue.head->letter; //the vertex we look its adjacent vertecies (usually the first in queue)
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
            if(walkList->letter == walk->letter){
                //we check if it is infinit distance before we add the new one
                if(walk->distanceFromStart == -1){
                    walk->distanceFromStart = walkList->distanceToNext;
                    walk->via = queue.head->letter;
                }else{
                    if(walkList->distanceToNext < walk->distanceFromStart){
                        walkList->distanceToNext = walkList->distanceToNext + walk->distanceFromStart;
                        walk->via = queue.head->letter;
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
    Info swap;
    printf("walkkkk %d\n", walk->distanceFromStart);
    while(walk != NULL){
        walk1 = walk->next;
        printf("walk1 %d\n", walk1->distanceFromStart);
        while(walk1 != NULL){
            if(walk1->distanceFromStart < walk->distanceFromStart){
                printf("walk1 inside if %d\n", walk1->distanceFromStart);
                swap = *walk1;
                *walk1 = *walk;
                *walk = swap;
            }
            //printf("walk1 inside 2 while %d\n", walk1->distanceFromStart);
            walk1 = walk1->next;
        }
        walk = walk->next;
        printf("walk %d\n", walk->distanceFromStart);
    }
    return queue;
}