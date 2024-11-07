#include <iostream>

// This is taken from deal.II

// Class Template with a single value parameter
template <int dim>
struct NumberCache
{};

// Class Template Spezialization for dim=1:
template <>
struct NumberCache<1>
{
  unsigned int n_levels;
  unsigned int n_lines;
};

// Class Template Spezialization for dim=2:
template <>
struct NumberCache<2>
{
  unsigned int n_levels;
  unsigned int n_lines;
  unsigned int n_quads;
};

int
main()
{
  NumberCache<2> nc;
  nc.n_quads = 2;
  std::cout << nc.n_quads << std::endl;
}
