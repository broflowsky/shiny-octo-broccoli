#include <string>
using namespace std;
class Complex{

	friend ostream& operator <<(ostream &out, const Complex &c);


	double *rNumber;
	double *iNumber;
	double *magnitude;
	double *angle;

public:
	~Complex();
	Complex(string);
	Complex();
	void update(bool);/**/// false vector, true cartesian
	void add(Complex*);/**/
	void substract(Complex*);/**/
	void multiplying(Complex*);/**/
	void division(Complex*);/**/
	void conjugate();/**/
	void print(bool);/**/// false vector, true cartesian
	void changeNumber(string*);
	void saveDataOutFile(ofstream&);
};
