//gitHub sucks ass
#include "Complex.h"
#include <iostream>
#include <istream>
#include <fstream>
#include <list>

#define VECTOR true
#define CARTESIAN false
#define outFile "complexData.txt"

using namespace std;

void eraseData(ofstream&,string);
bool initStreams(ifstream&, ofstream&, string file);
int main(){

	ifstream in;
	ofstream out;
	bool quit = false;
	/*eraseData(out,outFile);*/

	if(initStreams(in,out,outFile)){
		cerr<<"Stream error";
		return 1;
	}
	while(!quit){
		cout<<"\nEnter complex number:\n";
		string *input = new string;
		getline(cin,*input);
		cin.clear();
		Complex *c = new Complex(*input);
		c->update(VECTOR);
		c->print(VECTOR);
		delete input;
		delete c;
	}
	Complex *c = new Complex("0.5 j-0.866");
	//c->update(CARTESIAN);
	//c->print(CARTESIAN);
	cout<<'\n';
	c->update(VECTOR);
	c->print(VECTOR);

	out.close();
	//eraseData(out,outFile);

	return 0;
}
bool initStreams(ifstream &in, ofstream& out, string File){
	return (!in && !out);
}
void eraseData(ofstream &out,string File){

	if(out)
		out.close();
	out.open(File);
	out<<' ';
	out.close();
}



























