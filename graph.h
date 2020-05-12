#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED

struct Vertex{
    char letter;
    int distanceToNext;
    struct Vertex * next;
};
typedef struct Vertex Vertex;
#endif