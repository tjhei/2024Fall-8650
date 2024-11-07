#include <cmath>
#include <iostream>
#include <vector>


template <typename number>
number
square(const number x)
{
  return x * x;
}

template <int N>
struct Point
{
  int elements[N];
};


template <int N>
double
norm(const Point<N> &v)
{
  double tmp = 0;
  for (int i = 0; i < N; ++i)
    tmp += square(v.elements[i]);
  return std::sqrt(tmp);
}


struct SlowPoint
{
  std::vector<int> elements;
};

double norm(const SlowPoint &p)
{
  double tmp = 0;
  for (int i = 0; i < p.elements.size(); ++i)
    tmp += square(p.elements[i]);
  return std::sqrt(tmp);
}


int
main()
{
  int y = square<>(5);
  std::cout << "5*5 = " << y << std::endl;

  Point<2> p;
  p.elements[0] = 1.0;
  p.elements[1] = 4.0;

  std::cout << "norm of p = " << norm(p) << std::endl;

  if (false)
  {
    SlowPoint p2;
    norm(p2);
  }

}
