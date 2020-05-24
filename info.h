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

Info * make_info_list(Map map, char entryVertex);
void showList(Info * list);
void enqueue(Queue queue, Info * list, Map map);
#endif