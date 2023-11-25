from tkinter import *


tk=Tk()
tk.geometry("700x700")

def click1():
    global img
    if var.get()==1:
        img=PhotoImage(file="flower.png")
    elif var.get()==2:
        img=PhotoImage(file="cake.png")
    elif var.get()==3:
        img=PhotoImage(file="view.png")
    select= Ibox.curselection()
    Ibox.get(ANCHOR)
    lbl.config(text=ent.get()+", "+Ibox.get(select))
    s=c.create_image(25,180,anchor=NW,image=img)
    

var = IntVar()
rbtn1=Radiobutton(text="flowers", variable=var, value=1)
rbtn2=Radiobutton(text="cake", variable=var, value=2)
rbtn3=Radiobutton(text="view", variable=var, value=3)
rbtn1.place(x=50, y=200)
rbtn2.place(x=50, y=225)
rbtn3.place(x=50, y=250)

c = Canvas(width=450,height=450)
c.place(x=125, y=100)

Ibox = Listbox(height=3)
Ibox.place(x=400,y=50)
Ibox.insert(1, "happy new year")
Ibox.insert(2, "happy b-day")
Ibox.insert(3, "happy 8 march")

lbl=Label(text="")
lbl.place(x=75,y=130)

btn=Button(text="Greatings", command=click1)
btn.place(x=120,y=150,width=200,height=50)

ent=Entry()
ent.place(x=150,y=40,width=100,height=50)

l1=Label(width=3, height=2, bg='yellow',text="Name:")
l1.place(x=80,y=40, width=50, height=50)

    
