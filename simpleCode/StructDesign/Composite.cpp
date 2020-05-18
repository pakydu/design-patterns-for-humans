#include <iostream>
#include <string>
#include <vector>

class Employee {
public:
    Employee(const std::string& name, float salary): m_name(name), m_salary(salary) {}
    virtual std::string GetName() { return m_name; }
    virtual float GetSalary() {return m_salary; }

protected:
    std::string m_name;
    float m_salary;
};

class Developer : public Employee {
public:
    Developer(const std::string& name, float salary): Employee(name, salary) {}
};

class Designer: public Employee {
public:
    Designer(const std::string& name, float salary): Employee(name, salary) {}
};

class Organization {
public:
    void AddEmployee(const Employee& employee){
        m_employees.push_back(employee);
    }

    float GetNetSalaries() {
        float net_salary = 0;
        for (auto&& employee: m_employees) {
            net_salary += employee.GetSalary();
        }
        return net_salary;
    }

private:
    std::vector<Employee> m_employees;
};

int main()
{
    Developer john("John Doe", 1200);
    Designer Jane("Jane Doe", 1500);

    Organization org;
    org.AddEmployee(john);
    org.AddEmployee(Jane);

    std::cout << "Net salaries: " << org.GetNetSalaries() << std::endl;
}
