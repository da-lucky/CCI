#ifndef LISTS_LISTLOOPFINDER_H
#define LISTS_LISTLOOPFINDER_H

#include "node.h"

template <typename T>
Node<T>* getListLoopStart(Node<T>* start){
    if(start) {
        auto slowP = start;
        auto fastP = start;
        auto loopFound = false;

        // check if loop exists
        while(fastP->next) {
            fastP = fastP->next;
            slowP = slowP->next;
            if(fastP->next) {
                fastP = fastP->next;
            } else {
                return nullptr;
            }
            if(fastP == slowP) {
                loopFound = true;
                break;
            }
        }
        // find start of the loop
        if(loopFound) {
            fastP = start;

            while(fastP != slowP) {
                fastP = fastP->next;
                slowP = slowP->next;
            }

            return fastP;
        }
    }
    return nullptr;
}

#endif //LISTS_LISTLOOPFINDER_H
