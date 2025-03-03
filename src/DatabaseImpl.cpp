module Database;

import std;

using namespace std;

namespace HR {

  Employee& Database::addEmployee(const string& firstName, const string& lastName) {
    Employee employee {firstName, lastName};
    employee.number(m_nextEmployeeNumber++);
    employee.hire();
    m_employees.push_back(employee);
    return m_employees.back();
  }

  Employee& Database::getEmployee(int number) {
    for (auto& employee : m_employees) {
      if (employee.number() == number) 
        return employee;
    }
    throw logic_error {"No employee found."};
  }

  Employee& Database::getEmployee(const string& firstName, const string& lastName) {
    for (auto& employee : m_employees) {
      if (employee.firstName() == firstName && employee.lastName() == lastName) 
        return employee;
    }
    throw logic_error {"No employee found."};
  }

  void Database::displayAll() const {
    for (const auto& employee : m_employees)
      employee.display();
  }

  void Database::displayCurrent() const {
    for (const auto& employee : m_employees)
      if (employee.isHired())
        employee.display();
  }

  void Database::displayFormer() const {
    for (const auto& employee : m_employees)
      if (!employee.isHired())
        employee.display();
  }

} // namespace HR
