#include <iostream>
#include <vector>
#include <math.h>
/*
* Decrease by half
* Exponentiation by squaring, recursive implementation
*/

/// <summary>
/// exponentiation by squaring
/// </summary>
/// <param name="base"></param>
/// <param name="power"></param>
/// <returns></returns>
int exp_square(int base, unsigned power) {
	if (power == 0)
		return 1;
	if (power == 1)
		return base;
		
	if (power % 2 == 0) {
		return pow(exp_square(base, power / 2), 2);
	}
	else {
		return pow(exp_square(base, (power - 1) / 2), 2) * base;
	}
	

}

int main() {
	
	std::cout << exp_square(2, 8) << std::endl;
	std::cout << exp_square(2, 9) << std::endl;
	//holy spent a lot of time wasn't using reture from exp_square as base...
	return 0;
}