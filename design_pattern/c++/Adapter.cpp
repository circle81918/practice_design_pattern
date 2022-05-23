#include <iostream>
using namespace std;

// Target
class IPort {
public:
  virtual void portOutputSignal() = 0;
  virtual void portDescription() = 0;
};

class VGA : public IPort {
public:
  void portOutputSignal() { printf("VGA port output signal\n"); }
  void portDescription() { printf("this is VGA port!\n"); }
};

//Adaptee
class IUSB {
public:
  virtual void usbOutputSignal() = 0;
  virtual void usbDescription() = 0;
};

class TypeC : public IUSB {
public:
  void usbOutputSignal() { printf("type C output signal\n"); }
  void usbDescription() { printf("this is typeC!\n"); }
};

// Adapter 
class typeCtoVGAAdapter : public IPort {
public:
  typeCtoVGAAdapter(IUSB* T) {
    adaptee = T;
  }
  ~typeCtoVGAAdapter() {
    delete adaptee;
  }
  void portOutputSignal() {
    adaptee->usbOutputSignal();
  }
  void portDescription() {
    adaptee->usbDescription();
  }
private:
  IUSB* adaptee;
};

int main()
{
  IPort* VGA = new typeCtoVGAAdapter(new TypeC());
  VGA->portOutputSignal();
  VGA->portDescription();
  return 0;
}