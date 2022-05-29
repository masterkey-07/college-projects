from Bio.SeqIO import parse

matrix = {
    'TT': 5,
    'GG': 5,
    'CC': 5,
    'AA': 5,
    'TA': -1,
    'T-': -1,
    'CA': -1,
    'TG': -2,
    'TC': -2,
    'GA': -2,
    'G-': -2,
    'A-': -3,
    'GC': -3,
    'C-': -4
}


def calculate_sequences(seq_a, seq_b):
    score = 0
    count = 0

    for a, b in zip(seq_a, seq_b):
        pos = None

        if (ord(a) > ord(b)):
            pos = a+b
        else:
            pos = b+a

        score += matrix[pos]
        count += 1 if matrix[pos] > 0 else 0

    mean_score = round(score / len(seq_a), 2)

    mean_count = round((count * 100) / len(seq_a), 2)

    return score, mean_score, mean_count


data = parse('./input.fasta', 'fasta')

file = open('./created_output.txt', 'w')

fasta = []

for dt in data:
    fasta.append(dt.seq)

score, mean_score, mean_count = calculate_sequences(fasta[0], fasta[1])

file.write('seq1.1 x seq1.2 : identity : {}%; score : {}; mean score : {}\n'.format(
    mean_count, score, mean_score))

score, mean_score, mean_count = calculate_sequences(fasta[2], fasta[3])

file.write('seq2.1 x seq2.2 : identity : {}%; score : {}; mean score : {}\n'.format(
    mean_count, score, mean_score))
