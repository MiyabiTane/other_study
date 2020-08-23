
from sys import stdin

class Node:
    def __init__(self, key):
        self.key = key
        self.prev = None
        self.next = None


class DoublyLinkedList:
    def __init__(self):
        self.nil = Node(None)  # tail->nil->head
        self.nil.next = self.nil
        self.nil.prev = self.nil

    def insert(self, x):
        new_node = Node(x)
        new_node.next = self.nil.next
        self.nil.next.prev = new_node
        self.nil.next = new_node
        new_node.prev = self.nil

    def listSearch(self, x):
        cur = self.nil.next
        while(cur != self.nil and cur.key != x):
            cur = cur.next
        return cur

    def deleteNode(self, node):
        if node == self.nil:
            return
        node.prev.next = node.next
        node.next.prev = node.prev

    def delete(self, x):
        cur = self.listSearch(x)
        self.deleteNode(cur)

    def deleteFirst(self):
        self.deleteNode(self.nil.next)

    def deleteLast(self):
        self.deleteNode(self.nil.prev)

    def printList(self):
        ans = []
        cur = self.nil.next
        while cur != self.nil:
            ans.append(cur.key)
            cur = cur.next
        print(*ans)


l = DoublyLinkedList()
n = int(input())
#print("---")
for i in range(n):
    cmd = stdin.readline()
    if cmd[0] == 'i':
        l.insert(int(cmd[7:]))
    else:
        if cmd[6] == 'F':
            l.deleteFirst()
        elif cmd[6] == 'L':
            l.deleteLast()
        else:
            l.delete(int(cmd[7:]))
    #l.printList()
l.printList()
