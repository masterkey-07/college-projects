def func(a, b):
    if a == b:
        return 5
    elif a == 'T':
        if b == 'A' or b == '-':
            return -1
        else:
            return -2
    elif a == 'G':
        if b == 'A' or b == '-':
            return -2
        else:
            return -3
    elif a == 'C':
        if b == 'A':
            return -1
        else:
            return -4
    elif a == 'A':
        return -3
