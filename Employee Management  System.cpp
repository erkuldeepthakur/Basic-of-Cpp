#include <iostream>
#include <string>

class Employee {
protected:
    std::string name;
    int id;
    int salary;

public:
    Employee(std::string n, int i, int s) : name(n), id(i), salary(s) {}
    virtual void calculateEarnings() = 0;
    virtual void display() = 0;
};

class Manager : public Employee {
private:
    int rating;

public:
    Manager(std::string n, int i, int s, int r) : Employee(n, i, s), rating(r) {}
    
    void calculateEarnings() override {
        double bonus = 0.1 * salary * rating;
        double totalEarnings = salary + bonus;
        std::cout << "Employee: " << name << " (ID: " << id << ")\n"
                  << "Role: Manager\n"
                  << "Base Salary: " << salary << "\n"
                  << "Bonus: " << bonus << "\n"
                  << "Total Earnings: " << totalEarnings << "\n";
    }

    void display() override {
        calculateEarnings();
    }
};

class Developer : public Employee {
private:
    int extraHours;

public:
    Developer(std::string n, int i, int s, int hours) : Employee(n, i, s), extraHours(hours) {}
    
    void calculateEarnings() override {
        double overtimeCompensation = 500 * extraHours;
        double totalEarnings = salary + overtimeCompensation;
        std::cout << "Employee: " << name << " (ID: " << id << ")\n"
                  << "Role: Developer\n"
                  << "Base Salary: " << salary << "\n"
                  << "Overtime Compensation: " << overtimeCompensation << "\n"
                  << "Total Earnings: " << totalEarnings << "\n";
    }

    void display() override {
        calculateEarnings();
    }
};

int main() {
    int type;
    std::cout << "Employee Type (1 for Manager, 2 for Developer): ";
    std::cin >> type;

    if (type < 1 || type > 2) {
        std::cout << "Invalid employee type.\n";
        return 0;
    }

    std::string name;
    int id, salary;

    std::cout << "Name: ";
    std::cin >> name;
    std::cout << "ID: ";
    std::cin >> id;
    std::cout << "Salary: ";
    std::cin >> salary;

    if (type == 1) {
        int rating;
        std::cout << "Rating (1-5): ";
        std::cin >> rating;
        Manager manager(name, id, salary, rating);
        manager.display();
    } else if (type == 2) {
        int extraHours;
        std::cout << "Extra Hours: ";
        std::cin >> extraHours;
        Developer developer(name, id, salary, extraHours);
        developer.display();
    }

    return 0;
}
