#ifndef UTILITIES_H
#define UTILITIES_H

#include "graph.h"

void addAjacentVertecies(Vertex * head, int numberOfVertex);
Map createGraphMap();
void showMap();
char * pushVertecies(char * unvisited, Map map);

#endif