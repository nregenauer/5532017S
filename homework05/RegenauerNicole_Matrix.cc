#include <iostream>
using namespace std;

class Matrix {
private:
	double* m; // points to a single vector of double...
	int rows;
	int cols;
public:
	// write constructor, destructor, copy constructor, operator =
	//constructor v1
	Matrix(int rows, int cols) : rows(rows), cols(cols) {
		m = new double[rows*cols];
		for(int i=0; i < rows*cols; ++i){
			m[i]=0;
		}
	}
	//constructor v2
	Matrix(int rows, int cols, double value) : rows(rows), cols(cols) {
		m = new double[rows*cols];
		for(int i=0; i < rows*cols; ++i){
			m[i]=value;
		}
	}
	//destructor
	~Matrix() {
		delete [] m;
	}
	//copy constructor 1
	Matrix(const Matrix& orig) : m(new double[orig.rows*orig.cols]), rows(orig.rows),cols(orig.cols){
		for(int i=0;i<rows*cols;++i){
			m[i]=orig.m[i];
		}
	}
	//operator =
	Matrix& operator =(const Matrix& orig){
		if(this!=&orig){
			delete [] m;
			m=new double[orig.rows*orig.cols];
			rows=orig.rows;
			cols = orig.cols;
			for(int i=0;i<rows*cols;++i){
				m[i]=orig.m[i];
			}
		}
		return *this;
	}


	friend ostream& operator <<(ostream& s, Matrix m1){
		for(int j=0;j<m1.rows;j++){
			for(int i=0; i<m1.cols; i++){
				s << m1.m[i*j + i] << " ";
			}
			cout << endl;
		}
			return s;
	}

	double  operator ()(int i, int j) const {
		return m[i*j+j];
	}
	double&  operator ()(int i, int j) {
		return m[i*j + j];
	}
	Matrix(Matrix&& orig) {
    m = orig.m;
		rows = orig.rows;
		cols = orig.cols;
		orig.m = nullptr;
	}
  friend Matrix operator +(const Matrix& a, const Matrix& b) {
		if(a.rows!=b.rows||a.cols!=b.cols){
			cout << "Cannot add matrices, returning first parameter by default\n";
		}
		else{
		Matrix ans(a.rows,a.cols);
		for(int j=0;j<a.rows;j++){
			for(int i=0; i<a.cols; i++){
				ans(j,i) = a.m[i*j + i] + b.m[i*j + i];
			}
		}
		return ans;
	}
	}

};

int main() {
	Matrix m1(3, 4); // zeros
	Matrix m2(2, 3, 1.5); // fill with 1.5
  cout << m1 << '\n';
	/*
		0   0   0   0
    0   0   0   0
    0   0   0   0
	*/
	cout << m1(0, 1) << '\n';
	m1(0,1) = 5.5;
  Matrix m3 = m1 + m1;
	Matrix m4 = m3;  //copy constructor
	cout << m4 << '\n';
	m4(1,2) = 11.2;
	m3 = m4; // operator =
	cout << m3 << endl;
}
