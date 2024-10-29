#include <cmath>
#include <iostream>
#include <vector>

#include "timer.h"

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
        // (i,j) is slow, (j,i) is fast
        double t = std::abs(mat(i,j));
        result += t * t;
      }
  return std::sqrt(result);
}

void
test(int size)
{
  matrix mat(size);
  fill(mat);
  Timer<> clock; // Timer is defined in timer.h in the same folder

  // Let's time it:
  clock.tick();
  int    runs = 1000000 / size;
  double r    = 1.0;
  for (int i = 0; i < runs; ++i)
    r += frob(mat);
  clock.tock();

  const double secs  = clock.duration().count() / 1000.0 / runs;
  const double bytes = 1.0 * sizeof(double) * size * size;
  const double flops = 3.0 * size * size;

  std::cout << "N=" << size
            << " mem: " << std::round(bytes / 1024 / 1024 * 100) / 100 << "mb"
            << " Mflops/s: " << std::round(flops / secs / 1000000)
            << " mem: " << std::round(bytes / secs / 1024 / 1024) << "mb/s"
            << " took " << secs << "s"
            << " runs: " << runs << " r=" << r << std::endl;
}

int
main(int argc, char *argv[])
{
  if (argc != 2)
    {
      std::cout << "Usage: \n\t" << argv[0] << " [size]\n\t" << argv[0]
                << " all\n";
      return 0;
    }

  if (std::string(argv[1]) == "all")
    {
      for (int i = 1; i < 30; ++i)
        {
          int size = 200 * i;
          test(size);
        }
    }
  else
    {
      int size = atoi(argv[1]);

      test(size);
    }
  return 1;
}
