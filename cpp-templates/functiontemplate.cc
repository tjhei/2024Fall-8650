#include <iostream>

// This function template takes any class T as an argument:
template <typename T>
void
yell(T test)
{
  test.shout("HI!");
};

class cat
{
public:
  void
  shout(const std::string &what)
  {
    std::cout << "cat says " << what << std::endl;
  }
};

class dog
{
public:
  void
  shout(const std::string &what)
  {
    std::cout << "woof!" << std::endl;
  }
};

int
main()
{
  cat mycat;
  dog mydog;

  yell(mycat);
  yell(mydog);
}
