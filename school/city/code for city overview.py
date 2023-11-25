#imported stuff
from tkinter import*
import time

#create the window
root = Tk()
root.title("the most simple window")
root.geometry("1000x800")

#functions
def click_paris():
    global img
    if var.get() == 0:
        img = PhotoImage(file = 'paris_day.png')
        label = Label(root, bg = "white", text = text_paris_day, relief = "solid", justify="left")
        label.place(x=80, y=20)
    elif var.get() == 1:
        img = PhotoImage(file = 'paris_night.png')
        label = Label(root, bg = "white", text = text_paris_night, relief = "solid", justify="left")  
        label.place(x=80, y=20)
    c=Canvas(width=450, height=400)
    c.place(x=325, y=50)
    s=c.create_image(250,200, image=img)


def click_oslo():
    
    global img
    if var.get() == 0:
        img = PhotoImage(file = 'oslo_day.png')
        label = Label(root, bg = "white", text = text_oslo_day, relief = "solid", justify="left")
        label.place(x=80, y=20)
    elif var.get() == 1:
        img = PhotoImage(file = 'oslo_night.png')
        label = Label(root, bg = "white", text = text_oslo_night, relief = "solid", justify="left")  
        label.place(x=80, y=20)
    c=Canvas(width=450, height=400)
    c.place(x=325, y=50)
    s=c.create_image(250,200, image=img)
  


def click_london():
    global img
    if var.get() == 0:
        img = PhotoImage(file = 'london_day.png')
        label = Label(root, bg = "white", text = text_london_day, relief = "solid", justify="left")
        label.place(x=80, y=20)
    elif var.get() == 1:
        img = PhotoImage(file = 'paris_night.png')
        label = Label(root, bg = "white", text = text_london_night, relief = "solid", justify="left")  
        label.place(x=80, y=20)
    c=Canvas(width=450, height=400)
    c.place(x=325, y=50)
    s=c.create_image(250,200, image=img)







#variables for Text
text_paris_day="""Paris is capital city of France.
At day time it looks adorable"""
text_paris_night= """At night light is lighed up.
Paris is starting to look like a candle"""
text_oslo_day= """Oslo is capital city of Norway.
At day time it looks like an ordinary magapolicem"""
text_oslo_night= """At night Oslo shines ligher then sun"""
text_london_day= """London is a capital city of the UK.
At day time it is the normal city"""
text_london_night= """At night it is very dangerous, bucause of moped-thieves"""

#widgets buttons
paris = Button(root, text='Paris', command = click_paris)
paris.place(x=20, y=20)
oslo = Button(root, text='Oslo', command = click_oslo)
oslo.place(x=20, y=50)
london = Button(root, text='London', command = click_london)
london.place(x=20, y=80)

var = IntVar()
check = Checkbutton (root, text = "nights photos", variable = var , onvalue = 1, offvalue = 0, height=5, width = 15)
check.place(x=10, y=105)
            

root.mainloop()
