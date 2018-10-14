#include <iostream>
#include <vector> // Dynamic array in C++
#include <string> // std::string

// Include namespace STD -> don't need to use std:: before every STL component. 
// Warning: Use carefully - can lead to name clashing, poluting your namespace, ...
using namespace std;

void print_cpp_args(const vector<string> &args) {
	cout << "Name of the program is \"" << args[0] << "\"\n";
	for (size_t i = 1; i < args.size(); ++i)
	{
		cout << "Argument nr. " << i << " contains: \"" << args[i] << "\"\n";
	}
}

void print_c_args(int argc, char **argv) {
	cout << "Name of the program is \"" << argv[0] << "\"\n";
	for (int i = 1; i < argc; ++i)
	{
		cout << "Argument nr. " << i << " contains: \"" << argv[i] << "\"\n";
	}
}

/**
* Main function can have arguments
* 
* @param argc Number of arguments. 
* @param argv C-array of C-strings containg arguments. The first argument is the name of the program. 
*/
int main(int argc, char **argv) {
	// Converts array of string into C++-ish array of string, i.e. vector<string>
	// Explanation: Pointers works as iterators -> calls "vector(iterator first, iterator last)" constructor. 
	//  This constructor traverses the iterators and creates a new string from each iterator's value. 
	//  The value of iterator is "char *" (c-string). When creating std::string, string(char *) constructor is called. 

	vector<string> arguments(argv, argv + argc);
	
	print_cpp_args(arguments);
	print_c_args(argc, argv);

	return 0;
}