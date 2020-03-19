#include "bimap.hpp"
#include <map>
#include <iostream>

struct BiMap
{
	map<string,int> str2int;
	map<int,string> int2str; 
};

/* Create a new BiMap */
BiMap *BiMap_create()
{
    return new BiMap();
}

/* Free all resources assocated with the bimap */
void BiMap_destroy(BiMap *bm)
{
    delete bm;
}

/*  Inserts a mapping value1 <-> value2
    If either value1 or value2 already exists then to nothing and return false.
    Otherwise insert the value and return true.
*/
bool BiMap_insert(BiMap *bm, const string &value1, int value2)
{

bm->str2int.insert({value1, value2});
bm->int2str.insert({value2, value1});
}
/* Number of mappings in the data-structure */
unsigned BiMap_size(const BiMap *bm)
{
    return bm->str2int.size();
}

/* Lookup a mapping by string.
    If the mapping is found, return true and put integer into value2.
    Otherwise return false.
*/
bool BiMap_lookup(BiMap *bm, const string &value1, int &value2)
{
//    for(unsigned i=0; i<bm->mappings.size(); i++){
        if(bm->str2int[value1]!=0){
            value2 = bm->str2int[value1];
            return true;
        }

    return false;
}

/* Lookup a mapping by id.
    If the mapping is found, return true and put string into value2.
    Otherwise return false.
*/

bool BiMap_lookup(BiMap *bm, int value2, string &value1)
{
        if(bm->int2str[value2]!=""){
                value1 = bm->int2str[value2];
                return true;
        }
    return false;
}


/*

vector<pair<string,int>> BiMap_export_mappings(const BiMap *bm)
{
	vector<pair<string,int>> mappings;
	for(int i=0; i<BiMap_size(bm); i++){
		for(int j=0; j<2147483647; j++){
			if(bm->int2str[j]!=""){
				mappings[i].first = bm->int2str[j];
				mappings[i].second = j;
			}
		}
	}
return mappings;
}

*/

/*
int main(){

BiMap *info = BiMap_create();
BiMap_insert(info, "ap1919", 1919);
BiMap_insert(info, "ep519", 519);
BiMap_insert(info, "kt1289", 1289);
BiMap_insert(info, "ep519", 1519);


string y;
int x;

cin >> y;
BiMap_lookup(info, y, x);

cout << x <<endl;


}
*/
