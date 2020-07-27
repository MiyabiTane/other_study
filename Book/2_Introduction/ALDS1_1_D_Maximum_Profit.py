n = int(input())

max_n = -float('inf')
for i in range(n):
    num = int(input())
    if i == 0:
        min_n = num
    else:
        if num - min_n > max_n:
            max_n = num - min_n
        if num < min_n:
            min_n = num
print(max_n)

    
    
