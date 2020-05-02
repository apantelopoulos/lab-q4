#include <iostream>
#include <vector>
#include <string>

using namespace std;

istream &operator>>(istream &src, vector<vector<string>> &words){
  int i=0;
  //words.resize(10);
  vector<string> tmp;
  string s;
  src>>s;
  while(!cin.fail()){
      tmp.push_back(s);
      if(s.back()=='.'){
      words.push_back(tmp);
      tmp.resize(0);
      }
      src>>s;
  }

}

int main(){
  string s;
  vector<vector<string>> words;

  cin>>words;


for(int a=0; a<words.size();a++)
  for(int i=0;i<words[a].size();i++){
      //if(words[a][i].back()=='.'|words[a][i].back()==','){
      if(!isalpha(words[a][i].back())){
      words[a][i].back()='\0';
    }
  }

/*/////TESTS//////
  cout << words.size() << endl;
  for(int a=0;a<words.size();a++){
    for(int i=0;i<words[a].size();i++){
      cout << words[a][i] << " ";
  }
  cout << endl;
}
*//////////////////


}
