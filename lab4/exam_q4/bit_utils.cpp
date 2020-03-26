#include <string>
#include "bit_utils.hpp"

int total_bit_flips_in_word(uint64_t x, uint64_t y)
{

int count=0;
for(int i=0; i<64; i++){
	if(x%2 != y%2){
		count = count + 1;
	}
	x=x/2;
	y=y/2;

}

return count;

}

//////////////////////////////////////////////////////////

vector<int> bit_flip_positions_in_vector(const vector<bool> &a, const vector<bool> &b)
{

vector <int> indices;

for(int i=0; i<a.size(); i++){

	if(a[i]!=b[i]){
		indices.push_back(i);
	}
}

return indices;
}

/////////////////////////////////////////////////////////

vector<bool> read_bit_vector(istream &src)
{

vector <string> x;
char temp;
string tempp;
while(cin){

temp = src.get();
tempp = temp;
if(tempp=="0" | tempp=="1"){
x.push_back(tempp);
}
if(temp == '\n'){break;}

tempp = "";
}
/*
vector <int> y;
for(int i=0; i<x.size(); i++){

	y.push_back(stoi(x[i]));
}
*/
vector <bool> z;
for(int j=0; j<x.size(); j++){

	if(x[j]=="0"){
		z.push_back(false);
	}
	else{
		z.push_back(true);
	}

}
return z;

}


///////////////////////////////////////////////////////

void write_bits_in_word(uint64_t x, int w, ostream &dst)
{
int temp;
for(int i=0; i<w; i++){

	temp = x%2;
	dst << temp;
	x=x/2;
}



}
