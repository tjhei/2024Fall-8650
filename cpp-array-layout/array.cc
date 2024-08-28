#include <iostream>
#include <vector>

// This demo demonstrates the memory layout of a simple array of ints

// 1. Sketch the memory layout of the array a
// 2. Try the dynamic version (demo-vector) and confirm that the memory layout
// is the same
// 3. What happens if you change the data type from int to double?

void
demo_array()
{
  int a[] = {1, 2, 3, 4, 5};

  std::cout << "a[2] = " << a[2] << std::endl;

  std::cout << &(a[0]) << std::endl;
  std::cout << &(a[1]) << std::endl;
  std::cout << &(a[2]) << std::endl;

  std::cout << sizeof(int) << std::endl;

  std::cout << (&(a[0]) + 2) << std::endl;
  std::cout << *(&(a[0]) + 2) << std::endl;
}

void
demo_vector()
{
  std::vector<int> v;
  v.push_back(1);
  v.push_back(2);
  v.push_back(3);

  std::cout << "v[2] = " << v[2] << std::endl;

  std::cout << &(v[0]) << std::endl;
  std::cout << &(v[1]) << std::endl;
  std::cout << &(v[2]) << std::endl;

  std::cout << sizeof(int) << std::endl;

  std::cout << (&(v[0]) + 2) << std::endl;
  std::cout << *(&(v[0]) + 2) << std::endl;
}

int
main()
{
  demo_array();
}
