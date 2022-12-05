#include<iostream>
#include<vector>
#include<string>

/*
* Exercise 9.51
* Write a class that has three unsigned members, year, month, day,
* a constructor that takes a string for a date, should handle a 
* variety of formats, 1/1/1900, jan 1, 1900
*/

using std::cout;
using std::cin;
using std::endl;

/*
* Class date records a specific date, year month day
* data members unsigned year, month, day
*/
class Date {
	unsigned month, day, year;
	
public:
	Date() : month(0), day(0), year(0) {}
	Date(const std::string& m, unsigned d, unsigned y) {
		std::vector<std::string> months{ "January", "February", "March",
		"April", "May", "June", "July", "August", "September",
			"October", "November", "December", "Jan", "Feb", "Mar",
		"Apr", "May", "June", "July", "Aug", "Sept", "Oct", "Nov",
		"Dec" };
		day = d;
		year = y;

		for (decltype(months.size()) i = 0; i < months.size(); ++i) {
			if (m == months[i]) {
				if (i > 11) {//if abbreviation
					auto j = i - 12;
					month = j + 1;
				}
				else {
					month = i + 1;
				}
				break;
			}
		}//end of for
		
	}

	Date(std::string date) {
		/*
		* given 1/1/1900
		* for/while loop stoi 1 how to know how long the number is
		* change back to string and count, divide by 10
		* increment
		*/
		std::string numbers{ "0123456789" };
		int mdy = 0;
		std::string temp;

		for (decltype(date.size()) i = 0; i < date.size(); ++i) {
			switch (mdy) {
			case 0:
				i = date.find_first_of(numbers, i);
				month = stoi(date.substr(date.find_first_of
				(numbers, i)));

				temp = std::to_string(month);
				i += temp.size();
				++mdy;
				break;
			case 1:
				i = date.find_first_of(numbers, i);
				day = stoi(date.substr(date.find_first_of
				(numbers, i)));

				temp = std::to_string(day);
				i += temp.size();
				++mdy;
				break;
			case 2:
				i = date.find_first_of(numbers, i);
				year = stoi(date.substr(date.find_first_of
				(numbers, i)));

				temp = std::to_string(year);
				i += temp.size();
				++mdy;
				break;
			default:
				break;
			}
		}//end of for
	}

	unsigned getMonth() { return month; }
	unsigned getDay() { return day; }
	unsigned getYear() { return year; }
};

int main() {

	Date d1("January", 1, 1900);
	Date d2("Feb", 12, 1900);
	Date d3("12/1/1900");

	cout << "The month, day, and year for d1 is: " << d1.getMonth()
		<< " " << d1.getDay() << " " << d1.getYear();
	cout << "\nThe month, day, and year for d2 is: " << d2.getMonth()
		<< " " << d2.getDay() << " " << d2.getYear();
	cout << "\nThe month, day, and year for d3 is: " << d3.getMonth()
		<< " " << d3.getDay() << " " << d3.getYear();

	/*
	* Online answers used substr, interesting, should define the 
	* constructors outside, had a separate function for print so can't
	* get access to unsigned
	*/
	return 0;
}