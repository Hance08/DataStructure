#include <stdio.h>

/*

Key point : Every round I will swap the biggest number on the right hand side.
Therefore, I need to use nested for loop.
Example: I have an array which length is 5. So, first round I need to swap 4 times,
after loop through the whole array the biggest number CERTAIN on the right.
And the second round I only need to swap 3 times.
So the swap times is like this: (assume arr_len = 5) swap times -> 4 -> 3 -> 2 -> 1

The for outter loop which control the swap time decreasing by 1.
The for inner loop which loop through the current size of array.

*/

int arr[] = {2, 3, 9, 17, 5, 8, 2, 33, 178};

int main()
{
    int len_of_arr = sizeof(arr) / sizeof(arr[0]);
    // printf("The length of this array : %d\n", len_of_arr);

    for (int i = 0; i < len_of_arr; i++)
    {
        for (int j = 0; j < len_of_arr - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                arr[j] = arr[j] ^ arr[j + 1];
                arr[j + 1] = arr[j] ^ arr[j + 1];
                arr[j] = arr[j] ^ arr[j + 1];
            };
        }
        printf("Step %d : ", i);
        printf("[");
        for (int t = 0; t < len_of_arr; t++)
        {
            if (t > 0)
            {
                printf(",");
            }
            printf("%d", arr[t]);
        }
        printf("] \n");
    }

    printf("Final result : ");
    printf("[");
    for (int i = 0; i < len_of_arr; i++)
    {
        if (i > 0)
        {
            printf(",");
        }
        printf("%d", arr[i]);
    }
    printf("]");
    return 0;
}