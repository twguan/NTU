
import tkinter as tk
from PyQt5 import QtWidgets
from Model import Model
from ViewQt import mywindow
from Control import Controller

class App(tk.Tk):
    def __init__(self):
        super().__init__()

        self.title('PyQt Demo')

        # create a model
        model = Model('hello@pythontutorial.net')

        # create a view and place it on the root window
        view = mywindow()
        view.show()

        # create a controller
        controller = Controller(model, view)

        # set the controller to view
        view.set_controller(controller)


if __name__=="__main__":
    import sys
    
    app=QtWidgets.QApplication(sys.argv)
    c = App()
    sys.exit(app.exec_())