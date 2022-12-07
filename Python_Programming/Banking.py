# Instance variable : Name, Amount, Address, Account number
# Instace method : CreateAccount(), DisplayAccountInfo()
# Class variable : Bank_Name, ROI_On_FD
# Class method : DisplayBankInformation()
# Static method : DisplayKYCInfo

class Bank_Account:

    Bank_Name = "HDFC Bank Pvt. Ltd."
    ROI_On_FD = 6.7

    def __init__(self):
        self.Name = ""
        self.Amount = 0
        self.Address = ""
        self.AccountNo = 0

    def CreateAccount(self):
        print("Enter your name : ")
        self.Name = input()

        print("Enter your initial amount : ")
        self.Amount = int(input())

        print("Enter your address : ")
        self.Address = input()

        print("Enter your account number : ")
        self.AccountNo = int(input())

    def DisplayAccountInfo(self):
        print("--------Your account information is as below--------")
        print("Name of account holder : ",self.Name)
        print("Account number : ",self.AccountNo)
        print("Address of account holder : ",self.Address)
        print("Current amount in account : ",self.Amount)

    @classmethod
    def DisplayBankInformation(cls):
        print("Welcone to banking console")
        print("Name of our bank is : ",cls.Bank_Name)
        print("Rate of interest we offer on fixed deposite is : ",cls.ROI_On_FD)

    @staticmethod
    def DisplayKYCInfo():
        print("Please consider below KYC information")
        print("According to the rules of Government of India you have to submite the below documents")
        print("1 : Clear and recent passport size photo")
        print("2 : Photo of aadhar card")
        print("3 : Photo of PAN card")

    def Deposite(self,value):
        self.Amount = self.Amount + value

    def Withdrawl(self,value):
        self.Amount = self.Amount - value

def main():

    print("----------------------------------------------------------------------")
    print("--------Banking Application--------")
    print("--------Calling static method who  display KYC input--------")
    print("----------------------------------------------------------------------")
    Bank_Account.DisplayKYCInfo()

    print("----------------------------------------------------------------------")
    print("--------Accessing the instance variable from main--------")
    print("----------------------------------------------------------------------")
    print("Name of Bank : ",Bank_Account.Bank_Name)
    print("Rate of Interest on Fixed deposit : ",Bank_Account.ROI_On_FD)

    print("----------------------------------------------------------------------")
    print("--------Calling the class method to display bank information--------")
    print("----------------------------------------------------------------------")
    Bank_Account.DisplayBankInformation()

    print("----------------------------------------------------------------------")
    print("--------Creating the object of calass --------")
    print("----------------------------------------------------------------------")
    User1 = Bank_Account()
    User2 = Bank_Account()

    print("----------------------------------------------------------------------")
    print("Creating the first account")
    print("--------Enter the details of first account holder --------")
    print("----------------------------------------------------------------------")
    User1.CreateAccount()

    print("----------------------------------------------------------------------")
    print("Creating the second account")
    print("--------Enter the details of second account holder --------")
    print("----------------------------------------------------------------------")
    User2.CreateAccount()

    print("----------------------------------------------------------------------")
    print("--------Calling display method to display account information of User1 --------")
    print("----------------------------------------------------------------------")
    User1.DisplayAccountInfo()

    print("----------------------------------------------------------------------")
    print("--------Calling display method to display account information of User2 --------")
    print("----------------------------------------------------------------------")
    User2.DisplayAccountInfo()

    print("----------------------------------------------------------------------")
    print("--------Depositing 500 in User1--------")
    print("----------------------------------------------------------------------")
    User1.Deposite(500)

    print("----------------------------------------------------------------------")
    print("--------Depositing 500 in User1--------")
    print("----------------------------------------------------------------------")
    User2.Deposite(1200)

    print("Amount of {} after deposite is {}".format(User1.Name,User1.Amount))
    print("Amount of {} after deposite is {}".format(User2.Name,User2.Amount))

    print("----------------------------------------------------------------------")
    print("--------Withdrawal of 200 in User1--------")
    print("----------------------------------------------------------------------")
    User1.Withdrawl(200)

    print("----------------------------------------------------------------------")
    print("--------Withdrawal of 3000 in User2--------")
    print("----------------------------------------------------------------------")
    User2.Withdrawl(3000)

    print("Amount of {} after withdraw is {}".format(User1.Name,User1.Amount))
    print("Amount of {} after withdraw is {}".format(User2.Name,User2.Amount))

    print("----------------------------------------------------------------------")
    print("--------End of Application--------")
    print("----------------------------------------------------------------------")

if __name__ == "__main__":
    main()