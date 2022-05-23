#include <iostream>
using namespace std;    // replace std::


int main(){
    // std::cout << "Hello\n";
    cout << "Hello\n";

    // dinamic mamory allocation
    int *ptr = new int[100];    // equals to malloc(sizeof(int)*100)
    int *num = new int(10);     // malloc one int, init as 10
    cout << "*num = " << *num << endl;
    
    // delete the malloc
    delete num;
    delete [] ptr;
    return 0;
}