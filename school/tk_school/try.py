import tkinter as tk
import tkinter.ttk as ttk

root = tk.Tk()

label = tk.Label(root, text="Test Callback")
btn = tk.Button(root, text="Text so long that root has to resize.")
btn.pack()
label.pack(fill='both', expand=True)

root.mainloop()
