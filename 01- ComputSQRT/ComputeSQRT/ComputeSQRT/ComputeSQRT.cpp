/* Name: Russell (Chumicat) (Li-Shuo ZENG)
 * SID¡G B10332030
 * Date: Feb. 28, 2018
 * Last Update: Mar. 6, 2018
 * Version: v1.1
 * Problem statement: Compute square root of number from input file
 * Reference:
	https://dotblogs.com.tw/v6610688/2013/11/11/cplusplus_check_file_exist
	https://dotblogs.com.tw/v6610688/2013/11/05/cplusplus_output_align_setw_set_field_width
	http://en.cppreference.com/w/cpp/io/ios_base/setf
	http://it-easy.tw/cout-float/
	https://stackoverflow.com/questions/201992/how-to-read-until-eof-from-cin-in-c
 */
#include <iomanip>
#include <iostream>
#include <math.h>

/* Babylonian algorithm */
double sqrt2(double value) 
{
	double guess = value / 2;
	while (true) {
		double guess2 = (guess + value / guess) / 2;
		if (fabs(guess2 - guess) < 0.01)
			break;
		else
			guess = guess2;
	}
	return guess;
}

int main() 
{	/* Read data one by one */
	double value;
	while (std::cin >> value){
		std::cout << std::fixed << std::setprecision(2) << sqrt2(value) << std::endl;
	}

	return 0;
}
