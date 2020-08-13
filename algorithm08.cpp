//DPCoinChange
#include <stdio.h>
#include <stdlib.h>

const int INF = 10001;
const int MAX_COUNT = 10;
const int MAX_LENGTH = 10000;

int main() {
	char str[MAX_LENGTH];
	int k[MAX_COUNT];
	int C[100001];

	int count = 0;
	int num = 0;
	int n;

	gets_s(str, MAX_LENGTH);

	for (int i = 0; count < MAX_COUNT && str[i]; i++) {
		if (str[i] != ',' && str[i] != ' ') {
			num = num * 10 + str[i] - '0';
		}
		else {
			if (num > 0) {
				k[count++] = num;
				num = 0;
			}
		}
	}

	if (num > 0)
		k[count++] = num;

	scanf("%d", &n);

	C[0] = 0;
	for (int i = 1; i <= n; i++)
		C[i] = INF;

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < count; j++) {
			if (k[j] <= i && C[i - k[j]] + 1 < C[i])
				C[i] = C[i - k[j]] + 1;
		}
	}

	printf("%d\n", C[n]);

	return 0;
}