'''
 map + linked list
# !!!for getting a sorted result in O(1) time: linked list ; OrderedDict in Python!!!

Idea:
- It's easy think about maps.
- It's not easy to think about linked list if you are not familiar with this data structure.
- But to have O(1) access to a node, and to update the recently-used time, linked list is the best choice.
    - Python tip: OrderedDict

# https://leetcode.com/problems/lru-cache/
'''
class Node:
    def __init__(self, k:int, v:int):
        self.key = k
        self.val = v
        self.prev = self.next = None

class LinkedList:
    # doubly linked list
    def __init__(self):
        # dummy nodes to avoid dealing with edge cases
        self.head = Node(0, 0)
        self.tail = Node(0, 0)
        self.head.next = self.tail
        self.tail.prev = self.head
    def add(self, node: Node):
        # add to the bottom (last - * - tail)
        last_node = self.tail.prev
        last_node.next = node
        node.next = self.tail
        self.tail.prev = node
        node.prev = last_node

    def remove(self, node: Node):
        # unlink the node:
        next_node = node.next
        prev_node = node.prev
        next_node.prev = prev_node
        prev_node.next = next_node


class LRUCache:
    # https://www.romaglushko.com/blog/design-lru-cache/
    def __init__(self, capacity: int):
        # add the node; get the node both consider to be "use"
        self.cache = {}
        self.int2node = dict()
        self.history = LinkedList()
        self.capacity = capacity

    def get(self, key: int) -> int:
        if key in self.int2node:
            # refresh the recently-used time
            n = self.int2node[key]
            self.history.remove(n)
            self.history.add(n)
            return n.val
        # otherwise return -1
        return -1


    def put(self, key: int, value: int) -> None:
        # re add the node to set the recently-used time

        if key in self.int2node:
            n = self.int2node[key]
            self.history.remove(n)
        n = Node(key, value)
        self.int2node[key] = n
        self.history.add(n)
        # print(key, self.int2node)
        if len(self.int2node) > self.capacity:
            # remove least recently used
            first  = self.history.head.next
            self.history.remove(first)
            del self.int2node[first.key]
