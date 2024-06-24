array = []

while(len(array)<5):
    array.append(int(input("Enter your no: ")))

print("Before sorting: ",array)

for i in range(len(array)):
    done = True
    for j in range(i, len(array)):
        if array[i]>array[j]:
            array[i], array[j] = array[j], array[i]
            done = False
    if done:
        break

print("After sorting: ", array)