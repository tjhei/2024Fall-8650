
#include <iostream>
using namespace std;

// abstract base class
class Shape
{
public:
  // a pure virtual function:
  virtual int
  area() = 0; // abstract function without implementation
};

class Rectangle : public Shape
{
public:
  Rectangle(int w, int h)
  {
    width  = w;
    height = h;
  }

  int
  area()
  {
    return width * height;
  }

private:
  int width, height;
};

class Square : public Shape
{
public:
  Square(int w)
  {
    width = w;
  }

  int
  area()
  {
    return width * width;
  }

private:
  int width;
};

// incomplete:
class Triangle : public Shape
{};

class NotAShape
{
public:
  int
  area()
  {
    return 1;
  }
};

void
do_something(Shape &shape)
{
  cout << "the area of this object is " << shape.area() << '\n';
}

template <class T>
void
do_something_else(T &shape)
{
  cout << "the area of this object is " << shape.area() << '\n';
}

int
main()
{
  // abstract objects can not be created:
  int i = 1;
  if (i == 2)
    {
      // Shape shape1;
      // Triangle shape2;
    }

  Rectangle rect(10, 20);
  Square    square(7);

  do_something(rect);
  do_something(square);
  // do_something(1);

  // duck typing doesn't work:
  NotAShape not_a_shape;
  // do_something(not_a_shape);


  do_something_else<>(not_a_shape);
  do_something_else<>(square);


  return 0;
}
