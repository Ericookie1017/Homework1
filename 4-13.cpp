#include <iostream>

using namespace std;
double convertToMPH(int, int);
double convertToMPH(double);

int main() {
	int minute, second;		/* 讓用戶輸入 */
	cout << "Enter your speed(minute and second per mile):";
	cin >> minute >> second;
	double kph;
	cout << "Enter your speed(kilometers per hour):";
	cin >> kph;

	cout << "MPH = " << convertToMPH(minute, second) << endl;
	cout << "MPH = " << convertToMPH(kph) << endl;

	return 0;
}

double convertToMPH(int minute, int second) {
	double hour = minute / 60.0 + second / 3600.0;	/* 把單位換成英里/小時 */
	return (1 / hour);
}

double convertToMPH(double kph) {
	double mph = kph / 1.61;
	return mph;
}