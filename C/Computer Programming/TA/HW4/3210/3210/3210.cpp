#include <iostream>
#include <string>
#include <fstream>
 
#include "investment.h"
#include "account.h"

using namespace std ;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	ifstream file("gold_price.csv") ;
    Investment *dataList = new Investment[100]() ;
    Account account(10000) ;
 
    size_t dataLength = 0 ;
    while (!file.eof()) {
        string line ;
        file >> line ;
        if (line.length() == 0) {
            continue ;
        }
 
        Investment investment(line) ;
        dataList[dataLength++] = investment ;
    }
    file.close() ;
 
    char command = 0 ;
    cin >> command ;
    
    while (command != 'q') {
        if (command == 'b') {
            int index = 0 ;
            cin >> index ;
            // 禦秈戈index
            account.buy(dataList , dataLength, index) ;
        }
		else if (command == 's') {
            // 芥程穝ら程蔼基
            account.sellLast(dataList[dataLength-1].high) ;
        }
		else if (command == 'l') {
            // ┮Τ畐Α(丁)()(讽ら程基)()(讽ら程蔼基)(传︽)
            account.list() ;
        }
		else if (command == 'c') {
            // ヘ玡瞷(俱计)
            cout << account.getCash() << endl ;
        }
 
        cin >> command ;
    }
 
    delete [] dataList;
 
    return 0;
	
	
	
	
	
	return 0;
}
