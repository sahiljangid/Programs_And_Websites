from tkinter import *
import speedtest

def speedcheck():
    sp = speedtest.Speedtest()
    sp.get_servers()
    down = str(round(sp.download()/(10**6),3)) + " Mbps"
    up = str(round(sp.upload()/(10**6),3)) + " Mbps"
    lab_down.config(text=down)
    lab_up.config(text=up)

sp = Tk()

sp.title("Internet Speed Test")

sp.geometry("500x700")
sp.config(bg = "gray")

lab = Label(sp, text = "Internet Speed Test", font=("Time New Roman", 33, "bold"), bg="gray", fg="white")
lab.place(x=40, y=40, height = 50, width = 420)

lab = Label(sp, text = "Download Speed", font=("Time New Roman", 33, "bold"), bg="gray", fg="white")
lab.place(x=40, y=110, height = 50, width = 420)

lab_down = Label(sp, text = "00", font=("Time New Roman", 33, "bold"), bg="gray", fg="white")
lab_down.place(x=40, y=180, height = 50, width = 420)

lab = Label(sp, text = "Upload Speed", font=("Time New Roman", 33, "bold"), bg="gray", fg="white")
lab.place(x=40, y=270, height = 50, width = 420)

lab_up = Label(sp, text = "00", font=("Time New Roman", 33, "bold"), bg="gray", fg="white")
lab_up.place(x=40, y=340, height = 50, width = 420)

button = Button(sp, text="Check Speed", font=("Time New Roman", 33, "bold"), bg="gray", fg="white", relief=RAISED, command=speedcheck)
button.place(x=40, y=440, height = 50, width = 420)

sp.mainloop()




