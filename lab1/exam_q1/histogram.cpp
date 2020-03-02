#include "histogram.hpp"


int histogram_get_count(const vector<pair<string,int>> &counts, const string &word)
{
    for(unsigned i=0; i<counts.size(); i++){
        if(counts[i].first == word){
            return counts[i].second;
        }
    }
    return 0; // Word never appeared
}


void histogram_add(vector<pair<string,int>> &counts, const string &word){

int check = 0;
for(int i=0; i<counts.size(); i++){

	if(counts[i].first == word){

		counts[i].second +=1;
		check=1;
	}
}

if(check==0){
int a = counts.size();
counts.resize(a+1);

counts[a].first = word;
counts[a].second = 1;
}

}





void histogram_add(map<string,int> &counts, const string &word){

counts[word] = counts[word] + 1;


}

