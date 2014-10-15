// string permutation
// striing permuation means they have exactly same char but in diff order. 


#include <iostream>
#include <string>
#include <algorithm>
bool StringPermutation(std::string strA , std::string strB);

int main(int argc, char const *argv[])
{
	

	std::string test1 = "Hello World!";
	std::string test2 = "IamtheX.";
	std::string test3 = "";
	std::string test4 = "amIthXe.";

	bool result = StringPermutation(test1, test2);

	std::cout << "Test: " << test1 << '\t' << test2 <<  
				" Result: " << (result ? "True" : "False")  << std::endl;
	
	result = StringPermutation(test2, test3);

	std::cout << "Test: " << test2 << '\t' << test3 << 
				 " Result: " << (result ? "True" : "False") << std::endl;

	result = StringPermutation(test3, test3);

	std::cout << "Test: " << test3 << '\t' << test3 <<
				 " Result: " << (result ? "True" : "False") << std::endl;

	result = StringPermutation(test2, test4);

	std::cout << "Test: " << test2 << '\t' << test4 <<
				 " Result: " << (result ? "True" : "False") << std::endl;




	return 0;
}


bool StringPermutation(std::string strA , std::string strB){


	int checkerA[128] = {0};
	int checkerB[128] = {0};
	int sizeA = strA.length();
	int sizeB = strB.length();


	int currentChar;
	if (sizeA != sizeB)
	{
		return false;
	}else if (sizeA == 0)
	{
		return true;
	}else
	{
	
		for (int i = 0; i < sizeA; ++i)
		{
			currentChar = (int)strA[i];
			++checkerA[currentChar];

			currentChar = (int)strB[i];
			++checkerB[currentChar];
		}

		for (int i = 0; i < 128; ++i)
		{
			if (checkerA[i] != checkerB[i])
			{
				return false;
			}
		}

		return true;


	}
}

