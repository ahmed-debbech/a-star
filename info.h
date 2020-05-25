#ifndef INFO_H
#define INFO_H

#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

struct Info{
    char letter;
    char via;
    int distanceFromStart;
    struct Info * next;
};
typedef struct Info Info;
typedef struct{
    Info * head;
    Info * tail;
}Queue;

Queue make_info_queue(Map map, char entryVertex);
void showQueue(Queue info);
#endif