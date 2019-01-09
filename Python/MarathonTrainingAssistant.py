#Marathon Training Assistant
#---------------------------

import math

#This function converts a number of minutes and seconds into just seconds.
def total_seconds(min, sec):
  return min * 60 + sec
  
#This function calculates a speed in miles per hour given # a time (in secoonds) to run a single mile.
def speed(time):
  return 3600 / time
  
#Prompt user for pace and mileage.
pace_minutes = int(input('Minutes per mile?'))
pace_seconds = int(input('Seconds per mile?'))
miles = int(input('Total miles?'))

#Calulcate and print speed.
mph = speed(total_seconds(pace_minutes, pace_seconds))
print('Your speed is')
print(mph)

#Calculate elapsed time for planned workout.
total = miles * total_seconds(pace_minutes, pace_seconds)
elapsed_minutes = total // 60
elapsed_seconds = total % 60

print('Your total elapsed time is')
print(elapsed_minutes)
print(elapsed_seconds)
