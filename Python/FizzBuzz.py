#!/usr/bin/python3

def fizzBuzz():
    print ("Welcome to Fizz Buzz!")

    fizzNum=int(input("What number to Fizz Buzz?: "))

    i = 0

    while (i <= fizzNum):
        if i % 15 == 0:
            print("Fizz Buzz")
            i = i + 1
        elif i % 3 == 0:
            print("Fizz")
            i = i + 1
        elif i % 5 == 0:
            print("Buzz")
            i = i + 1
        else:
            print(i)
            i = i + 1

fizzBuzz()
