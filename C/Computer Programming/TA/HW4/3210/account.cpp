#include "account.h"
#include <iostream>
 
using namespace std;
 
Account::Account(int initCash) : investmentCount(0), cash(initCash), investments(new Investment[50]())
{}
 
Account::~Account() throw(){
    delete [] this->investments;
}
 
void Account::buy(Investment *datalist, size_t dataLength, int index){
   // TODO: 實作買入動作
    if (dataLength < index)
        cout << "index out of range" << endl;
    else{
        this->cash -= datalist[index].low;
        this->investmentCount++;
    }
}
 
void Account::sellLast(const int currentPrice){
   // TODO: 實作賣出最近買入商品
    if (this->investmentCount < 1)
        cout << "no investment" << endl;
    else {
        this->cash += currentPrice;
        this->investmentCount--;
    }
}
 
void Account::list(){
   // TODO: 實作列出投資紀錄
    for (int i = 0; i < this->investmentCount; i++){
        cout << this->investments[i].date << " "
             << this->investments[i].low << " "
             << this->investments[i].high << endl;
    }
}
 
int Account::getCash(){
    return this->cash;
}