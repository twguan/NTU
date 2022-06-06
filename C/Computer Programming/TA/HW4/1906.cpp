#include <iostream>

using namespace std;

class eCash{
    private:
        int money;

    public:
        eCash(){
            money = 0;
        }
        void store(int m){
            if (m <= 0){
                cout << "eCash: Please enter a number > 0." << endl;
                return;
            }
            money += m;
            cout << "eCash: You stored " << m << "." << endl;
        }
        void pay(int m){
            if (m > money){
                cout << "eCash: Insufficient balance." << endl;
                return;
            }
            if (m <= 0){
                cout << "eCash: Please enter a number > 0." << endl;
                return;
            }
            cout << "eCash: You spend " << m << "." << endl;
            money -= m;
        }
        void display(){
            cout << "eCash: You remaining " << money << "." << endl;
        }
};

int main(){
    eCash account;
    char order;
    int m;
    while(1){
        cin >> order;
        if (order == 'q'){
            cout << "eCash: Thank you. Bye Bye.";
            break;
        }
        else if (order == 's'){
            cin >> m;
            account.store(m);
        }
        else if (order == 'p'){
            cin >> m;
            account.pay(m);
        }
        else if (order == 'd'){
            account.display();
        }
    }
    return 0;
}