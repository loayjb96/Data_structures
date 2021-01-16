//
// Created by loay on 1/11/21.
//

#ifndef MIN_STACK_LINKED_LIST_H
#define MIN_STACK_LINKED_LIST_H

#include <iostream>

template <class T>
class node{

public:
    node():val(NULL),next(NULL){};
    node(T val ,node<T>*ptr);
    node<T>* next;
    T val;

};
template <class T>
node<T>::node(T val, node<T>* ptr):val(val), next(ptr){}


template <class T>
class linked_list{
public:
    node<T>* head;
    linked_list();
    ~linked_list();
    bool sub_list_detection(linked_list<T>*other);
    bool check_circle();
    size_t get_size();

    class Iterator{
    public:
        explicit Iterator(node<T>* newPtr) : ptr(newPtr){}
        friend class linked_list<T>;

        bool operator!=(const Iterator& itr) const;
        bool operator==(const Iterator& itr) const;
        T& operator*() const;
        Iterator operator++(int);

    private:
        node<T>* ptr;


    };
    Iterator begin() ;

//    Iterator end() const;

    Iterator insert(Iterator &position,const T& value);

    Iterator erase(Iterator position);

    void print();

private:


    size_t  size;





};
template <class T>
typename linked_list<T>::Iterator linked_list<T>::insert(linked_list<T>::Iterator &position, const T &value)
{

    node<T>* newNode = new node<T>(value, NULL);

    if (size == 0) {
        head = newNode;
        position.ptr = head;
    }
  else {
        position.ptr->next = newNode;
        position++;
    }
    ++size;

    return position;
}



template <class T>
void linked_list<T>::print(){
    Iterator postion = begin();

    size_t i = 0;
    std::cout<<"[";
    while(postion.ptr !=NULL)
    {
        std::cout<<postion.ptr->val<< " ";
    std::cout<<postion.ptr->val;
if(i< size -1)
    std::cout<<"->";

        ++i;

        postion++;


    }



    std::cout<<"]"<<std::endl;

}
template <class T>
typename linked_list<T>::Iterator linked_list<T>::Iterator::operator++(int)
{

    Iterator temp = *this;
    ptr = ptr->next;
    return temp;
}

template<class T>
linked_list<T>::linked_list() {
    head = new node<T>();
    size = 0;
}

template<class T>
size_t linked_list<T>::get_size() {
    return size;
}

template<class T>
typename linked_list<T>::Iterator linked_list<T>::begin(){

    return Iterator(head);
}

template<class T>
bool linked_list<T>::Iterator::operator==(const linked_list::Iterator &itr) const {
    return !(*this != itr);
}
template<class T>
linked_list<T>::~linked_list() {
    while (head->next != NULL) {
        node<T>* temp = head;
        head = head->next;
        delete temp;
    }
    delete head;
}
template <class T>
bool linked_list<T>::check_circle() {

    Iterator postion = begin();
    node<T>* fast_ptr = postion.ptr;
    node<T>* slow_ptr = postion.ptr;


    while(fast_ptr && fast_ptr->next)
    {

            slow_ptr = slow_ptr->next;
            fast_ptr = fast_ptr->next->next;

            if(slow_ptr == fast_ptr)
                break;


    }
    if(!fast_ptr)
        return false;


    //solving circleation

    Iterator pos =begin();
    slow_ptr = pos.ptr;

    node<T> * prev_ptr = fast_ptr;
    if(slow_ptr == fast_ptr)
    {
        while(prev_ptr->next != fast_ptr)
            prev_ptr = prev_ptr->next;
    }
    while(slow_ptr != fast_ptr)
    {

        prev_ptr = fast_ptr;
        fast_ptr = fast_ptr->next;
        slow_ptr = slow_ptr->next;

    }
    prev_ptr->next = NULL;
    return true;

}
template<typename T>
T & linked_list<T>::Iterator::operator*() const
{
if(this->ptr !=NULL)

    return this->ptr->val;

else
{
    T temp =NULL;
    return temp;
}
}


#endif //MIN_STACK_LINKED_LIST_H
