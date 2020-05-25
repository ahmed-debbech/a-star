#include <stdlib.h>
#include <stdio.h>
#include "utilities.h"
#include "graph.h"
#include "info.h"

int main(){
    Map map;

    Queue queue; // this will hold all the information table of the graph
    queue.head = NULL;
    queue.tail = NULL;

    map = createGraphMap();
    showMap(map);

    char entry, exit;
    printf("Give the character of the entry vertex.");
    scanf(" %c", &entry);
    printf("Give the character of the exit vertex.");
    scanf(" %c", &exit);

    char * visited; //heap located array pointer
    char * unvisited; // heap located array pointer
    unvisited = pushVertecies(unvisited,map);
    queue = make_info_queue(map, entry);
    showQueue(queue);
    
    return 0;
}