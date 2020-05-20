#include <stdlib.h>
#include <stdio.h>
#include "utilities.h"
#include "graph.h"

int main(){
    Map map;
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
    return 0;
}