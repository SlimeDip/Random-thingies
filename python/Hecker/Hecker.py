import tkinter as tk

def Hecker():
    print(f"User: {Userinpt.get()}\nPass: {Passinpt.get()}")

root = tk.Tk()
root.geometry("800x500")
root.title("Legit Growtopia Site")

frame1 = tk.Frame(root)
frame1.place(relx=0.5, rely=0.2, anchor="center")

Title = tk.Label(frame1, text="Log in to claim 2DLs! Wowers", font=("Arial", 18))
Title.pack(pady=10)

LoginF = tk.Frame(root)
LoginF.place(relx=0.5, rely=0.5, anchor="center")

User = tk.Label(LoginF, text="Username:", font=("Arial", 18))
User.grid(row=0, column=0, padx=5, pady=5, sticky="e")
Userinpt = tk.Entry(LoginF, font=("Arial", 18))
Userinpt.grid(row=0, column=1, padx=5, pady=5)

Pass = tk.Label(LoginF, text="Password:", font=("Arial", 18))
Pass.grid(row=1, column=0, padx=5, pady=5, sticky="e")
Passinpt = tk.Entry(LoginF, font=("Arial", 18), show="*")
Passinpt.grid(row=1, column=1, padx=5, pady=5)

Login = tk.Button(LoginF, text="Login", font=("Arial", 16, "bold"), command=Hecker)
Login.grid(row=2, column=0, columnspan=2, pady=10)

root.mainloop()
