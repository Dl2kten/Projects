#include<iostream>
#include<vector>

/*
* Exercise 7.57
* Own version of class Account
*/

using namespace std;

/*
* class Account representing a bank account
*/
class Account {
public:
	Account(const string& s = "") : owner(s), amount(0.0) {}
	Account(const string& s, double d) : owner(s), amount(d) {}
	void calculate() { amount += amount * interestRate; }
	double get_Amount() const { return amount; }
	static double rate() { return interestRate; }
	static void rate(double);

private:
	static double interestRate;
	static constexpr int period = 30;
	double daily_tbl[period];
	string owner;
	double amount;
	static double initRate() { return 0.10; };
};

//define outside class
constexpr int Account::period;
double Account::interestRate = initRate();

/*
* function rate to set the interest rate
* param double
* return void
*/
void Account::rate(double i) {
	interestRate = i;
}

int main() {

	Account ac1;
	Account ac2("A", 10000);

	ac1.calculate();
	cout << ac1.rate() << " " << ac1.get_Amount() << endl;

	Account::rate(0.15);
	ac2.calculate();
	cout << ac2.rate() << " " << ac2.get_Amount() << endl;

	return 0;
}