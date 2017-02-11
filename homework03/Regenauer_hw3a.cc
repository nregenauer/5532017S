//Nicole Regenauer
//HW3a: Vec3d
//I pledge my honor that I have abided by the Stevens Honor System

#include <iostream>
using namespace std;

class Vec3d {
private:
	double xval,yval,zval;
public:
	Vec3d(double x=0.0, double y=0.0, double z = 0.0) : xval(x),yval(y),zval(z) {}
	//this is overloading the << operator to make it work for the Vec3d class
	//overloading is usually done by defining a friend function
	friend ostream& operator <<(ostream& s, Vec3d f){
		return s << '('<<  f.xval << ',' << f.yval << ','<<f.zval << ')';
	}

	//this is overloading the + operator to make it work for the Vec3d class
	//overloading is usually done by defining a friend function
	friend Vec3d operator +(Vec3d a, Vec3d b) {
		Vec3d ans(a.xval+b.xval,a.yval+b.yval,a.zval+b.zval);
		return ans;
	}

	//this is overloading the * operator
	//this overload is done as a method to allow us to make 2 definitions
	//since this is a method on a vec, we know what xval, yval, zval refer to
	Vec3d operator *(double d) const{
			Vec3d ans(xval*d,yval*d,zval*d);
			return ans;
	}

	//this is overloading the *operator again
	//this overload is done as a friend-> lets us change the order in which params are passed
	friend Vec3d operator *(double d,Vec3d a){
			Vec3d ans(a.xval*d, a.yval*d,a.zval*d);
			return ans;
	}

	//this is a method that is called on a constant fraction
	//since it is called as a method on a vec, we know what xval, yval, zval refer to
	Vec3d add (Vec3d two) const {
		Vec3d ans(xval+two.xval,yval+two.yval,zval+two.zval);
		return ans;
	}

	//this is a method that is called on a constant fraction
	//since it is called as a method on a vec, we know what xval, yval, zval refer to
	double dot(Vec3d b) const{
		double ans =xval*b.xval + yval*b.yval + zval*b.zval;
		return ans;
	}
};


int main() {
	const Vec3d a(1.0, 2, 2.5); //(1.0, 2.0, 2.5) (x,y,z)
	cout << a << '\n';
	Vec3d b(5.0);         //(5.0, 0.0, 0.0)
	Vec3d c = a + b;
	cout << c << '\n';
	Vec3d c2 = a.add(b);   // call a method
	cout << c2 << '\n';
	double d = a.dot(b); //  dot product = a.x*b.x + a.y*b.y + a.z*b.z
	cout << d << '\n';

	Vec3d e = a * 2;   //scalar multiplication
	cout << e << '\n';
	Vec3d f = 2 * a;   //scalar multiplication
	cout << f << '\n';
}
