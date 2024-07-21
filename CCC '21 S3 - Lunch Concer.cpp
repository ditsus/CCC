#include <iostream>
using namespace std;

long long int N, high, low, mid, PWD[0][0], time1, time2, time3, tempPos, pos;

int main() {
	long long int N, high = 0, low = 0, mid;
	cin >> N;

	long long int PWD[N][3];

	for (long long int i = 0; i < N; i++) {
		cin >> PWD[i][0] >> PWD[i][1] >> PWD[i][2];	
		if ((PWD[i][0] + PWD[i][2]) > high) {
			high = PWD[i][0] + PWD[i][2];
		}
	}
	
	while (high >= low) {
		mid = (high + low) / 2;

		time1 = 0;
		tempPos = 0;
		pos = mid - 1;
		for (long long int i = 0; i < N; i++) {
			if (PWD[i][0] >= pos && PWD[i][0] - PWD[i][2] <= pos) {
				time1 += 0;
			}
			else if (PWD[i][0] <= pos && PWD[i][0] + PWD[i][2] >= pos) {
				time1 += 0;
			}
			else {
				if (PWD[i][0] > pos) {
					tempPos = PWD[i][0] - PWD[i][2];
					while (tempPos > pos) {
						tempPos -= 1;
						time1 += PWD[i][1];
					}
				}
				else {
					tempPos = PWD[i][0] + PWD[i][2];
					while (tempPos < pos) {
						tempPos += 1;
						time1 += PWD[i][1];
					}
				}	
			}
		}

		
		time2 = 0;
		tempPos = 0;
		pos = mid;
		for (long long int i = 0; i < N; i++) {
			if (PWD[i][0] >= pos && PWD[i][0] - PWD[i][2] <= pos) {
				time2 += 0;
			}
			else if (PWD[i][0] <= pos && PWD[i][0] + PWD[i][2] >= pos) {
				time2 += 0;
			}
			else {
				if (PWD[i][0] > pos) {
					tempPos = PWD[i][0] - PWD[i][2];
					while (tempPos > pos) {
						tempPos -= 1;
						time2 += PWD[i][1];
					}
				}
				else {
					tempPos = PWD[i][0] + PWD[i][2];
					while (tempPos < pos) {
						tempPos += 1;
						time2 += PWD[i][1];
					}
				}	
			}
		}

		time3 = 0;
		tempPos = 0;
		pos = mid + 1;
		for (long long int i = 0; i < N; i++) {
			if (PWD[i][0] >= pos && PWD[i][0] - PWD[i][2] <= pos) {
				time3 += 0;
			}
			else if (PWD[i][0] <= pos && PWD[i][0] + PWD[i][2] >= pos) {
				time3 += 0;
			}
			else {
				if (PWD[i][0] > pos) {
					tempPos = PWD[i][0] - PWD[i][2];
					while (tempPos > pos) {
						tempPos -= 1;
						time3 += PWD[i][1];
					}
				}
				else {
					tempPos = PWD[i][0] + PWD[i][2];
					while (tempPos < pos) {
						tempPos += 1;
						time3 += PWD[i][1];
					}
				}	
			}
		}
		
		if (time2 <= time3 && time2 <= time1) {
			cout << time2;
			low = high + 1;
		}
		else if (time2 > time3) {
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}	
}
