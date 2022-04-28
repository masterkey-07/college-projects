from Bio.SeqIO import parse
from matplotlib import pyplot


def write_head(output):
    output.write('Segmento | ')
    output.write('A | ')
    output.write('T | ')
    output.write('C | ')
    output.write('G | ')
    output.write('CG% | ')
    output.write('Temp. ')
    output.write('\n')


def get_total(data):
    return data['C'] + data['G'] + data['T'] + data['A']


def calculate_cg(data):
    return round(((data['C'] + data['G']) * 100) / (data['total']), 2)


def create_empty_data():
    return {'A': 0, 'T': 0, 'C': 0, 'G': 0}


def calculate_melting(data):
    return round(64.9 + (0.41*data['CG']) - (500/data['total']), 2)


def read_segment(segment):
    data = create_empty_data()

    for char in segment:
        data[char] += 1

    data['total'] = get_total(data)

    data['CG'] = calculate_cg(data)

    data['temperature'] = calculate_melting(data)

    return data


def read_segments(segments):
    data = []
    for segment in segments:
        data.append(read_segment(segment.seq))

    return data


def count_total(data):
    total = create_empty_data()
    array = ['A', 'T', 'C', 'G']

    for dt in data:
        for char in array:
            total[char] += dt[char]

    return total


def write_total(file, total):
    file.write('Todo Segmento\n')
    file.write('A : {}\n'.format(total['A']))
    file.write('T : {}\n'.format(total['T']))
    file.write('C : {}\n'.format(total['C']))
    file.write('G : {}\n'.format(total['G']))
    file.write('\n')


def write_segments(file, data):
    i = 1
    for dt in data:
        file.write('{} | '.format(i))
        file.write('{} | '.format(dt['A']))
        file.write('{} | '.format(dt['T']))
        file.write('{} | '.format(dt['C']))
        file.write('{} | '.format(dt['G']))
        file.write('{}% | '.format(dt['CG']))
        file.write('{} °C'.format(dt['temperature']))
        file.write('\n')
        i += 1


def plot_data(data):
    j = 1
    x = []
    y = []
    for dt in data:
        x.append(dt['CG'])
        y.append(dt['temperature'])

    pyplot.scatter(x, y)
    pyplot.xlabel('CG %')
    pyplot.ylabel('Melting Temperature')
    pyplot.savefig('./output/chart.png')


fasta = parse('./input/influenza.fna', 'fasta')

output = open('./output/output.txt', 'w')

data = read_segments(fasta)

total_data = count_total(data)

write_total(output, total_data)

write_head(output)

write_segments(output, data)

plot_data(data)
