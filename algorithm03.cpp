//closest pair

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct
{
    int x;
    int y;
} coord;

coord* minPairs = NULL;
double min = -1;

double measureDistance(coord* a, coord* b)
{
    double distance = sqrt(pow(a->x - b->x, 2) + pow(a->y - b->y, 2));

    if (min == -1 || distance < min)
    {
        *minPairs = *a;
        *(minPairs + 1) = *b;
        min = distance;
    }
    return distance;
}

double ClosestPair(coord* pairs, int left, int right, int size)
{
    if (size == 2)
        return measureDistance(pairs, pairs + 1);

    else if (size == 3)
    {
        double distance1, distance2, distance3, min;
        distance1 = measureDistance(pairs, pairs + 1);
        distance2 = measureDistance(pairs + 1, pairs + 2);
        distance3 = measureDistance(pairs + 2, pairs);

        min = distance1 < distance2 ? distance1 : distance2;
        min = distance3 < min ? distance3 : min;
        return min;
    }

    else
    {
        int mid = (left + right) / 2;

        double distanceRange;
        double CPright, CPleft;

        CPleft = ClosestPair(pairs, left, mid, mid - left + 1);
        CPright = ClosestPair(pairs, mid + 1, right, right - mid);
        distanceRange = CPleft < CPright ? CPleft : CPright;

        coord* pairsTmp = (coord*)malloc(sizeof(coord) * size);
        int cnt = 0;
        double minSub = -1;

        for (int i = left; i <= right; i++)
        {
            if (abs((pairs + i)->x - (pairs + mid)->x) < distanceRange)
            {
                (pairsTmp + cnt)->x = (pairs + i)->x;
                (pairsTmp + cnt)->y = (pairs + i)->y;
                cnt++;
            }
        }

        for (int i = 0; i < cnt; i++)
        {
            for (int j = i + 1; j < cnt; j++)
            {
                minSub = distanceRange < measureDistance(pairsTmp + i, pairsTmp + j) ? distanceRange : measureDistance(pairsTmp + i, pairsTmp + j);

                if (minSub < distanceRange)
                {
                    distanceRange = minSub;
                    if (minSub < min)
                    {
                        *minPairs = *(pairsTmp + i);
                        *(minPairs + 1) = *(pairsTmp + j);
                    }
                }
            }
        }

        free(pairsTmp);
        return distanceRange;
    }
}

void swap(coord* a, coord* b)
{
    coord temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void QuickSort(coord* node, int left, int right) {
    int num, l, r, tmp;
    if (right > left) {
        num = node[right].x;
        l = left - 1;
        r = right;

        while (1) {
            while (node[++l].x < num && l < right);
            while (node[--r].x > num && left < r);
            if (l >= r) break;

            swap(&node[l], &node[r]);
        }
        swap(&node[l], &node[right]);

        QuickSort(node, left, l - 1);
        QuickSort(node, l + 1, right);
    }
}


int main(void)
{
    int n;
    coord* pairs = NULL;

    scanf("%d", &n);

    pairs = (coord*)malloc(sizeof(coord) * n);

    minPairs = (coord*)malloc(sizeof(coord) * 2);

    for (int i = 0; i < n; i++)
    {
        scanf("%d, %d", &(pairs + i)->x, &(pairs + i)->y);
    }

    QuickSort(pairs, 0, n - 1);

    printf("%lf\n", ClosestPair(pairs, 0, n - 1, n));

    free(pairs);
    free(minPairs);
    return 0;
}