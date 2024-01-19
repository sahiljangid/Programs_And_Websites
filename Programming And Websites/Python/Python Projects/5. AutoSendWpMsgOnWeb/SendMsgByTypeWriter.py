

import pyautogui as pyt
import random
import time

time.sleep(5)

count = 1

# lst = ['Kya h', 'Bolna', 'Bol', 'Kya huaa', 'Bolna kya huaa', 'kya', 'Oye', 'Btana yrrr']

while count<=5:

    # ch = random.choice(lst)
    pyt.typewrite(f"{count} .")  ### pyautogui.typewrite(f"{count}. You are {ch}")
    pyt.press("enter")
    count = count + 1


