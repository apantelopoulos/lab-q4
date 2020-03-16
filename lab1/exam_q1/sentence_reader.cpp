#include "sentence_reader.hpp"

SentenceReader::SentenceReader(istream &_src)
    : src(_src)
{
  // If you wish you can add things here
}

vector<string> SentenceReader::next()
{

vector <string> res;

string y;

char a;
string b;
string temp;

while(cin){
//for(int i=0; i<5; i++){

	a = src.get();
	temp.push_back(a);
	if(temp=="."|temp=="?"){
		y=b;
		res.push_back(y);
		a = src.get();
		break;
	}
	else if/*(temp!=" ")*/(temp=="a"|temp=="b"|temp=="c"|temp=="d"|temp=="e"|temp=="f"|temp=="g"|temp=="h"|temp=="i"|temp=="j"|temp=="k"|temp=="l"|temp=="m"|temp=="n"|temp=="o"|temp=="p"|temp=="q"|temp=="r"){
		b.push_back(a);
		temp="";
	}
	else if(temp==" "){

		y=b;
		if(y!=""){res.push_back(y);}
		b="";
		temp="";

	}

	else{

		y=b;
		if(y!=""){res.push_back(y);}
		b="";
		temp="";
		a=src.peek();
		temp.push_back(a);
		if(isspace(src.peek())){a=src.get();}
		temp="";
	}


}



return res;

}


/*
int main(){

SentenceReader a(cin);

vector<string>sents = a.next();

//cout << sents[0] << endl << sents[1] << endl;

cout << sents.size();
}


*/

//gtxs
