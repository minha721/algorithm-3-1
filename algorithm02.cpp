//quick sort

#include<stdio.h>
#include<stdlib.h>

void QuickSort(int arr[], int left, int right) {
	int num, l, r, tmp;
	if (right > left) {
		num = arr[right];
		l = left - 1;
		r = right;

		while (1) {
			while (arr[++l] < num && l < right);
			while (arr[--r] > num && left < r);
			if (l >= r) break;

			tmp = arr[l];
			arr[l] = arr[r];
			arr[r] = tmp;
		}
		tmp = arr[l];
		arr[l] = arr[right];
		arr[right] = tmp;

		QuickSort(arr, left, l - 1);
		QuickSort(arr, l + 1, right);
	}
}

int main() {
	int i, n;
	scanf("%d", &n);
	int* pt = (int*)malloc(sizeof(int) * n);

	for (i = 0; i < n; i++)
		scanf("%d", &pt[i]);

	QuickSort(pt, 0, n - 1);

	for (i = 0; i < n; i++)
		printf("%d\n", pt[i]);

	free(pt);

	return 0;
}