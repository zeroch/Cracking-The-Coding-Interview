#include <string>
#include <stdio.h>
#include <iostream>
#include <algorithm>
// write an algorithm to find a string has all unique characters. if you can't use additional data structure. 
bool uniqueChar(std::string s);
bool uniqueCharMap(std::string s);

int main(int argc, char const *argv[])
{
	std::string test1 = "Hello World!";
	std::string test2 = "IamtheX.";
	std::string test3 = "";

	bool result = uniqueCharMap(test1);

	std::cout << "Test: " << test1 << " Result: " << (result ? "True" : "False") << std::endl;
	
	result = uniqueCharMap(test2);

	std::cout << "Test: " << test2 << " Result: " << (result ? "True" : "False") << std::endl;

	result = uniqueCharMap(test3);

	std::cout << "Test: " << test3 << " Result: " << (result ? "True" : "False") << std::endl;


	return 0;
}

bool uniqueChar(std::string s){

	std::string copy_string;
	// fixit me sizeof s
	memcpy(&copy_string, &s, sizeof(s));
	std::sort(copy_string.begin(), copy_string.end());
	int string_length = copy_string.length();
	int j; 
	for (int i = 0; i < string_length-1; ++i)
	{
		j  = i+1;
		if (copy_string[i] == copy_string[j])
		{
			return false;
		}
	}

	return true;

}

bool uniqueCharMap(std::string s){

	bool mapping[128] = {false};

	 int string_length =  s.length();
	 for (int i = 0; i < string_length - 1; ++i)
	 {
	 	int currentChar = (int)s[i];

	 	if (mapping[currentChar])
	 	{
	 		return false;
	 	}
	 	mapping[currentChar] = true;
	 }

	 return true;

}