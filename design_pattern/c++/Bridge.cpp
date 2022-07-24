#include <iostream>

class ImplementPaint {
public:
  virtual void implDraw() = 0;
};

class Pencil : public ImplementPaint {
public:
  Pencil() = default;
  void implDraw() override {
    std::cout << "with pencil" << std::endl;
  }
};

class Brush : public ImplementPaint {
public:
  Brush() = default;
  void implDraw() override {
    std::cout << "with Brush" << std::endl;
  }
};

class ImplementShape {
  public:
    virtual void implShape(ImplementPaint* impl) = 0;
};

class Square : public ImplementShape {
  public:
    Square() = default;
    void implShape(ImplementPaint* implPaint) override {
      this->paint = implPaint;
      std::cout<< "I can create Square ";
      paint->implDraw();  
    }
  private:
    ImplementPaint *paint = nullptr;
};

class Circle : public ImplementShape {
  public:
    Circle() = default;
    void implShape(ImplementPaint* implPaint) override {
      this->paint = implPaint;
      std::cout << "I can create Circle ";
      paint->implDraw();
    }
  private:
    ImplementPaint* paint = nullptr;
};


int main() {
  Pencil pencil;

  Square square;
  square.implShape(&pencil);

  Circle circle;
  circle.implShape(&pencil);

  system("pause");
  return 0;
}
