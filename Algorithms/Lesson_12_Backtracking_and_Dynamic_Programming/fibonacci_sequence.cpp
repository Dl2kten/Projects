#include <iostream>
#include <vector>
#include <string>

/*
* Dynamic Programming - general design for solving optimization problems
* Fibonacci numbers
*
* Step 1 - decompose into simpler sub problems
* fibonacci(n) = fibonacci(n-1) + fibonacci(n-2)
* Step 2 - express solution in terms of sub problem
* keep calling the sub solution until n
* Step 3 - use table to compute optimal value bottom up
* instead of recursive top down, work from bottom up, storing values along the
* way
* Step 4 - find optimal solution based on step 1-3
* return solution
*/

/// <summary>
/// Finds the value of the nth number in the fibonnaci sequence assuming
/// the sequence starts at 0
/// </summary>
/// <param name="n"></param>
/// <returns></returns>
unsigned fibonnaci(std::size_t n) {
	std::vector<unsigned> fib(n + 1);
	fib[0] = 0;
	fib[1] = 1;
	for (std::size_t i = 2; i != n + 1; i++) {
		fib[i] = fib[i - 1] + fib[i - 2];
	}

	return fib[n];
}


int main() {

	std::string word;
	std::cout << "Enter the position of the number you wish to know in"
		<< " the fibonacci sequence(enter stop to quit):\n";
	std::cin >> word;

	while (word != "stop") {
		std::cout << "The value of the number at " << word << " position is: "
			<< fibonnaci(std::stoul(word)) << std::endl;
		std::cout << "Enter the position of the number you wish to know in"
			<< " the fibonacci sequence(enter stop to quit):\n";
		std::cin >> word;
	}

	return 0;
}