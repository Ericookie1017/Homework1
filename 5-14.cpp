#include <iostream>
#include <cmath>

using namespace std;
#define reviewers 4
#define movie 6
void scan_score(int[]);
double predict(const int[], const int[]);
void print_answer(const int[], const int[]);
int main() {
	/* 專家的評分表 */
	int reviewers_score[reviewers][movie] = {
		{ 3, 1, 5, 2, 1, 5 },
		{ 4, 2, 1, 4, 2, 4 },
		{ 3, 1, 2, 4, 4, 1 },
		{ 5, 1, 4, 2, 4, 2 }
	};
	int users_score[movie] = { -1, -1, -1, -1, -1, -1 };
	scan_score(users_score);

	int closest_reviewer = 0;
	double min_distance = predict(reviewers_score[0], users_score);
	for (int i = 1; i < reviewers; i++) {
		double distance = predict(reviewers_score[i], users_score);
		if (distance < min_distance) {
			min_distance = distance;
			closest_reviewer = i;
		}
	}

	print_answer(reviewers_score[closest_reviewer], users_score);

	return 0;
}

void scan_score(int score[]) {
	/* 假設輸入-1代表跳過 */
	cout << "You can only rate three of these movie." << endl;
	for (int i = 0; i < movie; i++) {
		cout << "Enter your score for movie " << 100 + i << "(-1 to skip):";
		cin >> score[i];
	}
	/* 測試是否輸入3個分數 */
	int test = 0;
	for (int i = 0; i < movie; i++) {
		if (score[i] == -1) {
			test++;
		}
	}
	if (test != 3) {
		cout << "You don't enter the right form,please enter again!";
		return scan_score(score);
	}
	return;
}

double predict(const int reviewer[], const int user[]) {
	/* 分別計算與專家的評分差距 */
	double distance = 0;
	for (int i = 0; i < movie; i++) {
		if (user[i] != -1) {
			distance += pow(user[i] - reviewer[i], 2);
		}
	}
	return sqrt(distance);
}

void print_answer(const int reviewer[], const int user[]) {
	cout << "After predicting:" << endl;
	for (int i = 0; i < movie; i++) {
		if (user[i] == -1) {
			cout << "Movie " << 100 + i << " is " << reviewer[i] << endl;
		}
	}
	return;
}