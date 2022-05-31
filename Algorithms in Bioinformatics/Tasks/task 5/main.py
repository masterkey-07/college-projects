from Bio.SeqIO import parse
from Bio.pairwise2 import align


def get_matrix():
    matrix = {}

    matrix[('A', 'A')] = 5
    matrix[('A', 'T')] = -1
    matrix[('A', 'C')] = -1
    matrix[('A', 'G')] = -2
    matrix[('A', '-')] = -3
    matrix[('T', 'T')] = 5
    matrix[('T', 'A')] = -1
    matrix[('T', 'C')] = -2
    matrix[('T', 'G')] = -2
    matrix[('T', '-')] = -1
    matrix[('G', 'G')] = 5
    matrix[('G', 'A')] = -2
    matrix[('G', 'C')] = -3
    matrix[('G', 'T')] = -2
    matrix[('G', '-')] = -2
    matrix[('C', 'C')] = 5
    matrix[('C', 'A')] = -1
    matrix[('C', 'T')] = -2
    matrix[('C', 'G')] = -3
    matrix[('C', '-')] = -4
    matrix[('-', 'A')] = -3
    matrix[('-', 'T')] = -1
    matrix[('-', 'G')] = -2
    matrix[('-', 'C')] = -4
    matrix[('-', '-')] = 0

    return matrix


def get_sequences():
    output = []
    for data in parse('./input.fasta', 'fasta'):
        output.append(data.seq)

    return output


def calculate_result(score, identity, length):
    mean_score = round(score / length, 2)

    mean_count = round((identity * 100) / length, 2)

    return score, mean_score, mean_count


matrix = get_matrix()


def align_created(seq_a, seq_b):
    score = 0
    count = 0

    for a, b in zip(seq_a, seq_b):
        score += matrix[(a, b)]
        count += 1 if matrix[(a, b)] > 0 else 0

    return calculate_result(score, count, len(seq_a))


def align_pairwise(seq_a, seq_b):
    identity_result = align.localxx(seq_a, seq_b, one_alignment_only=True)

    score_result = align.localds(seq_a, seq_b, matrix, -2, -
                                 2, one_alignment_only=True)

    print(seq_a)

    print(seq_b)

    print(score_result[0][0])
    print(score_result[0][1])

    return calculate_result(score_result[0][2], identity_result[0][2], len(seq_a))


def write_test(file, head, sequences, align_function):
    file.write('\n' + head + '\n')

    score, mean_score, mean_count = align_function(sequences[0], sequences[1])

    file.write('seq1.1 x seq1.2 : identity : {}%; score : {}; mean score : {}\n'.format(
        mean_count, score, mean_score))

    score, mean_score, mean_count = align_function(sequences[2], sequences[3])

    file.write('seq1.1 x seq1.2 : identity : {}%; score : {}; mean score : {}\n'.format(
        mean_count, score, mean_score))


sequences = get_sequences()

file = open('./output.txt', 'w')

write_test(file, 'CREATED METHOD', sequences, align_created)

write_test(file, 'PAIRWISE METHOD', sequences, align_pairwise)
