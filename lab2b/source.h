//
// Created by Admin on 03.03.2020.
//

#ifndef LAB2B_SOURCE_H
#define LAB2B_SOURCE_H

#include <cstdio>

template <class T>
class hashedArrayTree{
private:
    T **top;
    size_t size

public:
    hashedArrayTree(){
        **top = new T[1];
        *top[0] = new T[1];
        size = 0;
    }

};

#endif //LAB2B_SOURCE_H
