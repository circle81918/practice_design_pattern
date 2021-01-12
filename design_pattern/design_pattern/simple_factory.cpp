#include <iostream>
#include <map>

using namespace std;

// Interface of animal
class IAnimal {
public:
  virtual int getNumberOfLegs() const = 0;
  virtual void speak() = 0;
  virtual void free() = 0;
};

class Cat : IAnimal {
public:
  int getNumberOfLegs() const { return 4; }
  void speak() { cout<<"Meow"<<endl; }
  void free() { delete this; };
};

class Dog : IAnimal {
public:
  int getNumberOfLegs() const { return 4; }
  void speak() { cout<<"Woof"<<endl; }
  void free() { delete this; }
};

class SimpleFactory {
public:
  static SimpleFactory* getInstance();
  static IAnimal* createAnimal(const string& animalType);

};

IAnimal* SimpleFactory::createAnimal(const string& animalType) {
  if(animalType == "Cat")
    new Cat();
  else if(animalType == "Dog")
    new Dog();
  else
    return nullptr;
}

SimpleFactory* SimpleFactory::getInstance() {
  static SimpleFactory instance;
  return &instance;
}

int main()
{
  IAnimal *pAnimal = SimpleFactory::getInstance()->createAnimal("Dog");
  if(pAnimal)
  { 
    pAnimal->speak();
    pAnimal->free();
  }

  return 0;
}
