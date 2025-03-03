import std;
import Database;
import Employee;

using namespace std;
using namespace HR;

int main() {

  Database db;

  Employee& e1 {db.addEmployee("Greg", "Wallis")};
  e1.fire();

  Employee& e2 {db.addEmployee("Marc", "White")};
  e2.salary(100'000);

  Employee& e3 {db.addEmployee("John", "Doe")};
  e3.salary(10'000);

  println("");
  println("All Employees\n===============\n");
  db.displayAll();
  println("");

  println("");
  println("Current Employees\n===============\n");
  db.displayCurrent();
  println("");

  println("");
  println("Former Employees\n===============\n");
  db.displayFormer();
  println("");

}
