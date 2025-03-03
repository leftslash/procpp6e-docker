export module Employee;

import std;

namespace HR {

  using namespace std;

  const int DefaultStartingSalary{30'000};
  export const int DefaultRaiseAndDemeritAmount{1'000};

  export enum class Title { Unknown, Engineer, SeniorEngineer, Manager };
  export string titleToString(Title title);
  export Title intToTitle(int title);

  export class Employee {

    public:
      Employee(const string& firstName, const string& lastName);
      void promote(int raiseAmount = DefaultRaiseAndDemeritAmount);
      void demote(int demeritAmount = DefaultRaiseAndDemeritAmount);
      void hire();
      void fire();
      void display() const;
      void firstName(const string& firstName);
      const string& firstName() const;
      void lastName(const string& lastName);
      const string& lastName() const;
      void number(int number);
      int number() const;
      void salary(int salary);
      int salary() const;
      void title(Title title);
      Title title() const;
      bool isHired() const;

    private:
      string m_firstName{};
      string m_lastName{};
      int m_number{-1};
      int m_salary{DefaultStartingSalary};
      bool m_isHired{false};
      Title m_title{Title::Unknown};

  }; // class Employee

} // namespace HR
