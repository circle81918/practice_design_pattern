#include <iostream>
using namespace std;

// Interface of animal
class IAnimal {
public:
  virtual int getNumberOfLegs() const = 0;
  virtual void speak() = 0;
};

class Cat : public IAnimal {
public:
  int getNumberOfLegs() const { return 4; }
  void speak() { cout << "Meow" << endl; }
};

class Dog : public IAnimal {
public:
  int getNumberOfLegs() const { return 4; }
  void speak() { cout << "Woof" << endl; }
};

class ISchool {
public:
  virtual void teach() = 0;
};

class CatTrainer : public ISchool {
public:
  void teach() { cout << "I can train cat!" << endl; }
};

class DogTrainer : public ISchool {
public:
  void teach() { cout << "I can train dog!" << endl; }
};

class IFactory {
public:
  virtual IAnimal* make() = 0;
  virtual ISchool* getTeacher() = 0;
};

class DogFactory : public IFactory {
public:
  IAnimal* make() { return new Dog(); }
  ISchool* getTeacher() { return new DogTrainer(); };
};

class CatFactory : public IFactory {
public:
  IAnimal* make() { return new Cat(); }
  ISchool* getTeacher() { return new CatTrainer(); };
};


int main()
{
  IFactory* pDogFactory = new DogFactory();
  IAnimal* pDog = pDogFactory->make();
  ISchool* pTrainer = pDogFactory->getTeacher();
  pDog->speak();
  pTrainer->teach();
  return 0;
}