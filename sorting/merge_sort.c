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

void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2; // Find the mid index, equal to (left + right) / 2, but more safety
        mergeSort(arr, left, mid);           // Divide to left array
        mergeSort(arr, mid + 1, right);      // Divide to right array
        merge(arr, left, mid, right);        // After the above recursion function finished, start merging
    }
}

void merge(int arr[], int left, int mid, int right)
{
    int left_arr_len = mid - left + 1; // Define the length of left array
    int right_arr_len = right - left;  // Define the length of right array

    int L[left_arr_len], R[right_arr_len]; // Create the temp arrays for left and right
    for (int i = 0; i < left_arr_len; i++) // Fill the value from origin array to temp array
        L[i] = arr[left + i];
    for (int j = 0; j < right_arr_len; j++) // Fill the value from origin array to temp array
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, insert_index = left;        // Create the index for comparing the vaule between left array and right array
    while (i < left_arr_len && j < right_arr_len) // Check if either left or right array is empty
    {
        if (L[i] <= R[j]) // If left array's value less equal than right arrays's vaule
        {
            arr[insert_index] = L[i]; // Put the left array's value into the origin array
            i++;                      // Move one index forward from left array
        }
        else
        {
            arr[insert_index] = R[j]; // Put the right array's value into the origin array
            j++;                      // Move one index forward from right array
        }
        insert_index++; // Move one index forward from origin array
    }

    while (i < left_arr_len) // This statement will be used while there have remained value in the left array and then put all the remain value in the origin array
    {
        arr[insert_index] = L[i];
        i++;
        insert_index++;
    }
    while (j < right_arr_len)
    {
        arr[insert_index] = R[j];
        j++;
        insert_index++;
    }
}