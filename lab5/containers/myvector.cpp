#include "myvector.h"
#include <cstring>
#include <algorithm>

MyVector::MyVector(const char* el, int max_size)
    : max_size(max_size), size(0), pdata(new char* [max_size]) {
    if (el != NULL) {
        pdata[0] = new char[strlen(el) + 1];
        strcpy(pdata[0], el);
        size = 1;
    }
}

MyVector::MyVector(const MyVector& v)
    : max_size(v.max_size), size(v.size), pdata(new char* [max_size]) {
    for (int i = 0; i < size; i++) {
        pdata[i] = new char[strlen(v.pdata[i]) + 1];
        strcpy(pdata[i], v.pdata[i]);
    }
}

MyVector::~MyVector() {
    for (int i = 0; i < size; i++) {
        delete[] pdata[i];
    }
    delete[] pdata;
}

void MyVector::resize() {
    int new_max_size = max_size * 2;
    char** new_pdata = new char* [new_max_size];

    for (int i = 0; i < size; i++) {
        new_pdata[i] = pdata[i];
    }

    delete[] pdata;
    pdata = new_pdata;
    max_size = new_max_size;
}

void MyVector::add_element(const char* el) {
    if (size >= max_size) {
        resize();
    }
    pdata[size] = new char[strlen(el) + 1];
    strcpy(pdata[size], el);
    size++;
}

bool MyVector::delete_element(int i) {
    if (i < 0 || i >= size) return false;

    delete[] pdata[i];
    for (int j = i; j < size - 1; j++) {
        pdata[j] = pdata[j + 1];
    }
    size--;

    return true;
}

char* MyVector::operator[](int i) {
    if (i < 0 || i >= size) return NULL;
    return pdata[i];
}

void MyVector::sort() {
    std::sort(pdata, pdata + size, [](char* a, char* b) {
        return strcmp(a, b) < 0;
    });
}

int MyVector::find(const char* el) const {
    for (int i = 0; i < size; i++) {
        if (strcmp(pdata[i], el) == 0) {
            return i;
        }
    }
    return -1;
}

MyVector& MyVector::operator=(const MyVector& v) {
    if (this == &v) return *this;

    for (int i = 0; i < size; i++) {
        delete[] pdata[i];
    }
    delete[] pdata;

    max_size = v.max_size;
    size = v.size;
    pdata = new char* [max_size];

    for (int i = 0; i < size; i++) {
        pdata[i] = new char[strlen(v.pdata[i]) + 1];
        strcpy(pdata[i], v.pdata[i]);
    }

    return *this;
}

std::ostream& operator<<(std::ostream& out, const MyVector& v) {
    out << "{";
    for (int i = 0; i < v.size; i++) {
        out << "\"" << v.pdata[i] << "\"";
        if (i != v.size - 1) out << ", ";
    }
    out << "}";
    return out;
}
