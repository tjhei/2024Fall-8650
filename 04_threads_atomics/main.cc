// this example demonstrates using an atomic counter

#include <math.h>

#include <atomic>
#include <chrono>
#include <fstream>
#include <iostream>
#include <thread>
#include <vector>

std::atomic<int> counter;

void
call_from_thread(int /*tid*/)
{
  // std::cout << "I am " << std::this_thread::get_id()
  //      << " with index " << tid << std::endl;

  for (unsigned int i = 0; i < 10000; ++i)
    {
      ++counter;
    }
}

int
main()
{
  const int num_threads = 4;
  std::cout << "Starting " << num_threads << " threads ..." << std::endl;

  std::thread t[num_threads];

  counter = 0;

  for (int i = 0; i < num_threads; ++i)
    {
      t[i] = std::thread(call_from_thread, i);
    }

  std::cout << "Done launching threads ...\n" << std::endl;

  for (int i = 0; i < num_threads; ++i)
    {
      t[i].join();
    }

  std::cout << "All threads are done. counter: " << counter << " (should be "
            << num_threads * 10000 << ")" << std::endl;
}
