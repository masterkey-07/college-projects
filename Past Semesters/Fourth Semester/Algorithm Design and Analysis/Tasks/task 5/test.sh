clear

gcc ./main.c -w -o main.exe

echo 'test A'

./main.exe < ./input/a.txt

echo '\n'

echo 'expect:'

cat ./output/a.txt

echo '\n'

echo 'test B'

./main.exe < ./input/b.txt

echo '\n'

echo 'expect:'

cat ./output/b.txt

echo '\n'

echo 'test C'

./main.exe < ./input/c.txt

echo '\n'

echo 'expect:'

cat ./output/c.txt

echo '\n'

echo 'test D'

./main.exe < ./input/d.txt

echo '\n'

echo 'expect:'

cat ./output/d.txt

echo '\n'

echo 'test E'

./main.exe < ./input/e.txt

echo '\n'

echo 'expect:'

cat ./output/e.txt

echo '\n'
