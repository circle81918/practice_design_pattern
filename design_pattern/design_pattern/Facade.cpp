
#include <iostream>

class EmployeeSystem {
public:
  void identifyEmployee() {
    printf("Verify Pass! User = Jason\n");
  }
};

class StockSystem {
public:
  void checkStock() {
    printf("Verify Pass! Stuff is in stock!\n");
  }
};

class FinanceSystem {
public:
  void recordTransaction() {
    printf("Record Transaction");
  }
};

class PurchaseSystemFacade {
public:
  void purchaseStuff() {
    employee_system.identifyEmployee();
    stock_system.checkStock();
    finance_system.recordTransaction();
  }
private:
  EmployeeSystem employee_system;
  StockSystem stock_system;
  FinanceSystem finance_system;
};

int main() {
  std::unique_ptr<PurchaseSystemFacade> purchase_system = std::make_unique<PurchaseSystemFacade>();
  purchase_system->purchaseStuff();
}