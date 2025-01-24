import tkinter as tk
import random

root = tk.Tk()

money = 100
bet = 10
guess = None

def bet_btn(select):
    global bet

    if select == "up":
        bet += 10
    else:
        bet -= 10
    
    if bet < 10:
        bet = 10
    if bet > money:
        bet = money

    label3.config(text=f"Bet: {bet}")

def set_guess(selected_guess):
    global guess
    guess = selected_guess
    label4.config(text=f"Guess: {selected_guess}")

def flip():
    global money, bet, guess

    if guess is None:
        label5.config(text="Please make a guess (Heads or Tails)!")
        return

    value = random.randint(1, 2)

    if value == 1:
        outcome = "Heads"
    else:
        outcome = "Tails"

    label5.config(text=f"Outcome: {outcome}")

    if (guess == "Heads" and value == 1) or (guess == "Tails" and value == 2):
        money += bet
        label2.config(text=f"Money: {money}")
        label5.config(text=f"Outcome: {outcome} - You won!")
    else:
        money -= bet
        label2.config(text=f"Money: {money}")
        label5.config(text=f"Outcome: {outcome} - You lost!")


    if money < bet:
        bet = money
        label3.config(text=f"Bet: {bet}")

root.geometry("800x500")


label = tk.Label(root, text="Coin Flip Sugal", font=('Arial', 18))
label.pack(padx=20, pady=20)


label2 = tk.Label(root, text=f"Money: {money}", font=('Arial', 18))
label2.pack(anchor='w')


button_frame = tk.Frame(root)
button_frame.pack(pady=10)

button1 = tk.Button(button_frame, text="+10", font=('Arial', 18), command=lambda: bet_btn("up"))
button2 = tk.Button(button_frame, text="-10", font=('Arial', 18), command=lambda: bet_btn("down"))
button1.pack(side="left", padx=10)
button2.pack(side="left", padx=10)


label3 = tk.Label(root, text=f"Bet: {bet}", font=('Arial', 18))
label3.pack(pady=10)


guess_frame = tk.Frame(root)
guess_frame.pack(pady=10)

guess_heads = tk.Button(guess_frame, text="Heads", font=('Arial', 18), command=lambda: set_guess("Heads"))
guess_tails = tk.Button(guess_frame, text="Tails", font=('Arial', 18), command=lambda: set_guess("Tails"))
guess_heads.pack(side="left", padx=10)
guess_tails.pack(side="left", padx=10)


button3 = tk.Button(root, text="Start Flipping", font=('Arial', 18), command=flip)
button3.pack(padx=10, pady=20)


label4 = tk.Label(root, text="Guess: ", font=('Arial', 18))
label5 = tk.Label(root, text=f"Please make a guess (Heads or Tails)!", font=('Arial', 18))
label4.pack(pady=10)
label5.pack(pady=10)

root.mainloop()
