#include <string>

// write an algorithm to find a string has all unique characters. if you can't use additional data structure. 

class CodeString
{
public:
	CodeString();
	~CodeString();

	bool uniqueChar(std::string s)
};


bool CodeString::uniqueChar(std::string s){

	std::string copy_string;
	// fixit me sizeof s
	memcpy(copy_string, s, sizeof(s));
	copy_string.sort();
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