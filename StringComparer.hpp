#ifndef STRINGCOMPARER_HPP
#define STRINGCOMPARER_HPP

#include <string>
using namespace std;

class StringComparer {

	private:
		int numStrings;
		string* strings;
		char** similarities;

	public:
		StringComparer();
		~StringComparer();
		void readStrings();
		void compareStrings();
		void outputResults();

};
#endif
