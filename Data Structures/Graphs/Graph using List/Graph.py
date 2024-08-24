class AdjNode():
    def __init__(self, data) -> None:
        self.data = data
        self.next = None


class GraphByList():
    def __init__(self, v) -> None:
        self.vertex = v
        self.graph = [None] * v

    def print(self):
        for i in range(len(self.graph)):
            print(i, end="")
            temp = self.graph[i]
            while temp:
                print(" -> ",temp.data,end="")
                temp = temp.next
            print()

    def addEdge(self, x, y):
        temp = AdjNode(y)
        temp.next = self.graph[x]
        self.graph[x] = temp

        temp = AdjNode(x)
        temp.next = self.graph[y]
        self.graph[y] = temp

    def removeEdge(self, x, y):
        temp = self.graph[x]
        if temp != None and temp.data == y:
            self.graph[x] = temp.next
        else:
            while temp != None:
                if temp.next.data == y:
                    temp.next = temp.next.next
                    break
                else:
                    temp = temp.next

        temp = self.graph[y]

        if temp != None and temp.data == x:
            self.graph[y] = temp.next
        else:
            while temp != None:
                if temp.next.data == x:
                    temp.next = temp.next.next
                    break
                else:
                    temp = temp.next



    def addVertex(self, x, y, z):
        self.addEdge(y, x)
        self.addEdge(x, z)

    def deleteVertex(self, v):
        for i in range(len(self.graph)):
            temp = self.graph[i]
            if i == v:
                self.graph[i] = temp.next
                temp = self.graph[i]
            while temp!=None:
                if(temp.data == v):
                    break
                prev = temp
                temp = temp.next
                if(temp == None):
                    continue
                prev.next = temp.next
                temp = None
            
                

if __name__ == "__main__":
    # g = GraphByList(5)
 
    # g.addEdge(0, 1)
    # g.addEdge(0, 4)
    # g.addEdge(1, 2)
    # g.addEdge(1, 3)
    # g.addEdge(1, 4)
    # g.addEdge(2, 3)
    # g.addEdge(3, 4)
 
    # g.print()

    # g.removeEdge(1, 4)
 
    # g.print()
    g = GraphByList(6)
    g.addEdge(0, 1)
    g.addEdge(0, 3)
    g.addEdge(0, 4)
    g.addEdge(1, 2)
    g.addEdge(3, 2)
    g.addEdge(4, 3)

    g.addVertex(5, 3, 2)
    g.print()
    print('__________________________')
    g.deleteVertex(4)
    g.print()
