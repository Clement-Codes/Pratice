
class Graph:
    def __init__(self, vertex) -> None:
        self.vertex = vertex
        self.graph = []
    
    def addEdge(self, u, v, d):
        self.graph.append([u, v, d])

    def BellmanFordAlgo(self, startVertex):
        distance = [float('Inf')] * self.vertex
        distance[startVertex] = 0
        for _ in range(self.vertex - 1):
            for u, v, d in self.graph:
                if distance[u] != float('Inf') and distance[v] > distance[u] + d:
                    distance[v] = distance[u] + d
        
        for u, v, d in self.graph:
            if distance[u] != float('Inf') and distance[v] > distance[u] + d:
                print("Graph contains negative cycle")
        self.print(distance)
    
    def print(self, distance):
        for i, j in enumerate(distance):
            print(i," ", j)

if __name__ == "__main__":
    g = Graph(5)
    g.addEdge(0, 1, -1)
    g.addEdge(0, 2, 4)
    g.addEdge(1, 2, 3)
    g.addEdge(1, 3, 2)
    g.addEdge(1, 4, 2)
    g.addEdge(3, 2, 5)
    g.addEdge(3, 1, 1)
    g.addEdge(4, 3, -3)

    g.BellmanFordAlgo(0)
