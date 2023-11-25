
from tkinter import *

# Create the main window
root = Tk()

# Set the size of the canvas
canvas_width = 300
canvas_height = 400
canvas = Canvas(root, width=canvas_width, height=canvas_height)
canvas.pack()

# Draw the snowman
body = canvas.create_oval(50, 50, 250, 250, fill="white", outline="black", width=2)
head = canvas.create_oval(100, 10, 200, 110, fill="white", outline="black", width=2)
eye1 = canvas.create_oval(130, 40, 150, 60, fill="black")
eye2 = canvas.create_oval(170, 40, 190, 60, fill="black")
nose = canvas.create_polygon(150, 70, 175, 100, 125, 100, fill="orange")

# Start the main loop
root.mainloop()
