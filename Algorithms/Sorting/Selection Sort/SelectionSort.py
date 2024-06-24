array = []

while(len(array)<5):
    array.append(int(input("Enter your no: ")))

print("Before sorting: ",array)
for i in range(len(array)):
    min = i
    for j in range(i+1, len(array)):
        if array[min]>array[j]:
            min = j
    if min!=i:
        array[i],array[min] = array[min], array[i]
print("After sorting: ",array)
