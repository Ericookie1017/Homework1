#include <iostream>

using namespace std;
#define PIN 5
#define NUM 10
void random_number(int[]);
void print_number(const int[]);
void scan_pin(int[]);
bool check_pin(const int[], const int[], const int[]);

int main() {
	int pin[PIN] = { 1,2,3,4,5 };	/* 真實密碼 */
	int random_num[NUM] = { 0 };	/* 數字對應的隨機數 */
	random_number(random_num);		/* 隨機選數 */
	print_number(random_num);		/* 輸出隨機數對應表 */
	int input_pin[PIN] = {0};
	scan_pin(input_pin);
	if (check_pin(pin, input_pin, random_num)) {
		cout << "You are pass!";
	}
	else {
		cout << "Stupid!";
	}

	return 0;
}
void random_number(int random[]) {
	srand(time(0));
	for (int i = 0; i < 10; i++) {
		random[i] = rand() % 3 + 1;
	}
	return;
}
void print_number(const int random[]) {
	cout << "PIN: ";
	for (int i = 0; i < 10; i++) {
		cout << i << " ";
	}
	cout << endl << "NUM: ";
	for (int i = 0; i < 10; i++) {
		cout << random[i] << " ";
	}
	return;
}

void scan_pin(int input_pin[]) {
	cout << "You need enter the number corresponding to the password." << endl;
	cout << "PIN:";
	for (int i = 0; i < PIN; i++) {
		cin >> input_pin[i];
	}
	return;
}

bool check_pin(const int pin[], const int input[], const int random[]) {
	for (int i = 0; i < PIN; i++) {
		if (random[pin[i]] != input[i]) {
			return false;
		}
	}
	return true;
}