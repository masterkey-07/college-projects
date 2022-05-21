from Bio.Seq import translate
from Bio.SeqIO import parse

file = parse('./fasta.fna', 'fasta')

output_files = []

for i in range(0, 3):
    output_files.append(open('./output/frame_{}.txt'.format(i + 1), 'w'))

for data in file:
    seq = data.seq
    for i in range(0, 3):
        data.seq = data.seq[i:].translate()
        output_files[i].write(data.format('fasta'))
        data.seq = seq
