from Bio.pairwise2 import align
from Bio.SeqIO import parse
from Bio.pairwise2 import format_alignment

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


def get_sequences():
    output = []
    for data in parse('./input.fasta', 'fasta'):
        output.append(data.seq)

    return output


def calculate_sequences(seq_a, seq_b):
    for result in align.localds(seq_a, seq_b, matrix, -2, -1, one_alignment_only=True):
        print(format_alignment(*result, full_sequences=True))


sequences = get_sequences()

print(sequences[0])
print(sequences[1])

align_sequences(sequences[0], sequences[1])
