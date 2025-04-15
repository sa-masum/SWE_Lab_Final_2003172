#include<iostream>
using namespace std;
#include <gtest/gtest.h>

class Shape {
public:
    virtual double area() = 0;
    virtual ~Shape() {}
};

class Circle : public Shape {
    int radius;
public:
    Circle(int r) : radius(r) {}
    double area() override {
        return 3.14 * radius * radius;
    }
};

class Square : public Shape {
    int edge;
public:
    Square(int e) : edge(e) {}
    double area() override {
        return edge * edge;
    }
};

class Rectangle : public Shape {
    int length, width;
public:
    Rectangle(int l, int w) : length(l), width(w) {}
    double area() override {
        return length * width;
    }
};

class ShapeFactory {
public:
    Shape* createCircle(int radius) {
        return new Circle(radius);
    }
    Shape* createSquare(int edge) {
        return new Square(edge);
    }
    Shape* createRectangle(int length, int width) {
        return new Rectangle(length, width);
    }
};

TEST(ShapeTest, CircleArea)
{
    ShapeFactory factory;
    Shape* circle = factory.createCircle(5);
    ASSERT_NEAR(78.5, circle->area(), 0.1);
    delete circle;
}

TEST(ShapeTest, SquareArea)
{
    ShapeFactory factory;
    Shape* square = factory.createSquare(4);
    ASSERT_EQ(16, square->area()); 
    delete square;
}

TEST(ShapeTest, RectangleArea)
{
    ShapeFactory factory;
    Shape* rectangle = factory.createRectangle(4, 6);
    ASSERT_EQ(24, rectangle->area()); 
    delete rectangle;
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
