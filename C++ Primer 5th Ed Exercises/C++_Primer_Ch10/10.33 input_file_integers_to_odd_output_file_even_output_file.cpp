#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>
#include<functional>
#include<fstream>

/*
* Exercise 10.33
* Write a program that takes one input file and two output files, 
* input file holds integers, use istream_iterator to read input file,
* using ostream_iterator to write odd numbers into first output file,
* each value followed by space, write even numbers into second output
* file, each number on a separate line
*/

using std::cout;
using std::cin;
using std::endl;

/*
* Function writeFile, writes integer values to an ouput file
* param istream_iterator<int>, two ostream_iterator<int>
* return void
*/
void writeFile(std::istream_iterator<int>& is,
	std::ostream_iterator<int> odd, std::ostream_iterator<int> even) {
	std::istream_iterator<int> eof;

	while (is != eof) {
		if (*is % 2 != 0) {//odd
			odd = *is++;
		}
		else {
			even = *is++;
		}
	}
}

int main() {
	/*
	* input file of integers
	* istream iter to read dividing into two vectors
	* function takes outstream iter, and writes to files
	*/

	std::ifstream inputFile("Integers.txt");
	std::ofstream oddFile("OddIntegers.txt");
	std::ofstream evenFile("EvenIntegers.txt");

	if (!inputFile) {
		std::cerr << "Could not open file." << endl;
		return -1;
	}

	if (!oddFile) {
		std::cerr << "Could not write to odd file." << endl;
		return -2;
	}

	if (!evenFile) {
		std::cerr << "Could not write to even file." << endl;
		return -3;
	}

	std::istream_iterator<int> intin_iter(inputFile);
	std::ostream_iterator<int> outOdd_iter(oddFile, " "),
		outEven_iter(evenFile, "\n");

	writeFile(intin_iter, outOdd_iter, outEven_iter);

	/*
	* online answers used for_each which became just one line of code
	* for_each(intin_iter, eof, [&](int i) {i % 2 ? odd_iter = i :
	* even_iter = i;});, i%2 would return 1 or 0
	*/

	return 0;
}