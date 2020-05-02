#include <iostream>
#include <vector>
#include <string>

using namespace std;

istream &operator>>(istream &src, vector<string> &words){
  string s;
  while(cin){
    char a = src.get();
    if(a=='.'){
      words.push_back(s);
      break;

    }
    s.push_back(a);
    if(src.peek()==' '){
        words.push_back(s);
        s="";
        a = src.get();
    }

    //  words.push_back(s);
      //src>>s;
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
