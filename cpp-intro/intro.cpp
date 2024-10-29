// compile with:
// g++ Wall intro.cpp
// run with:
// ./a.out

#include <algorithm>
#include <cmath>
#include <iostream>
#include <numeric>
#include <vector>

void
step_some_basics()
{
  int i = 4;

  ++i;
  std::cout << "printing things is a bit more complicated, but here is i=" << i
            << std::endl;

  // C++ is a superset of C, which often relies on static arrays and pointers;
  int  x[] = {1, 2, 3};
  int *p   = x;
  ++p;
  std::cout << "the second element = " << *p << std::endl;

  // The standard library in C++ contains many containers and algorithms:
  std::vector<int> values = {
    1, 2, 3}; // a dynamic array containing ints, this is a template class
  values.push_back(4);
  int sum = std::accumulate(values.begin(), values.end(), 0);

  std::cout << "a vector with " << values.size()
            << " elements and sum = " << sum << " and entries:" << std::endl;
  // a range-based for loop:
  for (auto x : values)
    {
      std::cout << x << std::endl;
    }

  // a classical manual for loop:
  for (unsigned int i = 0; i < values.size(); ++i)
    {
      std::cout << "v[" << i << "]=" << values[i] << std::endl;
    }

  // Exercise:
  // - Ceate a vector of doubles that contains the elements i / (i % 5)
  // - find the algorithm "sort" to sort the elements by size
}

class MyQueue
{};

void
f1(int x, std::vector<int> values, MyQueue queue)
{
  // all three arguments are copied
}

void
f2(int &x, const std::vector<int> &values, const MyQueue &queue)
{
  // Here none of the arguments are copied. A const references can not be
  // modified, but a "non-const" one can. So, by convention, x is an "in-out"
  // parameter.
  x = values[0];
}

void
step_value_semantics()
{
  // By default, types are treated as values for function arguments and
  // assignments and as such, are copied. This includes simple types (int,
  // float, double, bool, ...), the standard library (std::vector, std::map,
  // ...), and your own types.
  int              x      = 1;
  std::vector<int> values = {1, 2, 3, 4};
  MyQueue          queue;
  f1(x, values, queue);
  f2(x, values, queue);

  // Exercise:
  // - Write a function that given a vector of ints returns the smallest
  // element.
}

void
f3(int n)
{
  int t;
  std::cout << "f3() with n = " << n << std::endl;
  std::cout << "address of n: " << &n << std::endl;
  std::cout << "address of t: " << &t << std::endl;

  if (n > 1)
    f3(n - 1);
}

void
step_stack_memory()
{
  // local variables and function arguments live on the stack:
  std::vector<int> x;
  std::cout << "address of x: " << &x << std::endl;

  f3(2);

  // but objects can of course also be allocated dynamically:
  int *p = new int();
  std::cout << "address of p: " << p << std::endl;
  delete p;

  // Exercise:
  // - Demonstrate that passing an argument by const reference does
  //   not create a copy.
}

// A very simple matrix class
class matrix
{
public:
  matrix(int N)
    : N(N)
  {
    data.resize(N * N);
  }

  double &
  operator()(int i, int j)
  {
    return data[j * N + i];
  }

  int                 N;
  std::vector<double> data;
};

void
fill(matrix &mat)
{
  for (int i = 0; i < mat.N; ++i)
    for (int j = 0; j < mat.N; ++j)
      {
        mat(i, j) = 1.0 * (i + j);
      }
}

// compute the Frobenius norm
double
frob(matrix &mat)
{
  double result = 0.0;
  for (int i = 0; i < mat.N; ++i)
    for (int j = 0; j < mat.N; ++j)
      {
        // try what happens when you do mat(j,i) instead
        double t = std::abs(mat(i, j));
        result += t * t;
      }
  return std::sqrt(result);
}

void
step_frob()
{
  // This is the old example

  matrix mat(100);
  fill(mat);
  double r = frob(mat);
  std::cout << r << std::endl;
}

int
main()
{
  step_some_basics();
  step_value_semantics();
  step_stack_memory();

  step_frob();
}
