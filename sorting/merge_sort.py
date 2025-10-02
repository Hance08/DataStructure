def mergeSort(arr, left, right):
    if (left < right):
        mid = int(left + (right - left) / 2)
        mergeSort(arr, left, mid)
        mergeSort(arr, mid + 1, right)
        merge(arr, left, mid, right)
    return

def merge(arr, left, mid, right):
    left_arr_len = mid - left + 1
    right_arr_len = right - mid

    L = [0] * left_arr_len
    R = [0] * right_arr_len
    for i in range(left_arr_len):
        L[i] = arr[left + i]
    for j in range(right_arr_len):
        R[j] = arr[mid + 1 + j]
    
    i = 0
    j = 0
    key = left
    while (i < left_arr_len and j < right_arr_len):
        if (L[i] <= R[j]):
            arr[key] = L[i]
            i += 1
        else:
            arr[key] = R[j]
            j += 1
        key += 1
    
    while (i < left_arr_len):
        arr[key] = L[i]
        i += 1
    while (j < right_arr_len):
        arr[key] = R[j]
        j += 1

arr = [2, 4, 10, 7, 3]
arr_len = len(arr)

mergeSort(arr, 0, arr_len - 1)
print(arr)
