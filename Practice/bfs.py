# breadth first search algorithm
# performs a breadth first search on a graph and returns the path from the start node to the end node
# if no path is found, returns None
# if the start node is the end node, returns the start node
# if the start node or end node is not in the graph, returns None
# if the graph is empty, returns None
# works with both directed and undirected graphs

def bfs(graph, start, end):
    # create a queue for the nodes to visit
    visit = []
    # create a set for the visited nodes
    visited = set()
    # create a dictionary to store the path
    path = {}
    # add the start node to the queue
    visit.append(start)
    # while the queue is not empty
        # get the first node from the queue
        # if the node is the end node
            # return the path
        # if the node has not been visited
            # add the node to the visited set
            # add the node to the path
            # add the node's children to the queue
    while(len(visit) > 0):
        node = visit.pop(0)
        if node == end:
            return path
        if node not in visited:
            visited.add(node)
            path[node] = graph[node]
            for child in graph[node]:
                visit.append(child)
    
    # if no path is found, return None
    if(end not in path):
        return None
    pass


