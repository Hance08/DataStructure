#include <stdio.h>

/*

Outter for loop control the min_index, when the inner for loop found the smallest number, it will sort in the left.
Inner for loop is used to find the smallest number and swap into arr[min_index]

*/

int arr[] = {2, 3, 9, 17, 5, 8, 2, 33, 178};

int main()
{
    int len_of_arr = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < len_of_arr; i++)
    {
        int min_index = i;
        for (int j = 0 + i; j < len_of_arr; j++)
        {
            if (arr[j] < arr[min_index])
            {
                arr[j] = arr[j] ^ arr[min_index];
                arr[min_index] = arr[j] ^ arr[min_index];
                arr[j] = arr[j] ^ arr[min_index];
            }
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