import tkinter as tk

markup = 1.229

def calculate():
    try:
        global markup
        raw_price = int(price_inpt.get())
        retail_price = raw_price * markup
        retail_price = int(retail_price)
        price_label.config(text=f"Retail price: {retail_price}")

    except ValueError:
        price_label.config(text="Please enter a valid price!")

def mrkp(percent):
    global markup 
    markup = percent

    if markup == 1.229:
        mrkp_label.config(text="Markup rate: 20%")
    elif markup == 1.329:
        mrkp_label.config(text="Markup rate: 30%")
    else:
        mrkp_label.config(text="Markup rate: 40%")


root = tk.Tk()
root.geometry("800x500")
root.title("Price Calculator")

frame1 = tk.Frame(root)
frame1.place(relx=0.5, rely=0.2, anchor="center")

price_label = tk.Label(frame1, text="Retail price: ", font=("Arial", 18, "bold"))
price_label.pack(pady=10)

frame2 = tk.Frame(root)
frame2.place(relx=0.5, rely=0.5, anchor="center")

label1 = tk.Label(frame2, text="Input raw price", font=("Arial", 18))
label1.pack(pady=10)

price_inpt = tk.Entry(frame2, font=("Arial", 18))
price_inpt.pack(pady=5)

calculate = tk.Button(frame2, text="Calculate", font=("Arial", 18), command=calculate)
calculate.pack(pady=10)

frame3 = tk.Frame(root)
frame3.place(relx=0.5, rely=0.8, anchor="center")

mrkp_label = tk.Label(frame3, text="Markup rate: 20%", font=("Arial", 16))
mrkp_label.pack(pady=10)

mrkp1 = tk.Button(frame3, text="20%", font=("Arial", 18), command=lambda: mrkp(1.229))
mrkp1.pack(pady=5, side="left", padx=10)
mrkp2 = tk.Button(frame3, text="30%", font=("Arial", 18), command=lambda: mrkp(1.329))
mrkp2.pack(pady=5, side="left", padx=10)
mrkp3 = tk.Button(frame3, text="40%", font=("Arial", 18), command=lambda: mrkp(1.429))
mrkp3.pack(pady=5, side="left", padx=10)

root.mainloop()