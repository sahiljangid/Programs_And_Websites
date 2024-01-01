print("Enter data: ")
originalString = input()

numbers = []
alphabets = []
others = []

for char in originalString:
    if 48 <= ord(char) <= 57:
        numbers.append(char)
    elif 65 <= ord(char) <= 90 or 97 <= ord(char) <= 122:
        alphabets.append(char)
    else:
        others.append(char)

print("Your data is categorized like:")
numbers = ''.join(numbers)
alphabets = ''.join(alphabets)
others = ''.join(others)
print("Numbers: ",numbers)
print("Alphabets: ",alphabets)
print("Others: ",others)
