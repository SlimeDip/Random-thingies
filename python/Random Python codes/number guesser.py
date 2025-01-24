import random

value = (random.randrange(1,100))
value = int(value)
numguess = 1
print("Try and guess the number!!! 1-100")

while True:
    guess = input(": ")
    guess = int(guess)
    if guess == value:
        print("you guessed the number!!")
        break
    elif guess > value:
        print("your guess it to high")
    elif guess < value:
        print("your guess is to low")
        
    numguess += 1
    
print(f"number of guesses: {numguess}")