arr = [2, 3, 9, 17, 5, 8, 2, 33, 178]
arr_len = len(arr)


for i in range(1, arr_len):
    current = arr[i]
    previous_index = i - 1

    while previous_index >= 0 and arr[previous_index] > current:
        arr[previous_index + 1] = arr[previous_index]
        previous_index-=1

    arr[previous_index + 1] = current

print(arr)