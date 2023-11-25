from tkinter import*
root=Tk()
root.geometry ("750x700")
#dollar
ent1=Entry()
ent1.place(x=170, y=5, width=100,height=35)
ent1.insert(END, '39.6')

lb1=Label(width=11, height=2, text="Dollar: ")
lb1.place(x=85,y=5)
lb11=Label(width=3, height=2, text="uah")
lb11.place(x=250,y=5)
#euro
lbeur=Label(width=11, height=2, text="Euro: ")
lbeur.place(x=325, y=5)
enteur=Entry()
enteur.place(x=400, y=5, width=100,height=35)
enteur.insert(END, '40.9')
lbeurua=Label(width=3, height=2, text="uah")
lbeurua.place(x=480, y=5)
#else
lbgbp=Label(width=11, height=2, text="CZ krona: ")
lbgbp.place(x=530,y=5)
entgbp=Entry()
entgbp.place(x=610, y=5, width=100,height=35)
entgbp.insert(END, '1.65')
lbgbpua=Label(width=3, height=2, text="uah")
lbgbpua.place(x=690,y=5)

entry2=Entry()
entry2.place(x=400, y=70, width=100,height=35)

label2=Label(width=17, height=2, text="Amount of the money: ")
label2.place(x=270,y=70)

entry3=Entry()
entry3.place(x=350, y=130, width=100,height=35)

def click1():
    a=ent1.get()
    a=float(a)

    b=entry2.get()
    b=float(b)

    result=str(a*b)
    entry3.delete(0, END)
    entry3.insert(0, result)
button1=Button(text="Exchange Uah to usd", command=click1)
button1.place(x=150, y=200, width=140, height=40)

def click2():
    c=enteur.get()
    c=float(c)

    d=entry2.get()
    d=float(d)

    result=str(c*d)
    entry3.delete(0, END)
    entry3.insert(0, result)
button2=Button(text="Exchange Uah to euro", command=click2)
button2.place(x=300, y=200, width=140, height=40)

def click3():
    e=entgbp.get()
    e=float(e)

    f=entry2.get()
    f=float(f)

    result=str(f*e)
    entry3.delete(0, END)
    entry3.insert(0, result)
button3=Button(text="Exchange Uah to something", command=click3)
button3.place(x=450, y=200, width=140, height=40)


c=Canvas(width=400,height=400)
c.place(x=150, y=300)
p=PhotoImage(file="try.png")
c.create_image(200,200,image=p)
