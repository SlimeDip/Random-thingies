import tkinter as tk
from tkinter import ttk
import time

def reading():
    nums = Userinpt.get()
    print(f"You entered: {nums}")

    loading_window = tk.Toplevel(root)
    loading_window.geometry("500x250")
    loading_window.title("Loading...")

    closeness = ttk.Progressbar(loading_window, orient="horizontal", length=400, mode="determinate")
    closeness.pack(pady=50)

    loading_label = tk.Label(loading_window, text="Mind Reading in Progress...", font=("Arial", 14))
    loading_label.pack(pady=10)

    for i in range(101):
        closeness["value"] = i
        loading_window.update() 
        time.sleep(0.03)

    loading_label.config(text=f"The word/number you entered was: {nums} 🎯")


root = tk.Tk()
root.geometry("500x300")
root.title("Let's read minds!")

frame1 = tk.Frame(root)
frame1.place(relx=0.5, rely=0.2, anchor="center")

Title = tk.Label(frame1, text="Enter any word or number!", font=("Arial", 18))
Title.pack(pady=10)

Inpt = tk.Frame(root)
Inpt.place(relx=0.5, rely=0.5, anchor="center")
Userinpt = tk.Entry(Inpt, font=("Arial", 18))
Userinpt.grid(row=0, column=1, padx=5, pady=5)

Login = tk.Button(Inpt, text="Submit", font=("Arial", 16, "bold"), command=reading)
Login.grid(row=2, column=0, columnspan=2, pady=10)

root.mainloop()
