#include <stdlib.h>
#include <stdio.h>
#include "utilities.h"
#include "graph.h"

int main(){
    Map map;
    map = createGraphMap();
    showMap(map);
    return 0;
}