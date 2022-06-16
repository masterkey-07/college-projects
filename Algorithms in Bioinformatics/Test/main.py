V = []


def backpack(wi, vi, n, W):

    for i in range(n + 1):
        V.append([])
        for _ in range(W + 1):
            V[i].append(0)


backpack(0, 0, 4, 13)


V[0][3] = 10000000

print(V)
