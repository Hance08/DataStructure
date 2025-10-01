arr = [2, 3, 9, 17, 5, 8, 2, 33, 178]
arr_len = len(arr)

for i in range(arr_len):
    min_index = i
    for j in range(i + 1, arr_len):
        if (arr[j] < arr[min_index]):
            min_index = j
            arr[i] = arr[i] ^ arr[min_index]
            arr[min_index] = arr[i] ^ arr[min_index]
            arr[i] = arr[i] ^ arr[min_index]
print(arr)