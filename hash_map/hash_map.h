//
// Created by loay on 1/13/21.
//

#ifndef MIN_STACK_HASH_MAP_H
#define MIN_STACK_HASH_MAP_H
#define HASH_SIZE 10

#include <string>
#include "my_vector.h"
#include "linked_list.h"

using std::string;
template <class T>
class Pair
        {

    public:
            Pair(string key,T val):p_key(key),p_value(val){};
            T get_value();
            string get_key();

    private:
        string p_key;
        T p_value;
        };


template <class T>
T Pair<T>::get_value()
{
    return this->p_value;
}

template <class T>
string Pair<T>::get_key()
{
    return this->p_key;
}
template <class T>
class hash_map
        {
public:
        hash_map(size_t deafult_size = HASH_SIZE);
        size_t hash_func(size_t key);
        T resize(size_t size);
        void print_hash_utilaization();
        void put(string key, T val);
        T get(string key);
        void print_hash();

private:
    size_t table_size;
    size_t num_of_pairs;
    my_vector<linked_list<Pair<T>*>*>* hash_vect;
    size_t calc_hash(const string &key , size_t tableSize);
        };


template <class T>
hash_map<T>::hash_map(size_t deafult_size):table_size(deafult_size),num_of_pairs(0) {

    hash_vect = new my_vector<linked_list<Pair<T>*>*>(deafult_size);

}
template <class T>
void hash_map<T>::put(string key, T val) {
    size_t hash_key = calc_hash(key,table_size);
    Pair<T> *p = new Pair<T>(key,val);

    linked_list<Pair<T>*>* list;
    list = hash_vect->at(hash_key);

    if(!list)
    {
        list = new linked_list<Pair<T>*>();

        linked_list<Pair<int>*>::Iterator it = list->begin();
    list->insert(it,p);
  (*hash_vect)[hash_key] = list;
    }
    else
    {
        linked_list<Pair<int>*>::Iterator it = list->begin();
        for (int i = 0; i <  list->get_size()-1; ++i) {
            it++;
        }
        list->insert(it,p);
        (*hash_vect)[hash_key] = list;
    }
    ++num_of_pairs;
}

template<class T>
size_t hash_map<T>::calc_hash(const string &key , size_t tableSize)
{
    size_t hashVal = 0;

    for(int i = 0; i < key.length();i++)
        hashVal += 37 * key[i];

    hashVal %= tableSize;

    if(hashVal < 0)
        hashVal += tableSize;

    return hashVal;
}

template<class T>
T hash_map<T>::get(string key)
{
    size_t hash_key = calc_hash(key,table_size);
    linked_list<Pair<T>*>* list = hash_vect->at(hash_key);
    if(list != NULL)
    {
        linked_list<Pair<int>*>::Iterator it = list->begin();
        for (int i = 0; i < list->get_size() ; ++i) {

            Pair<T> *p = *it;
            if(p->get_key() == key)
                return p->get_value();
            it++;
        }

    }

    return -1;
}

template <class T>
T hash_map<T>::resize(size_t size)
{
    size_t hash_key;
    this->table_size = size;
    my_vector<linked_list<Pair<T>*>*> * temp = new my_vector<linked_list<Pair<T>*>*>(size);

    for(int i = 0; i< hash_vect->getsize(); i++){

        linked_list<Pair<T>*>* list = hash_vect->at(i);
        if(list != NULL)
        {
            linked_list<Pair<T>*>* new_list;
            linked_list<Pair<int>*>::Iterator it = list->begin();

            for (int j = 0; j < list->get_size() ; ++j)
            {
                Pair<T> *p = *it;

                hash_key = calc_hash(p->get_key(), table_size);
                if(temp->at(hash_key) == NULL || temp->at(hash_key)->head ==NULL)
                {

                    new_list = new linked_list<Pair<T>*>();
                    new_list->insert(it,p);
                }

                else
                {
                    linked_list<Pair<int>*>::Iterator it1 = new_list->begin();
                    for (int k = 0; k <  new_list->get_size()-1; ++k) {
                        it1++;
                    }
                    new_list->insert(it1,p);
                    it++;
                }

            }

            (*temp)[hash_key] = new_list;
            delete list;
        }

    }
    delete hash_vect;

    hash_vect = temp;
}

template <class T>
void hash_map<T>::print_hash_utilaization() {
    size_t buckets = 0;

    for(int i = 0; i< hash_vect->getsize(); i++){

        if(hash_vect->at(i) != NULL)
        {
            ++buckets;
        }

    }
    double uti = ((double)buckets/(double)table_size);

    std::cout<<"Size: "<<table_size<<std::endl<<"Number of pairs:"<<num_of_pairs<<std::endl;
    std::cout<<"Buckets in use:"<<buckets<<std::endl<<"Utilization:"<<uti<<std::endl;
}
template <class T>
void hash_map<T>::print_hash() {

    for (int i = 0; i < hash_vect->getsize(); i++) {


        linked_list<Pair<T> *> *list = hash_vect->at(i);
        if (list != NULL) {
            linked_list<Pair<int> *>::Iterator postion = list->begin();

            size_t j = 0;
            std::cout << "[";
            size_t size = list->get_size();
            while (j<size) {
                Pair<T> *p = *postion;
                std::cout << p->get_value() << " ";

                if (j < list->get_size() - 1)
                    std::cout << "->";

                ++j;

                postion++;
            }

            std::cout << "]" << std::endl;

        }
    }
    }

#endif //MIN_STACK_HASH_MAP_H
