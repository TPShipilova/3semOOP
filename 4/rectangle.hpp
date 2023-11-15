#pragma once

#include "figure.hpp"
#include <iostream>

using namespace std;

template <typename T>
class Rectangle : public Figure<T> {

    friend ostream& operator << (ostream& os, const Rectangle<T>& Rectangle){
        os << "Rectangle's coordinates x,y: "<< endl;
        for(size_t i = 0; i < 4; ++i){
            os << Rectangle.po[i] << endl;
        }
        return os;
    }

    friend istream& operator >> (istream& is, Rectangle<T>& Rectangle) {
        cout << "Введите координаты прямоугольника по часовой стрелке, начиная от левой нижней вершины, ";
        cout << "если бы прямоугольник был расположен так, чтобы его большая стороны была параллельна оси Y (x1 y1 ... x4 y4): " << endl;
        for (size_t i = 0; i < 4; ++i) {
            is >> Rectangle.po[i];
        }
        return is;
    }

public:
    Rectangle();
    Rectangle(Point<T>& p1, Point<T>& p2, Point<T>& p3, Point<T>& p4);

    virtual T square() const override;
    virtual Point<T> center() const override;

    Rectangle<T>& operator = (const Rectangle<T> &other);
    Rectangle<T>& operator = (Rectangle<T> &&other);
    bool operator == (const Rectangle<T> &other);
    virtual operator T() const override;


    ~Rectangle() = default;

private:
    Point<T> po[4];

};


template <typename T>
Rectangle<T>::Rectangle() : po{Point<T>(), Point<T>(), Point<T>(), Point<T>()} {}

template <typename T>
Rectangle<T>::Rectangle(Point<T>& p1, Point<T>& p2, Point<T>& p3, Point<T>& p4) : po{p1, p2, p3, p4}  {}

template <typename T>
Point<T> Rectangle<T>::center() const {
    //cout << "Rectangle center() " << endl;
    T x = 0, y = 0;
    for(size_t i = 0; i < 4; ++i){
        x += po[i].x_;
        y += po[i].y_;
    }
    return Point<T>(x / 4.0, y / 4.0);
}

template <typename T>
T Rectangle<T>::square() const {
    //cout << "Rectangle square() " << endl;
    T x1 = po[0].x_; T y1 = po[0].y_;
    T x2 = po[1].x_; T y2 = po[1].y_;
    T x3 = po[2].x_; T y3 = po[2].y_;
    T x4 = po[3].x_; T y4 = po[3].y_;
    //первая сторона
    T a = sqrt(pow(abs(x1 - x2),2) + pow(abs(y1 - y2),2));
    //вторая сторона
    T b = sqrt(pow(abs(x2 - x3),2) + pow(abs(y2 - y3),2));
    //площадь
    T S = a*b;
    return S;
}

template <typename T>
Rectangle<T>& Rectangle<T>::operator = (const Rectangle<T> &other){
    if (this == &other) {
        return *this;
    }

    for(size_t i = 0; i < 4; ++i){
        po[i] = other.po[i];
    }

    return *this;
}

template <typename T>
Rectangle<T>& Rectangle<T>::operator = (Rectangle<T> &&other){
    if (this == &other) {
        return *this;
    }

    for(size_t i = 0; i < 4; ++i){
        po[i] = move(other.po[i]);
    }

    return *this;
}


template <typename T>
bool Rectangle<T>::operator == (const Rectangle<T>& other){
    for(size_t i = 0; i < 4; ++i){
        if(!(po[i] == other.po[i])){
            return false;
        }
    }
    return true;
}


template <typename T>
Rectangle<T>::operator T() const{
    return square();
}
