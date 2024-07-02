from collections import deque;

class Node:
    def __init__(self, data) -> None:
        self.data = data
        self.left  = None
        self.right = None

def insertion(head, data):
    x = Node(data)
    q = deque()
    if head == None:
        return x
    q.append(head)
    while q:
        temp = q.popleft()
        if temp.left != None:
            q.append(temp.left)
        else:
            temp.left = x
            break
        if temp.right != None:
            q.append(temp.right)
        else:
            temp.right = x
            break    

def preorder(head):
    if head == None:
        return

    print(head.data, ',', end='')
    preorder(head.left)
    preorder(head.right)

def inorder(head):
    if head == None:
        return
    inorder(head.left)
    print(head.data, ',', end='')
    inorder(head.right)

def postorder(head):
    if head == None:
        return
    postorder(head.left)
    postorder(head.right)
    print(head.data, ',', end='')

def levelorder(head):
    if head == None:
        print('None')
    q = deque()
    q.append(head)
    while q:
        temp = q.popleft()
        print(temp.data, end =',')
        if temp.left != None:
            q.append(temp.left)
        if temp.right != None:
            q.append(temp.right)

def delete(head, x):
    if head == None:
        print('None')
    q = deque()
    q.append(head)
    keyNode = None
    temp = None
    while q:
        temp = q.popleft()
        if temp.data == x:
            keyNode = temp
        if temp.left != None:
            q.append(temp.left)
        if temp.right != None:
            q.append(temp.right)
    
    if keyNode != None:
        t = temp.data
        keyNode.data = t
        deleteDepth(head, temp)


def deleteDepth(head, x):
    q = deque()
    q.append(head)
    while q:
        temp = q.popleft()
        if temp == x:
            temp = None
            del x
            return
        if temp.left != x:
            q.append(temp.left)
        else:
            temp.left = None
            del x
            return
        if temp.right != x:
            q.append(temp.right)
        else:
            temp.right = None
            del x
            return
        
if __name__ == "__main__":
    head = Node(1)
    insertion(head, 2)
    insertion(head, 3)
    insertion(head, 4)
    insertion(head, 5)

    print('inorder:', end='')
    inorder(head)
    print()

    print('preorder:', end='')
    preorder(head)
    print()

    print('postorder:', end='')
    postorder(head)
    print()

    print('levelorder:', end='')
    levelorder(head)
    print()

    delete(head, 3)

    print('levelorder:', end='')
    levelorder(head)
    print()
