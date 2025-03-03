import std;
import Employee;

using namespace std;
using namespace HR;

int main() {

  println("");
  println("Testing Employee");
  println("");
  Employee e{"Jane", "Roe"};
  e.firstName("John");
  e.lastName("Doe");
  e.employeeNumber(71);
  e.salary(50'000);
  e.promote();
  e.promote(50);
  e.hire();
  e.display();

}
