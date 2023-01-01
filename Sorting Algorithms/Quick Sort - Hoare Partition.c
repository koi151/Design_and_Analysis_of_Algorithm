#include <stdio.h>

typedef int keytype;
typedef float othertype;

typedef struct {
    keytype key;
    othertype otherfeild;
}recordtype;

void Swap(recordtype *a, recordtype *b)
{
    recordtype temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int FindPivot(recordtype a[], int i, int j)
{
    int next_pos = i+1;
    keytype first_key = a[i].key;
    while (next_pos <= j && a[i].key == a[next_pos].key) next_pos++;
    if (next_pos > j) return -1;
    return (a[next_pos].key > first_key) ? next_pos : i; 
}

int Partition(recordtype a[], int i, int j, keytype pivot)
{
    int l = i, r = j;
    while (l <= r)
    {
        while (a[l].key < pivot) l++;
        while (a[r].key >= pivot) r--;
        if (l < r) Swap(&a[l], &a[r]);
    }
    return l;
}

void QuickSort(recordtype a[], int i, int j)
{
    int PivotIndex = FindPivot(a, i, j);
    if (PivotIndex != -1)
    {
        keytype pivot = a[PivotIndex].key;
        int k = Partition(a, i, j, pivot);
        QuickSort(a, i, k-1);
        QuickSort(a, k, j);
    }
}

//======================================================
int main ()
{
    printf("Enter the number of elements in your array: ");
    int n=0, i;
    scanf("%d", &n);
    recordtype a[n];

    for (i = 0; i < n; i++)
        scanf("%d", &a[i].key);
    
    printf("Array before sorting:\n");
    for (i = 0; i < n; i++)
        printf("%d ", a[i].key);

    QuickSort(a, 0, n-1);
    printf("\nArray after using Quick Sort (Hoare Partition):\n");
    for (i = 0; i < n; i++)
        printf("%d ", a[i].key);

    return 0;
}