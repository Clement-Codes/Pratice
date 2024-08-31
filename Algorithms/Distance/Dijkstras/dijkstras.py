import sys

class Graph:
    def __init__(self, vertex) -> None:
        self.vertex = vertex
        self.graph = []
    
    def minDistance(self, dist, processed):
        min = sys.maxsize
        
        for i in range(self.vertex):
            if dist[i] < min and not processed[i]:
                min = dist[i]
                minIndex = i
        
        return minIndex


    def dijkstras(self, index):
        dist = [sys.maxsize] * self.vertex
        processed = [False] * self.vertex

        dist[index] = 0

        for i in range(self.vertex):
            x = self.minDistance(dist, processed)
            processed[x] = True

            for j in range(self.vertex):
                if self.graph[x][j] and not processed[j] and dist[j] > dist[x] + self.graph[x][j]:
                    dist[j] = dist[x] + self.graph[x][j]

        self.print(dist)

    def print(self, dist):
        for i in range(self.vertex):
            print(i,"  ", dist[i])
 

if __name__ == "__main__":
    g = Graph(9)
    g.graph = [[0, 4, 0, 0, 0, 0, 0, 8, 0],
               [4, 0, 8, 0, 0, 0, 0, 11, 0],
               [0, 8, 0, 7, 0, 4, 0, 0, 2],
               [0, 0, 7, 0, 9, 14, 0, 0, 0],
               [0, 0, 0, 9, 0, 10, 0, 0, 0],
               [0, 0, 4, 14, 10, 0, 2, 0, 0],
               [0, 0, 0, 0, 0, 2, 0, 1, 6],
               [8, 11, 0, 0, 0, 0, 1, 0, 7],
               [0, 0, 2, 0, 0, 0, 6, 7, 0]
               ]
    g.dijkstras(0)