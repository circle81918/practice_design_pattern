#include <iostream>

class IceDrinkMachine {
  public:
    void makeDrink() {
      AddWater();
      AddMaterial();
      AddSugar();
      AddIce();
    };
  protected:
    void AddWater() {
      printf("Add water!\n");
    };
    virtual void AddMaterial() = 0;
    virtual void AddSugar() {
      printf("Add sugar!\n");
    }
    virtual void AddIce() {
      printf("Add ice!\n");
    }
};

class MilkDrink : public IceDrinkMachine {
  protected:
    void AddMaterial() override {
      printf("Add milk powder!\n");
    }
};

class CoffeeDrink : public IceDrinkMachine {
protected:
  void AddMaterial() override {
    printf("Add coffee powder!\n");
  }
};

int main() {
  IceDrinkMachine *machine = new MilkDrink();
  machine->makeDrink();
  delete machine;
  return 0;
}