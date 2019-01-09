#!/usr/bin/python3

# Calculate the hyotenuse of a triangle using Pythagorean Theorem

import math

sideA=float(input('Length of Side A? '))
sideB=float(input('Length of Side B? '))

hypotenuse=math.sqrt(sideA**2 + sideB**2)

print('=====')
print(hypotenuse)

input("\nPress enter to exit ")
