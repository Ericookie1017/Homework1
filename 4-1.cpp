#include <iostream>

using namespace std;
void input(int&, int&);
char convert(int&, int&);
void output(int, int, char);

int main() {
	int hour, minute;
	char again = ' ';
	do {
		input(hour, minute);	/* 輸入小時與分鐘 */
		char symbol;
		symbol = convert(hour, minute);		/* 判斷是上午還是下午 */
		output(hour, minute, symbol);		/* 輸出 */
		cout << "Do you want to convert again(y to yes,n to no)?";
		cin >> again;
	} while (again == 'y');

	return 0;
}

void input(int& hour, int& minute) {
	bool valid = false;
	do {
		cout << "Enter the time that is 24-hour notation:";
		cin >> hour >> minute;
		valid = true;
		if (hour > 24 || hour < 0 || minute >= 60 || minute < 0) {
			valid = false;
			cout << "You enter the invalid time!" << endl;
		}
	} while (!valid);
}

char convert(int& hour, int& minute) {
	if (hour > 12) {
		hour -= 12;
		return 'P';
	}
	else if (hour == 12) {
		return 'P';
	}
	else {
		return 'A';
	}
}

void output(int hour, int minute, char symbol) {
	switch (symbol)
	{
		case 'A':
			cout << "By convert to 12-hour notation,the time is " << hour << ":" << minute << " A.M." << endl;
			break;
		case 'P':
			cout << "By convert to 12-hour notation,the time is " << hour << ":" << minute << " P.M." << endl;
			break;
	default:
		break;
	}
}