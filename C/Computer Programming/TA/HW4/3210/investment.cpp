#include "investment.h"
#include <cstdlib>

Investment::Investment(): date(""), high(0), low(0){
}
 
Investment::Investment(string data){
    // TODO: 需實做建構子
    string s;
    size_t t = 0;
    t = data.find(',');
    string date;
    date.assign(data, 0, t);
    data.erase(0, t+1);

    t = data.find(',');
    s.assign(data, 0, t);
    int low = atoi(s.c_str());
    data.erase(0, t+1);

    t = data.find(',');
    s.assign(data, 0, t);
    int high = atoi(s.c_str());
}