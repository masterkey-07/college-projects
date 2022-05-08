from Bio.SeqIO import parse

fasta = parse('./fasta.fno', 'fasta')


def compare(segment_a, segment_b):
    count = 0
    length_a = len(segment_a)
    length_b = len(segment_b)

    if (length_a < length_b):
        length = length_a
    else:
        length = length_b

    for i in range(0, length):
        if (segment_a[i] == segment_b[i]):
            count += 1
        else:
            break

    return count


def join_segments(segment_a, segment_b):
    equal_segment = (0, 0, 0)

    for i in range(0, len(segment_a)):
        for j in range(0, len(segment_b)):
            segment_count = compare(segment_a[i:], segment_b[j:])
            if (equal_segment[0] < segment_count):
                equal_segment = (segment_count, i, j)

    segment_count = equal_segment[0]

    if (i < j):
        position_a = equal_segment[1]
        position_b = equal_segment[2]
    else:
        segment_c = segment_a
        segment_a = segment_b
        segment_b = segment_c
        position_a = equal_segment[2]
        position_b = equal_segment[1]

    segment_a_1 = segment_a[0:position_a]
    segment_a_2 = segment_a[position_a+segment_count:]

    segment_b_1 = segment_b[0:position_b]
    segment_b_2 = segment_b[position_b+segment_count:]

    if (len(segment_a_1) > len(segment_b_1)):
        return segment_a_1 + segment_a[position_a: position_a+segment_count] + segment_a_2 + segment_b_1 + segment_b_2
    else:
        return segment_b_1 + segment_a[position_a: position_a+segment_count] + segment_b_2 + segment_a_1 + segment_a_2


segment_a = None
segment_b = None

for data in fasta:
    segment_b = data.seq

    if segment_a:
        segment_a = join_segments(segment_a, segment_b)
    else:
        segment_a = segment_b

print(segment_a)
