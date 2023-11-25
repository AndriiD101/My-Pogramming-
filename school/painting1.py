from tkinter import *
root = Tk()
c = Canvas(root, width=400, height=400)
c.pack()
c.create_oval(35,20,365,350)
c.create_oval(130,110,160,170)
c.create_oval(230,110,260,170)
c.create_line(170,250,200,272,230,250)
c.create_rectangle(200, 200, 210, 210)
