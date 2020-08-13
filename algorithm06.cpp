//all pairs shortest
#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;
const int INF = 99999;

int main()
{
	int N;
	cin >> N;

	vector<vector<int>> dp(N, vector<int>(N));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> dp[i][j];
		}
	}

	for (int k = 0; k < N; ++k) {
		for (int i = 0; i < N; ++i) {
			if (i != k) {
				for (int j = 0; j < N; ++j) {
					if (j != k && j != i) {
						if (dp[i][k] != INF && dp[k][j] != INF)
							dp[i][j] = min(dp[i][k] + dp[k][j], dp[i][j]);
					}
					else
						continue;
				}
			}
			else
				continue;
		}
	}


	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
}