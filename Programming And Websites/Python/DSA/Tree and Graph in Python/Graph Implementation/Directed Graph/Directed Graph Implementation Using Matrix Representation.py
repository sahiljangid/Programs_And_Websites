
def add_node(vertex): ## Add new node into the matrix
    global count
    if vertex in node_names: ## Node can't be add into the graph if new node is already present into the graph
        print(vertex," is already present in Graph")
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
        print(f"Edge Connected Successfully from {v1} to {v2}")
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
        print(f"Edge Disconnected Successfully from {v1} to {v2}")
        print("Nodes:",node_names)
        print("Graph:",graph)
        print_graph()



def print_graph():
    for i in range(count):
        for j in range(count):
            print(graph[i][j], end=" ")
        print()

node_names = []
graph = []
count = 0
print("************************ Directed Graph Using Matrix Representation ************************")
print("Nodes:", node_names)
print("Graph:", graph)
add_node("A")
add_node("B")
add_node("C")
add_node("D")
add_node("E")
add_edge("A","B")
add_edge("A","C")
add_edge("A","D")
add_edge("C","D")
add_edge("B","D")
add_edge("D","E")
add_edge("B","E")
add_node("F")
add_edge("F","E")
delete_node("F")
delete_edge("C","D")









