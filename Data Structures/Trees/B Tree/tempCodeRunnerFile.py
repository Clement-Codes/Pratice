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
        if len(self.root.keys) == (2 * self.size) - 1:
            temp = Node()
            temp.childrens.insert(0, root)
            self.root = temp
            self.split(self.root, 0)
        else:
            self.insertionFull(x, root)

    def insertionFull(self, x, root):
        if root.leaf:
            i = len(root.keys) - 1
            root.keys.insert(i + 1, (None, None))
            while  i>=0 and x[0] < root.keys[i][0]:
                root.keys[i+1] = root.keys[i]
                i -= 1
            i = i + 1
            root.keys[i] = x
        else:
            i = len(root.keys) - 1
            while  i>=0 and x[0] < root.keys[i][0]:
                root.keys[i+1] = root.keys[i]
                i -= 1
            i += 1
            if root.childrens[i].keys[0][0] > x[0]:
                i +=1
            if len(root.childrens[i].keys) == (2 * self.size) - 1:
                self.split(root, i)
                self.insertionFull(x, root.childrens[i])
            else:
                self.insertionFull(x, root.childrens[i])

    def split(self, root, i):
        x = root.childrens[i]
        temp = Node(x.leaf)
        root.childrens.insert(i, temp)
        root.keys.insert(i, x.keys[self.size])
        temp.keys = x.keys[0: self.size]
        x.keys = x.keys[self.size+1: ]
        if not x.leaf:
            temp.childrens = x.childrens[0: self.size]
            x.childrens = x.childrens[self.size: ]


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
        bst.printBST()
        bst.insertion((i, 2*i))