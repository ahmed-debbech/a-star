#include <stdio.h>
#include <stdlib.h>
#include "info.h"

Info * make_info_list( Map map, char entryVertex){
    int i=0;
    Info * head = NULL;
    Info * hold = NULL;
    for(i=0; i<map.size; i++){
        Info * node = (Info*)malloc(sizeof(Info));
        node = 
        if(i == 0){
            head = node;
            hold = head;
        }else{
            hold->next = node;
            hold = node;
        }
    }
    return head;
}