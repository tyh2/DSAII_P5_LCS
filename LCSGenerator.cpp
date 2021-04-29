#include "LCSGenerator.hpp"
#include <iostream>
#include <fstream>
#include <string>

LCSGenerator::LCSGenerator() {

	stringX = "";
	stringY = "";
	m = 0;
	n = 0;
	count = 0;
}

LCSGenerator::LCSGenerator(string x, string y, int i, int j) {
	
	this->stringX = x;
	this->stringY = y;
	this->m = i;
	this->n = j;
	count = 0;

	c = new int*[m+1];
	for(int i = 0; i <= m; i++) {
		c[i] = new int[n+1];
	}

}

LCSGenerator::~LCSGenerator() {

	for(int i = 0; i <= m; i++) {
		delete[] c[i];
	}

	delete[] c;
}

void LCSGenerator::readStrings() {

	ifstream in;
	in.open("twoStrings.txt");

	if(in.is_open()) {
		getline(in, stringX);
		getline(in, stringY);
	}

	in.close();

	m = stringX.size();
	n = stringY.size();

	c = new int*[m+1];
	for(int i = 0; i <= m; i++) {
		c[i] = new int[n+1];
	}
}

void LCSGenerator::LCS() {

	for(int i = 1; i <= m; i++) {
		c[i][0] = 0;
	}
	
	for(int j = 0; j <= n; j++) {
		c[0][j] = 0;
	}

	for(int i = 1; i <= m; i++) {
		for(int j = 1; j <= n; j++) {
			if(stringX.at(i-1) == stringY.at(j-1)) {
				c[i][j] = c[i-1][j-1] + 1;
			}
			else {
				if(c[i-1][j] >= c[i][j-1]) {
					c[i][j] = c[i-1][j];
				}
				else {
					c[i][j] = c[i][j-1];
				}
			}
		}
	}
}

void LCSGenerator::getLCSLength(int i, int j) {
	
	  if(i == 0 || j == 0) {
                return;
        }
        else if(stringX.at(i) == stringY.at(j)) {
                getLCSLength(i-1, j-1);
		count++;
        }
        else if(c[i-1][j] >= c[i][j-1]) {
                getLCSLength(i-1, j);
        }
        else {
                getLCSLength(i, j-1);
        }
}

void LCSGenerator::printLCS(int i, int j) {

	if(i == 0 || j == 0) {
		return;
	}
	else if(stringX.at(i) == stringY.at(j)) {
		printLCS(i-1, j-1);
		cout << stringX.at(i-1);
	}
	else if(c[i-1][j] >= c[i][j-1]) {
		printLCS(i-1, j);
	}
	else {
		printLCS(i, j-1);
	}

}

int LCSGenerator::getCount() {
	return count;
}

void LCSGenerator::outputResults() {

	cout << "LCS: " << endl;
       	printLCS(m-1,n-1);
	cout << endl;
	getLCSLength(m-1,n-1);
        cout << "Length: " << count << endl << endl;
}
