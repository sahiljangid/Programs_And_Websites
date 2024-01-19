
def add_node(v):
    if v in graph:
        print(v,"is already present in graph")
    else:
        graph[v] = []
        print(v,"node successfully added into the graph")
        print("Graph:", graph)
        print("Weight:", weights)

def delete_node(v):
    if v not in graph:
        print(v,"is not present in graph")
    else:
        graph.pop(v)
        for i in graph:
            lst = graph[i]
            if v in lst:
                lst.remove(v)
        print(v,"node deleted successfully")
        print("Graph:", graph)
        print("Weight:", weights)

def add_edge(v1,v2,weight):
    if v1 not in graph:
        print(v1," is not present in the graph")
    elif v2 not in graph:
        print(v2," is not present in the graph")
    else:
        graph[v1].append(v2)
        weights[(v1, v2)] = weight
        print(f"Edge connected successfully from {v1} to {v2} with weight {weight}")
        print("Graph:", graph)
        print("Weight:", weights)

def delete_edge(v1, v2):
    if v1 not in graph:
        print(v1," is not present in the graph")
    elif v2 not in graph:
        print(v2," is not present in the graph")
    else:
        if v2 in graph[v1]:
            graph[v1].remove(v2)
            del weights[(v1, v2)]
            print(f"Edge disconnected successfully from {v1} to {v2}")
            print("Graph:", graph)
            print("Weight:", weights)


def DFS_traversal(node, visited, graph):
    if node not in graph:
        print(node," is not present in graph")
    if node not in visited:
        print(node,end=" ")
        visited.add(node)
        for i in graph[node]:
            DFS_traversal(i, visited, graph)


def BFS_traversal(start_node, graph):
    visited = []
    queue = [start_node]
    visited.append(start_node)
    while queue:
        node = queue.pop(0)
        print(node, end=" ")
        for neighbor in graph[node]:
            if neighbor not in visited:
                queue.append(neighbor)
                visited.append(neighbor)



visited = set()

graph = {}
weights = {}
add_node("A")
add_node("B")
add_node("C")
add_node("D")
add_node("E")

add_edge("A","B",10)
add_edge("A","C",20)
add_edge("C","D",30)
add_edge("B","D",40)
add_edge("B","E",50)
add_edge("D","E",60)

delete_edge("B","E")
delete_edge("D","E")

delete_node("E")

print("DFS Traversal")
DFS_traversal("A",visited,graph)
print("\nBFS Traversal")
BFS_traversal("A",graph)









