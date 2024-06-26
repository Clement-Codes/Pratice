array = []

def merge(left, right):
    result = []

    i , j = 0, 0
    while i<len(left) and j<len(right):
        if left[i]<=right[j]:
            result.append(left[i])
            i += 1
        else:
            result.append(right[j])
            j += 1
    
    while i<len(left):
        result.append(left[i])
        i += 1

    while j<len(right):
        result.append(right[j])
        j += 1

    return result

def mergesort(array):
    
    if len(array)<=1:
        return array
    
    mid = len(array)//2

    left = mergesort(array[:mid])
    right = mergesort(array[mid:])

    return merge(left, right)
    

while(len(array)<5):
    array.append(int(input("Enter your no: ")))
    

print("Before sorting: ",array)

array = mergesort(array)

print("After sorting: ",array)
