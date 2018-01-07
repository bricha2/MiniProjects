# Description:                                                                  
# This is an autofill program.

def convert(filename):
    myBoard = []
    fileThing = open(filename, "r")
    for line in fileThing:
        lineList = []
        for i in range (0, len(line)-1):
            lineList.append(line[i])
        myBoard.append(lineList)
    fileThing.close()
    return myBoard

def changeBoard(myBoard, num1, num2):
    if myBoard[num1][num2] == "X":
        return
    else:
        myBoard[num1][num2] = "X"
        if num1 > 0:
            changeBoard(myBoard, num1-1, num2)
        if num1 < len(myBoard)-1:
            changeBoard(myBoard, num1+1, num2)
        if num2 > 0:
            changeBoard(myBoard, num1, num2-1)
        if num2 < len(myBoard[0])-1:
            changeBoard(myBoard, num1, num2+1)
        return myBoard

def printBoard(myBoard):
    for i in range(len(myBoard)):
        for j in range(len(myBoard[0])):
            print(myBoard[i][j], end = "")
        print()
    return

def main():
    filename = input("Please enter a filename: ")
    myBoard = convert(filename)
    printBoard(myBoard)
    num1, num2 = eval(input("Please enter a square to fill or q to exit: "))
    while num1 != 'q' or num2 != 'q':
        myBoard = changeBoard(myBoard, num1, num2)
        printBoard(myBoard)
        num1, num2 = eval(input("Please enter a sqaure to fill or q to exit: "))
main()
