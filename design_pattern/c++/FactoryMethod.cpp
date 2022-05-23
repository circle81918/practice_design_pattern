#include <iostream>

using namespace std;

class IAnimal {
public:
  virtual int getNumberOfLegs() const = 0;
  virtual void speak() = 0;
  virtual void free() = 0;
};

class Cat : public IAnimal {
public:
  int getNumberOfLegs() const override { return 4; }
  void speak() override { cout << "Meow" << endl; }
  void free() override { delete this; };
};

class Dog : public IAnimal {
public:
  int getNumberOfLegs() const override { return 4; }
  void speak() override { cout << "Woof" << endl; }
  void free() override { delete this; }
};

class IAnimalFactory {
public:
  virtual IAnimal* createAnimal() = 0;
};

class DogFactory : public IAnimalFactory {
  IAnimal* createAnimal() {return new Dog(); }
};

class CatFactory : public IAnimalFactory {
  IAnimal* createAnimal() {return new Cat(); }
};



int main()
{
  IAnimalFactory *dogfactory = new DogFactory();
  IAnimal* dog = dogfactory->createAnimal();
  dog->speak();

  return 0;
}

