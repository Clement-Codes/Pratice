def binarySearch(arr, low, high, x):
    while low <= high:
        mid = low + (high-low) // 2
        if arr[mid] == x:
            return True
        elif arr[mid] < x:
            low = mid + 1
        elif arr[mid] > x:
            high = mid - 1
    return False



array = []

while(len(array)<5):
    array.append(int(input("Enter your no: ")))


x = int(input("Enter your no to be searched: "))


print(binarySearch(array, 0, len(array)-1, x))



