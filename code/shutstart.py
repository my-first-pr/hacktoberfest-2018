def binary(a, tv):
    minimum = 0
    maximum = len(a) - 1
    while minimum < maximum:
        guess = round((minimum + maximum)/2)
        if a[guess] == tv:
            return guess
        elif a[guess] < tv:
            minimum = guess + 1
        else:
            maximum = guess - 1
    return -1


arr = []

ind = binary(arr, 4)
print("index:")
print(ind)
