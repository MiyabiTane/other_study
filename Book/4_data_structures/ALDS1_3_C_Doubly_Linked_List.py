class Node:
    def __init__(self, key):
        self.key = key
        self.prev = None
        self.next = None

class DoublyLinkedList:
    def __init__(self):
        self.head = Node(None)
        self.tail = Node(None)
        self.head.next = self.tail
        self.tail.prev = self.head

    def insert(self, x):
        cur_head = self.head.next
        new_head = Node(x)
        new_head.next = cur_head
        new_head.prev = self.head
        self.head.next = new_head
        cur_head.prev = new_head

    def delete(self, x):
        cur = self.head
        while True:
            pre = cur
            cur = cur.next
            #print("key", cur.key)
            #print("head", self.head.key)
            if cur.key == x:
                pre.next = cur.next
                cur.next.prev = pre
                break
            elif cur.key == None:
                break    

    def deleteFirst(self):
        del_node = self.head.next
        self.head.next = del_node.next
        del_node.next.prev = self.head

    def deleteLast(self):
        del_node = self.tail.prev
        #print("key", del_node.key)
        self.tail.prev = del_node.prev
        del_node.prev.next = self.tail

    def printList(self):
        ans = []
        cur = self.head.next
        while cur != self.tail:
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





        


