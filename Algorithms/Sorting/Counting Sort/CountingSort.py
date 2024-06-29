
def getMax(Array):
    max = array[0]
    for i in array:
        if max<=i:
            max = i
    return max

def countingSort(array):
    output = [0] * len(array)
    max = getMax(array)
    count = [0] * (max+1)

    for i in array:
        count[i] += 1

    for i in range(1, len(count)):
        count[i] += count[i-1]
    
    for i in range(len(array)-1, -1, -1):
        output[count[array[i]]-1] = array[i]
        count[array[i]] -= 1
    
    print(output)
    for i in range(0, len(array)):
        array[i] = output[i]


    

array = []

while(len(array)<5):
    array.append(int(input("Enter your no: ")))

print("Before sorting: ",array)

countingSort(array)

print("After sorting: ",array)
