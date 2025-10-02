#include <stdio.h>
int arr[] = {2, 3, 9, 17, 5, 8, 2, 33, 178};
int arr_len = sizeof(arr) / sizeof(arr[0]);

int main()
{
    for (int i = 1; i < arr_len; i++)
    {
        int current = arr[i];
        int previous_index = i - 1;

        while (previous_index >= 0 && arr[previous_index] > current)
        {
            arr[previous_index + 1] = arr[previous_index];
            previous_index--;
        }
        arr[previous_index + 1] = current;
        printf("Step %d : ", i);
        printf("[");
        for (int t = 0; t < arr_len; t++)
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
    for (int i = 0; i < arr_len; i++)
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