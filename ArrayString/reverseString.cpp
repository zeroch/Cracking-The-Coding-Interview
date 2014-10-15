class CodeString
{
public:
	char* reverseString(const char * s){

		// run pointer to the end of string
		char * runner = s;
		int size = 0;
		while( *(++runner) = '\0')
			++size;

		char * resultString = (char*) malloc(size * sizeof(char));
		
		int i = 0;
		while(runner != s)
			resultString[i] = *(--runner);

		return resultString;

	}
	
};