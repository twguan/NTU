#include <iostream>
#include "investment.h"
#include <cstring>
#include <cstdlib>

using namespace std ;

Investment::Investment(): date(""), high(0), low(0){
}
 
Investment::Investment(string data){
    // TODO: 需實做建構子
    char s[128] ;
    
    strcpy(s , data.c_str()) ;
    
    char *p ;
    p = strtok(s , ",") ;
    
    date = p ;
    
    p = strtok(NULL , ",") ;
    low = atoi(p) ;
    
    p = strtok(NULL , ",") ;
    high = atoi(p) ;
    
    //cout << date << " " << low << " " << high << endl ;
}


