#include "StringComparer.hpp"
#include "LCSGenerator.hpp"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

StringComparer::StringComparer() {

	readStrings();
}

StringComparer::~StringComparer() {

	delete[] strings;

	for(int i = 0; i < numStrings; i++) {
		delete[] similarities[i];
	}

	delete[] similarities;
}

void StringComparer::readStrings() {

	ifstream in;
	in.open("multiStrings.txt");

	if(in.is_open()) {
		in >> numStrings;
		strings = new string[numStrings];

		similarities = new char*[numStrings];
		for(int i = 0; i < numStrings; i++) {
			similarities[i] = new char[numStrings];
		}
		
		string temp = "";
		getline(in, temp);
		for(int i = 0; i < numStrings; i++) {
			getline(in, strings[i]);
		}
	}
}

void StringComparer::compareStrings() {

	int shortLen = 0;
	int longLen = 0;
	for(int i = 0; i < numStrings; i++) {
		for(int j = 0; j < numStrings; j++) {

			if(j <= i) {
				similarities[i][j] = '-';
			}
			else {
				if(strings[i].size() > strings[j].size()) {
					longLen = strings[i].size();
					shortLen = strings[j].size();
				}
				else {
					longLen = strings[j].size();
					shortLen = strings[i].size();

				}
				
				
				LCSGenerator lcs(strings[i], strings[j], strings[i].size(), strings[j].size());
				lcs.LCS();	
				lcs.getLCSLength(strings[i].size()-1, strings[j].size()-1);
				int lcsLength = lcs.getCount();
				double shortToLong = static_cast<double>(shortLen)/longLen;
				double lcsToShort = static_cast<double>(lcsLength)/shortLen;

				if(shortToLong >= 0.9 && lcsToShort >= 0.9) {
					similarities[i][j] = 'H';
				}
				else if(shortToLong >= 0.8 && lcsToShort >= 0.8) {
					similarities[i][j] = 'M';
				}
				else if(shortToLong >= 0.6 && lcsToShort >= 0.5) {
					similarities[i][j] = 'L';
				}
				else {
					similarities[i][j] = 'D';
				}
				
			}
			
		}
	}

}

void StringComparer::outputResults() {

	cout << "String Comparisons" << endl;
	for(int i = 0; i < numStrings; i++) {
		cout << "    " << (i + 1);
	}
	cout << endl;

	for(int i = 0; i < numStrings; i++) {
		
		cout << (i+1) << "   ";

		for(int j = 0; j < numStrings; j++) {
			cout << similarities[i][j] << "    ";
		}
		cout << endl;
	}		
}
