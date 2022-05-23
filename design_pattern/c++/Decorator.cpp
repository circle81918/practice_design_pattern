#include <iostream>

class IPizza {
public:
  virtual void make() = 0;
  virtual int getCost() = 0;
};

class Pizza : public IPizza {
public:
  virtual void make() { printf("Make a basic pizza!\n"); }
  virtual int getCost() { return cost; }
private:
  int cost = 10;
};

class IDecorator : public IPizza {
public:
  virtual void make() = 0;
  virtual int getCost() = 0;
};

class WithCheese : public IDecorator {
public:
  WithCheese(IPizza *decorator) : decorator_(decorator){};
  ~WithCheese() { delete decorator_; };
  void make() {
    decorator_->make();
    printf("Add cheese!\n");
  }

  int getCost() {
    return decorator_->getCost() + 5;
  }

private:
  IPizza *decorator_;
};

class WithTomato : public Pizza {
public:
  WithTomato(IPizza *decorator) : decorator_(decorator){};
  ~WithTomato() { delete decorator_; };
  void make() {
    decorator_->make();
    printf("Add tomato!\n");
  }

  int getCost() {
    return decorator_->getCost() + 5;
  }

private:
  IPizza *decorator_;
};

int main() {
  auto customizedPizza = new WithTomato(new WithCheese(new Pizza()));
  customizedPizza->make();
  printf("Total Cost : %d\n", customizedPizza->getCost());
  
  return 0;
}