#ifndef MYSET_H
#define MYSET_H

#include <iostream>
#include "myvector.h"

class MySet : public MyVector {
public:
    MySet(const char* el = NULL) : MyVector(el) {};
    MySet(const MySet& s) : MyVector(s) {};
    bool operator==(const MySet& s);
    MySet& operator+=(const MySet& s);
    MySet& operator-=(const MySet& s);
    MySet& operator*=(const MySet& s);
    MySet& operator=(const MySet& s);
    void add_element(const char* el);
    void delete_element(const char* el);
    bool is_element(const char* el) const;
    friend std::ostream& operator<<(std::ostream& out, const MySet& s);
    friend MySet operator+(const MySet& s1, const MySet& s2);
    friend MySet operator-(const MySet& s1, const MySet& s2);
    friend MySet operator*(const MySet& s1, const MySet& s2);
};

#endif // MYSET_H
