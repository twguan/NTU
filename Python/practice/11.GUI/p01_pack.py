import tkinter as tk

root = tk.Tk()
root.title('Pack Demo')
root.geometry("300x200")

# box 1
box1 = tk.Label(root, text="Box 1", bg="green", fg="white")
box1.pack(ipadx=10, ipady=10, )#fill='x')

# box 2
box2 = tk.Label(root, text="Box 2", bg="red", fg="white")
box2.pack(ipadx=10, ipady=10)

root.mainloop()
