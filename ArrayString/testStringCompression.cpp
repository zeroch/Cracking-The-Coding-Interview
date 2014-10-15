#include <iostream>
#include <string>

std::string stringCompression(std::string s);


int main(int argc, char const *argv[])
{
	std::string test1 = "Hello World!";
	std::string test2 = "Iam th e X.   ";
	std::string test3 = "aaabbcjksdddf";
	std::string test4 = "amI thXXXeefdfdf";

	std::string result = stringCompression(test1);
	std::cout << "Test: " << test1 << '\t' << 
				" Result: " <<  result  << std::endl;

	result = stringCompression(test2);	
	std::cout << "Test: " << test2 << '\t' << 
				" Result: " <<  result  << std::endl;

	result = stringCompression(test3);	
	std::cout << "Test: " << test3 << '\t' << 
				" Result: " <<  result  << std::endl;

	result = stringCompression(test4);	
	std::cout << "Test: " << test4 << '\t' << 
				" Result: " <<  result  << std::endl;


	return 0;
}


std::string stringCompression(std::string s){

	std::string::iterator slow = s.begin();
	std::string::iterator fast = s.begin()+1;
	int charCount = 1;

	std::string result;

	while(fast != s.end()){


		if (*(slow) == *(fast))
		{
			++charCount;
			++fast;
		}else 
		{
			result.push_back(*(slow));
			result.append(std::to_string(charCount));

			slow = fast;
			charCount = 1;
			++fast;
		}
	}
	result.push_back(*(slow));
	result.append(std::to_string(charCount));

	return result;

}