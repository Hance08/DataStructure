#include <stdio.h>
#include <stdlib.h>

void mergeSort(int arr[], int left, int right);
void merge(int arr[], int left, int mid, int right);

int main()
{
    int arr[] = {38, 27, 43, 3};
    // int arr1[] = {2, 3};
    int arr_len = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, 0, arr_len - 1);

    printf("Sorted : ");
    for (int i = 0; i < arr_len; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}

void mergeSort(int arr[], int left, int right) // Example left = 0, right = 2 [3, 5, 1]
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        for (int i = 0; i < mid; i++)
        {
            printf("%d ", arr[i]);
        }
        for (int i = mid + 1; i < right; i++)
        {
            printf("%d ", arr[i]);
        }

        mergeSort(arr, left, mid);      // Divide to left array
        mergeSort(arr, mid + 1, right); // Divide to right array
        merge(arr, left, mid, right);   // When the recursion is fullfill, start merge
    }
}

void merge(int arr[], int left, int mid, int right) // First execute argument (arr, 0, 0, 1)
{
    int left_arr_len = mid - left + 1;
    int right_arr_len = right - mid;

    int L[left_arr_len], R[right_arr_len];

    for (int i = 0; i < left_arr_len; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < right_arr_len; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, key = left;
    while (i < left_arr_len && j < right_arr_len)
    {
        if (L[i] <= R[j])
        {
            arr[key] = L[i];
            i++;
        }
        else
        {
            arr[key] = R[j];
            j++;
        }
        key++;
    }
    while (i < left_arr_len)
    {
        arr[key] = L[i];
        i++;
    }

    while (j < right_arr_len)
    {
        arr[key] = R[j];
        j++;
    }
}