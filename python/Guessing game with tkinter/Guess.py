import tkinter as tk
import random

root = tk.Tk()

value = (random.randrange(0,100))
value = int(value)
print(f"key = {value}")

def check_guess():
    user_guess = guess.get()
    user_guess = int(user_guess)

    if user_guess == value:
        response.config(text="You've guessed it right!!!!")
    elif user_guess > 100 or user_guess < 0:
        response.config(text="Guess around 0-100")
    elif user_guess > value:
        response.config(text="Try lower")
    else:
        response.config(text="Try higher")

    print(f"user = {user_guess}")



root.geometry("800x500")
root.title("Guessing game V2")

label1 = tk.Label(root, text="Welcome to guessing game by Dip", font=("Arial", 18, "bold"))
label1.pack(pady=20)
label2 = tk.Label(root, text="Guess a number from 0-100!", font=("Arial", 18))
label2.pack()

guess = tk.Entry(root, font=("Arial", 18))
guess.pack(pady=20)

submit = tk.Button(root, text="Guess", font=("Arial", 18), command=check_guess)
submit.pack()

response = tk.Label(root, text="Input a guess", font=("Arial", 18))
response.pack(pady=25)


root.mainloop()