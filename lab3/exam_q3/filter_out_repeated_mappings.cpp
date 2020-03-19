#include <iostream>
#include "bimap.hpp"
using namespace std;

istream &operator>>(istream &src, BiMap *bm){

int x;
string y;

src >> y; 
src.ignore(256, ' ');
src >> x;

BiMap_insert(bm, y, x);

}


int main(){

BiMap *info = BiMap_create();

//cin >> info;
while(!cin.fail()){
	cin >> info;
}

vector<pair<string,int>> mappings = BiMap_export_mappings(info);

for(int i=0; i<mappings.size(); i++){

	cout << mappings[i].first << " " << mappings[i].second << endl;

}

}



/*
int x;

BiMap_lookup(info, "asd", x); 

cout << x << endl;

cout << BiMap_size(info) << endl;
}
*/
