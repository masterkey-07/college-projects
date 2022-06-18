from numpy import append


items = [(5, 5), (4, 6), (7, 8), (7, 4)]

limit = 13

matrix = []

for i in range(len(items) + 1):
    matrix.append([])
    for _ in range(limit + 1):
        matrix[i].append(0)

for i in range(1, len(items) + 1):
    for w in range(1, limit + 1):
        value, weight = items[i - 1]

        if (weight <= w):
            if (value + matrix[i-1][w - weight] > matrix[i-1][w]):
                matrix[i][w] = value + matrix[i-1][w - weight]
            else:
                matrix[i][w] = matrix[i-1][w]
        else:
            matrix[i][w] = matrix[i-1][w]

i = len(items)
k = limit

backpack = []

while i > 0 and k > 0:
    if matrix[i][k] != matrix[i-1][k]:
        backpack.append((i - 1, items[i - 1]))
        k -= items[i - 1][1]
        i -= 1
    else:
        i -= 1


file = open('./output.txt', 'w')

file.write("matrix:\n")
for row in matrix:
    file.write(str(row)+'\n')

file.write("\nmochila:\n")
for item in backpack:
    file.write('item:' + str(item[0] + 1) + ' v:' +
               str(item[1][0])+' w:' + str(item[1][1])+'\n')
