#ifndef ALGO_H
#define ALGO_H

#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "info.h"

Info *  fill_distance(Map map, Info * queue);
Queue sort_distance(Queue queue);

#endif