//Task Scheduling
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int start;
    int finish;
} task;

void swap(task* a, task* b)
{
    task temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void QuickSort(task* node, int left, int right) {
    if ((right - left) <= 0) return;

    int pivot = node[right].start;

    int i = left;

    for (int j = left; j < right; j++) {
        if (node[j].start <= pivot) {
            swap(&node[i], &node[j]);
            i += 1;
        }
    }

    swap(&node[i], &node[right]);

    QuickSort(node, left, i - 1);
    QuickSort(node, i + 1, right);
}


void scheduling(task* t, int N) {
    int machineNum = 0;
    task early;

    for (int i = 0; i < N; i++) {
        early = t[i];
        t[i].start = 0;
        t[i].finish = 0;

        if ((&early)->start == 0 && (&early)->finish == 0)
            continue;
        else {
            machineNum += 1;
            for (int j = 0; j < N; j++) {

                if ((&t[j])->start == 0 && (&t[j])->finish == 0)
                    continue;

                if ((&early)->finish <= t[j].start) {
                    early = t[j];
                    t[j].start = 0;
                    t[j].finish = 0;
                }
            }
        }
    }

    printf("%d\n", machineNum);
}

int main()
{
    int N;
    scanf("%d", &N);

    task* t = (task*)malloc(sizeof(task) * N);

    for (int i = 0; i < N; i++) {
        scanf("%d", &t[i].start);
        scanf("%d", &t[i].finish);
    }

    QuickSort(t, 0, N - 1);

    scheduling(t, N);

    return 0;

}