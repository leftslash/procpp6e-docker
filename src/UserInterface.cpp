import std;
import Database;
import Employee;

using namespace std;
using namespace HR;

int displayMenu();
void doHire(Database &db);
void doFire(Database& db);
void doPromote(Database& db);

int main() {

  Database db;
  bool done {false};

  while (!done) {
    int selection {displayMenu()};
    switch (selection) {
      case 0:
        done = true;
        break;
      case 1:
        doHire(db);
        break;
      case 2:
        doFire(db);
        break;
      case 3:
        doPromote(db);
        break;
      case 4:
        db.displayAll();
        break;
      case 5:
        db.displayCurrent();
        break;
      case 6:
        db.displayFormer();
        break;
      default:
        println(cerr, "Unknown command.");
        break;
    } // switch

  } // while

  return 0;
}

int displayMenu() {
  int selection;
  println("");
  println("Employee Database");
  println("=================");
  println("1) Hire a new employee");
  println("2) Fire an employee");
  println("3) Promote an employee");
  println("4) Display all employees");
  println("5) Display all current employees");
  println("6) Display all former employees");
  println("0) Quit");
  println("");
  print("> ");
  cin >> selection;
  println("");
  return selection;
}

void doHire(Database& db) {
  string firstName;
  string lastName;
  print("First Name: ");
  cin >> firstName;
  print("Last Name: ");
  cin >> lastName;
  Employee& employee {db.addEmployee(firstName, lastName)};
  println("");
  println("Hired employee {} {} with employee number {}",
      firstName, lastName, employee.number());
}

void doFire(Database& db) {
  int number;
  print("Employee number: ");
  cin >> number;
  try {
    auto& employee {db.getEmployee(number)};
    employee.fire();
    println("");
    println("Employee {} terminated.", employee.number());
  } catch (const logic_error& err) {
    println(cerr, "Unable to terminate employee: {}", err.what());
  }
}

void doPromote(Database& db) {
  int number;
  int raiseAmount;
  int title;
  print("Employee number: ");
  cin >> number;
  print("Raise in dollars: ");
  cin >> raiseAmount;
  println("");
  println("Titles:");
  println("=======");
  println("0) Unknown");
  println("1) Engineer");
  println("2) Senior Engineer");
  println("3) Manager");
  println("");
  print("New title: ");
  cin >> title;
  try {
    auto& employee {db.getEmployee(number)};
    employee.promote(raiseAmount);
    employee.title(intToTitle(title));
    println("");
    println("Employee {} promoted.  New salary: {}.", 
        employee.number(), employee.salary());
  } catch (const logic_error& err) {
    println(cerr, "Unable to promote employee: {}", err.what());
  }
}
