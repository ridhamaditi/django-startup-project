# you need to try a different approach in which you'll need to make two lists
# and put all elements of production rule which are on right side having left recursion
# and in second list you'll put all remaining elements which aren't having lr
# then form answer containing first list in S'
# and second list elements into S

def if_left_rec(S, elem):
    for i in elem:
        if S==i[0]:
            return True
    return False

def find_left(S, elem):
    for i in range(len(elem)):
        if S==elem[i][0]:
            return i

prod_rule = input("Enter Production Rule: ")
str1 = prod_rule.split("=")
for i in range(len(str1)):
    str1[i] = str1[i].strip()
elem = str1[1].split("/")
for i in range(len(elem)):
    elem[i] = elem[i].strip()
if(if_left_rec(str1[0], elem)):
    pos = find_left(str1[0], elem)
    lefty = elem.pop(pos)
    S = ""
    S1 = ""
    for i in range(len(elem)):
        S = S + elem[i] + "S1"
        if(i != len(elem)-1):
            S = S + " / "
    S1 = lefty[1:] + "S1 / null"
    print("S =",S)
    print('S1 =',S1)
else:
    print('No left recursion in given production rule.')
