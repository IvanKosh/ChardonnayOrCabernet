/* 
 * File:   main.cpp
 * Author: bat
 *
 * Created on 17 Сентябрь 2015 г., 19:13
 */

#include <iostream>
#include <fstream>
#include <string>
//#include <sys/types.h>
//#include <regex.h>


#include <regex.h>

//#include <boost/regex.hpp>

using namespace std;

int match(const char *string, char *pattern)
{
    int    status;
    regex_t    re;

    if (regcomp(&re, pattern, REG_EXTENDED|REG_NOSUB) != 0) {
		cout << "error1";
        return(0);      /* report error */
    }
    status = regexec(&re, string, (size_t) 0, NULL, 0);
    regfree(&re);
    if (status != 0) {
		cout << "error2";
        return(0);      /* report error */
    }
    return(1);
}


int main(int argc, char *argv[]) {
	ifstream stream(argv[1]);
	string line;
	while (getline(stream, line)) {
		cout << line << endl;
	}
	
	//regex integer;
	
	string input;
	//regex_t integer;
	//integer = new regex_t("(\\+|-)?[[:digit:]]+");
	
	regex_t reg;
	regcomp(&reg, "a|b", REG_EXTENDED|REG_NOSUB);
	
	cout << regexec(&reg, "a", (size_t) 0, NULL, 0);
	cout << regexec(&reg, "b", (size_t) 0, NULL, 0);
	cout << regexec(&reg, "ab", (size_t) 0, NULL, 0);
	
	regfree(&reg);
	cout << match("a", "a|b") << endl;
	cout << match("c", "a|b") << endl;
	
	//reg
	
	//int regcomp(regex_t *preg, const char *regex, int cflags);
	//cout << regcomp(integer, "123", 1);
	
 	//As long as the input is correct ask for another number
// 	while(true)
// 	{
// 		cout<<"Give me an integer!"<<endl;
// 		cin>>input;
// 		if(!cin) break;
// 		//Exit when the user inputs q
// 		if(input=="q")
// 			break;
// 		if(reg regex_match(input, integer))
// 			cout<<"integer"<<endl;
// 		else
// 		{
// 			cout<<"Invalid input"<<endl;
// 		}
// 	}
	return 0;
}