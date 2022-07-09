def maximum(a, b):
    return a if a > b else b


def get_value(a, b):
    if (a == '-' or b == '-'):
        return -4
    elif (a == b):
        return 5
    else:
        return -3


def get_score(matrix, i, j, seq1, seq2):
    value = matrix[i][j]

    if (value == 0):
        return 0
    elif (abs(value - matrix[i - 1][j]) == 4):
        return value + get_score(matrix, i-1, j)
    elif (abs(value - matrix[i][j-1]) == 4):
        return value + get_score(matrix, i, j-1)
    else:
        return value + get_score(matrix, i-1, j-1)


seq1 = ['-', 'G', 'A', 'C', 'T', 'T', 'A', 'C']

seq2 = ['-', 'C', 'G', 'T', 'G', 'A', 'A', 'T', 'T', 'C', 'A', 'T']

matrix = []

w = -4

for i in range(len(seq1)):
    matrix.append([])
    for _ in seq2:
        matrix[i].append(0)

for i in range(1, len(seq1)):
    for j in range(1, len(seq2)):
        score = get_value(seq1[i], seq2[j])

        value = maximum(matrix[i-1][j-1] + score, matrix[i][j-1] + w)

        value = maximum(value, matrix[i-1][j] + w)

        value = maximum(value, 0)

        matrix[i][j] = value


for row in matrix:
    print(row)

new_seqs = [[], []]

results = []

best_result = 0

for i in range(len(matrix)):
    new_seqs = [[], []]
    for j in range(len(matrix[i])):
        result = get_score(matrix, i, j, new_seqs[0], new_seqs[1])

        if (result == best_result)
