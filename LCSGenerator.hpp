#ifndef LCSGENERATOR_HPP
#define LCSGENERATOR_HPP
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
class LCSGenerator {

	private:
		string stringX;
		string stringY;
		int** c;
		int m;
		int n;
		int count;
		string lcsString = "";
	public:
		LCSGenerator();
		LCSGenerator(string x, string y, int i, int j);
		~LCSGenerator();
		void readStrings();
		void LCS();
		void getLCSLength(int i, int j);
		void printLCS(int i, int j);
		int getCount();
		void outputResults();
};
#endif
