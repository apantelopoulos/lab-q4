#include <iostream>
#include <vector>
#include <string>

using namespace std;

istream &operator>>(istream &src, vector<vector<string>> &words){
  string s;
  words.resize(1000);
  int i = 0;
  while(cin){
    if(src.fail()){break;}
    char a = src.get();
    if(a=='.'|a==' '|a==','){
        if(a==','){
          src.ignore(256,' ');
          words[i].push_back(s);
          s="";
        }

        if(a==' '){
          words[i].push_back(s);
          s="";
        }

        if(a=='.'){
          words[i].push_back(s);
          i++;
          s="";
          src.ignore(256,' ');
        }
    }
    else{s.push_back(a);}
}
words.resize(i);
}

int main(){
  string s;
  vector<vector<string>> words;

  cin>>words;

/*/////////////TESTS////////////
*/  cout << words.size() << endl;
  for(int a=0;a<words.size();a++){
    for(int i=0;i<words[a].size();i++){
      cout << words[a][i] << " ";
  }
  cout << endl;
}
/*
*//////////////////////////////


}
