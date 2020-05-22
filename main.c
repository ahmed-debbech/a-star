#include <stdlib.h>
#include <stdio.h>
#include "utilities.h"
#include "graph.h"
#include "info.h"

int main(){
    Map map;
    Info * listOfVertecies; // this will hold all the information table of the graph
    map = createGraphMap();
    showMap(map);
    Info infoTable[map.size];
    char entry, exit;
    printf("Give the character of the entry vertex.");
    scanf(" %c", &entry);
    printf("Give the character of the exit vertex.");
    scanf(" %c", &exit);
    char * visited; //heap located array pointer
    char * unvisited; // heap located array pointer
    unvisited = pushVertecies(unvisited,map);
    listOfVertecies = make_info_list(map);
    return 0;
}