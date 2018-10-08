while True:
    line = input()

    if line:
        try:
            a = int(line)
            print("Correct!")
            exit(0)
        except ValueError as vr:
            print("Value Error:",vr)
            continue
    else:
        print("Enter something")
        continue
