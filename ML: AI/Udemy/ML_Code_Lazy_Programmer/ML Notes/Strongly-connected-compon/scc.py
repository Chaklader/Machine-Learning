import sys

# Problem description: Find the strongly connected components in a graph

# Input:
# Each test file consists of m+1 lines.
# The first line contains two integers n and m, separated by a space.
# As usual, n is the total number of nodes in the graph and m is the
# total number of edges. Nodes are indexed from 1 to n.
# Each of the next m lines contains two integers u and v separated by a
# space, and indicating a directed edge from node u to node v.

# Output:
# -------
# Your output file should consist of K+1 lines, where K is the number
# of strongly connected components in the input graph.
# The first line in your output file should only contain K.
# Each of the next K lines should contain P+1 integers separated by spaces,
# where P is the number of nodes in the strongly connected component.
# The first integer in each line is P.
# The next P integers in the line are the nodes in the
# strongly connected component.
# Within each strongly connected component, the nodes must be sorted in
# increasing order in terms of their indices.
# The strongly connected components must appear sorted in increasing order
# in terms of the index of their first node.

class Graph(object):
    def __init__(self, g, n, m):
        self.graph = g
        self.nodes = n
        self.edges = m
        self.explored = [0]*(n+1) # indexed by vertex, 0 is never touched

    # Reverses the directed edges of a graph, returning a new graph
    def reverse(self):
        graph = {}
        for i, j_list in self.graph.iteritems():
            for j in j_list:
                if j not in graph:
                    graph[j] = []
                graph[j].append(i)
        return Graph(graph, self.nodes, self.edges)


# Read a directed graph from standard input
def read_graph(filename):
    lines = [line.strip() for line in open(filename)]
    graph = {}
    nodes, edges = [int(n) for n in lines[0].split()]
    for edge in lines[1:]:
        i, j = [int(n) for n in edge.split()]
        if i not in graph:
            graph[i] = []
        graph[i].append(j)
    return Graph(graph, nodes, edges)


# Find Strongly Connected Components using Kosaraju's algorithm
# Kosaraju's algorithm works as follows:
#
# Let G be a directed graph and S be an empty stack.
# While S does not contain all vertices:
#   Choose an arbitrary vertex v not in S.
#   Perform a depth-first search starting at v.
#   Each time that depth-first search finishes expanding a vertex u, push u onto S.
# Reverse the directions of all arcs to obtain the transpose graph.
# While S is nonempty:
#   Pop the top vertex v from S.
#   Perform a depth-first search starting at v in the transpose graph.
#   The set of visited vertices will give the strongly connected component containing v;
#   record this and remove all these vertices from the graph G and the stack S. 
def scc(g):
    results = []
    # Initial DFS on G
    search_stack = []
    for v, explored in enumerate(g.explored):
        if not explored and v > 0:
            dfs(g, v, search_stack)

    # Reverse Graph
    gr = g.reverse()

    # DFS ordered by search_stack
    while len(search_stack) > 0:
        u = search_stack[-1]
        scc_stack = []
        dfs(gr, u, scc_stack)
        for v in scc_stack:
            if v in gr.graph:
                del gr.graph[v]
            search_stack.remove(v)
        results.append(scc_stack)
    return results


# Depth first search with postorder append to stack
def dfs(g, u, stack):
    g.explored[u] = 1
    if u in g.graph:
        for v in g.graph[u]:
            if not g.explored[v]:
                dfs(g, v, stack)
    stack.append(u)


# This is where the program starts executing
if __name__ == "__main__":
    if len(sys.argv) < 2:
        print "Usage: python scc.py <input_graph>"
        exit()

    G = read_graph(sys.argv[1])
    results = [sorted(result) for result in scc(G)]
    results.sort(key=lambda result: result[0])
    print len(results)
    for result in results:
        print len(result), ' '.join(map(str, result))
