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

class IGender {
public:
  virtual void genderDescription() = 0;
};

class Boy : public IGender {
public:
  void genderDescription() { cout << "The gender is a boy" << endl; }
};

class Girl : public IGender {
public:
  void genderDescription() { cout << "The gender is a Girl" << endl; }
};

class IAnimalFactory {
public:
  virtual IAnimal* createAnimal(int gender) = 0;
  virtual IGender* getGender(int type) = 0;
};

class DogFactory : public IAnimalFactory {
public:
  IGender* getGender(int type) {
    if (!gender) {
      if(type)
        return new Girl();
      else
        return new Boy();
    }
    return gender;
  }
  IAnimal* createAnimal(int type) { 
    cout<< "The animal is a dog" << endl;
    auto gender = getGender(type);
    gender->genderDescription();
    return new Dog(); 
  }

  IGender *gender = nullptr;
};

int main() {
  IAnimalFactory* dogfactory = new DogFactory();
  IAnimal* dog1 = dogfactory->createAnimal(0);
  IAnimal* dog2 = dogfactory->createAnimal(1);

}