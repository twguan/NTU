#include <iostream>
#include "account.h"

using namespace std ;

Account::Account(int initCash) : investmentCount(0), cash(initCash), investments(new Investment[50]())
{}
 
Account::~Account() throw(){
	delete [] this->investments;
}
 
void Account::buy(Investment *datalist , size_t dataLength , int index) {
	// TODO: ��@�R�J�ʧ@
	if (index > dataLength) {
		cout << "index out of range" << endl ;
	}
	else {
		cash -= datalist[index].low ;
	
		investments[investmentCount] = datalist[index] ;
		investmentCount++ ;
	}
}
 
void Account::sellLast(const int currentPrice){
	// TODO: ��@��X�̪�R�J�ӫ~
	if (investmentCount == 0) {
		cout << "no investment" << endl ;
	}
	else {
		cash += currentPrice ;
		
		Investment tmp ;
		investments[investmentCount] = tmp ;
	
		investmentCount-- ;
	}
}
 
void Account::list() {
	// TODO: ��@�C�X������
	if (investmentCount == 0) {
		cout << "no investment" << endl ;
	}
	else {
		for (int i = 0 ; i < investmentCount ; i++) {
			cout << investments[i].date << " " << investments[i].low << " " << investments[i].high << endl ;
		}
	}
}
 
int Account::getCash(){
    return this->cash;
}





