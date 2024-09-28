data = [
    [0,0.02,0.21],
    [0.02,0.02,0.23],
    [0.04,0.08,0.03],
    [0.18,0.14,0.03],
]

print('P(X = 4)', sum(data[3]))
print('P(X = 3)', sum(data[2]))
print('P(X = 2)', sum(data[1]))
print('P(X = 1)', sum(data[0]))

P_Y_3 = sum(row[2] for row  in data)

print('P(Y = 3)', P_Y_3)
print('P(Y = 2)', sum(row[1] for row  in data))
print('P(Y = 1)', sum(row[0] for row  in data))

print('P(X = x, Y = y) = 1')

print('P(X = 4|y = 3)', round(data[3][2] / P_Y_3, 2))
print('P(X = 3|y = 3)', round(data[2][2] / P_Y_3, 2))
print('P(X = 2|y = 3)', round(data[1][2] / P_Y_3, 2))
print('P(X = 1|y = 3)', round(data[0][2] / P_Y_3, 2))


print('E(X)', round(sum([(index + 1) * sum(row) for index, row in enumerate(data)]) ,2))

print('E(X|y=3)', round(sum([(index + 1) * (row[2] / P_Y_3) for index, row in enumerate(data)]) ,2))

print('E(X)', round(sum([(index + 1) * sum(row) for index, row in enumerate(data)]) ,2))
