class GraphByMatrix:
    def __init__(self, n) -> None:
        self.n = n
        self.graph = [[0,0,0,0],[0,0,0,0],[0,0,0,0],[0,0,0,0]]
    
    def print(self):
        for i in range(0,self.n):
            for j in range(0,self.n):
                print(self.graph[i][j], sep=" ", end="")
            print()

    def addEdge(self, x, y):
        if x >= self.n or y >= self.n:
            print("No Vertex found")
        elif x == y:
            print("Same Vertex")
        else:
            self.graph[x][y] = 1
            self.graph[y][x] = 1

    def removeEdge(self, x, y):
        if x >= self.n or y >= self.n:
            print("No Vertex found")
        elif x == y:
            print("Same Vertex")
        else:
            self.graph[x][y] = 0        
            self.graph[y][x] = 0

    def addVertex(self):
        for i in range(0,self.n):
            self.graph[i] = self.graph[i] + [0]
        self.n += 1
        self.graph.append([0] * self.n)

    def removeVertex(self, x):
        if x >= self.n:
            print('No Vertex to be removed')
        else:
            while x < self.n - 1:
                for i in range(self.n):
                    self.graph[i][x] = self.graph[i][x+1]
                for i in range(self.n):
                    self.graph[x][i] = self.graph[x+1][i]
                x +=1
            for i in range(self.n):
                self.graph[i].pop(-1)
            self.graph.pop(-1)
            self.n -= 1

if __name__ == "__main__":
    g = GraphByMatrix(4)
    g.print()
    g.addEdge(0, 1)
    g.print()
    g.addEdge(0, 2)
    g.addEdge(1, 2)
    g.addEdge(2, 3)

    g.print()
    
    g.addVertex()
    g.addEdge(4, 1)
    g.addEdge(4, 3)
    g.print()
        
    g.removeVertex(1)
    g.print()

# class Graph:
#     def __init__(self, n) -> None:
#         self.n = n
#         self.data = [[0] * n]*n

#     def addVertieces(self, vertex):
#         if self.n >vertex
#         pass

#     def addEdge(self, edge):
#         if edge[0]>=self.n or edge[1]>=self.n:
#             print("No vertices found")
#         elif edge[0] == edge[1]:
#             print("Same vertices")
#         else:
#             self.data[edge[0]][edge[1]] = self.data[edge[1]][edge[0]] = 1
    
#     def deleteEdge():
#         pass

#     def deleteVertex():
#         pass

# if __name__ == '__main__':
#     g = Graph(4)
#     print(g.data)