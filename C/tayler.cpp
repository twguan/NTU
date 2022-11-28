#include <iostream>
using namespace std;

int answer1, answer2, answer3;

class Time
{
public:
	void setTime();
	void printTime();
private:
	int hour = 1, minute = 1, second = 1;
};

void Time::setTime()
{
	int h, m, s;
	cout << "Please enter hour (integer between 0-23):";
	cin >> h;
	cout << "Please enter minute (integer between 0-59):";
	cin >> m;
	cout << "Please enter second (integer between 0-59):";
	cin >> s;
	answer1 = h;
	answer2 = m;
	answer3 = s;
    hour = h;
    minute = m;
    second = s;
}

void Time::printTime()
{
	cout << "The time is: " << hour << ":" << minute << ":" << second << endl;
}

int main()
{
	Time x;
    x.printTime();
	x.setTime();
	x.printTime();
	return 0;
}