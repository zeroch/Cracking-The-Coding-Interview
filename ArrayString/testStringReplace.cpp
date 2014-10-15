#include <iostream>
#include <string>
#include <algorithm>

std::string stringReplace(std::string s);


int main(int argc, char const *argv[])
{
	std::string test1 = "Hello World!      ";
	std::string test2 = "Iam th e X.        ";
	std::string test3 = "";
	std::string test4 = "amI thXe.    ";

	std::string result = stringReplace(test1);
	std::cout << "Test: " << test1 << '\t' << 
				" Result: " <<  result  << std::endl;

	result = stringReplace(test2);	
	std::cout << "Test: " << test2 << '\t' << 
				" Result: " <<  result  << std::endl;

	result = stringReplace(test3);	
	std::cout << "Test: " << test3 << '\t' << 
				" Result: " <<  result  << std::endl;

	result = stringReplace(test4);	
	std::cout << "Test: " << test4 << '\t' << 
				" Result: " <<  result  << std::endl;

	return 0;
}


std::string stringReplace(std::string s){

	std::string::iterator runner = s.begin();
	int length = s.length();
	std::string result;
	int count = 0;
	char* space = " ";
	while(runner != s.end())
	{
		char currentChar 	= *runner;
		char nextChar 		= *(runner+1);

		// std::cout << "DEBUG: " << currentChar << ":" << nextChar << 
		// strcmp(	&currentChar, 	space) << 
		// std::endl;

		if(		((currentChar == space[0]) ) 	&& 
				((nextChar == space[0])) 	&& 
				count <= length
			){
			break;

		}

		if ((currentChar != space[0]))
		{
			result.push_back(currentChar);
		}else
		{
			// std::cout << "DEBUG: " << currentChar << ":" << "changing " << std::endl;

			result.append("%20");
		}
		runner++;
		count++;
	}

	return result;

}