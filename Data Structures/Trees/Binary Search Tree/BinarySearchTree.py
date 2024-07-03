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
        if (data <= temp.data):
            if temp.left != None:
                q.append(temp.left)
            else:
                temp.left = x
                break
        elif (data > temp.data):
            if temp.right != None:
                q.append(temp.right)
            else:
                temp.right = x
                break    


def insertionRecurresion(head, data):
    if head is None:
        x = Node(data)
        return x
    elif data <= head.data:
        head.left = insertionRecurresion(head.left, data)
    elif data > head.data:
        head.right = insertionRecurresion(head.right, data)
    return head

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
        
        if temp.left and temp.left != x:
            q.append(temp.left)
        else:
            temp.left = None
            del x
            return
        if temp.right and temp.right != x:
            q.append(temp.right)
        else:
            temp.right = None
            del x
            return

def minvalue(head):
    if head.left is not None:
        return minvalue(head.left)
    else:
        return head

def deletion(head, x):
    if head is None:
        return head
    elif x < head.data:
        deletion(head.left, x)
    elif x > head.data:
        deletion(head.right, x)
    else:
        if head.left is None:
            return head.right
        elif head.right is None:
            return head.left
        temp = minvalue(head.right)
        head.data = temp.data
        head.right = deletion(head.right, temp.data)
    return head

if __name__ == "__main__":
    head = Node(50)
    # insertion(head, 30)
    # insertion(head, 20)
    # insertion(head, 40)
    # insertion(head, 70)
    # insertion(head, 60)
    # insertion(head, 80)
    head = insertionRecurresion(head, 30)
    head = insertionRecurresion(head, 20)
    head = insertionRecurresion(head, 40)
    head = insertionRecurresion(head, 70)
    head = insertionRecurresion(head, 60)
    head = insertionRecurresion(head, 80)

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

    deletion(head, 30)

    print('levelorder:', end='')
    levelorder(head)
    print()
