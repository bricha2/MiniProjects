# Description:
# This is a connect four game, which took a long time.


#makes a board 2d list
#input: rows, cols
#output:board
def makeBoard(rows, cols):
    myBoard = []
    for i in range(rows):
        lists = []
        for j in range(cols):
            lists.append(0)
        myBoard.append(lists)
    return myBoard

#prints board
#input: theboard
#output: nothing
def printBoard(myBoard):
    for i in range(len(myBoard)):
        for j in range(len(myBoard[i])):
            if myBoard[i][j] == 1:
                print("x", end = "")
            elif myBoard[i][j] == -1:
                print("o", end = "")
            else:
                print("_", end = "")
        print()
    return

#saves file
#input: the board, the player who's turn it was, name of file
#output: nothing
def save(myBoard, player, filename):
    fileThing = open(filename, "w")
    for i in range(len(myBoard)):
        for j in range(len(myBoard[i])):
            if myBoard[i][j] == -1:
                fileThing.write(str(2))
            else:
                fileThing.write(str(myBoard[i][j]))
        fileThing.write("\n")
    fileThing.write(str(player))
    fileThing.write("\n")
    print("Saving...")
    fileThing.close()
    return

#loads file
#input: name of file
#output: the board, who's turn it is
def load(filename):
    fileThing = open(filename, "r")
    c = 0
    myBoard = []
    for line in fileThing:
        if len(line) > 3:
            lineList = []
            for i in range (0, len(line)-1):
                if line[i] != "2":
                    lineList.append(int(line[i]))
                else:
                    lineList.append(int(-1))
            myBoard.append(lineList)
        else:
            turn = int(line)
    return myBoard, turn

#determines if an input is an integer
#input: number
#output: True or False
def isInt(number):
    while True:
        try:
            number = int(number)
        except ValueError:
            return False
        else:
            return True

#makes the move
#input: the board, column entered, player who moved
#output: the board
def move(myBoard, col, player):
    col = int(col)
    rows = len(myBoard)
    for i in range(1,rows+1):
        if myBoard[rows-i][col-1] == 0:
            myBoard[rows-i][col-1] = player
            break
    return myBoard

#determines if move can be made
#input: the board, column entered, player who moved
#output: True or False
def canMove(myBoard, col, player):
    intOrNah = isInt(col)
    if intOrNah == False:
        return False
    col = int(col)
    if col > len(myBoard[0]):
        return False
    if myBoard[0][col-1] != 0:
        return False
    return True

#determines if game is draw
#input: the board
#output: True or False
def isDraw(myBoard):
    validMoves = 0
    for i in range(len(myBoard)):
        for j in range(len(myBoard[0])):
            if myBoard[i][j] == 0:
                validMoves = validMoves + 1
    if validMoves == 0:
        return True
    return False

#checks to see who won
#input: the board and the last move
#output: player
def checkWin(myBoard, lastColPlayed):
    col = int(lastColPlayed)-1
    row = "cat"
    count = 0
    while row == "cat" and count < len(myBoard):
        if myBoard[count][col] != 0:
            row = count 
        else:
            count = count + 1
    if count == len(myBoard):
        winner = myBoard[count-1][col]
    else:
        winner = myBoard[count][col]
    #Do I need this conditional?
    if winner == 0:
        return 0
    #horizontal
    horizontalList = []
    for i in range(len(myBoard[0])):
        horizontalList.append(myBoard[row][i])
    repeat = checkList(horizontalList, winner)
    if repeat>=4:
        return winner
    else:
        repeat = 0
    #vertical
    verticalList = []
    for i in range(len(myBoard)):
        verticalList.append(myBoard[i][col])
    repeat = checkList(verticalList, winner)
    if repeat >= 4:
        return winner
    else:
        repeat = 0
    #diagonalleft-right
    diagonalList = []
    if col > row:
        x = row
    else:
        x = col
    highLRow = row - x
    highLCol = col - x
    if (len(myBoard[0]) - highLCol) > (len(myBoard) - highLRow):
        howLong = len(myBoard)- highLRow
        #howLong = len(myBoard)- row
    else:
        howLong = len(myBoard[0])- highLCol
        #howLong = len(myBoard[0]) - col
    for i in range(howLong):
        diagonalList.append(myBoard[highLRow+i][highLCol+i])
    repeat = checkList(diagonalList, winner)
    if repeat >= 4:
        return winner
    else:
        repeat = 0
    #diagonalrighttoleft
    diagonalList2 = []
    if (len(myBoard[0])-col)>row:
        x = row
    else:
        x = len(myBoard[0])- col-1 #subtracted 1
    if (len(myBoard)- row) > col:
        y = col
    else:
        y = len(myBoard) - row-1 #subtracted 1
    for i in range(x+y+1):
        diagonalList2.append(myBoard[row-x+i][col+x-i])
    repeat = checkList(diagonalList2, winner)
    if repeat >= 4:
        return winner
    return 0


#determines if there is a 4 in a row
#input: list, number to repeat
#output: number of repeats
def checkList(theList, play):
    repeats = []
    count = 0
    for i in range(len(theList)):
        if theList[i] == play:
            count = count + 1
        else:
            repeats.append(count)
            count = 0
    repeats.append(count)
    return max(repeats)

def main():
    print("Welcome to Connect Four!")
    answer = "y"
    saved = False
    while (answer == "y" and saved == False):
        upload = input("Would you like to load a game (y/n)?")
        if upload == "y":
            name = input("What is the name of the file you would like to open?")
            myBoard, player = load(name)
            if player == -1:
                player = 2
            else:
                player = 1
        else:
            player = 1
            rows = input("Please enter a number of rows: ")
            if isInt(rows) == True:
                rows = int(rows)
            while isInt(rows) == False or int(rows) < 5:
                rows = input("Please enter a valid choice: ")
                if isInt(rows) == True:
                    rows = int(rows)
            cols = input("Please enter a number of columns: ")
            if isInt(cols) == True:
                cols = int(cols)
            while isInt(cols) == False or int(cols) < 5:
                cols = input("Please enter a valid choice: ")
                if isInt(cols) == True:
                    cols = int(cols)
            myBoard = makeBoard(rows, cols)
        playerMove = 0
        while(checkWin(myBoard, playerMove) == 0 and isDraw(myBoard) == False):
            printBoard(myBoard)
            play = 0
            if player % 2 == 1:
                print("Player 1's turn: ")
                play = 1
            else:
                play = -1
                print("Player 2's turn: ")
            playerMove = input("Please enter a move: ")
            if playerMove == "s":
                filename = input("What would you like to call your game? ")
                save(myBoard, play, filename)
                saved == True
                exit()
            while isInt(playerMove) == False or canMove(myBoard, int(playerMove), play) == False:
                playerMove = input("Please enter a valid choice: ")
                if playerMove == "s":
                     filename = input("What would you like to call your game? ")
                     save(myBoard, play, filename)
            player = player + 1
            if saved == False:
                playerMove = int(playerMove)
                myBoard = move(myBoard, playerMove, play)
    #outside of loop                                                            
        win = checkWin(myBoard,playerMove)
        printBoard(myBoard)
        if win == 1:
            print("Player 1 wins!")
        elif win == -1:
            print("Player 2 wins!")
        else:
            print("The game is a draw!")
        answer = input("Would you like to play again (y/n): ")
main()
