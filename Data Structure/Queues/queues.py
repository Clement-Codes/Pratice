queue = []
queue.append(1)
queue.append(2)
queue.append(3)
print("Length: ",len(queue))
while(queue):
    print(queue[0])
    queue.pop(0)