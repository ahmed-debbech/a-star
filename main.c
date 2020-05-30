#include <stdlib.h>
#include <stdio.h>
#include "utilities.h"
#include "graph.h"
#include "info.h"
#include "algo.h"

int main(){
    //changing stdin for faster input
    freopen("examples/graph1.txt", "r", stdin);

    Map map;

    Queue queue; // this will hold all the information table of the graph
    queue.head = NULL;
    queue.tail = NULL;

    map = createGraphMap();
    showMap(map);

    char entry, exit;
    printf("Give the character of the entry vertex.\n");
    scanf(" %c", &entry);
    printf("Give the character of the exit vertex.\n");
    scanf(" %c", &exit);

    char * visited; //heap located array pointer
    char * unvisited; // heap located array pointer
    unvisited = pushVertecies(unvisited,map);
    queue = make_info_queue(map, entry);
    showQueue(queue);
    queue = fill_distance(map, queue);
    printf("****************\n");
    showQueue(queue);
    return 0;
}