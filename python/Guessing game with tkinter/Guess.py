import tkinter as tk
from tkinter import ttk
import random

root = tk.Tk()

value = (random.randrange(0,1000))
value = int(value)
guess_num = 0
print(f"key = {value}")

def check_guess():
    try:
        user_guess = int(guess.get())
        global guess_num

        if user_guess == value:
            response.config(text=f"You've guessed it right! No. of guess: {guess_num}")
            closeness["value"] = 100
        elif user_guess < 0 or user_guess > 1000:
            response.config(text="Guess around 0-1000")
        elif user_guess > value:
            guess_num += 1
            response.config(text="Try lower")
            closeness["value"] = max(0, 100 - abs(user_guess/10 - value/10))
        else:
            guess_num += 1
            response.config(text="Try higher")
            closeness["value"] = max(0, 100 - abs(user_guess/10 - value/10))

        print(f"user = {user_guess}")
        print(f"guess = {guess_num}")
    except ValueError:
        response.config(text="Please enter a valid number!")



root.geometry("800x500")
root.title("Guessing game V2")

label1 = tk.Label(root, text="Welcome to guessing game by Dip", font=("Arial", 18, "bold"))
label1.pack(pady=20)
label2 = tk.Label(root, text="Guess a number from 0-1000!", font=("Arial", 18))
label2.pack()

guess = tk.Entry(root, font=("Arial", 18))
guess.pack(pady=20)

submit = tk.Button(root, text="Guess", font=("Arial", 18), command=check_guess)
submit.pack()

response = tk.Label(root, text="Input a guess", font=("Arial", 18))
response.pack(pady=25)

label3 = tk.Label(root, text="Closeness meter", font=("Arial", 11))
label3.pack(pady=5)

closeness = ttk.Progressbar(root, orient="horizontal", length=400, mode="determinate")
closeness.pack()

root.mainloop()
