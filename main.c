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
    
    return 0;
}