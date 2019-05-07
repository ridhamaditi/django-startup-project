# program to find identifier and operator in a 'assembly-program.txt' file

file = open('assembly-program.txt','r')
symbol = []
opr = []
operators = ['+', '-', '*', '/', '=', '%']
while 1:
    f = file.readline()
    # breaks out of loop if end of file
    if not f:
        break
    # for i in operators:
    #     x = f.find(i)
    #     if x > -1:
    #         f = f.replace(i, '', x)
    #         opr.append(i)

    # logic to find operators in program with duplicate
    for i in range(len(f)):
        if f[i] in operators:
            opr.append(f[i])
            f = f.replace(f[i], ' ')

    # Logic to find Symbols/Identifiers in Program without duplicate
    list = f.split(' ')
    while len(list) is not 0:
        elem = list.pop(0)
        elem = elem.strip()
        if elem not in symbol and elem is not '':
            symbol.append(elem)
    # print(f)

print('Operators and Identifiers are in sequence of appearing in the program.')
print("Operators:",opr)
print("Identifiers:",symbol)
