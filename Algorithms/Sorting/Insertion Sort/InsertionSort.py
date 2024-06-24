array = []

while(len(array)<5):
    array.append(int(input("Enter your no: ")))

print("Before sorting: ",array)

for i in range(len(array)):
    key = i
    j = i-1
    while j>=0:
        if array[key]<array[j]:
            array[key], array[j] = array[j], array[key]
            key = j
            j -= 1


print("After sorting: ",array)
