import sys
import queue
import heapq

all_numbers = []
found_list = []
visited = []
listed_queue = []
total_nodes = []

class Node:
    def __init__ (self, identification):
        self.ids = identification
        self.children = []
        self.cost = []
        self.parent = [];
    
    def __lt__ (self, other):
        return self.ids < other.ids

# This function recursively finds a node given a number
# It is guaranteed that the number is in the graph
def findNode(number):
    for i in total_nodes:
        if i.ids == number:
            return i

def openFile(filename):
    firsts = []
    seconds = []
    thirds = []
    for line in filename:
        words = line.split()
        first = int(words[0])
        second = int(words[1])
        third = int(words[2])
        
        firsts.append(first)
        seconds.append(second)
        thirds.append(third)

    #  Combine all nodes and make unique
    all_numbers = firsts + seconds
    all_numbers = list(set(all_numbers))

    # Make a node from each value in total
    for i in all_numbers:
        node = Node(i)
        total_nodes.append(node)

    # Connect all nodes based on first and second array
    for i in range(0, len(firsts)):
        first_node = findNode(firsts[i])
        second_node = findNode(seconds[i])
        first_node.children.append(second_node)
        first_node.cost.append(thirds[i])
        second_node.parent.append(first_node)
        
    return all_numbers;


def BFS(currentNode, end, found_list):

    found_list = found_list + [currentNode]
    if currentNode.ids == end:
        return found_list
    
    shortest = []
    
    for i in currentNode.children:
        if i not in found_list:
            temp = BFS(i, end, found_list)
            if temp and (not shortest or len(temp) < len(shortest)):
                shortest = temp
    return shortest

def DFS(currentNode, visited, end, found_list):

    visited.append(currentNode)

    if (currentNode.ids == end):
        found_list.append(currentNode)
        return found_list

    for i in currentNode.children:
        if i not in visited:
            found_list = DFS(i, visited, end, found_list)
            if found_list:
                found_list.append(currentNode)
                return found_list
    return []
            
def UCS(currentNode, visited, end, cost, found_list):

    found_list = found_list + [currentNode];
    visited.append(currentNode)
    if currentNode.ids == end: # if the current node is the end
        return cost, found_list
        
    cheapest = []
    cheapest_cost = 0
    
    for i in range(0, len(currentNode.children)):
        if currentNode.children[i] not in found_list:
            new_cost = cost + currentNode.cost[i]
            child = currentNode.children[i]
            new_cost, new_list = UCS(child, visited, end, new_cost,found_list)
            if new_list and (not cheapest or cheapest_cost > new_cost):
                cheapest = new_list
                cheapest_cost = new_cost
   
    return cheapest_cost, cheapest;

def printAnswer(results = []):
    answers = []
    for i in results:
        answers.append(i.ids)
    return answers

def main(argv):

    filename = sys.argv[1]
    f = open(filename, 'r')
    all_numbers = openFile(f)
    f.close()

    start = int(sys.argv[2])
    end = int(sys.argv[3])
    search_type = sys.argv[4]

    # Check if numbers are even in the graph
    if end not in all_numbers:
        print('cant find', [])
        return
    if start not in all_numbers:
        print('cant find2', [])
        return
    
    # Figure out which search is being used
    if search_type == 'BFS':
        currentNode = findNode(start)
        answer = BFS(currentNode, end, found_list)
        answers = printAnswer(answer)
        print(answers)
    elif search_type == 'DFS':
        currentNode = findNode(start)
        answer = DFS(currentNode, visited, end, found_list)
        answer.reverse()
        answers = printAnswer(answer)
        print(answers)
    elif search_type == 'UCS':
        currentNode = findNode(start)
        cost, answer = UCS(currentNode, visited, end, 0, found_list)
        answers = printAnswer(answer)
        print(answers)

main(sys.argv[1:])
