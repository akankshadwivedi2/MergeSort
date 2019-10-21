#include <bits/stdc++.h>

using namespace std;

void mergec(int arr[], int s, int e, int mid)
{
    int p = s;
    int q = mid + 1;

    int a[e - s + 1], k = 0;

    for (int i = s; i < e; i++)
    {
        if (p > mid)
        {
            a[k++] = arr[q++];
        }
        else if (q > e)
        {
            a[k++] = arr[p++];
        }
        else if (arr[p] < arr[q])
            a[k++] = arr[p++];

        else
            a[k++] = arr[q++];
    }
    for (int p = 0; p < k; p++)
    {
        arr[s++] = a[p];
    }
}

void merges(int arr[], int s, int e)
{
    if (s < e)
    {
        int mid = (s + e) / 2;
        merges(arr, s, mid);
        merges(arr, mid + 1, e);
        mergec(arr, s, e, mid);
    }
}

void printArray(int a[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main()
{
    int arr[5] = {5, 4, 2, 1, 3};

    merges(arr, 0, 5 - 1);
    printArray(arr, 5);

    return 0;
}
