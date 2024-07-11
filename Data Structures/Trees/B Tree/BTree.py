class Node:
    def __init__(self, size, leaf = False) -> None:
        self.leaf = leaf
        self.keys = []
        self.childrens = []
        self.n = 0
        self.size = size

    def findKey(self, x):
        temp = 0
        while x > self.keys[temp][0] and x < len(self.keys):
            temp += 1
        return temp
    
    def delete(self, x):
        i = self.findKey(x)
        if i <self.n and self.keys[i][0] == x:
            if self.leaf:
                self.deleteAtLeaf(i)
            else:
                self.deleteAtNode(i)

        if self.leaf:
            print("No Node found", self.keys)
            return
        

            
        if self.childrens[i].n < self.size:
            self.fill(i)
        flag = i == self.n
        if flag:
            self.childrens[i-1].delete(x)
        else:
            self.childrens[i].delete(x)

    def fill(self, i):
        if i!=0 and self.childrens[i-1].n >= self.size:
            self.borrowPrev(i)
        elif i!=self.n and self.childrens[i+1].n >= self.size:
            self.borrowSuccessor(i)
        else:
            if i!=self.n:
                self.merge(i)
            else:
                self.merge(i-1)
    

    def borrowPrev(self, i):
        child = self.childrens[i]
        prev = self.childrens[i-1]

        n = child.n - 1
        while n >= 0:
            child.keys[n+1] = child.keys[n]

        if not child.leaf:
            n = child.n + 1
            while n >= 0:
                child.childrens[n+1] = child.childrens[n]
            child.childrens[0] = prev.childrens[prev.n]

        child.keys[0] = self.keys[i - 1]
        self.keys[i - 1] = prev.keys[prev.n - 1]

        child.n += 1
        prev.n -= 1

    def borrowSuccessor(self, i):
        child = self.childrens[i]
        next = self.childrens[i+1]

        child.keys[child.n] = self.keys[i]
        self.keys[i] = next.keys[0]

        if not child.leaf:
            child.children[child.n] = next.childern[0] 
        
        n = next.n - 1
        while n > 0:
            next.keys[n - 1] = next.keys[n]

        if not child.leaf:
            n = next.n 
            while n > 0:
                next.children[n - 1] = next.children[n]
        
        child.n += 1
        next.n -= 1


    def deleteAtLeaf(self, i):
        while i<self.n-1:
            self.keys[i] = self.keys[i+1]
            i +=1
        self.n -= 1

    def deleteAtNode(self, i):
        if self.childrens[i].n >= self.size:
            ch = self.getPredecessor()
            self.keys[i] = ch
            self.childrens[i].remove(ch)
        elif self.childrens[i + 1].n >= self.size:
            ch = self.getSuccessor()
            self.keys[i] = ch
            self.childrens[i+1].remove(ch)
        else:
            self.merge(i)
            self.childrens[i].remove(self.keys[i])

    def merge(self, ii):
        child = self.childrens[ii]
        next = self.childrens[ii+1]
        child.keys.append(self.keys[ii])

        for i in range(len(next.keys)):
            child.keys.append(next.keys[i])
        
        if not next.leaf:
            for i in range(len(next.keys) + 1):
                child.childrens.append(next.childrens[i])
        
        for i in range(ii+1, len(self.keys)):
            self.keys[i - 1] = self.keys[i]
        
        for i in range(ii+2, len(self.keys)+1):
            self.childrens[i - 1] = self.childrens[i]

        child.n += next.n + 1
        self.n -=1

    def getPredecessor(self, i):
        ch = self.childrens[i]
        while ch.leaf is False:
            ch = ch.childrens[ch.n]
        return ch.key[ch.n - 1]
    
    def getSuccessor(self, i):
        ch = self.childrens[i+1]
        while ch.leaf is False:
            ch = ch.childrens[0]
        return ch.key[0]   
class BTree:
    def __init__(self, size) -> None:
        self.root = Node(size, True)
        self.size = size


    def deletion(self, x):
        if self.root is None:
            print("empty")

        self.root.delete(x)

        if self.root.n == 0:
            temp = self.root
            if temp.leaf:
                self.root = None
            else:
                self.root = temp.childrens[0]
            del temp


    def insertion(self, x):
        root = self.root
        if len(root.keys) == (2 * self.size) - 1:
            temp = Node(self.size, False)
            temp.childrens.insert(0, root)
            self.root = temp
            self.split(self.root, 0)
            self.insertionFull(x, temp)
        else:
            self.insertionFull(x, root)

    def insertionFull(self, x, root):
        i = len(root.keys) - 1
        if root.leaf:
            root.keys.append((None, None))
            while  i>=0 and x[0] < root.keys[i][0]:
                root.keys[i+1] = root.keys[i]
                i -= 1
            i = i + 1
            root.keys[i] = x
            root.n +=1
        else:
            while  i>=0 and x[0] < root.keys[i][0]:
                i -= 1
            i += 1
            if len(root.childrens[i].keys) == (2 * self.size) - 1:
                self.split(root, i)
                if root.keys[i][0] < x[0]:
                    i +=1
            self.insertionFull(x, root.childrens[i])
           

    def split(self, root, i):
        x = root.childrens[i]
        temp = Node(self.size, x.leaf)
        root.childrens.insert(i+1, temp)
        root.n += 1
        root.keys.insert(i, x.keys[self.size - 1])
        temp.keys = x.keys[self.size:]
        temp.n = x.size - self.size
        x.keys = x.keys[0: self.size-1]
        x.n = self.size - 1
        if not x.leaf:
            temp.childrens = x.childrens[self.size: ]
            x.childrens = x.childrens[0: self.size]


    def printBST(self, l = 0, root = None):
        if root:
            print("Level", l, root.leaf, end=": ")

            for i in root.keys:
                print(i, end=" ")
            print()
            if not root.leaf :
                l += 1
                for i in root.childrens:
                    self.printBST(l, i)
        else:
            self.printBST(l, self.root) 


if __name__ == "__main__":
    bst = BTree(size=3)

    for i in range(20):
        bst.insertion((i, i))
    
    bst.printBST()

    for i in range(20):
        print(i)
        bst.deletion(i)

    bst.printBST()


























# class Node:
#     def __init__(self, leaf=False) :
#         self.leaf = leaf
#         self.keys = []
#         self.child = []

# class BTree:
#     def __init__(self, t) -> None:
#         self.root = Node(True)
#         self.size = t

#     def insert_non_full(self, root, x):
#         i = len(root.keys) - 1
#         if root.leaf:
#             root.keys.append((None, None))
#             while i >= 0 and root.keys[i][0] > x[0] :
#                 root.keys[i+1] = root.keys[i]
#                 i = i - 1
#             root.keys[i+1]=x
#         else:
#             while i >= 0 and root.keys[i][0] > x[0] :
#                 i = i - 1
#             i += 1 
#             if len(root.child[i].keys) == (2*self.size) - 1:
#                 self.split_child(root, i)
#                 if x[0] > root.keys[i][0]:
#                     i += 1
#             self.insert_non_full(root.child[i], x)


#     def insert(self, x):
#         root = self.root
#         if len(root.keys) == (self.size * 2) -1:
#             temp = Node()
#             self.root = temp
#             temp.child.insert(0, root)
#             self.split_child(temp, 0)
#             self.insert_non_full(temp, x)
#         else:
#             self.insert_non_full(root, x)

#     def print_tree(self, x, l = 0):
#         print("Level ", l, " ", len(x.keys), end=":")
#         for i in x.keys:
#             print(i, end = " ")
#         print()
#         l += 1
#         if len(x.child)>0:
#             for i in x.child:
#                 self.print_tree(i,l)

#     def split_child(self, x, i):
#         t = self.size
#         y = x.child[i]
#         z = Node(y.leaf)
#         x.child.insert(i+1, z)
#         x.keys.insert(i, y.keys[t-1])
#         z.keys = y.keys[t: (2*t) - 1]
#         y.keys = y.keys[0:t-1]
#         if not y.leaf:
#             z.child = y.child[t:2*t]
#             y.child = y.child[0:t-1]

#     def search(self, root , x):
#         if root is not None:
#             i = 0
#             while x > root[i]:
#                 pass
#         else:
#             self.search(self.root, x)
# if __name__ == '__main__':
#     btree = BTree(3)
#     for i in range(20):
#         btree.print_tree(btree.root)
#         btree.insert((i, 2*i))
       