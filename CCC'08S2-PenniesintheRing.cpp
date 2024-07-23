#include <iostream>
#include <cmath>
using namespace std;

double N = 1;
int corner, piece;

int main() {
	while (N != 0){
		cin >> N;
		if (N > 0){
			corner = 0;
		
		for (int x = 1; x < N; x++){
			piece = floor(sqrt((N*N) - (x*x)));
			corner += piece;
					
			}


			cout << int (corner * 4 + 1 + 4 * N) << "\n";
		}
	
	}
		

	return 0;
}
