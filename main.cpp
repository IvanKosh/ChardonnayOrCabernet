/* 
 * File:   main.cpp
 * Author: bat
 *
 * Created on 17 Сентябрь 2015 г., 19:13
 */

#include <iostream>
#include <fstream>
#include <string>

using namespace std;


short ci, cj, cl, ck, count;
bool check_sub_in_word(string sub, string word) {
	//cout << sub << " in " << word << endl;
	cl = word.length();
	ck = sub.length();
	count = 0;
	// если буква из слова есть в под строке, то ++ и букву в подстроке на пробел
	
	for (ci = 0; ci < cl; ci++) {
		for (cj = 0; cj < ck; cj++) {
			if (word[ci] == sub[cj]) {
				sub[cj] = ' ';
				count ++;
				break;
			}
		}
	}
	return count >= ck;
}

int main(int argc, char *argv[]) {
	ifstream stream(argv[1]);
	string line, temp;
	short i, j, l;
	bool test;
	while (getline(stream, line)) {
		l = line.length();
		for (i = l; line[i] != '|'; i--) {}
		
		//cout << line[i];
		
		temp = line.substr(i+2, l-i+2);
		
		//cout << temp;
		
		l = i;
		j = 0;
		test = true;
		for (i = 0; i < l; i++) {
			if (line[i] == ' ') {
				if (check_sub_in_word(temp, line.substr(j, i-j))) {
					if (test) {
						cout << line.substr(j, i-j);
					}
					else {
						cout << ' ' << line.substr(j, i-j);
					}
					test = false;
				}
				
				//cout << '[' << line.substr(j, i-j) << ']';
				j = i+1;
				
			}
		}
		
		if (test) {
			cout << "False";
		}
		cout << endl;
		//cout << line << endl;
	}
	return 0;
}