def linearSearch(arr, x):
    for i in arr:
        if x == i:
            return True
    return False

array = []

while(len(array)<5):
    array.append(int(input("Enter your no: ")))


x = int(input("Enter your no to be searched: "))


print(linearSearch(array, x))



