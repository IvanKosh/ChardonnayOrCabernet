/* 
 * File:   main.cpp
 * Author: bat
 *
 * Created on 17 Сентябрь 2015 г., 19:13
 */

#include <iostream>
#include <fstream>
#include <regex.h>

using namespace std;

int main(int argc, char *argv[]) {
	ifstream stream(argv[1]);
	string line, temp;
	
	regex_t regex;
	int reti;
	char msgbuf[16];
	short i, j, l;
	bool test;
	
	while (getline(stream, line)) {
		// найти позицию " | "
		temp = "^[a-z]*";
		test = true;
		l = line.length();
		for (i = l; line[--i] != '|';) {
		}
		
		// составить регулярное выражение на основе правой части
		for (j = i+2; j < l; j++) {
			//cout << line[j] << '*';
			temp += line[j];
			temp += "[a-z]*";
		}
		temp += '$';
		
		//cout << temp << endl;
		
		reti = regcomp(&regex, temp.c_str(), REG_ICASE);
		if (reti) {
			fprintf(stderr, "Could not compile regex\n");
			return 1;
		}
		
		// для каждого слова левой части заюзать регулярное выражение
		l = i;
		j = 0;
		for (i = 0; i < l; i++) {
			if (line[i] == ' ') {
//				cout << '[' << line.substr(j, i-j) << ']';
//				
//				//char_temp = line.substr(j, i-j).c_str();
//				cout << line.substr(j, i-j).c_str() << endl;
//				
//				//reti = regexec(&regex, "Merlot", 0, NULL, 0);
				reti = regexec(&regex, line.substr(j, i-j).c_str(), 0, NULL, 0);
//				cout << reti;
				if (!reti) {
					cout << line.substr(j, i-j+1);
					test = false;
				}
				else if (reti == REG_NOMATCH) {
					//cout << "No match";
				}
				else {
					regerror(reti, &regex, msgbuf, sizeof(msgbuf));
					fprintf(stderr, "Regex match failed: %s\n", msgbuf);
					cout << "Error";
					return 1;
				}
				
				
				j = i+1;
			}
		}
		
		// если test == true вывести False
		if (test) {
			cout << "False";
		}
		cout << endl;
		//cout << endl << line << endl;
	}
	return 0;
}