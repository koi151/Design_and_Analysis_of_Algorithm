#include <stdio.h>

typedef int keytype;
typedef float othertype;

typedef struct {
    keytype key;
    othertype otherfields;
}recordtype;

void Swap(recordtype *x, recordtype *y)
{
    recordtype temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void Insertion_Sort(recordtype a[], int n)
{
    int i, j;
    for ( i = 0; i < n; i++)
    {
        j = i;
        while (j > 0 && a[j-1].key > a[j].key)
        {
            Swap(&a[j-1], &a[j]);
            --j;
        }
    }
}

//====================================================
int main ()
{
    printf("Enter the number of recordtype: ");
    int n, i;
    scanf("%d", &n);
    recordtype test[n];

    for (i = 0; i < n; i++)
    {
        printf("Enter key value at position %d: ", i+1);
        scanf("%d", &test[i].key);
    }

    printf("All values before sorting:\n[");
    for ( i = 0; i < n - 1; i++)
        printf("%d, ", test[i].key);
    printf("%d]\n", test[n-1].key);

    Insertion_Sort(test, n);
    printf("All values after using Insertion sort:\n[");
    for ( i = 0; i < n - 1; i++)
        printf("%d, ", test[i].key);
    printf("%d]\n", test[n-1].key);

}

