import math
import operator
file1_strings = []
file2_strings = []
file3_strings = []
file4_strings = []
file5_strings = []

def in_other(string):

    countString = 0

    if file1_strings.count(string) > 0:
        countString = countString + 1


    if file2_strings.count(string) > 0:
        countString = countString + 1
        
        
    if file3_strings.count(string) > 0:
        countString = countString + 1
        
        
    if file4_strings.count(string) > 0:
        countString = countString + 1
        

    if file5_strings.count(string) > 0:
        countString = countString + 1

    return countString

def runNPrint(file_strings, filename):

    # Make a dictionary and put strings and td-idf scores in it
    scores = {}
    
    for i in file_strings:
        in_this_file = file_strings.count(i)
        TF = in_this_file / len(file_strings)
        in_other_score = in_other(i)
        IDF = math.log(5/in_other_score)
        scores[i] = TF * IDF


    # Print the results for the first file
#    for x in scores:
#        print(x, scores[x])
    top = dict(sorted(scores.items(), key = operator.itemgetter(1), reverse= True)[:5])
    top = sorted(top.items(), key = operator.itemgetter(1))
    print("Top words in document ", filename)
    for x,y in top:
        print("Word:", x + ", TF-IDF:", y)

    print()


def main():

    # Open the files and put them in arrays split by space
    global file1_strings, file2_strings, file3_strings, file4_strings, file5_strings
    
    file1 = open("apple.txt", "r").read()
    file1_strings = file1.split()
    
    file2 = open("facebook.txt", "r").read()
    file2_strings = file2.split()

    file3 = open("google.txt", "r").read()
    file3_strings = file3.split()

    file4 = open("microsoft.txt", "r").read()
    file4_strings = file4.split()

    file5 = open("tesla.txt", "r").read()
    file5_strings = file5.split()

    runNPrint(file1_strings, "apple.txt")
    runNPrint(file2_strings, "facebook.txt")
    runNPrint(file3_strings, "google.txt")
    runNPrint(file4_strings, "microsoft.txt")
    runNPrint(file5_strings, "tesla.txt")




main()
