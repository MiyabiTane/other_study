def calc(stack, char):
    num1 = int(stack.pop())
    num2 = int(stack.pop())
    if char == "+":
        return num2 + num1
    elif char == "-":
        return num2 - num1
    elif char == "*":
        return num2 * num1
    elif char == "/":
        return num2 / num1


def polish(lst):
    stack = []
    while lst:
        char = lst.pop(0)
        if char.isdigit():
            stack.append(char)
        else:
            num = calc(stack, char)
            stack.append(num)
        #print(stack)
    return int(stack.pop())


lst = list(input().split()) #['1','2','+','3','4','-','*'] 
ans = polish(lst)
print(ans)
            

