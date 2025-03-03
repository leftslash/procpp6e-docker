module Employee;

import std;
using namespace std;

namespace HR {

  Employee::Employee(const string& firstName, const string& lastName)
    : m_firstName{firstName}, m_lastName{lastName} {}

  void Employee::promote(int raiseAmount) {
    salary(salary() + raiseAmount);
  }

  void Employee::demote(int demeritAmount) {
    salary(salary() - demeritAmount);
  }

  void Employee::hire() {
    m_isHired = true;
  }

  void Employee::fire() {
    m_isHired = false;
  }

  void Employee::display() const {
    println("Employee: {}, {}", lastName(), firstName());
    println("-----------------------------");
    println("{}", isHired() ? "Current Employee" : "Former Employee");
    println("Employee No. {}", number());
    println("Title: {}", titleToString(title()));
    println("Salary: {}", salary());
    println("");
  }

  void Employee::firstName(const string& firstName) {
    m_firstName = firstName;
  }

  const string& Employee::firstName() const {
    return m_firstName;
  }

  void Employee::lastName(const string& lastName) {
    m_lastName = lastName;
  }

  const string& Employee::lastName() const {
    return m_lastName;
  }

  void Employee::number(int number) {
    m_number = number;
  }

  int Employee::number() const {
    return m_number;
  }

  void Employee::salary(int salary) {
    m_salary = salary;
  }

  int Employee::salary() const {
    return m_salary;
  }

  void Employee::title(Title title) {
    m_title = title;
  }

  Title Employee::title() const {
    return m_title;
  }

  bool Employee::isHired() const {
    return m_isHired;
  }

  string titleToString(Title title) {

    switch (title) {
      case Title::Engineer:
        return "Engineer";
        break;
      case Title::SeniorEngineer:
        return "Senior Engineer";
        break;
      case Title::Manager:
        return "Manager";
        break;
      case Title::Unknown:
        return "Unknown";
        break;
    }
  }

  Title intToTitle(int selection) {
    switch (selection) {
      case 1:
        return Title::Engineer;
        break;
      case 2:
        return Title::SeniorEngineer;
        break;
      case 3:
        return Title::Manager;
        break;
      default:
        return Title::Unknown;
        break;
    }
  }

} // namespace HR
