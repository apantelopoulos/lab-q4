#include <iostream> 
#include <vector>
#include <string>
#include "bit_utils.hpp"

using namespace std;

int main(int argc, char **argv){
	double clock_rate;
	double energy_per_flip;
	string arg;
	if(argc == 1){
		clock_rate = 100e6;
		energy_per_flip = 1e-12;
	}
	else{
	arg = argv[1];
	clock_rate = stod(arg);
	arg = argv[2];
	energy_per_flip = stod(arg);
	}

//	cout << clock_rate << " " << energy_per_flip <<endl;

vector <vector<bool>> lines;
vector <bool> temp = read_bit_vector(cin);
while(temp.size()!=0){

	lines.push_back(temp);
	temp = read_bit_vector(cin);
}

//cout << lines.size() << endl;

int flips = 0;
for(int i=0; i<lines.size()-1; i++){
	for(int j=0; j<lines[0].size(); j++){

		if(lines[i][j] != lines[i+1][j]){
			flips = flips + 1;
		}
	}
}

//cout << flips << endl;


int cycles = lines.size();

int signals = lines[0].size();

double power = (flips*energy_per_flip)/(cycles / clock_rate);

cout << signals << endl;
cout << cycles << endl;
cout << flips << endl;
cout << power << endl;

}
