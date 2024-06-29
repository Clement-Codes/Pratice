
def countsort(array, N, e):

    output = [0] * 10
    count = [0] * 10
    for i in array:
        count[int(i/e)%10] += 1
    print(count)
    for i in range(1, len(count)):
        count[i] += count[i-1]
    print(count)

    for i in range(len(array)-1, -1, -1):
        output[count[int(array[i]/e)%10]-1] = array[i]
        count[int(array[i]/e)%10] -= 1
    
    for i in range(len(array)):
        array[i] = output[i]

    print(count)


def radixsort(array, N):
    m = max(array)
    
    e = 1
    while int(m/e) > 0 :
        countsort(array, N, e)
        e = e*10

array = []

while(len(array)<5):
    array.append(int(input("Enter your no: ")))
    

print("Before sorting: ",array)

radixsort(array, len(array)-1)

print("After sorting: ",array)