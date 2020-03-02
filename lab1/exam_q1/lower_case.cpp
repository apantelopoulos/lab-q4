#include "lower_case.hpp"

using namespace std;

string lower_case(const string &x)
{
    // IMPLEMENT ME

	string y = x;
	for_each(y.begin(), y.end(), [](char &c){

		c = tolower(c);
	});

	return y;

}

