# Python program to check if a number 
# is a krishnamurthy number 
  
# function to calculate the factorial 
# of any number 
def factorial(n) : 
    fact = 1
    while (n != 0) : 
        fact = fact * n 
        n = n - 1
    return fact 
  
# function to Check if number is 
# krishnamurthy/special 
def isKrishnamurthy(n) : 
    sum = 0
    temp = n 
    while (temp != 0) : 
  
        # calculate factorial of last digit 
        # of temp and add it to sum 
        rem = temp%10
        sum = sum + factorial(rem) 
  
        # replace value of temp by temp / 10 
        temp = temp // 10
          
    # Check if number is krishnamurthy 
    return (sum == n) 
  
# Driver code 
n = int(input())
if (isKrishnamurthy(n)) : 
    print("YES") 
else : 
    print("NO") 
