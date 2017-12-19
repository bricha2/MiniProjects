import math
import operator

work_class = ["Private", "Self-emp-not-inc", "Self-emp-inc", "Federal-gov", "Local-gov", "State-gov", "Without-pay", "Never-worked"]

education = ["Bachelors", "Some-college", "11th", "HS-grad", "Prof-school", "Assoc-acdm", "Assoc-voc", "9th", "7th-8th", "12th",
             "Masters", "1st-4th", "10th", "Doctorate", "5th-6th", "Preschool"]

marital = ["Married-civ-spouse", "Divorced", "Never-married", "Separated", "Widowed", "Married-spouse-absent", "Married-AF-spouse"]

occupation = ["Tech-support", "Craft-repair", "Other-service", "Sales", "Exec-managerial", "Prof-specialty", "Handlers-cleaners",
              "Machine-op-inspct", "Adm-clerical", "Farming-fishing", "Transport-moving", "Priv-house-serv", "Protective-serv",
              "Armed-Forces"]

relationship = ["Wife", "Own-child", "Husband", "Not-in-family", "Other-relative", "Unmarried"]

race = ["White", "Asian-Pac-Islander", "Amer-Indian-Eskimo", "Other", "Black"]

sex = ["Female", "Male"]

native_country = ["United-States", "Cambodia", "England", "Puerto-Rico", "Canada", "Germany", "Outlying-US(Guam-USVI-etc)",
                  "India", "Japan", "Greece", "South", "China", "Cuba", "Iran", "Honduras", "Philippines", "Italy", "Poland",
                  "Jamaica", "Vietnam", "Mexico", "Portugal", "Ireland", "France", "Dominican-Republic", "Laos", "Ecuador",
                  "Taiwan", "Haiti", "Columbia", "Hungary", "Guatemala", "Nicaragua", "Scotland", "Thailand", "Yugoslavia",
                  "El-Salvador", "Trinadad&Tobago", "Peru", "Hong", "Holand-Netherlands"]
POS = ""
NEG = ""


class Node:
    # toSplit is the index of allDescriptors this node will split by
    # data has the different samples 
    # labels has the different labels attribute to data
    # attrVal has the value this node was split by
    # attrInd is the index of the value this node was split by
    # Identity is label
    def __init__(self, toSplit, data, labels, attrVal, attrInd = None):
        self.decisionAttr = attrInd
        self.potentialSplits = toSplit
        self.data = data
        self.children = []
        self.labels = labels
        self.attrValue = attrVal
        self.identity = None

    def addChild(self, childNode):
        self.children.append(childNode)

    def getChildren(self):
        return self.children

    def getSplits(self):
        return self.potentialSplits

    def getLabels(self):
        return self.labels

    def getData(self):
        return self.data

    def getValue(self):
        return self.attrValue

    def setValue(self, val):
        self.attrValue = val

    def getIdentity(self):
        return self.identity

    def setIdentity(self, iden):
        self.identity = iden

    def getAttrInd(self):
        return self.decisionAttr

    def setAttrInd(self, ind):
        self.decisionAttr = ind

# Will return the number of pos and neg labels
def countEach(labels, POS, NEG):
    POS_val = 0
    NEG_val = 0
    for i in labels:
        if i == POS:
            POS_val +=1
        else:
            NEG_val +=1

    return POS_val, NEG_val

def train(data, labels):
    
    # Make the positive and negative values
    POS = list(set(labels))[0]
    NEG = list(set(labels))[1]

    possibleAttr = [work_class, education, marital, occupation, relationship, race, sex, native_country]
    possibleSplits = list(range(len(possibleAttr)))

    # get an entropy score for the root
    numPos, numNeg = countEach(labels, POS, NEG)
    posFrac = numPos / (numPos + numNeg)
    negFrac = numNeg / (numPos + numNeg)
    entropy = - (posFrac*math.log2(posFrac)) - (negFrac*math.log2(negFrac))

    gain = []
    
    for attr in range(0, len(possibleAttr)): # Ex. Race
        
        positionScore = entropy

        b = list(set(x[attr] for x in data)) # get all possible attr

        for option in b: # Ex. for Black in Race
            
            tempData = []
            tempLabels = []

            for i in range(0, len(data)): # For person 1 in data
                
                if data[i][attr] == option: # if the data has the same val
                    
                    tempData.append(data[i])
                    tempLabels.append(labels[i])

            numPos, numNeg = countEach(tempLabels, POS, NEG)
            posFrac = numPos/(numPos + numNeg)
            negFrac = numNeg/(numPos + numNeg)

            if posFrac != 0 and negFrac != 0:
                tempScore = ((-posFrac)*math.log2(posFrac)) - (negFrac * math.log2(negFrac))
            elif posFrac == 0:
                tempScore = - negFrac*math.log2(negFrac)
            else:
                tempScore = -posFrac*math.log2(posFrac)

            positionScore -= ((numPos + numNeg)/len(data))*tempScore
        
        gain.append(positionScore)

    # Get the max of the gain and split the root node by that value
    max_indx, max_val = max(enumerate(gain), key = operator.itemgetter(1))
    root = Node(possibleSplits, data, labels, None, max_indx)

    # Make the children nodes
    orgSplit = possibleSplits[:]
    possibleSplits.remove(max_indx)
    
    def buildTree(currentNode):
    
        t_possibleSplits = currentNode.getSplits()
        t_labels = currentNode.getLabels()
        t_data = currentNode.getData()
        
        if len(list(set(t_labels))) == 1: # if all the labels are the same
            currentNode.setIdentity(t_labels[0]) # set ID
            
            return root
        
        if len(possibleSplits) == 0: # if there are no more potential splits
            numPos, numNeg = countEach(t_labels, POS, NEG)
            if numPos > numNeg: # Identity is the most common label
                currentNode.setIdentity(POS)
            else:
                currentNode.setIdentity(NEG)
            return root

        # get an entropy score for the root
        numPos, numNeg = countEach(t_labels, POS, NEG)
        posFrac = numPos / (numPos + numNeg)
        negFrac = numNeg / (numPos + numNeg)
        entropy = - (posFrac*math.log2(posFrac)) - (negFrac*math.log2(negFrac))
        gain = []
        
        for t_attr in t_possibleSplits: # Ex. Race
            
            positionScore = entropy
            
            b = list(set(x[t_attr] for x in t_data)) # get all possible attr

            for option in b: # Ex. for Black in Race
                
                tempData = []
                tempLabels = []

                for i in range(0, len(t_data)):
             
                    if t_data[i][t_attr] == option: # if the data has the same val
                        tempData.append(t_data[i])
                        tempLabels.append(t_labels[i])
                        
                numPos, numNeg = countEach(tempLabels, POS, NEG)
                posFrac = numPos/(numPos + numNeg)
                negFrac = numNeg/(numPos + numNeg)
                
                if posFrac != 0 and negFrac != 0:
                    tempScore = ((-posFrac)*math.log2(posFrac)) - (negFrac * math.log2(negFrac))
                elif posFrac == 0:
                    tempScore = - negFrac*math.log2(negFrac)
                else:
                    tempScore = -posFrac*math.log2(posFrac)

                positionScore -= ((numPos + numNeg)/len(data))*tempScore

            gain.append(positionScore)


        # Get the max of the gain and split the root node by that value
        t_max_indx, t_max_val = max(enumerate(gain), key = operator.itemgetter(1))
        currentNode.setAttrInd(t_possibleSplits[t_max_indx])

        # Make the children nodes
        originalSplit = t_possibleSplits[:]
        b = list(set(x[t_possibleSplits[t_max_indx]] for x in t_data))
        t_possibleSplits.remove(t_possibleSplits[t_max_indx])

        for i in b:

            tempData = []
            tempLabels = []
            for j in range(0, len(t_data)):

                if i == t_data[j][originalSplit[t_max_indx]]:
                    tempData.append(t_data[j])
                    tempLabels.append(t_labels[j])
                    
            newNode = Node(t_possibleSplits, tempData, tempLabels, i)
            currentNode.addChild(newNode)
            buildTree(newNode)
            

    b = list(set(x[orgSplit[max_indx]] for x in data))
    for i in b: # Ex. for Black in Race options

        tempData = []
        tempLabels = []
        for j in range(0, len(data)):
            if i == data[j][orgSplit[max_indx]]:
                tempData.append(data[j])
                tempLabels.append(labels[j])
        
#        print(tempData)
        newNode = Node(possibleSplits, tempData, tempLabels, i)
        root.addChild(newNode)
        buildTree(newNode)

    return root

def printModel(model, count):
    
    # print the index it sorts by, the value it was sorted by, the number of children, ID
    print("New node")
    print("index I could sort by: ", model.getSplits())
    print("index I sort by", model.getAttrInd())
    print("I was sorted by this val: ", model.getValue())
    print("I have this many children: ", len(model.getChildren()))
    print("MY ID is: ", model.getIdentity())
    if (model.getIdentity() == None and len(model.getChildren()) != 0) or (model.getIdentity != None and len(model.getChildren()) == 0):
        print("SUCCESS")
    else:
        print("FAILURE")
    
    print("COUNT", count)

    for i in model.getChildren():
        printModel(i, count+1)

    return

def classify(x, model):
    
#    printModel(model, 0)

    currentNode = model

    ind = currentNode.getAttrInd()

    children = currentNode.getChildren()

    if len(children) == 0: # If there are no children
        return currentNode.getIdentity()

    for i in children:
        
        if i.getValue() == x[ind]: #if the child has the value that matches x
#            print("currentNode sorts by", ind)
#            print("next node has a value of ", i.getValue())
            return classify(x, i)


    """
    Given a some data point (known or not) x, this function
    should apply the model (trained in the above function)
    and return the classification of x based on the model.

    x: a single integer attribute vector for an adult
    """

def convert(data_list):
    """This function converts the categorical values of data_list into integers """

    attributes = [work_class, education, marital, occupation, relationship, race, sex, native_country]

    converted_data = []

    for attribute_value in data_list:

        for attribute_values in attributes:

            if attribute_value in attribute_values:
                converted_data.append(attribute_values.index(attribute_value))

    return converted_data

def main():

    LABELS = ["<=50K",">50K"]

    #here is some code that reads the data from the current dir
    #feel free to change this as you wish
    with open("adult.data") as f:
        data = []
        labels = []
        for line in f:

            #skip bad data
            if len(line) < 10 or "?" in line:
                continue

            line = line.strip().split(",")
            data.append(convert(line[:-1]))
            labels.append(LABELS.index(line[-1]))


    #example run:
    dT = train(data[1:10], labels[1:10])
    sample = ["Private","Bachelors","Married-civ-spouse","Exec-managerial","Husband","Asian-Pac-Islander","Male","Japan"] #>50K
    sample = convert(sample)
    lbl = classify(sample, dT)
    print(sample, lbl)


if __name__ == "__main__":
    main()

                                              
