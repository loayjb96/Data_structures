//
// Created by loay on 3/29/21.
//

#include <iostream>
#include "Dynamic_array.h"

void Dynamic_array::push(int Data)
{
    if(size == capacity)
    {

        int * temp = new int[capacity * 2];

        for(int i =0; i<capacity;++i){

            temp[i] = arr[i];
        }
        delete [] arr;
        arr = temp;
        capacity *= 2;

    }
    arr[size] = Data;
    size += 1;

}

void Dynamic_array::push(int Data, int index)
{
    if(index == capacity)
        push(Data);

    else
        arr[index] = Data;

}
int Dynamic_array::get(int index)
{
    if(index >= 0 && index < size)

        return arr[index];


}

int Dynamic_array::get_size()
{

    return size;
}

int Dynamic_array::get_capacity()
{
    return capacity;
}

int Dynamic_array::pop()
{

   int elem = arr[size - 1];
   size --;
   return elem;
}

int Dynamic_array::pop(int index)
{
    if(index >= 0 && index < size)

        size --;
    for(int i = index; i < size; ++i)
    {
        arr[i] = arr[i + 1];

    }

}
void Dynamic_array::print()
{
    std::cout<<"[";
    for(int i = 0; i< size; ++i)
    {

        std::cout<<arr[i]<<", ";
    }
    std::cout<<"]";
}