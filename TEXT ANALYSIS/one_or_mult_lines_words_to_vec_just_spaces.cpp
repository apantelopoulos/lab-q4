#include <iostream>
#include <vector>
#include <string>

using namespace std;

istream &operator>>(istream &src, vector<string> &words){
  string s;
  src>>s;
  while(!cin.fail()){
      words.push_back(s);
      src>>s;
  }

}

int main(){
  string s;
  vector<string> words;

  cin>>words;

  cout << words.size() << endl;
  for(int i=0;i<words.size();i++){
      cout << words[i] << endl;
  }


}
