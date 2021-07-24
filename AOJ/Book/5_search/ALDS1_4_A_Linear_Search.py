from sys import stdin

n = int(stdin.readline().rstrip())
lst1 = list(map(int, input().split()))
m = int(stdin.readline().rstrip())
lst2 = list(map(int, input().split()))

count = 0
for num in lst2:
    if num in lst1:
        count += 1
print(count)
