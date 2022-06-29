from PyQt5 import QtWidgets, QtCore
from QtUI import Ui_Form


class mywindow(QtWidgets.QWidget, Ui_Form):
    def __init__(self):
        super(mywindow,self).__init__()
        self.setupUi(self)
        
        self.save_button.clicked.connect(self.save_button_clicked)
        self.controller = None
        
    
    def set_controller(self, controller):
        """
        Set the controller
        :param controller:
        :return:
        """
        self.controller = controller

    def save_button_clicked(self):
        """
        Handle button click event
        :return:
        """
        if self.controller:
            self.controller.save(self.email_entry.text())

    def show_error(self, message):
        """
        Show an error message
        :param message:
        :return:
        """
        
        msg = str(message)
        self.email_entry.setStyleSheet("color: red;")
        self.message_label.setText(msg)
        self.message_label.setStyleSheet("color: red;")
        QtCore.QTimer.singleShot(2000, self.hide_message)

    def show_success(self, message):
        """
        Show a success message
        :param message:
        :return:
        """
        
        self.email_entry.setText("")
        self.message_label.setText(message)
        self.message_label.setStyleSheet("color: green;")
        QtCore.QTimer.singleShot(2000, self.hide_message)

    def hide_message(self):
        """
        Hide the message
        :return:
        """
        self.message_label.setText("")
        self.email_entry.setStyleSheet("color: black;")
        
        
if __name__=="__main__":
    import sys
    
    app=QtWidgets.QApplication(sys.argv)
    myshow=mywindow()
    myshow.show()
    sys.exit(app.exec_())
