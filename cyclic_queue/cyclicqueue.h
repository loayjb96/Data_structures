//
// Created by loay on 1/10/21.
//

#ifndef MIN_STACK_CYCLICQUEUE_H
#define MIN_STACK_CYCLICQUEUE_H

#include "my_vector.h"

class cyclicqueue {


public:

    cyclicqueue(size_t k) ;

    void enqueue(int data);
    int dequeue();
    void print();
private:
    size_t head;
    size_t tail;
    unsigned int size;
    my_vector<int> queue;
};


#endif //MIN_STACK_CYCLICQUEUE_H
