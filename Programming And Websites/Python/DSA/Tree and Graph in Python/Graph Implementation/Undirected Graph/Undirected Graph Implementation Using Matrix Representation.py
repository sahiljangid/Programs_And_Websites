
def add_node(vertex): ## Add new node into the matrix
    global count
    if vertex in node_names: ## Node can't be add into the graph if new node is already present into the graph
        print(vertex,"is already present in Graph")
    else:
        count += 1
        node_names.append(vertex)
        for new_column in graph: ## Create new column into all the vertices and add them into the graph
            new_column.append(0)
        new_row = []
        for i in range(count): ## Create new row
            new_row.append(0)
        graph.append(new_row) ## Add new row into graph
        print(vertex,"node added successfully into the graph")
        print("Nodes:", node_names)
        print("Graph:", graph)
        print_graph()

def add_edge(v1, v2):
    if v1 not in node_names:
        print(v1,"Node is not present in Graph")
    elif v2 not in node_names:
        print(v2, "Node is not present in Graph")
    else:
        ind1 = node_names.index(v1)
        ind2 = node_names.index(v2)
        graph[ind1][ind2] = 1
        graph[ind2][ind1] = 1
        print(f"Edge Connected Successfully Between {v1} and {v2}")
        print("Nodes:", node_names)
        print("Graph:", graph)
        print_graph()




def delete_node(vertex):
    global count
    if vertex not in node_names:
        print(vertex,"is not present in the graph")
    else:
        indx = node_names.index(vertex)
        count -= 1
        node_names.remove(vertex)
        graph.pop(indx)
        for n in graph:
            n.pop(indx)
        print(vertex,"node deleted successfully")
        print("Nodes:", node_names)
        print("Graph:", graph)
        print_graph()




def delete_edge(v1, v2):
    if v1 not in node_names:
        print(v1, "Node is not present in Graph")
    elif v2 not in node_names:
        print(v2, "Node is not present in Graph")
    else:
        ind1 = node_names.index(v1)
        ind2 = node_names.index(v2)
        graph[ind1][ind2] = 0
        graph[ind2][ind1] = 0
        print(f"Edge Disconnected Successfully Between {v1} and {v2}")
        print("Nodes:",node_names)
        print("Graph:",graph)
        print_graph()



### Traversing


## BFS
def bfs(graph, start):
    visited = set()
    queue = [start]
    bfs_traversal = []

    while queue:
        vertex = queue.pop(0)
        if vertex not in visited:
            visited.add(vertex)
            bfs_traversal.append(vertex)
            neighbors = [node_names[i] for i, value in enumerate(graph[node_names.index(vertex)]) if value == 1]
            queue.extend([v for v in neighbors if v not in visited])
    print(bfs_traversal)



## DFS
def dfs(graph, start):
    visited = set()
    stack = [start]
    dfs_traversal = []
    while stack:
        vertex = stack.pop()
        if vertex not in visited:
            visited.add(vertex)
            dfs_traversal.append(vertex)
            neighbors = [node_names[i] for i, value in enumerate(graph[node_names.index(vertex)]) if value == 1]
            stack.extend([v for v in neighbors if v not in visited])
    print(dfs_traversal)







def print_graph():
    for i in range(count):
        for j in range(count):
            print(graph[i][j], end=" ")
        print()

node_names = []
graph = []
count = 0
print("************************ Undirected Graph Using Matrix Representation ************************")
print("Nodes:", node_names)
print("Graph:", graph)
add_node("A")
add_node("B")
add_node("C")
add_node("D")
add_node("E")
add_node("F")
add_node("G")
add_node("H")
add_node("K")
add_edge("A","B")
add_edge("A","D")
add_edge("B","C")
add_edge("B","D")
add_edge("C","F")
add_edge("D","E")
add_edge("D","G")
add_edge("E","F")
add_edge("E","G")
add_edge("E","H")
add_edge("F","H")
add_edge("F","K")
add_edge("G","H")

print("BFS Traversal: ")
bfs(graph,"A")

print("DFS Traversal: ")
dfs(graph,"A")



# vertex = "A"
# neighbors = [node_names[i] for i, value in enumerate(graph[node_names.index(vertex)]) if value == 1]
# print(neighbors)




