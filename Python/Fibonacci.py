#!/usr/bin/python3

def fibonacci():

    print("Welcome to Fibionacci Sequncer \n")

    num1=int(input("\nWhat is the first number in sequence?: \n"))
    num2=int(input("\nWhat is the second number in sequence?: \n"))
    seqNum=int(input("\nHow many times?: \n"))
    print("=====")

    i = 0

    while(i < seqNum):

        fibNum = num1 + num2
        num1=num2
        num2=fibNum
        print(fibNum)

        i = i + 1

    print("=====")
    print(fibNum)

fibonacci()
