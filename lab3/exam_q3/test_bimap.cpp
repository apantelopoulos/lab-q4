#include "bimap.hpp"
#include <iostream>
#include <string>

using namespace std;


int main(){

BiMap *info = BiMap_create();

BiMap_insert(info, "ap1919", 1919);
BiMap_insert(info, "ep519", 519);
BiMap_insert(info, "kt1289", 1289);
BiMap_insert(info, "ep519", 1519);


if(BiMap_size(info) == 3){

	cout << "Insert Function OK" << endl;
}
//cout << BiMap_size(&info) << endl;

int x;

BiMap_lookup(info, "ep519", x);
BiMap_lookup(info, "wrong", x);


if(x == 519){

	cout << "Lookup with string Function OK" << endl;
}

string y;

BiMap_lookup(info, 1919, y);
BiMap_lookup(info, 123, y);

if(x == 519){

	cout << "Lookup with id Function OK" << endl;
}


}

