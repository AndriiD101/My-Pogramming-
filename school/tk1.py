from tkinter import *
def pr():
    print("Hi")
root = Tk() 
root.title("Task")
root.geometry("500x400")
button = Button(text="Push",command=pr, bg="Gray", height=500, width=400)
button.pack()
