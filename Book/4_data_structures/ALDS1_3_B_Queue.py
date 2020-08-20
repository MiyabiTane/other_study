def schedule(lst, q):
    time = 0
    ans = []
    while lst:
        pr, tm = lst.pop(0)
        tm = int(tm)
        if tm <= q:
            time += tm
            ans.append((pr, time))
        else:
            lst.append((pr, tm - q))
            time += q
    return ans


n, q = map(int, input().split())
lst = []
for i in range(n):
    p, t = input().split()
    lst.append((p, t))
ans = schedule(lst, q)
for pr, tm in ans:
    print(pr,tm)

