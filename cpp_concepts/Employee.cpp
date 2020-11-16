//steps to compile
//g++ -std=c++14  Employee.cpp -o employee
#include <iostream>
#include <string>
#include <vector>
#include <array>

class Employee {
    std::string _name;
    int _salary;
public:
    Employee(std::string name, int salary)
        : _name(name), _salary(salary) {};
    virtual int show(void);
    //Employee hike(float percentage);
};
int Employee::show(void)
{
    std::cout << "name: " << _name << std::endl;
    std::cout << "salary: " << _salary << std::endl;
    return 0;
}

class SoftwareDev: public Employee {
    std::string job;
public:
    virtual int show(void);
    SoftwareDev(std::string n, std::string j, int s);
    ~SoftwareDev(void) {};
};
SoftwareDev::SoftwareDev(std::string n,
        std::string j, int s): Employee(n, s), job(j) {};

int SoftwareDev::show(void)
{
    Employee::show();
    std::cout << "job type: " << "Software Dev" << std::endl;
    return 0;
}

class Manager: public Employee {
    std::string job;
public:
    virtual int show(void);
    Manager(std::string n, std::string j, int s);
    ~Manager(void) {};
};

Manager::Manager(std::string n,
        std::string j, int s): Employee(n, s), job(j) {}

int Manager::show(void)
{
    Employee::show();
    std::cout << "job type: " << "Manager" << std::endl;
    return 0;
}

int main(int argc, char *argv[])
{
    class Manager m("m1", "manager1", 100);
    class Manager m2("m2", "manager2", 200);
    class SoftwareDev d1("d1", "Developer1", 100);
    class SoftwareDev d2("d2", "Developer2", 120);
    class SoftwareDev d3("d3", "Developer3", 130);
    //class Employee *e = &m;
    std::vector<class Employee *> vec;
    vec.push_back(&m);
    vec.push_back(&m2);
    vec.push_back(&d1);
    vec.push_back(&d2);
    vec.push_back(&d3);
    for(auto v: vec) {
        v->show();
    }
    return 0;
}
