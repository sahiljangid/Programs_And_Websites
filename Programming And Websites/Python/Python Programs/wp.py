import pyautogui
import random
import time

time.sleep(5)

count = 1

while count <= 50:
    pyautogui.typewrite("print(\"Hello World\")")
    pyautogui.press("enter")
    count += 1
    
    