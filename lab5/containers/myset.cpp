#include "myset.h"

void MySet::add_element(const char* el) {
    if (!is_element(el)) {
        MyVector::add_element(el);
        sort();
    }
}

void MySet::delete_element(const char* el) {
    int index = find(el);
    if (index != -1) {
        MyVector::delete_element(index);
    }
}

bool MySet::is_element(const char* el) const {
    return find(el) != -1;
}

bool MySet::operator==(const MySet& s) {
    if (size != s.size) return false;

    for (int i = 0; i < size; i++) {
        if (!s.is_element(pdata[i])) {
            return false;
        }
    }
    return true;
}

MySet& MySet::operator+=(const MySet& s) {
    for (int i = 0; i < s.size; i++) {
        add_element(s.pdata[i]);
    }
    return *this;
}

MySet& MySet::operator-=(const MySet& s) {
    for (int i = 0; i < s.size; i++) {
        delete_element(s.pdata[i]);
    }
    return *this;
}

MySet& MySet::operator*=(const MySet& s) {
    MySet result;
    for (int i = 0; i < size; i++) {
        if (s.is_element(pdata[i])) {
            result.add_element(pdata[i]);
        }
    }
    *this = result;
    return *this;
}

MySet& MySet::operator=(const MySet& s) {
    MyVector::operator=(s);
    return *this;
}

std::ostream& operator<<(std::ostream& out, const MySet& s) {
    out << "{";
    for (int i = 0; i < s.size; i++) {
        out << "\"" << s.pdata[i] << "\"";
        if (i != s.size - 1) out << ", ";
    }
    out << "}";
    return out;
}

MySet operator+(const MySet& s1, const MySet& s2) {
    MySet result = s1;
    result += s2;
    return result;
}

MySet operator-(const MySet& s1, const MySet& s2) {
    MySet result = s1;
    result -= s2;
    return result;
}

MySet operator*(const MySet& s1, const MySet& s2) {
    MySet result;
    for (int i = 0; i < s1.size; i++) {
        if (s2.is_element(s1.pdata[i])) {
            result.add_element(s1.pdata[i]);
        }
    }
    return result;
}
