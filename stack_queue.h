//
// Created by loay on 1/11/21.
//

#ifndef MIN_STACK_STACK_QUEUE_H
#define MIN_STACK_STACK_QUEUE_H

#include <exception>
#include "stack.h"

template <class T>
class stack_queue {

public:
    explicit stack_queue(size_t size);
    ~stack_queue();


    bool is_empty();
    T & dequeue();
    void enqueue(T val);
    size_t get_size();
    void print();


private:
    size_t q_size;
    size_t q_capacity;
    stack<T> * my_stack;

    void shift_stack();


};

template <class T>
stack_queue<T>::stack_queue(size_t size):q_capacity(size),q_size(0)
{

    my_stack = new stack<T>(size);
}


template <class T>
bool stack_queue<T>::is_empty()
{

    return q_size == 0;
}
template <class T>
void stack_queue<T>::enqueue(T val) {
    if(q_size < q_capacity)
    {
        ++q_size;

        my_stack->push(val);
    }

}

template <class T>
T& stack_queue<T>::dequeue() {
    if(is_empty())
        throw "empty queue";
    this->shift_stack();
    my_stack->pop();
    --q_size;
    this->shift_stack();
}

template <class T>
void stack_queue<T>::print() {
    std::cout<<*my_stack;
}
template <class T>
stack_queue<T>::~stack_queue()
{

    delete my_stack;
}

template <class T>
void stack_queue<T>::shift_stack()
{
    size_t new_size =  q_size;
    T* arr = new T(new_size);
    for (int i = new_size - 1; i >= 0 ; --i)
    {
        arr[i] = my_stack->top();
        my_stack->pop();
    }

    for (int i = new_size - 1; i >= 0 ;--i) {
        my_stack->push(arr[i]);
    }
    delete[] arr;

}
#endif //MIN_STACK_STACK_QUEUE_H
