#include <iostream>

class SortStrategy{
public:
  virtual void sort() = 0;
};

class QuickSort : public SortStrategy {
public:
  void sort() {
    printf("use quick sort\n");
  }
};

class BubbleSort : public SortStrategy {
public:
  void sort() {
    printf("use bubble sort\n");
  }
};

class Sorter {
public:
  Sorter(SortStrategy* method) : sortMethod(method){};
  void sortElement();
  void setSorter(SortStrategy* method);
private:
  SortStrategy* sortMethod = nullptr;
};

void Sorter::setSorter(SortStrategy* method) {
  if(sortMethod)
    delete sortMethod;
  sortMethod = method;
}

void Sorter::sortElement() {
  sortMethod->sort();
}

int main() {
  Sorter sorter(new BubbleSort());
  sorter.sortElement();

  sorter.setSorter(new QuickSort());
  sorter.sortElement();

  return 0;
}