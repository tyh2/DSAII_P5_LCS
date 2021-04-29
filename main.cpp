#include "LCSGenerator.hpp"
#include "StringComparer.hpp"

int main() {

	LCSGenerator lcs;
	lcs.readStrings();
	lcs.LCS();
	lcs.outputResults();

	StringComparer sc;
	sc.compareStrings();
	sc.outputResults();

	return 0;
}
