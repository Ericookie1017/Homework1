#include <iostream>

using namespace std;
#define ARRAYSIZE 6
void scan_grade(int[]);
void print_array(const int[]);

int main() {
	int array[ARRAYSIZE] = { 0 };	/* �Ψ��x�s0-5�����Ӽ� */
	scan_grade(array);
	print_array(array);

	return 0;
}

void scan_grade(int array[]) {
	/* ���Τ��Jgrade����-1 */
	int grade;
	do
	{
		cout << "Enter student's grade(-1 to stop):";
		cin >> grade;
		if (grade >= 0 && grade < ARRAYSIZE) {
			array[grade]++;
		}
		else if (grade == -1){
			break;
		}
		else {
			cout << "You enter the invalid number!";
		}
	} while (true);
	return;
}

void print_array(const int array[]) {
	for (int i = 0; i < ARRAYSIZE; i++) {
		cout << array[i] << " grade(s) of " << i << endl;
	}
	return;
}