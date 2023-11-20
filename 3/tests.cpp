#include <gtest/gtest.h>
#include "trapezia.hpp"
#include "romb.hpp"
#include "rectangle.hpp"
#include "vector.hpp"
#include <iostream>

using namespace std;

TEST(Trapezia_, test_TrapeziaInit_01)
{
    Trapezia tr;
    Point p1(1,1), p2(2,3), p3(4,3), p6(5,1);
    Point p4(p6);
    Trapezia tr2(p1,p2,p3,p4);
    tr = tr2;
    ASSERT_TRUE(p1.x_ == 1);
    ASSERT_TRUE(p2.x_ == 2);
    ASSERT_TRUE(tr == tr2);
}

TEST(Trapezia_, test_TrapeziaInit_02)
{
    Trapezia tr;
    Point p(-1,-1), p2(-2,-3), p3(-4,-3), p5(-5,-1);
    Point p4;
    p4 = p5;
    Trapezia tr2(p,p2,p3,p4);
    tr = tr2;
    ASSERT_TRUE(p4 == p5);
    ASSERT_TRUE(p4 != p2);
    ASSERT_TRUE(tr == tr2);
}

TEST(Trapezia_, test_TrapeziaSquare_01)
{
    Point p(1,1), p2(2,3), p3(4,3), p5(5,1);
    Point p4(p5);
    Trapezia tr(p,p2,p3,p4);
    ASSERT_TRUE(tr.square() == 6.0);
}

TEST(Trapezia_, test_TrapeziaSquare_02)
{
    Trapezia tr;
    Point p(-1,3), p2(2,4), p3(5,1), p5(4,-2);
    Point p4;
    p4 = p5;
    Trapezia tr2(p,p2,p3,p4);
    tr = tr2;
    ASSERT_TRUE(tr.square() == 16.0);
    cout << "tr.square() 2   " << tr.square() << endl;
}

TEST(Trapezia_, test_TrapeziaCenter_01)
{
    Trapezia tr;
    Point p(-1,-1), p2(-2,-3), p3(-4,-3), p6(-5,-1);
    Point p4;
    p4 = p6;
    Point p7(-3,-2);
    Trapezia tr2(p,p2,p3,p4);
    tr = tr2;
    ASSERT_TRUE(tr.center() == p7);

    cout << "tr.center() 1  " << tr.center() << endl;
}

TEST(Trapezia_, test_TrapeziaCenter_02)
{
    Trapezia tr;
    Point p;
    ASSERT_TRUE(tr.center() == p);
}

TEST(Romb_, test_RombInit_01)
{
    Trapezia tr;
    Point p(2,-3), p2(3,-1), p3(4,-3), p5(3,-5);
    Point p4;
    p4 = p5;
    Trapezia tr2(p,p2,p3,p4);
    tr = tr2;
    ASSERT_TRUE(p4 == p5);
    ASSERT_TRUE(p4 != p2);
    ASSERT_TRUE(tr == tr2);
}

TEST(Romb_, test_RombInit_02)
{
    Romb tr;
    Point p(2,-3), p2(3,-1), p3(4,-3), p6(3,-5);
    Point p4(p6);
    Romb tr2(p,p2,p3,p4);
    tr = tr2;
    ASSERT_TRUE(p4.x_ == 3);
    ASSERT_TRUE(p4.y_ == -5);
    ASSERT_TRUE(tr == tr2);
}

TEST(Romb_, test_RombSquare_01)
{
    Point p(2,-3), p2(3,-1), p3(4,-3), p6(3,-5);
    Romb tr2(p,p2,p3,p6);
    double sqr = tr2;
    ASSERT_TRUE(sqr == 4.0);
}

TEST(Romb_, test_RombSquare_02)
{
    Vector arr;
    Point p(2,-3), p2(3,-1), p3(4,-3), p6(3,-5);
    Romb tr2(p,p2,p3,p6);
    arr.push_back(&tr2);

    ASSERT_TRUE(arr.get(0)->square() == 4.0);

}

TEST(Romb_, test_RombCenter_01)
{
    Vector arr;
    Point p(2,-3), p2(3,-1), p3(4,-3), p4(3,-5),p5(3,-3);
    Romb tr2(p,p2,p3,p4);
    arr.push_back(&tr2);

    ASSERT_TRUE(arr.get(0)->center() == p5);

}

TEST(Romb_, test_RombCenter_02)
{
    Trapezia tr;
    Point p, p2, p3, p6;
    Point p4(p6);
    Trapezia tr2(p,p2,p3,p4);
    ASSERT_TRUE(tr.center() == p);
}

TEST(Rectangle_, test_RectangleInit_01)
{
    Rectangle tr;
    ASSERT_TRUE(tr.square() == 0);
    Point p(-4,2), p2(-2,4), p3(3,-1), p4(1,-3);
    Rectangle tr2(p,p2,p3,p4);
    tr = tr2;
    ASSERT_TRUE(tr == tr2);
    ASSERT_TRUE(tr.square() != 0);
}

TEST(Rectangle_, test_RectangleInit_02)
{
    Rectangle tr;
    Point p(2,-3), p2(3,-1), p3(6,-3), p4(4,-4);
    Rectangle tr2(p,p2,p3,p4);
    tr = tr2;
    ASSERT_TRUE(p.x_ == 2);
    ASSERT_TRUE(p.y_ == -3);
    ASSERT_TRUE(tr == tr2);
}

TEST(Rectangle_, test_RectangleSquare_01)
{
    Point p(-4,2), p2(-2,4), p3(3,-1), p6(1,-3);
    Rectangle tr2(p,p2,p3,p6);
    double sqr = tr2;
    ASSERT_TRUE(sqr != 0);
}

TEST(Rectangle_, test_RectangleSquare_02)
{
    Vector arr;
    Point p(-4,2), p2(-2,4), p3(3,-1), p6(1,-3);
    Rectangle tr2(p,p2,p3,p6);
    arr.push_back(&tr2);

    ASSERT_TRUE(arr.get(0)->square() != 0);

}

TEST(Rectangle_, test_RectangleCenter_01)
{
    Vector arr;
    Point p(-4,2), p2(-2,4), p3(3,-1), p5(1,-3);
    Rectangle tr2(p,p2,p3,p5);
    arr.push_back(&tr2);
    Point p6;

    ASSERT_TRUE(arr.get(0)->center() != p6);
}

TEST(Rectangle_, test_RectangleCenter_02)
{
    Rectangle tr;
    Point p, p2, p3, p6;
    Rectangle tr2(p,p2,p3,p6);
    ASSERT_TRUE(tr.center() == p);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
