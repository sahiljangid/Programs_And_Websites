

import random

import time

alpha = [' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z']

word = 'hello world'
ans = []
for ch in word:
    while True:
        sch = random.choice(alpha)
        if ch == sch:
            ans.append(ch)
            res = ' '.join(ans)
            print(res)
            time.sleep(0.001)
            break
        res = ' '.join(ans)
        print(res)
        time.sleep(0.001)




