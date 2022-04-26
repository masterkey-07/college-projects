from asyncore import write
import math
from Bio.SeqIO import parse
from matplotlib import pyplot

input_path = './input/influenza.fna'
output_path = './output/output.txt'

fasta = parse(input_path, 'fasta')

data = []

cg = []

temperature = []

for dna in fasta:
    counter = {'A': 0, 'T': 0, 'G': 0, 'C': 0, 'total': 0}
    for char in dna.seq:
        counter[char] += 1
        counter['total'] += 1

    counter['CG'] = (counter['C']*200) / counter['total']

    cg.append(counter['CG'])

    counter['temperature'] = 81.5 + \
        (16.6 * math.log10(0.1)) + \
        (0.41 * counter['CG']) - (500 / len(dna.seq))
    temperature.append(counter['temperature'])

    data.append(counter)


output_file = open(output_path, 'w')

for dt in data:
    output_file.write('A : {}\n'.format(dt['A']))
    output_file.write('T : {}\n'.format(dt['T']))
    output_file.write('C : {}\n'.format(dt['C']))
    output_file.write('G : {}\n'.format(dt['G']))
    output_file.write('CG % : {}\n'.format(dt['CG']))
    output_file.write('Temperature : {}\n'.format(dt['temperature']))
    output_file.write('\n')

output_file.close()

cg.sort()

temperature.sort()

pyplot.plot(cg, temperature)

pyplot.xlabel('CG %')

pyplot.ylabel('Celsius')

pyplot.savefig('./output/chart.png')
