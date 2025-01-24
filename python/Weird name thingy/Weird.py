import time
import random
import string

speed = 0.005
target = input(": ")
ans = ""

valid_characters = string.ascii_letters + string.digits + string.punctuation + " "

for i in range(len(target)):
    while True:
        time.sleep(speed)
        randomchar = random.choice(valid_characters)
        print(ans + randomchar)
        if target[i] == randomchar:
            ans += randomchar
            break

    if ans == target:
        break