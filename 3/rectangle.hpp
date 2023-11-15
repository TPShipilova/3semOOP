#pragma once

#include "figure.hpp"
#include <iostream>

class Rectangle : public Figure {

    friend std::ostream& operator<<(std::ostream& os, const Rectangle& f);
    friend std::istream& operator>>(std::istream& is, Rectangle& f);

public:
    Rectangle();
    Rectangle(Point& p1, Point& p2, Point& p3, Point& p4);

    virtual double square() const override;
    virtual Point center() const override;

    //Point get_point(const int i) const;

    Rectangle& operator = (const Rectangle &other);
    Rectangle& operator = (Rectangle &&other);
    bool operator == (const Rectangle &other);
    virtual operator double() const override;



    ~Rectangle(){};

private:
    Point po[4];

};