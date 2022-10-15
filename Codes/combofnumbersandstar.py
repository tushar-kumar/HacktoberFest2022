#numbers

#1
#2*2
#3*3*3
#4*4*4*4


def pattern(rows):
    for i in range(1, rows):
        for j in range(1, 2*i):
            if(j % 2 == 0):
                print("*", end="")
            else:
                print(i, end="")
        print("")

    for i in range(rows, -1, -1):
        for j in range(1, 2*i):
            if(j % 2 == 0):
                print("*", end="")
            else:
                print(i, end="")
        print("")

rows = int(input("Enter a number: "))
pattern(rows)