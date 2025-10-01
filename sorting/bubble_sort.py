arr = [2, 3, 9, 17, 5, 8, 2, 33, 178]

len_of_arr = len(arr)

# print(len_of_arr)
for i in range(len_of_arr):
    for j in range(len_of_arr - i - 1):
        if (arr[j] > arr[j + 1]):
            arr[j] = arr[j] ^ arr[j + 1]
            arr[j + 1] = arr[j] ^ arr[j + 1]
            arr[j] = arr[j] ^ arr[j + 1]

print(arr)
