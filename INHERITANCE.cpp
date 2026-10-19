#include <iostream>
#include <string>
using namespace std;

// Level 1: Base Class
class Person {
protected:
    string name;
    int age;

public:
    Person(const string& name, int age) : name(name), age(age) {}

    void introduce() {
        cout << "Hi, my name is " << name << " and I am " << age << " years old.\n";
    }
};

// Level 2: Intermediate Class
class Employee : public Person {
protected:
    int employeeId;
    double salary;

public:
    Employee(const string& name, int age, int id, double salary) 
        : Person(name, age), employeeId(id), salary(salary) {}

    void work() {
        cout << name << " (Employee ID: " << employeeId << ") is performing daily work tasks.\n";
    }
};

// Level 3: Derived Class
class Manager : public Employee {
private:
    int teamSize;

public:
    Manager(const string& name, int age, int id, double salary, int teamSize) 
        : Employee(name, age, id, salary), teamSize(teamSize) {}

    void conductMeeting() {
        cout << name << " is leading a meeting with a team of " << teamSize << " staff members.\n";
    }
};

int main() {
    // Create a Manager object at the bottom of the chain
    Manager leadManager("Alice", 35, 1042, 75000.0, 8);

    // Accessing members from all three levels of the chain
    leadManager.introduce();      // Inherited from Person
    leadManager.work();           // Inherited from Employee
    leadManager.conductMeeting(); // Defined locally in Manager

    return 0;
}