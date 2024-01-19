import random

characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*_"

while True:
    pass_length = int(input("Enter the length of the Password: "))
    pass_count = int(input("Enter the number of Password: "))

    for i in range(pass_count):
        password = ""

        for j in range(pass_length):
            pass_char = random.choice(characters)
            password += pass_char
        print("You can use this password: ", password)
    repeat = input("Do you want to generate more password? ")

    if repeat.lower() != "yes":
        break
print("Thank You")
