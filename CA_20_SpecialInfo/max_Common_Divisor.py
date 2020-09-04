#
# max_Common_Divisor.py
# @author bulbasaur
# @description 
# @created 2020-07-29T19:15:50.411Z+08:00
# @last-modified 2020-07-29T19:19:46.775Z+08:00
#

# Define a func
def fun(x, y):
    # get min
    if x > y:
        smaller = y
    else:
        smaller = x
    
    for i in range(1, smaller + 1):
        if((x % i == 0) and (y % i == 0)):
            fun = i
    
    return fun

# Input
num1 = int(input("Num1: "))
num2 = int(input("Num2: "))

print( num1, " and ", num2, " the max common divisor is ", fun(num1, num2))