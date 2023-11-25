from tkinter import *
tk=Tk()
tk.geometry("300x250")
def click():
    print("Привіт")
btn=Button(text="Привітання", command=click)
btn.place(y=100,width=100,height=50)
btn.pack(expand=True)

