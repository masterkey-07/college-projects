from pandas import read_csv

data = read_csv('./data.csv')

print(data['Job Title'].drop_duplicates().to_csv('jobs.csv'))
