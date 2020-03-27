#include <iostream> 
#include <vector>
#include <string>
#include "bit_utils.hpp"
#include <cassert>
#include <string>
#include <fstream>

using namespace std;

int main(int argc, char **argv){
	double clock_rate = 0;
	double energy_per_flip = 0;
	assert(argc >= 3);
	string arg;
	arg = argv[1];
	clock_rate = stod(arg);
	arg = argv[2];
//	energy_per_flip = stod(arg);

	assert(clock_rate != 0);
//	assert(energy_per_flip != 0);

//	cout << clock_rate << " " << energy_per_flip <<endl;

vector <double> e;
string line;
ifstream myfile(arg);
if(myfile.is_open()){
	while(getline(myfile,line)){
		e.push_back(stod(line));
	}
	myfile.close();
}

/////////////////////////////////////////////////////////////////////////////

vector <vector<bool>> lines;
vector <bool> temp = read_bit_vector(cin);
while(temp.size()!=0){

	lines.push_back(temp);
	temp = read_bit_vector(cin);
}

//cout << lines.size() << endl;

int flips_all = 0;
for(int i=0; i<lines.size()-1; i++){
	for(int j=0; j<lines[0].size(); j++){

		if(lines[i][j] != lines[i+1][j]){
			flips_all = flips_all + 1;
		}
	}
}

//cout << flips_all << endl;


int cycles = lines.size();

int signals = lines[0].size();

/*
vector <double> e;
e.resize(signals);
for(int a =0; a<signals; a++){
	e[a] = energy_per_flip*(a+1);
}
*/

vector <int> flips_for;
int flips = 0;
for(int i=0; i<lines[0].size(); i++){
        for(int j=0; j<lines.size()-1; j++){

                if(lines[j][i] != lines[j+1][i]){
                        flips = flips + 1;
                }
        }
flips_for.push_back(flips);
flips = 0;
}

//cout << lines[0][3] << lines[1][3] << lines[2][3] << endl;
//cout << flips_for[3] << endl;

double total_power = 0;
vector <double> pb_power;

for(int b=0; b<signals; b++){

	double tmp = (flips_for[b]*e[b])/(cycles / clock_rate);
	total_power = total_power + tmp; //(flips_for[b]*e[b])/(cycles / clock_rate);
	pb_power.push_back(tmp);

}

cout << signals << endl;
cout << cycles << endl;
cout << flips_all << endl;
cout << total_power << endl;

for(int c=0; c<signals; c++){

	cout << pb_power[c] << endl;

}

}
