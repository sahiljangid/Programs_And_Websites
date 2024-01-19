
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
        print("Weigths:", weights)
        print_graph()

def add_edge(v1, v2, weight):
    if v1 not in node_names:
        print(v1,"Node is not present in Graph")
    elif v2 not in node_names:
        print(v2, "Node is not present in Graph")
    else:
        ind1 = node_names.index(v1)
        ind2 = node_names.index(v2)
        graph[ind1][ind2] = 1
        graph[ind2][ind1] = 1
        weights[(v1, v2)] = weight
        weights[(v2, v1)] = weight
        print(f"Edge Connected Successfully Between {v1} and {v2} with weight {weight}")
        print("Nodes:", node_names)
        print("Graph:", graph)
        print("Weigths:", weights)
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
        print("Weigths:", weights)
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
        del weights[(v1, v2)]
        del weights[(v2, v1)]
        print(f"Edge Disconnected Successfully Between {v1} and {v2}")
        print("Nodes:",node_names)
        print("Graph:",graph)
        print("Weigths:",weights)
        print_graph()



def print_graph():
    for i in range(count):
        for j in range(count):
            print(graph[i][j], end=" ")
        print()

node_names = []
graph = []
weights = {}
count = 0
print("************************ Wel-Come ************************")
print("Nodes:", node_names)
print("Graph:", graph)
add_node("A")
add_node("B")
add_node("C")
add_node("D")
add_node("E")
add_edge("A","B",10)
add_edge("A","C",20)
add_edge("A","D",30)
add_edge("C","D",40)
add_edge("B","D",50)
add_edge("D","E",60)
add_edge("B","E",70)
add_node("F")
add_edge("F","E",80)
delete_node("F")
delete_edge("C","D")









