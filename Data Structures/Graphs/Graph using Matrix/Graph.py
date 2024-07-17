class Graph:
    def __init__(self, n) -> None:
        self.n = n
        self.data = [[0] * n]*n

    def addVertieces(self, vertex):
        if self.n >vertex
        pass

    def addEdge(self, edge):
        if edge[0]>=self.n or edge[1]>=self.n:
            print("No vertices found")
        elif edge[0] == edge[1]:
            print("Same vertices")
        else:
            self.data[edge[0]][edge[1]] = self.data[edge[1]][edge[0]] = 1
    


if __name__ == '__main__':
    g = Graph(4)
    print(g.data)