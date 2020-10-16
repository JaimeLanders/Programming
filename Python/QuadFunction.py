#!/usr/bin/python3

import math

def quadFun():
    print("Quadratic Function")

    print("=====")
    print("Enter: ")

    a=float(input("a: "))
    b=float(input("b: "))
    c=float(input("c: "))

    poss = (-b + math.sqrt(b * b - (4 * a * c))) / (2 * a)
    neg = (-b - math.sqrt(b * b - (4 * a * c))) / (2 * a)

    print("=====")
    print("x = ")
    print(poss)
    print(neg)

    print()
    input("Press enter to exit ")

quadFun()
