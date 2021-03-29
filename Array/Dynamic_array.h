//
// Created by loay on 3/29/21.
//

#ifndef DATA_STRUCTERS_DYNAMIC_ARRAY_H
#define DATA_STRUCTERS_DYNAMIC_ARRAY_H


class Dynamic_array {

public:
   Dynamic_array()
   {
       arr = new int[2];
       capacity = 2;
       size = 0;
   };

   void push(int Data);
   void push(int Data, int index);
   int get(int index);
   int pop();
   int pop(int index);
   int get_size();
   int get_capacity();
   void print();

private:
    int *arr;
    int capacity;
    int size;
};


#endif //DATA_STRUCTERS_DYNAMIC_ARRAY_H
