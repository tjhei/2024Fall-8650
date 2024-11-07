// This example demonstrates using a mutex to avoid a race condition when
// adding values to a vector.

#include <math.h>

#include <chrono>
#include <fstream>
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

std::mutex       data_mutex;
std::vector<int> data;

void
call_from_thread(int tid)
{
  for (unsigned int i = 0; i < 5; ++i)
    {
      int value = tid; // imagine some computation here

      // compute something
      {
        std::lock_guard<std::mutex> lock(data_mutex);
        data.push_back(value);
      }

      // equivalent:
      // data_mutex.lock();
      // data.push_back(value);
      // data_mutex.unlock();

      // compute more
    }
}

int
main()
{
  const int num_threads = 10;
  std::cout << "Starting " << num_threads << " threads ..." << std::endl;

  std::thread t[num_threads];

  for (int i = 0; i < num_threads; ++i)
    {
      t[i] = std::thread(call_from_thread, i);
    }

  std::cout << "Done launching threads ...\n" << std::endl;

  for (int i = 0; i < num_threads; ++i)
    {
      t[i].join();
    }

  std::cout << "All threads are done." << std::endl;
  for (const auto i : data)
    std::cout << i << " ";
  std::cout << std::endl;
}
