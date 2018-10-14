#include <iostream>
#include <vector>
#include <string> // stoi
#include <algorithm> // std::transform
#include <numeric> // std::accumulate
#include <functional> // plus, minus, multiplies, divides
#include <iterator> // back_inserter

using std::vector;
using std::string;
using std::cbegin;
using std::cend;


vector<int> convert_to_int(const vector<string> &arr_to_convert) {
	vector<int> res;
	// Reserve space in the array. 
	res.reserve(arr_to_convert.size());
	// Transforms given array into new array with given function.
	std::transform(cbegin(arr_to_convert), cend(arr_to_convert), std::back_inserter(res), [](const string &str) { return std::stoi(str); });
	return res;
}


std::function<int(int, int)> convert_to_operation(const string &str) {
	if (str == "SUM") {
		return std::plus();
	} else if (str == "SUB") {
		return std::minus();
	} else if (str == "MUL") {
		return std::multiplies();
	} else if (str == "DIV") {
		return std::divides();
	} else {
		throw std::runtime_error("Invalid operation.");
	}
}

/**
 * Execute operation on given arguments. 
 * Example usage: "calc.exe SUM 1 2 3"
 */
int main(int argc, char **argv) {
	auto op = convert_to_operation(argv[1]);
	auto ints_to_calc = convert_to_int(vector<string>(argv + 2, argv + argc));
	int op_result = std::accumulate(cbegin(ints_to_calc) + 1, cend(ints_to_calc), ints_to_calc.front(), op);
	std::cout << "Result is: " << op_result;
}