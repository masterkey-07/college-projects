input = open("covid.txt")
output = open("output.txt", 'w')

data = input.readlines()

data.pop(0)

result = {
    "A": 0,
    "T": 0,
    "G": 0,
    "C": 0,
    "\n": 0
}

for line in data:
    for char in line:
        result[char] += 1

output.write("A : " + str(result["A"]) + "\n")
output.write("T : " + str(result["T"]) + "\n")
output.write("G : " + str(result["G"]) + "\n")
output.write("C : " + str(result["C"]) + "\n")
