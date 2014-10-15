#include <iostream>

char* reverseString(char * s);
void printString(char * s);

int main(int argc, char const *argv[])
{
	
	char* test1 = "Hello World!";
	char* test2 = "IamtheX.";
	char* test3 = "";

	char* result = reverseString(test1);
	std::cout << "Test: " << test1 << " Result: " << result << std::endl;
	free(result);

	result = reverseString(test2);
	std::cout << "Test: " << test2 << " Result: " << result << std::endl;
	free(result);

	result = reverseString(test3);
	std::cout << "Test: " << test3 << " Result: " << result << std::endl;
	free(result);

	return 0;
}


char* reverseString(char * s){

	// run pointer to the end of string
	if (s == "")
	{
			char * resultString = (char*) malloc((1) * sizeof(char));	
			resultString[0] = '\0';
			return resultString;
	}
	char * runner = s;
	int size = 0;
	while( *(++runner))
		size++;
	char * resultString = (char*) malloc((size + 1) * sizeof(char));	
	int i = 0;
	runner--;
	while(i <= size){
		resultString[i] = *(runner);
		runner--;
		i++;
	}
	resultString[i] = '\0';
	return resultString;

}

	
