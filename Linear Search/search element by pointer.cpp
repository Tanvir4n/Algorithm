#include<stdio.h>

int linerSearch(int *p, int n, int value)
{
    for(int i = 0; i < n; i++)
    {
        if(*(p+i)==value)
        {
            return i;
        }
    }
    return -1;
}
int main()
{
    int n;
    printf("Enter the array size: ");
    scanf("%d", &n);
    int ar[n];
    printf("Enter the element of array: ");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &ar[i]);
    }
    int *p;
    p = ar;
    int value;
    printf("Enter the search element: ");
    scanf("%d", &value);
    int result = linerSearch(p, n, value);
    if(result == -1) printf("Not found\n");
    else printf("Found at index %d : ",result);
    return 0;
}
