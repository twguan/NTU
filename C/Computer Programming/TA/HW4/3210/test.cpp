#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class book{
public:
    string name;
    int price;
};

int main(){   
    book *list = new book[500];
    list[0].name = "mama";
    cout << list[0].name;
}
