#include "rectangle.hpp"

using namespace std;

Rectangle::Rectangle() : po{Point(), Point(), Point(), Point()} {}

Rectangle::Rectangle(Point& p1, Point& p2, Point& p3, Point& p4) : po{p1, p2, p3, p4}  {}

Point Rectangle::center() const {
    //cout << "Rectangle center() " << endl;
    double x = 0, y = 0;
    for(size_t i = 0; i < 4; ++i){
        x += po[i].x_;
        y += po[i].y_;
    }
    return Point(x / 4.0, y / 4.0);
}

double Rectangle::square() const {
    //cout << "Rectangle square() " << endl;
    double x1 = po[0].x_; double y1 = po[0].y_;
    double x2 = po[1].x_; double y2 = po[1].y_;
    double x3 = po[2].x_; double y3 = po[2].y_;
    double x4 = po[3].x_; double y4 = po[3].y_;
    
    //первая сторона
    double a = sqrt(pow(abs(x1 - x2),2) + pow(abs(y1 - y2),2));
    //вторая сторона
    double b = sqrt(pow(abs(x2 - x3),2) + pow(abs(y2 - y3),2));
    //площадь
    double S = a*b;
    return S;
}

Rectangle& Rectangle::operator = (const Rectangle &other){
    if (this == &other) {
        return *this;
    }

    for(size_t i = 0; i < 4; ++i){
        po[i] = other.po[i];
    }

    return *this;
}

Rectangle& Rectangle::operator = (Rectangle &&other){
    if (this == &other) {
        return *this;
    }

    for(size_t i = 0; i < 4; ++i){
        po[i] = move(other.po[i]);
        //po[i] = other.po[i];
        //other.po[i] = nullptr;
        
    }

    return *this;
}

bool Rectangle::operator == (const Rectangle& other){
    for(size_t i = 0; i < 4; ++i){
        if(po[i] != other.po[i]){
            return false;
        }
    }
    return true;
}

ostream& operator << (ostream& os, const Rectangle& Rectangle){
    os << "Rectangle's coordinates x,y: "<< endl;
    for(size_t i = 0; i < 4; ++i){
        os << Rectangle.po[i] << endl;
    }
    return os;
}

istream& operator >> (istream& is, Rectangle& Rectangle) {
    cout << "Введите координаты прямоугольника по часовой стрелке, начиная от левой нижней вершины, ";
    cout << "если бы прямоугольник был расположен так, чтобы его большая сторона была параллельна оси Y (x1 y1 ... x4 y4): " << endl;
    for (size_t i = 0; i < 4; ++i) {
        is >> Rectangle.po[i];
    }
    return is;
}

Rectangle::operator double() const{
    return square();
}

/*Point Rectangle::get_point(const int i) const{
    if ( i < 0 || 3 < i){
        throw invalid_argument("Out of index range");
    }
    return po[i];
}*/