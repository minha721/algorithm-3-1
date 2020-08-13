//fibonacci, zeckendorf's theorem
#include <stdio.h>

int fibo(int n) {
    int before = 0, cur = 1, i, temp;

    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else {
        for (i = 1; i < n; i++) {
            temp = cur;
            cur = before + cur;
            before = temp;
        }
        return cur;
    }
}

int zeckendorf(int n) {
    int i;
    int temp = n;

    if (n == 0)
        return fibo(0);
    else {
        for (i = 1; n >= fibo(i); ++i) {
            temp = n - fibo(i);
        }

        i--;

        return fibo(i - 1) + zeckendorf(temp);
    }
}

int main()
{
    int num;
    scanf("%d", &num);

    printf("%d", zeckendorf(num));
}

fibo를 재귀함수로 했을 때는 시간 초과가 떠서 반복문으로 바꿈