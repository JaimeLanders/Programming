#!/usr/bin/python3
cash = 0.0
checking = 0.0

def balance():
#    if(cash & checking):
    print("Cash: $", cash); print("Checking: $", checking)
    menu() 

def update():
    print("Welcome to accounting")
    cash=float(input("Cash: $"))
    print ("Cash: $",cash)
#    print(cash)
    checking=float(input("Checking: $"))
    print("Checking: $",checking)
    menu() 

def menu():
#    cash=0.0
#    checking=0.0
#    print("Cash: $", cash); print("Checking: $", checking)
    userSel=input("Enter 'b'alance, 'q'uit, 'u'pdate: ")

    while (userSel != "q"):

#    print("Cash: $", cash, "Checking: $", checking)

        if (userSel == "b"):
            balance()
        elif (userSel == "u"):
            update()
        else: 
            print("You did not enter a valid selection, try again... ")

        if (userSel == "q"):
            input("Press enter to exit")

menu()

