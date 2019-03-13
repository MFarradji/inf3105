from collections import deque


class Node:
    def __init__(self):
        self.edges = set()


class Graph:
    def __init__(self):
        self.nodes = {}  # node id => node object

    def add_node(self, identifier):
        node = Node()
        self.nodes[identifier] = node

    def add_undirected_edge(self, idA, idB):
        self.nodes[idA].edges.add(idB)
        self.nodes[idB].edges.add(idA)

    def add_directed_edge(self, idA, idB):
        self.nodes[idA].edges.add(idB)

    def dfs(self, start_id):
        visited = set()
        stack = []
        stack.append(start_id)
        while len(stack) != 0:
            identifier = stack.pop()
            if identifier not in visited:
                print(identifier, end=' ')
                visited.add(identifier)
                for edge in graph.nodes[identifier].edges:
                    stack.append(edge)
        print()

    def bfs(self, start_id, visited=set()):
        queue = deque()
        queue.append(start_id)
        visited.add(start_id)
        while len(queue) != 0:
            identifier = queue.popleft()
            print(identifier, end=' ')
            for edge in graph.nodes[identifier].edges:
                if edge not in visited:
                    visited.add(edge)
                    queue.append(edge)


    def extract_connected_components(self):
        print("{ ", end='')
        visited = set()
        for node_id in self.nodes:
            if node_id not in visited:
                print("{ ", end='')
                self.bfs(node_id, visited)
                print("} ", end='')
        print("}")

def create_graph1():
    graph = Graph()

    for i in range(8):
        identifier = chr(ord('a') + i) 
        graph.add_node(identifier)

    edges = [
        ('a', 'b'), ('a', 'c'), ('a', 'e'), ('b', 'c'), ('b', 'f'),
        ('c', 'd'), ('d', 'e'), ('d', 'f'), ('d', 'h'), ('e', 'g'),
        ('f', 'h'), ('g', 'h')
    ]

    for edge in edges:
        graph.add_undirected_edge(edge[0], edge[1])

    return graph


def create_graph2():
    graph = Graph()

    for i in range(8):
        identifier = chr(ord('a') + i) 
        graph.add_node(identifier)
    graph.add_node('x')
    graph.add_node('y')
    graph.add_node('z')

    edges = [
        ('a', 'b'), ('a', 'c'), ('b', 'c'), ('d', 'e'), ('d', 'f'), ('d', 'h'), ('e', 'g'), ('f', 'h'), ('g', 'h'), ('x', 'y')
    ]

    for edge in edges:
        graph.add_undirected_edge(edge[0], edge[1])

    return graph


def create_graph3():
    graph = Graph()

    for i in range(8):
        identifier = chr(ord('a') + i) 
        graph.add_node(identifier)

    edges = [
        ('a', 'b'), ('a', 'e'), ('b', 'a'), ('b', 'c'), ('b', 'f'),
        ('c', 'a'), ('c', 'b'), ('d', 'c'), ('d', 'e'), ('d', 'h'),
        ('e', 'd'), ('e', 'g'), ('f', 'd'), ('g', 'e'), ('g', 'h'),
        ('h', 'f')
    ]

    for edge in edges:
        graph.add_directed_edge(edge[0], edge[1])

    return graph


graphs = [create_graph1(), create_graph2(), create_graph3()]

for i, graph in enumerate(graphs):
    print("graph #{}".format(i + 1))
    print("dfs")
    graph.dfs('a')
    graph.dfs('c')
    print("bfs")
    graph.bfs('a', set())
    print()
    graph.bfs('c', set())
    print()
    print("connected components")
    graph.extract_connected_components()
