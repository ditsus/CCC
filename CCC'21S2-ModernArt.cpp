#include <iostream>
using namespace std;

int main() {

	int M, N, K, numrc, counter;
	counter = 0;
	cin >> M >> N >> K;
	int arr1[M];
	int arr2[N];

	for (int i = 0; i < M; i++)
	{
		arr1[i] = 0;
	}
	for (int j = 0; j < N; j++)
	{
		arr2[j] = 0;
	}
	
	string rc;
	for (int i = 0; i < K; i++)
	{
		cin >> rc >> numrc;
		if (rc == "R")
		{
			arr1[numrc - 1] += 1;
		}
		else
		{
			arr2[numrc - 1] += 1;
		}
	}

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
				if ((arr1[i] + arr2[j]) % 2 != 0)
				{
					counter += 1;
				}
		}
	}

	cout << counter;
	
	return 0;
}
