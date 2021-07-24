#gだけ離れた要素のみを対象にした挿入ソート
def insertionSort(lst, n, g, cnt):
    for i in range(g,n):
        v = lst[i]
        j = i - g
        while j >= 0 and lst[j] > v:
            lst[j+g] = lst[j]
            j = j - g
            cnt += 1
        lst[j+g] = v
    return cnt

def gGenerator(n):
    G = [1]
    while True:
        g = 3 * G[-1] + 1
        if g > n:
            return G[::-1]
        G.append(g)

def shellSort(lst, n):
    cnt = 0
    #G(n+1) = G(n)+1
    G = gGenerator(n)
    print(len(G))
    print(*G)
    for i in range(len(G)):
        cnt = insertionSort(lst, n, G[i], cnt)
    print(cnt)
    return lst


n = int(input())
lst = []
for i in range(n):
    lst.append(int(input()))
lst_n = shellSort(lst, n)
for num in lst_n:
    print(num)

#挿入ソートの「ほぼ整列されたデータに対して高速に動作する」
#という長所を活かしたアルゴリズム


