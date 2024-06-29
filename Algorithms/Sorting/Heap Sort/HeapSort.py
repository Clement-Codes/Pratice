
def heapify(arr, N, i):
    largest = i
    
    left = 2 * i + 1
    right = 2 * i + 2

    if(left<N and arr[left] >= arr[largest]):
        largest = left

    if(right<N and arr[right] >= arr[largest]):
        largest = right        

    if(largest != i):
        arr[largest], arr[i] = arr[i], arr[largest]
        heapify(arr, N, largest)

def heapsort(arr):
    for i in range(int(len(arr)/2) - 1, -1, -1):
        heapify(arr, len(arr), i)

    for i in range(len(arr)-1, -1, -1):
        arr[0], arr[i] = arr[i], arr[0]
        heapify(arr, i, 0)

array = []

while(len(array)<5):
    array.append(int(input("Enter your no: ")))

print("Before sorting: ",array)

heapsort(array)


print("After sorting: ",array)


