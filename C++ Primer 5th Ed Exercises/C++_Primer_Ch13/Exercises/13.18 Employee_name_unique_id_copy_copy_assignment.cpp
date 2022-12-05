#include <iostream>
#include <vector>
#include <list>

/*
* Exercise 13.18, 13.19
* Define an Employee class that contains employee name and a unique
* employee identifier, give the class a default constructor and a 
* constructor that takes a string representing the employee's name,
* each constructor should generate a unique ID by incrementing a static
* data member
* Implement whatever copy-control members is needed by Employee
*/

/*
* Class Employee contains an employee's name and unique employee 
* identifier
*/
class Employee {
public:
	Employee(): Employee_id(++id) {}
	Employee(const std::string& s) : Employee_id(++id), 
		Employee_name(s) {}
	//needs copy and copy-assignment operator so unique employee id is
	//not copied
	Employee(const Employee&);
	Employee& operator=(const Employee&);
	int get_employee_id() const { return Employee_id; }
	std::string get_employee_name() const { return Employee_name; }

private:
	static int id;
	int Employee_id;
	std::string Employee_name;
};

/*
* Define static member Employee_id 
*/
int Employee::id = 0;

/*
* Copy constructor for Employee
* param const Employee&
*/
Employee::Employee(const Employee& orig) {
	Employee_id = ++id;
}

/*
* Copy-assignment operator for Employee
* param const Employee&
* return Employee&
*/
Employee& Employee::operator=(const Employee& orig) {
	//Employee_id = ++id;
	return *this;
}

int main() {

	Employee worker1;
	Employee worker2("George");
	std::cout << "Employee: " << worker1.get_employee_name() << " ID: "
		<< worker1.get_employee_id()
		<< "\nEmployee: " << worker2.get_employee_name() << " ID: "
		<< worker2.get_employee_id() << std::endl;

	Employee worker3(worker2), worker4;
	worker4 = worker1;
	std::cout << "Employee: " << worker3.get_employee_name() << " ID: "
		<< worker3.get_employee_id()
		<< "\nEmployee: " << worker4.get_employee_name() << " ID: "
		<< worker4.get_employee_id() << std::endl;

	return 0;
}