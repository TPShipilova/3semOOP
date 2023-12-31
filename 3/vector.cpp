#include "vector.hpp"

Vector::Vector() : buf(nullptr), size_(0), cap(3), head(0){ //изначально создаем с буфером под три элемента класса Figure, но размер 0
    buf = new Figure*[cap];
    for (int i = 0; i < cap; i++) {
        buf[i] = nullptr;
    }
}


void Vector::resize(int new_size) {//изменяем размер буфера когда нужно
    Figure** tmp = new Figure*[new_size];
    for (int i = 0; i < new_size; i++) {
        tmp[i] = nullptr;
    }
    for (int i = 0; i < size_; i++) {
        int ind = (head + i) % cap;
        tmp[i] = buf[ind];
    }
    delete [] buf;
    buf = tmp;
    cap = new_size;
    head = 0;
}

int Vector::size() const{ 
    return size_;
}

void Vector::push_back(Figure* val){
    if (size_ == cap) {
        resize(cap * 2);
    }
    int ind = (head + size_) % cap;
    buf[ind] = val;
    size_++;
}


const Figure* Vector::get(int ind) const{
    if (ind >= 0 && ind < size_) {
        int real_ind = (head + ind) % cap;
        return buf[real_ind];
    }
    throw std::out_of_range("Index is out of range");
}

void Vector::remove(int ind){
    if (ind < 0 || ind > size_) {
        throw std::invalid_argument("Index out of range");
    }
    Figure** new_buf = new Figure*[cap];

    for (int i = 0; i < ind; i++) {
        int old_ind = (head + i) % cap;
        new_buf[i] = buf[old_ind];
    }
    for (int i = ind; i < size_ - 1; i++) {
        int old_ind = (head + i + 1) % cap;
        new_buf[i] = buf[old_ind];
    }

    delete [] buf;
    buf = new_buf;
    size_--;

    if (size_ <= cap / 3) {
        resize(cap * 3/5);
    }
}

Vector::~Vector(){
    size_ = 0;
    cap = 0;
    head = 0;
    delete [] buf;
    buf = nullptr;
}
