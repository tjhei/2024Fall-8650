#include <iostream>

// Function template with a single template type argument
template <typename Number>
Number
square(const Number x)
{
  return x * x;
}

class test
{
  int my_member_variable;
};

int
main()
{
  int    i = 2;
  double d = 3.5;

  int    i2 = square<int>(i);    // or square<>(i)
  double d2 = square<double>(d); // or square<>(d)

  std::cout << i << " -> " << i2 << std::endl;
  std::cout << d << " -> " << d2 << std::endl;

  // won't work:
  // test t1;
  // square(t1);
}
