class Graph:
    def __init__(self, vertices) -> None:
        self.vertices = vertices
        self.graph = []
        for i in range(self.vertices):
            self.graph.append([0] * vertices)
    
    def print(self):
        for i in self.graph:
            for j in i:
                print(j, end=" ")
            print()
    
    def addEdge(self, x, y):
        self.graph[x][y] = 1
        self.graph[y][x] = 1
    
    def removeEdge(self, x, y):
        self.graph[x][y] = 0
        self.graph[x][y] = 0
    
    def addVertex(self):
        for i in range(self.vertices):
            self.graph[i].append(0)
        self.vertices += 1
        self.graph.append([0] * self.vertices)
    
    def removeVertex(self,x):
        while x<self.vertices-1:
            for i in range(self.vertices):
                self.graph[i][x] += self.graph[i][x+1]
            for i in range(self.vertices):
                self.graph[x][i] += self.graph[x+1][i] 
            x += 1           
        self.vertices -= 1

    def BST(self, index):        
        lookup = [index]
        done = []
        while lookup:
            c = lookup.pop(0)
            done.append(c)
            temp = self.graph[c]
            for i, j in enumerate(temp):
                if j == 1 and i not in done:
                    lookup.append(i)
        self.printGraph(done)
    
    def DFS(self, index, past):
        if index not in past:
            past.append(index)
            for i, j in enumerate(self.graph[index]):
                if j == 1 and i not in past:
                    self.DFS(i, past)
        
            

    def printGraph(self, graph):
        alpha = ['A', 'B', 'C', 'D', 'E', 'F']
        for i in graph:
            print(alpha[i], end=" ")
        print()
        for i in graph:
            print(i, end=" ")

if __name__ == "__main__":
    g = Graph(6)
    g.addEdge(1, 2)
    g.addEdge(1, 0)
    g.addEdge(2, 0)
    g.addEdge(2, 3)
    g.addEdge(2, 4)

    g.print()

    #g.BST(0)

    past = []
    g.DFS(1, past)
    print(past)
