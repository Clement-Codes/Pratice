class Graph:
    def __init__(self, vertex):
        self.vertex = vertex
        self.graph = []
    
    def getMinKeys(self, keys, processed ):
        minVal = float("inf")
        minIndex = -1
        for i in range(self.vertex):
            if(keys[i] < minVal and not processed[i]):
                minIndex = i
                minVal = keys[i]
        return minIndex

    def primMST(self):
        parent = [-1] * self.vertex
        processed = [False] * self.vertex
        keys = [float("inf")] * self.vertex

        keys[0] = 0
        parent[0] = 0

        for _ in range(self.vertex):
            minKey = self.getMinKeys(keys, processed)
            processed[minKey] = True
            for i in range(self.vertex):
                if self.graph[minKey][i]>0 and not processed[i] and self.graph[minKey][i] < keys[i]: 
                    keys[i] = self.graph[minKey][i]
                    parent[i] = minKey
        self.print(parent)

    def print(self, parent):
        for i in range(1, self.vertex):
            print(parent[i], " - ", i, " ", self.graph[i][parent[i]])
        


if __name__ == "__main__":
    g = Graph(5)
    g.graph = [[0, 2, 0, 6, 0],
               [2, 0, 3, 8, 5],
               [0, 3, 0, 0, 7],
               [6, 8, 0, 0, 9],
               [0, 5, 7, 9, 0]]

    g.primMST()