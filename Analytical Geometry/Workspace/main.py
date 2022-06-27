def calc(array, number):
    for a, b in array:
        print(a + (b * number))


array = [(-2, -3), (1, -4), (-3, 4)]

calc(array, 0)
