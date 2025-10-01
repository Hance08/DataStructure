#include <stdio.h>
int arr[] = {2, 3, 9, 17, 5, 8, 2, 33, 178};
int arr_len = sizeof(arr) / sizeof(arr[0]);

int main()
{
    for (int i = 1; i < arr_len; i++) // Start with index 1 element
    {
        int current = arr[i];              // current index element (initial 1 which is 3)
        int j = i - 1;                     // The PREVIOUS element (which is 2, which is the sorted part)
        while (j >= 0 && arr[j] > current) // The condition about should insert or not (which is 2 > 3 false, NOT insert)
        {
            arr[j + 1] = arr[j]; // The previous element shift right by one (Example: 2, 3, 9, 17, 5... -> 2, 3, 9, 17, 17)
            j--; // Go to next sorted element (which is 9)
        }
        arr[j + 1] = current; // The INSERT happen here !!
    }

    for (int i = 0; i < arr_len; i++)
    {
        printf("%d,", arr[i]);
    }

    return 0;
}