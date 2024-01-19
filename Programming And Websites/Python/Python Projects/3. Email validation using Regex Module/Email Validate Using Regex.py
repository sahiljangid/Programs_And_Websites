import re

email_condition = "^[a-z A-Z]+[\._]?[a-z A-Z 0-9]+[@]\w+[.]\w{2,3}$"
user_email = input("Enter your E-mail :")

if re.search(email_condition, user_email):
    print("E-mail is Valid ✅")
else:
    print("E-mail is Invalid ❌")



