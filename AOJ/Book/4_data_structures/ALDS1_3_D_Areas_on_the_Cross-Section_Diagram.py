from sys import stdin

strs = stdin.readline().rstrip()
#strs = "\\\\///\_/\/\\\\\\\\/_/\\\\///__\\\\\_\\\\/_\/_/\\"
area_all = 0
stack_1 = []
stack_2 = []

for i, c in enumerate(strs):
    if c == '\\':
        stack_1.append(i)
    elif c == '/' and len(stack_1) > 0:
        start = stack_1.pop()
        area_all += i - start
        area_each = i - start
        while stack_2 and stack_2[-1][0] > start:
            #水たまりを合体
            s, area = stack_2.pop()
            area_each += area
        stack_2.append((start, area_each))

print(area_all)
each_ans = [area for i, area in stack_2]
print(len(stack_2), *each_ans)
