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