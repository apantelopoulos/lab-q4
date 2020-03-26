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

vector<bool> read_bit_vector(istream &src)
{
    // TODO
}

void write_bits_in_word(uint64_t x, int w, ostream &dst)
{
    // TODO
}
