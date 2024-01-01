
file = "D:\\6th sem\\Lab\\Python Lab\\s.txt"

for line in reversed(list(open(file))):
    print(line.rstrip())
