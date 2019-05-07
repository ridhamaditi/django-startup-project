# left factoring

def find_len_common(ls):
    le = 0
    p1 = ls[0]
    i = 0
    for j in p1:
        if(j == ls[1][i]):
            le+=1
            i+=1
        else:
            break
    return le

rule = input('Enter production rule: ')
prod = rule.split('=')
for i in range(len(prod)):
    prod[i] = prod[i].strip()
elem = prod[1].split('/')
for i in range(len(elem)):
    elem[i] = elem[i].strip()
length = find_len_common(elem)
if length > 0:
    St = elem[0][:length] # retrieve common factor
    S1 = ''
    for i in range(len(elem)):
        if i < (len(elem) - 1):
            S1 += elem[i][length:] + '/'
        else:
            S1 += elem[i][length:]
    print('\n\nS =',St,'\bS1')
    print('S1 =',S1)
else:
    print('No left factoring can be performed')
