#include <iostream>

class Singleton {
public:
  Singleton(const Singleton&) = delete;            // disable copy constructor
  Singleton& operator=(const Singleton&) = delete; // disable assign operator
  static Singleton& getInstance();
  void printTest();
private:
  Singleton(){};
};

Singleton& Singleton::getInstance() {
  static Singleton instance;
  return instance;
}

void Singleton::printTest() {
  printf("Test\n");
}

int main()
{
  Singleton::getInstance().printTest();
  return 0;
}