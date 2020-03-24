#include <istream>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "bimap.hpp"
#include <stdlib.h>
using namespace std;

istream &operator>>(istream &src, BiMap *bm){

int x=0;
string y;

while(cin){

	src >> y;
	src.ignore(256, ' ');
	BiMap_insert(bm, y, x);
	x=x+1;
	}

}



int main(){

BiMap *info = BiMap_create();
cin >> info;

vector<pair<string,int>> words = BiMap_export_mappings(info);
vector<string> cmpr;



//cout << words[0].first << endl << words[1].first << endl <<  words[2].first << endl << words[3].first <<endl;

string b;
int check;
int a = 0;
cmpr.push_back(words[0].first);
for(int i=1;i<words.size()-1; i++){
        b = "@";
	check = 1;
	for(int j=0; j<i; j++){
               if(words[i].first==words[j].first){
		string temp = to_string(j);

		b.append(temp);
                cmpr.push_back(b);
		//a = a + 1;
		check = 0;
               	break;
                }
        }
if(check){
	cmpr.push_back(words[i].first);
	}

}

for(int k=0; k<cmpr.size(); k++){
	cout << cmpr[k] << " ";
}

cout << endl;


}
