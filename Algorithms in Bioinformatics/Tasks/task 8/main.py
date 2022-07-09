def maximum(a, b):
    return a if a > b else b


def get_value(a, b):
    if (a == '-' or b == '-'):
        return -4
    elif (a == b):
        return 5
    else:
        return -3


def get_score(matrix, seqs, i, j, new_seqs):
    value = matrix[i][j]

    if (value == 0):
        return 0

    if ((value - matrix[i - 1][j - 1] == 5 and seqs[0][i] == seqs[1][j]) or value - matrix[i - 1][j - 1] == -3):
        new_seqs[0].append(seqs[0][i])
        new_seqs[1].append(seqs[1][j])
        return value + get_score(matrix, seqs, i-1, j-1, new_seqs)
    elif (value - matrix[i][j-1] == -4):
        new_seqs[0].append('-')
        new_seqs[1].append(seqs[1][j])
        return value + get_score(matrix, seqs, i, j-1, new_seqs)
    elif (value - matrix[i - 1][j] == -4):
        new_seqs[0].append(seqs[0][i])
        new_seqs[1].append('-')
        return value + get_score(matrix, seqs, i-1, j, new_seqs)

    return 0


seq1 = ['-', 'G', 'A', 'C', 'T', 'T', 'A', 'C']

seq2 = ['-', 'C', 'G', 'T', 'G', 'A', 'A', 'T', 'T', 'C', 'A', 'T']

matrix = []

w = -4

for i in range(len(seq1)):
    matrix.append([])
    for _ in seq2:
        matrix[i].append(0)

positions = []

highest = 0

for i in range(1, len(seq1)):
    for j in range(1, len(seq2)):
        score = get_value(seq1[i], seq2[j])

        value = maximum(matrix[i-1][j-1] + score, matrix[i][j-1] + w)

        value = maximum(value, matrix[i-1][j] + w)

        value = maximum(value, 0)

        if (highest < value):
            highest = value
            positions = [(i, j)]
        elif (value == highest):
            positions.append((i, j))

        matrix[i][j] = value

new_seqs = [[], []]

results = []

highest_score = 0

for i, j in positions:
    new_seqs = [[], []]
    highest_score = get_score(matrix, [seq1, seq2], i, j, new_seqs)
    results.append(new_seqs)

for result in results:
    result.reverse()
    for seq in result:
        seq.reverse()
        print(seq)
    print()
