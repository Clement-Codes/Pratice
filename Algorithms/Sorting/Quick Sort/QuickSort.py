array = []

def pivot(array, s, l):
    cc = s - 1
    for i in range(s, l):
        if array[i] <= array[l]:
            cc += 1
            print(i, cc)
            array[cc], array[i] = array[i], array[cc]
            
    array[cc + 1], array[l] = array[l], array[cc+1]
    print( array, s, l, cc+1)
    return cc + 1


def quicksort(array, s, l):
    if s<l:
        p = pivot(array, s, l)
        quicksort(array, s, p-1)
        quicksort(array, p+1, l)

while(len(array)<5):
    array.append(int(input("Enter your no: ")))
    

print("Before sorting: ",array)

quicksort(array, 0 , len(array)-1)

print("After sorting: ",array)
