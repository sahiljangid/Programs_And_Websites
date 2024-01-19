import smtplib as s

ob = s.SMTP('smtp.gmail.com', 587)

ob.ehlo()

ob.starttls()

ob.login('sahiljangid811@gmail.com', 'your_password')
subject = "test python"

body = "My name is sahil"

message = "subject: {}\n\n".format(subject, body)
listadd = ['sahiljangid8619@gmail.com']

### in one line

# ob.sendmail('sahiljangid811@gmail.com','sahiljangid8619@gmail.com','Hey! My name is sahil')
ob.sendmail('sahiljangid811@gmail.com', listadd, message)

print("Mail Sent")

ob.quit()



