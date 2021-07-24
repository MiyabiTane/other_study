n = int(input())
lst = list(map(int,input().split()))

count = 0
for i in range(n):
    minj = i
    for j in range(i+1,n):
        if lst[j] < lst[minj]:
            minj = j
    if minj != i:
        lst[i], lst[minj] = lst[minj], lst[i]
        count += 1
print(*lst)
print(count)

#安定でないソート
#O(N^2)

