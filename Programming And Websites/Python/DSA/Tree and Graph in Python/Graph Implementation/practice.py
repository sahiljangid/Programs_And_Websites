
def add_node(v):
    if v in graph:
        print(v," is already present in graph")
    else:
        graph[v] = []

def delete_node(v):
    if v not in graph:
        print(v," is not present in graph")
    else:
        graph.pop(v)
        for i in graph:
            lst = graph[i]
            if v in lst:
                lst.remove(v)
        print(v," node deleted successfully")

def add_edge(v1,v2):
    if v1 not in graph:
        print(v1," is not present in the graph")
    elif v2 not in graph:
        print(v2," is not present in the graph")
    else:
        graph[v1].append(v2)
        graph[v2].append(v1)

def delete_edge(v1, v2):
    if v1 not in graph:
        print(v1," is not present in the graph")
    elif v2 not in graph:
        print(v2," is not present in the graph")
    else:
        if v1 in graph[v2]:
            graph[v1].remove(v2)
            graph[v2].remove(v1)
            print(f"Edge disconnected successfully between {v1} and {v2}")


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
    print()

def DFS_traversal(node, visited, graph):
    if node not in graph:
        print(node," is not present in graph")
    if node not in visited:
        print(node,end=" ")
        visited.add(node)
        for i in graph[node]:
            DFS_traversal(i, visited, graph)





visited = set()

graph = {}

add_node("A")
add_node("B")
add_node("C")
add_node("D")
add_node("E")
print(graph)
add_edge("A","B")
add_edge("A","C")
add_edge("A","D")
add_edge("C","D")
add_edge("B","D")
add_edge("B","E")
add_edge("D","E")
print(graph)
add_node("F")
print(graph)
add_edge("E","F")
print(graph)
delete_node("F")
print(graph)
delete_edge("E","D")
print(graph)
print("\nBFS Traversal")
BFS_traversal("A",graph)
print("DFS Traversal")
DFS_traversal("A",visited,graph)









