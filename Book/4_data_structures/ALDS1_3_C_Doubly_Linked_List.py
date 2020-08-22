class Node:
    def __init__(self, key):
        self.key = key
        self.prev = None
        self.next = None


class DoublyLinkedList:
    def __init__(self):
        self.head = None
        self.tail = None

    def insert(self, x):
        new_node = Node(x)
        if self.head == None:
            self.head = new_node
            self.tail = new_node
        else:
            new_node.next = self.head
            self.head.prev = new_node
            self.head = new_node

    def delete(self, x):
        cur = self.head
        while cur:
            #print("key", cur.key)
            if cur.key == x:
                if cur.prev == None and cur.next == None:
                    self.head = None
                    self.tail = None
                else:
                    if cur == self.head:
                        self.head = self.head.next
                    else:
                        cur.prev.next = cur.next
                    if cur == self.tail:
                        self.tail = self.tail.prev
                        self.tail.next = None
                    else:
                        cur.next.prev = cur.prev
                break
            cur = cur.next

    def deleteFirst(self):
        if self.head == self.tail:
            self.head = None
            self.tail = None
        else:
            self.head = self.head.next
            self.head.prev = None

    def deleteLast(self):
        if self.head == self.tail:
            self.head = None
            self.tail = None
        else:
            self.tail = self.tail.prev
            self.tail.next = None

    def printList(self):
        ans = []
        cur = self.head
        if cur != None:
            #print("head",self.head.key," tail",self.tail.key)
            while cur:
                ans.append(cur.key)
                cur = cur.next
        print(*ans)


l = DoublyLinkedList()
n = int(input())
#print("---")
for i in range(n):
    cmd = input()
    if cmd[7].isdigit():
        target_num = int(cmd[7:])
        if cmd[0] == 'i':
            l.insert(target_num)
        elif cmd[0] == 'd':
            l.delete(target_num)
    else:
        if cmd[6] == 'F':
            l.deleteFirst()
        elif cmd[6] == 'L':
            l.deleteLast()
    #l.printList()
l.printList()
