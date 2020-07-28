n = int(input())
lst = list(map(int, input().split()))

for i in range(n):
    v = lst[i]
    j = i - 1
    while j >=0 and lst[j] > v:
        lst[j + 1] = lst[j]
        j -= 1
    lst[j + 1] = v
    print(*lst) 

#安定なソート
#最悪の計算量 O(N^2) ◁データが降順に並んでいる場合
#データが初めから昇順に並んでいればO(N)で済む