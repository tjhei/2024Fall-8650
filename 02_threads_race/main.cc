// this example demonstrates a race condition when several threads access the
// variable counter

#include <math.h>

#include <chrono>
#include <fstream>
#include <iostream>
#include <thread>
#include <vector>

int counter = 0;

void
call_from_thread(int /*tid*/)
{
  // std::cout << "I am " << std::this_thread::get_id()
  //      << " with index " << tid << std::endl;

  for (unsigned int i = 0; i < 10000; ++i)
    {
      ++counter;
      std::this_thread::sleep_for(std::chrono::milliseconds(2));
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

  std::cout << "All threads are done. counter: " << counter << " (should be "
            << num_threads * 10000 << ")" << std::endl;
}
