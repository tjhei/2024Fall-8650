// This show you how to create and run several threads using c++ std::thread

#include <math.h>

#include <fstream>
#include <iostream>
#include <thread>
#include <vector>

void
thread_function(int tid)
{
  std::cout << "I am " << std::this_thread::get_id() << " with index " << tid
            << std::endl;

  for (unsigned int i = 0; i < 10; ++i)
    {
      std::this_thread::sleep_for(std::chrono::milliseconds(1));
      std::cout << i << " ";
    }
  std::cout << std::endl;
}

int
main()
{
  const int num_threads = 4;
  std::cout << "Starting " << num_threads << " threads ..." << std::endl;

  std::thread t[num_threads];

  for (int i = 0; i < num_threads; ++i)
    {
      // The following code is like calling
      //   thread_function(i);
      // but on a separate thread:
      t[i] = std::thread(thread_function, i);
    }

  std::cout << "Done launching threads ...\n" << std::endl;

  // Now wait for everyone to finish:
  for (int i = 0; i < num_threads; ++i)
    {
      t[i].join();
    }

  std::cout << "All threads are done." << std::endl;
}
