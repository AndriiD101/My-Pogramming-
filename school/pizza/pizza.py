from tkinter import*
from tkinter import filedialog

#create the window
root = Tk()
root.title("Order")
root.geometry("440x300")

#menu
def NewFile():
    name=filedialog.asksaveasfile(mode='w',defaultextension=".txt")
    text2save="this is my file!"
    name.write(text2save)
    name.close
def OpenFile():
    name = filedialog.askopenfilename()
    print (name)
def About():
    print ("done by 11 class")

menu = Menu(root)
filemenu = Menu(menu)
root.config(menu=menu)

menu.add_cascade(label="file", menu=filemenu)
filemenu.add_command(label="new", command=NewFile)
filemenu.add_command(label="open", command=OpenFile)
filemenu.add_separator()
filemenu.add_command(label="exit", command=root.quit)

helpmenu = Menu(menu)
menu.add_cascade(label="help", menu=helpmenu)
helpmenu.add_command(label="about programm", command=About)

#variables
y1=0
y2=0
y3=0
y4=0

#functions
def s1_click(val1):
    k1=int(val1)
    global y1
    y1=k1*75
    var1.set(y1)
var1=StringVar()

def s2_click(val2):
    k2=int(val2)
    global y2
    y2=k2*12
    var2.set(y2)
var2=StringVar()

def s3_click(val3):
    k3=int(val3)
    global y3
    y3=k3*16
    var3.set(y3)
var3=StringVar()

def s4_click(val4):
    k4=int(val4)
    global y4
    y4=k4*8
    var4.set(y4)
var4=StringVar()

def btn_click():
    y=y1+y2+y3+y4
    var5.set(y)
var5=StringVar()
    

#headings
lbl=Label(text="Positions", font=('Arial 9 bold'))
lbl.place(x=20, y=20, width=50, height=30)
lbl=Label(text="Price, hrn", font=('Arial 9 bold'))
lbl.place(x=145, y=20, width=58, height=30)
lbl=Label(text="Amount", font=('Arial 9 bold'))
lbl.place(x=230, y=20, width=45, height=30)
lbl=Label(text="Cost, hrn", font=('Arial 9 bold'))
lbl.place(x=310, y=20, width=53, height=30)

#positions
lbl=Label(text="Pizza")
lbl.place(x=20, y=60, width=30, height=30)
lbl=Label(text="Ice cream")
lbl.place(x=20, y=100, width=50, height=30)
lbl=Label(text="Cake")
lbl.place(x=20, y=140, width=30, height=30)
lbl=Label(text="Juice")
lbl.place(x=20, y=180, width=30, height=30)

#stuff for positions
#for pizza
p1=Entry(font="Arial 10",bg="sky blue", justify="center")
p1.insert(END, "75")
p1.place(x=150, y=60, width=45, height=30)
sc_pizza = Scale(orient=HORIZONTAL, length = 50, from_=0, to=10, command=s1_click)
sc_pizza.place(x=230, y=50)
c1=Label(text=0, font="Arial 10", bg="deep sky blue", textvariable=var1)
c1.place(x=310, y=60, width=45, height=30)

#for ice cream
p2=Entry(font="Arial 10",bg="sky blue", justify="center")
p2.insert(END, "12")
p2.place(x=150, y=100, width=45, height=30)
sc_ice_cream = Scale(orient=HORIZONTAL, length = 50, from_=0, to=10, command=s2_click)
sc_ice_cream.place(x=230, y=90)
c2=Label(text=0, font="Arial 10", bg="deep sky blue", textvariable=var2)
c2.place(x=310, y=100, width=45, height=30)

#for cake
p3=Entry(font="Arial 10",bg="sky blue", justify="center")
p3.insert(END, "16")
p3.place(x=150, y=140, width=45, height=30)
sc_cake = Scale(orient=HORIZONTAL, length = 50, from_=0, to=10, command=s3_click)
sc_cake.place(x=230, y=130)
c3=Label(text=0, font="Arial 10", bg="deep sky blue", textvariable=var3)
c3.place(x=310, y=140, width=45, height=30)

#for juice
p3=Entry(font="Arial 10",bg="sky blue", justify="center")
p3.insert(END, "8")
p3.place(x=150, y=180, width=45, height=30)
sc_cake = Scale(orient=HORIZONTAL, length = 50, from_=0, to=10, command=s4_click)
sc_cake.place(x=230, y=170)
c3=Label(text=0, font="Arial 10", bg="deep sky blue",textvariable=var4)
c3.place(x=310, y=180, width=45, height=30)

#button
lbl=Label(text='Cost for all orders:')
lbl.place(x=20, y=220, width=100, height=40)
lbl_sum=Label(text=0, font="Arial 10", bg="deep sky blue", textvariable=var5)
lbl_sum.place(x=150, y=220, width=45, height=30)
lbl_hrn=Label(text='hrn')
lbl_hrn.place(x=230, y=220, width=50,height=35)
btn=Button(text="Count", command=btn_click)
btn.place(x=310,y=220,width=50,height=35)

root.mainloop()
