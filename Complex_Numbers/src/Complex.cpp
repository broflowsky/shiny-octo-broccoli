#include "Complex.h"

#include <cmath>
#include <iostream>
#include <iomanip>
using namespace std;

#define VECTOR true
#define CARTESIAN false

Complex::Complex(string number)
{
	rNumber = new double;
	iNumber = new double;
	magnitude = new double;
	angle= new double;
	changeNumber(&number);
}
Complex::Complex(){
	Complex("1 j1");
}
void Complex::changeNumber(string *numb)
{
	string a;
	size_t pos;
	size_t location = numb->find("j");
	if (location != string::npos)
	{
		/*try{
			if(numb->substr(location-1,1).compare("-")){
				throw "- sign before j";
				cout<<"error";
				cin>>a;
			}
			else cout<<"what";
		}
		catch(string &err){
			throw err;
		}*/
		*rNumber = stod(*numb, &pos);
		*iNumber =  stod(numb->substr(pos+2), &pos);
		this->update(VECTOR);
	}
	else
	{
		location = numb->find("<");
		if (location != string::npos)
		{
			*magnitude = stod(*numb, &pos);
			*angle = stod(numb->substr(pos+2), &pos);
			this->update(CARTESIAN);
		}
		else
			cout << "\nBAD INPUT!\n";

	}
}
void Complex::add(Complex *c){
	*this->rNumber += *c->rNumber;
	*this->iNumber += *c->iNumber;
	this->update(VECTOR);
}
void Complex::substract(Complex *c){
	*this->rNumber -= *c->rNumber;
	*this->iNumber -= *c->iNumber;
	this->update(VECTOR);
}
void Complex::multiplying(Complex *c){
	*this->magnitude *= *c->magnitude;
	*this->angle += *c->angle;
	this->update(CARTESIAN);
}
void Complex::division(Complex *c){
	*this->magnitude /= *c->magnitude;
	*this->angle -= *c->angle;
	this->update(CARTESIAN);
}
void Complex::conjugate(){
	*this->iNumber *= -1;
	this->update(VECTOR);
}
void Complex::print(bool which){
	if(!which)//printing in Cartesian form
		cout <<setprecision(10)<< *rNumber <<( (iNumber > 0) ? (" + j") : (" - j") )
		<< abs(*iNumber);

	//else vector form
	else cout << *magnitude << " <" << *angle;
}
void Complex::update(bool which){
	if(which){//updating the vector form
	*magnitude = hypot(*rNumber,*iNumber);
	*angle = atan( (*iNumber) / (*rNumber) ) *180/3.14;
	}
	else{
		*rNumber = *magnitude * (cos (*angle * 3.14/180) );
		*iNumber = *magnitude * (sin (*angle * 3.14/180) );
	}
}
void Complex::saveDataOutFile(ofstream &out){



}
ostream& operator <<(ostream &out, const Complex &c){

	out << *(c.rNumber)
		<<( (*(c.iNumber) > 0) ? (" + j") : (" - j") )
		<< abs(*(c.iNumber))<<endl;
	//out<<"worked.\n";
	return out;
}























