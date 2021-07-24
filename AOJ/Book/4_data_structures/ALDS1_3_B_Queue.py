"""
class Queue:
    def __init__(n):
        self.head = 0
        self.tail = 0
        self.n = 0
        self.queue = []

    def isEmpty():
        return head == tail
    
    def isFull():
        return head == (tail+1) % self.n
    
    def enqueue(pr, tm):
        if isFull():
            print("error")
            exit(1)
        self.queue[self.tail] = (pr, tm)
        tail = 0 if tail+1 = self.n else tail+1

    def dequeue():
        if isEmpty():
            print("error")
            exit(1)
        pr, tm = self.queue[head]
        head = 0 if head+1 = self.n else head+1
        return pr, tm
"""

def schedule(lst, q):
    #環状のqueue
    head = 0; tail = len(lst)-1
    time = 0
    ans = []
    while head != tail:
        pr, tm = lst[head]
        head = 0 if head+1 == n else head+1
        tm = int(tm)
        if tm <= q:
            time += tm
            ans.append((pr, time))
        else:
            tail = 0 if tail+1 == n else tail+1
            time += q
            lst[tail] = (pr, tm - q)
    #最後の要素
    pr, tm = lst[head]
    ans.append((pr, time + int(tm)))
    return ans


n, q = map(int, input().split())
lst = []
for i in range(n):
    p, t = input().split()
    lst.append((p, t))
ans = schedule(lst, q)
#print("---")
for pr, tm in ans:
    print(pr, tm)
