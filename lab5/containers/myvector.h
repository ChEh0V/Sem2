#ifndef MYVECTOR_H
#define MYVECTOR_H

#include <iostream>

const int MAX_SIZE = 5;

class MyVector {
protected:
    int max_size;
    int size;
    char** pdata;
    void resize();

public:
    MyVector(const char* el = NULL, int max_size = MAX_SIZE);
    MyVector(const MyVector& v);
    virtual ~MyVector();
    void add_element(const char* el);
    bool delete_element(int i);
    char* operator[](int i);
    void sort();
    int get_size() { return size; }
    int get_max_size() { return max_size; }
    int find(const char* el) const;
    MyVector& operator=(const MyVector& v);
    friend std::ostream& operator<<(std::ostream& out, const MyVector& v);
};

#endif // MYVECTOR_H
