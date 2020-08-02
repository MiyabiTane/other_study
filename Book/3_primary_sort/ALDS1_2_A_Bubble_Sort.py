n = int(input())
lst = list(map(int, input().split()))

count = 0
index = 0
while True:
    flag = True
    for i in range(n-1, index, -1):
        if lst[i] < lst[i-1]: #<1>
            count += 1
            lst[i],lst[i-1] = lst[i-1],lst[i]
            flag = False
    index += 1
    if flag:
        break

print(*lst)
print(count)

#安定なソート
#ただし、<1>で<ではなく<=にしてしまうと不安定なソート
#O(N^2)