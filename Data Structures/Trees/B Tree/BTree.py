class Node:
    def __init__(self, leaf = False) -> None:
        self.leaf = leaf
        self.keys = []
        self.childrens = []

class BTree:
    def __init__(self, size) -> None:
        self.root = Node(True)
        self.size = size

    def insertion(self, x):
        root = self.root
        if len(root.keys) == (2 * self.size) - 1:
            temp = Node()
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
        temp = Node(x.leaf)
        root.childrens.insert(i+1, temp)
        root.keys.insert(i, x.keys[self.size - 1])
        temp.keys = x.keys[self.size:]
        x.keys = x.keys[0: self.size-1]
        if not x.leaf:
            temp.childrens = x.childrens[self.size: ]
            x.childrens = x.childrens[0: self.size]


    def printBST(self, l = 0, root = None):
        print("Level", l,end=": ")
        if root:
            for i in root.keys:
                print(i, end=" ")
            print()
            if len(root.childrens) > 0 :
                l += 1
                for i in root.childrens:
                    self.printBST(l, i)
        else:
            self.printBST(l, self.root) 


if __name__ == "__main__":
    bst = BTree(size=3)

    for i in range(20):
        bst.insertion((i, 2*i))
    
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
       