import numpy as np
import matplotlib.pyplot as plt
import networkx as nx
import queue


def bfs(graph, start):
    visited = [False] * len(graph) 
    q = queue.Queue()
    q.put(start)
    visited[start] = True

    while not q.empty():
        current = q.get()
        print(current, end=' ')
        for i in range(len(graph)):
            if graph[current][i] == 1 and not visited[i]:
                q.put(i)
                visited[i] = True


adj_matrix = np.array([
    [0, 1, 0, 0, 1],
    [1, 0, 1, 0, 0],
    [0, 1, 0, 1, 0],
    [0, 0, 1, 0, 1],
    [1, 0, 0, 1, 0],
])

# Виклик BFS з першої вершини
print("BFS обхід графу:")
bfs(adj_matrix, 0)


plt.figure()
G = nx.from_numpy_array(adj_matrix)
nx.draw(G, with_labels=True, node_color='lightpink', node_size=600, font_weight='bold', edge_color='black')
plt.show()

