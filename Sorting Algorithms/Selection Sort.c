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

void Selection_Sort(recordtype a[], int n)
{
    int i, j, lowindex;
    keytype lowkey;
    for ( i = 0; i < n - 1; i++)
    {
        lowindex = i;
        lowkey = a[i].key;
        for ( j = i+1; j < n ; j++)
        {
            if (a[j].key < lowkey)
            {
                lowkey = a[j].key;
                lowindex = j;
            }
        }
        Swap(&a[lowindex], &a[i]);
    }
}

//======================================
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

    Selection_Sort(test, n);
    printf("All values after using Selection sort:\n[");
    for ( i = 0; i < n - 1; i++)
        printf("%d, ", test[i].key);
    printf("%d]\n", test[n-1].key);

}

