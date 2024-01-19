import random
import string

chars = " " + string.punctuation + string.digits + string.ascii_letters
chars = list(chars)

key = chars.copy()
random.shuffle(key)

# Encrypt (Plain text to Cipher text)
plain_text = input("Enter a message to encrypt: ")
cipher_text = ""
for letter in plain_text:
    index = chars.index(letter)
    cipher_text += key[index]
print(f"Encrypted Message: {cipher_text}")

# Decrypt (Cipher text to Plain text)
cipher_text = input("Enter a message to decrypt: ")
plain_text = ""
for letter in cipher_text:
    index = key.index(letter)
    plain_text += chars[index]
print(f"Original Message: {plain_text}")


