//
// Created by loay on 1/8/21.
//

#ifndef MIN_STACK_VECTOR_H
#define MIN_STACK_VECTOR_H

#include <unordered_map>
#include <iostream>

template <class T>
class my_vector {

public:
    explicit my_vector(size_t size = 1);
    inline ~my_vector();
    my_vector(const my_vector<T> & other);

    my_vector<T>& operator=(const my_vector<T> &other);
    /*q_capacity*/
    size_t getsize();
    size_t max_size();
    bool resize(unsigned int);
    size_t get_capacity();
    size_t get_current();

    bool empty();
    bool reserve(unsigned int );
    /*element access*/

    T&operator[](unsigned index);
    T&operator[](unsigned index)const;
    T at(unsigned index);
    T front(unsigned index);
    T back(unsigned index);
    T data(unsigned index);
//    template <class U>

    friend  std::ostream& operator<<(std::ostream& os, const my_vector<T> & v);
void print();
    /*Modifiers*/

    bool push_back(T elem);
    void pop_back();


    void clear();
    void swap(T elm1,T elme2);
    void set_all(T val);



    class Iterator{
    public:
        explicit Iterator(T* data_ptr=NULL);
        Iterator(const Iterator&);
        Iterator& operator++(); //prefix increment
        Iterator operator++(int); //postfix increment
        T& operator*();
        bool operator==(const Iterator& other)const;
        bool operator!=(const Iterator& other)const;
    private:
        T* data_ptr;
        size_t curr_index;
    };
    Iterator insert(Iterator position, const T& val);
    Iterator erase(Iterator position);
    Iterator begin();
    Iterator end();



private:
    T*vect;
    size_t capacity;
    size_t current;
    T set_all_val;
    std::unordered_map <int, T> indexing_array;


};

template <class T>
my_vector<T>::my_vector(size_t size)
{

    if(size < 0)
        size = 1;
    vect = new T[size];
    capacity = size;
    current = 0;
}
template <class T>
my_vector<T>::~my_vector() {
    delete[] vect;
}
template <class T>
my_vector<T>::my_vector(const my_vector<T> &other) {

    capacity = other.capacity;
    current = other.current;

    T* vect = new T[capacity];
    for(size_t i = 0; i< other.current; ++i){
        vect[i] = other[i];
    }


}

template <class T>
my_vector<T>& my_vector<T>::operator=(const my_vector<T>& other)
{
    if (this != other)
    {
        delete[] this;
        this->vect = new T [other.capacity];
        this->capacity = other.capacity;
        this->current = other.current;

        for (int i = 0; i < this->capacity ; ++i)
        {
            this->vect[i] = other.vect[i];

        }
        return *this;
    }


}

template <class T>
T & my_vector<T>::operator[](unsigned index)
        {
//    if(index > this->q_capacity)
//        return ;
    if (indexing_array[index])
        return vect[index];
//    vect[index] = set_all_val;
    return vect[index];
}

template <class T>
T & my_vector<T>::operator[](unsigned index)const
{
//    if(index > this->q_capacity)
//        return ;
    if (indexing_array[index])
        return vect[index];
//    vect[index] = set_all_val;
    return vect[index];
}
template <class T>
bool my_vector<T>::push_back(T elem)
{
    if(current == capacity)
    {
        T* temp = new T[2*capacity];
        for (int i = 0; i < this->capacity ; ++i)
        {
           temp[i] = this->vect[i];

        }
        delete[] vect;
        this->capacity *= 2;
        this->vect = temp;

    }
    indexing_array[current] = elem;
    this->vect[current] = elem;
    ++current ;


}
template <class T>
void my_vector<T>::pop_back()
{
    if(current == 0)
        return ;


    this->current--;


}
template<class T>
void my_vector<T>::clear(){
    delete [] vect;
    vect = new T[capacity];
    current = 0;
}

template <class T>
bool my_vector<T>::empty() {
    return this->capacity==0;
}

//
//template <class T>
//T& my_vector<T>::operator[](unsigned index) {
//    return vect[index];
//}
template <class T>
T my_vector<T>::at(unsigned index) {

    if(index < capacity)
        return this->vect[index];
}

template <class T>
T my_vector<T>::data(unsigned index) {}

template<class T>
static void swap(T& a, T& b){
    T temp = a;
    a = b;
    b = a;
}
template <class T>
size_t my_vector<T>::get_capacity()
{
    return this->capacity;
}

template <class T>
size_t my_vector<T>::get_current()
{
    return this->current;
}
template <class T>
T my_vector<T>::back(unsigned index) {

    return this->vect[capacity - 1];
}


template <class T>
T my_vector<T>::front(unsigned index) {
    return this->vect[0];
}

template <class T>

bool my_vector<T>::resize(unsigned int new_capacity) {
    reserve(new_capacity);
    capacity = new_capacity;
}

template <class T>
bool my_vector<T>::reserve(unsigned int new_capacity) {
    if(new_capacity <= 0){
        return false;
    }
    if(new_capacity > capacity){
        T* temp = new T[new_capacity];
        for(size_t i = 0; i < current; ++i) {
            temp[i] = vect[i];
        }
        delete [] vect;
        vect = temp;
        new_capacity = new_capacity;
    }
    return true;
}
template <class T>

std::ostream& operator<<(std::ostream &os,  my_vector<T> &v) {
    os << "[";
    for (int i = 0; i < v.get_current(); ++i) {
        os << v[i];
        if (i != v.get_current() - 1)
            os << ", ";
    }
    os << "]\n";
    return os;
}
template <class T>
void my_vector<T>::print() {
    for (int i = 0; i < this->current; i++) {
        std::cout << vect[i] << " ";
    }
    std::cout << std::endl;
}
template <class T>

void my_vector<T>::set_all(T val) {
    set_all_val = val;
    current = capacity;

}
template <class T>
typename my_vector<T>::Iterator my_vector<T>::insert(my_vector<T>::Iterator position, const T& val)
{
    if(current == capacity){
        reserve(capacity * 2);
    }
    T temp=vect[position.curr_index];
    T new_val = val;
    vect[position.curr_index]= new_val;
    for(size_t i=position.curr_index+1; i < current  ; ++i) {
        swap(vect[i], temp);
    }
    vect[current]=temp;
    current++;
    return Iterator(vect,position.curr_index);
}

// Iterator

template<class T>
my_vector<T>::Iterator::Iterator(T* data_ptr):data_ptr(data_ptr),curr_index(0){}

template<class T>
my_vector<T>::Iterator::Iterator(const my_vector<T>::Iterator& other):data_ptr(other.data_ptr),curr_index(other.curr_index){}

template<class T>
typename my_vector<T>::Iterator& my_vector<T>::Iterator::operator++(){
    curr_index++;
    return *this;
}
template<class T>
typename my_vector<T>::Iterator my_vector<T>::Iterator::operator++(int){
    my_vector<T>::Iterator it(*this);
    curr_index++;
    return it;
}
template<class T>
T& my_vector<T>::Iterator::operator*(){
    return data_ptr[curr_index];
}
template<class T>
bool my_vector<T>::Iterator::operator==(const Iterator& other)const{
    return other.curr_index == curr_index;
}
template<class T>
bool my_vector<T>::Iterator::operator!=(const Iterator& other)const{
    return other.curr_index != curr_index;
}
template<class T>
size_t my_vector<T>::getsize() {

    return  this->capacity;
}
#endif //MIN_STACK_VECTOR_H






























