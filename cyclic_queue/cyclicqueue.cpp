//
// Created by loay on 1/10/21.
//

#include "cyclicqueue.h"


cyclicqueue::cyclicqueue(size_t k)
    {
        head = -1;
        tail = -1;
        size = k;

        queue.resize(size);
        queue.set_all(-1);

    }
    void cyclicqueue::enqueue(int data) {

        if((tail+1)%size == head){


            tail = head;
            queue[tail] = data;
        } else {
            tail = (tail+1) % size;
            queue[tail] = data;

            if(head==-1)
                head=0;
        }
}
void cyclicqueue::print() {
    std::cout<<queue;
}

int cyclicqueue::dequeue() {



        queue[head] = -1;
        tail = head-1;

    }
//
//int main(){
//     cyclicqueue queue(5);
//     queue.enqueue(1);
//    queue.enqueue(2);
//    queue.enqueue(3);
//    queue.enqueue(4);
//    queue.enqueue(5);
//    queue.print();
//    queue.enqueue(6);
//    queue.print();
//    queue.enqueue(6);
//    queue.print();
//    queue.dequeue();
//    queue.print();
//    queue.enqueue(60);
//    queue.print();
//
//
//    return 0;
//}