words = 0
lines = 0
characters = 0

f = "D:\\6th sem\\Lab\\Python Lab\\s.txt"
file = open(f, 'r')

for l in file:
    words += len(l.split())
    lines += 1
    characters = len(l)

print("No of characters: ", characters)
print("No of words: ", words)
print("No of lines: ", lines)
