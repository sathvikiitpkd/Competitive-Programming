/*Given an array of size N containing only 0s, 1s, and 2s; sort the array in ascending order.
//TIME COMPLEXITY  O(n)
//SPACE COMPLEXITY  O(1)

#include <stdio.h>

void sort012(int arr[], int n)
{
    int a=0,b=0,c=0;
    for(int i = 0;i<n;i++)
    {
        if(arr[i] == 0)
        {
            a++;
        }
        else if(arr[i] == 1)
        {
            b++;
        }
        else if(arr[i] == 2)
        {
            c++;
        }
    }
    for(int i=0;i<a;i++)
    {
        arr[i] = 0;
    }
    for(int i=a;i<b+a;i++)
    {
        arr[i] = 1;
    }
    for(int i=a+b;i<n;i++)
    {
        arr[i] = 2;
    }
}

// { Driver Code Starts.

int main() {

    int t;
    scanf("%d", &t);

    while(t--){
        int n;
        scanf("%d", &n);
        int arr[n];
        for(int i=0;i<n;i++){
            scanf("%d", &arr[i]);
        }

        sort012(arr, n);

        for (int i = 0; i < n; i++)
            printf("%d ", arr[i]);
        printf("\n");
    }
    return 0;
}
  // } Driver Code Ends
