/*Nicole Regenauer
HW4a: BitMap
I pledge my honor that I have abided by the Stevens Honor System
Bresenham's line algorithm obtained from Wikipedia:
https://en.wikipedia.org/wiki/Bresenham's_line_algorithm */

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

class Bitmap {
private:
	enum { ROWS = 30, COLS = 40 };
	int a[ROWS][COLS];
	int initial_value;
public:
  Bitmap(int initial_value = 0) {
		for (int i = 0; i < ROWS; i++)
			for (int j = 0; j < COLS; j++)
				a[i][j] = initial_value;
	}
	void horizLine(int row, int col1, int col2, int color){
				for(int i=0; i < (col2 - col1); i++){
					a[row][col1+i]=color;
				}
	}

	void vertLine(int col, int row1, int row2, int color){
				for(int i=0; i < (row2-row1); i++){
					a[row1+i][col]=color;
				}
	}

	void rect(int xval, int yval, int width, int height, int color){
		for(int i=0; i< width; i++){
			for(int j=0; j<height; j++){
				a[yval+j][xval+i] = color;
			}
		}
	}

	void line(int x1, int y1, int x2, int y2, int color){
		if(x1>x2){
			int temp = x1;
			x1 = x2;
			x2 = temp;
		}
		if(y1>y2){
			int temp = y1;
			y1=y2;
			y2=temp;
		}
		int delx = x2 - x1;
		int dely = y2 - y1;
		double delerr = abs(double(dely)/double(delx));
		double error = delerr - 0.5;
		int y = y1;
		for(int i=x1; i <= x2; i++){
			a[y][i]=color;
			error+=delerr;
			if(error>=0.5){
				y=y+1;
				error=error-1.0;
			}
		}
	}

	friend ostream& operator <<(ostream& s, Bitmap b){
		for(int i=0; i < ROWS; i++){
			for(int j=0;j<COLS;j++){
					s << setw(3) << b.a[i][j] << ' ';
			}
					s << '\n';
		}
		return s;
	}

};

int main() {
	Bitmap b1;
	Bitmap b2(3);
	// no sizes yet...	Bitmap b3(100,200);
	// each method has a last parameter (color) which is an integer (32-bit)
	b2.horizLine(5, 1, 27, 99); // row=5, col 1 to 27, set every pixel to 99
	b2.vertLine(19, 5, 20, 45); // col 19, row 5 to 20, set every pixel to 45
  b2.rect(9,9, 5, 8, 205); // x=9, y = 9, w=5, h=8, set every pixel to 205
	b2.line(28, 7, 8, 25, 92); // diagonal line using Bresenham, set every pixel to 92
	cout << b2;
}
