class Graph:
    def __init__(self, vertex) -> None:
        self.vertex = vertex
        self.graph = []
    
    def addEdge(self, u, v, w):
        self.graph.append([u, v, w])
    
    def getParent(self, parent, i):
        if parent[i] != i:
            parent[i] =  self.getParent(parent, parent[i])
        return parent[i]
    
    def union(self, parent, rank, u, v):
        if rank[u] < rank[v]:
            parent[u] = v
        elif rank[u] > rank [v]:
            parent[v] = u
        else:
            parent[v] = u
            rank[u] += 1

    def kuskals(self):
        self.graph.sort(key=lambda x: x[2])

        parent = []
        rank = []
        for i in range(self.vertex):
            parent.append(i)
            rank.append(0)

        result = []

        e = 0
        while e < self.vertex - 1:
            for u, v, w in self.graph:
                parent_u = self.getParent(parent, u)
                parent_v = self.getParent(parent, v)
                
                if parent_u != parent_v:
                    e += 1
                    self.union(parent, rank, parent_u, parent_v)
                    result.append([u, v, w , parent_u, parent_v])

        for u, v, w, x, y in result:
            print(u,' ', v, ' ', w, ' ', x, ' ', y)

if __name__ == "__main__":
    g = Graph(4)
    g.addEdge(0, 1, 10) 
    g.addEdge(0, 2, 6) 
    g.addEdge(0, 3, 5) 
    g.addEdge(1, 3, 15) 
    g.addEdge(2, 3, 4) 

    g.kuskals()