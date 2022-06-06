#include <iostream>
#include "square.h"

using namespace std;

Square::Square() {
	Length = 0;
}
Square::Square(int n) {
	Length = n;
}
int Square::area(){
	int area = Length * Length;
	return area;
}
int Square::getLen(){
	return Length;
}
void Square::setLen(int n){
	if (n >= 1)
		Length = n;
	else{
		Length = 1;
		cout << "len setting error" << endl;
	}
}

int cmpSquare(Square &s1, Square &s2){
	if (s1.Length == s2.Length)
		cout << "1==2" << endl;
	else if (s1.Length > s2.Length)
		cout << "1>2" << endl;
	else
		cout << "1<2" << endl;
}
