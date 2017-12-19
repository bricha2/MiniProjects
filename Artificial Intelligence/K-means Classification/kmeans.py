import random
import math
import operator
from random import randint
from operator import sub
'''
Project 4: K-means Classificiation
Author:
Date: 

Implements a K-means classifier on the Iris dataset
'''

def train(data, labels, k=3):
    random.seed()
            
    # set of which indices are in which final set
    sets = []
    for i in range (0, k):
        sets.append([])

    # Make a dictionary with the data
    flowerWithLabel = {}
    for i in range(0 ,len(data)):
        flowerWithLabel[repr(data[i])] = labels[i] 

    # Randomly select k centroids
    centroids = [];
    for i in range(0, k):
        num = randint(0, len(data)-1)
        centroids.append(data[num])

    # Check the distance between centroids and data and put
    # in appropriate set
    for i in range(0, len(data)):
        distance = []
        for j in range(0, k):
            subtracted = map(sub, centroids[j], data[i])
            squared = map(lambda x: x ** 2, subtracted) 
            distance.append(math.sqrt(sum(squared)))

        min_indx, min_val = min(enumerate(distance), key = operator.itemgetter(1))
        sets[min_indx].append(data[i])
        

    # Make the new centroids based on sets
    centroids = []
    for i in sets:
        centroids.append(list(map(lambda x: sum(x)/float(len(x)), zip(*i))))
            
    # Call RepeatedTrain
    sets, centroids = repeatedTrain(data, sets, centroids, 3)
    
    # Count the labels within each set
    uniqueLabels = list(set(labels))
    model = []
    model.append([0]*k)
    model.append([0]*k)
    for i in range(0, len(sets)): # for lists of data flowers closest to 1 centroid
        model[0][i] = centroids[i]
        eachType = [0]*len(uniqueLabels)
        for j in range(0, len(uniqueLabels)): # for each label
            for l in sets[i]: # see which data labels show up most often
                if flowerWithLabel[repr(l)] == uniqueLabels[j]:
                    eachType[j] += 1
        max_indx, max_val = max(enumerate(eachType), key = operator.itemgetter(1))
        model[1][i] = uniqueLabels[max_indx]

    return model

def repeatedTrain(data, oldSet, centroids, k = 3):
    
    sets = []
    for i in range(0, k):
        sets.append([])

    # Check the distance between centroids and data and put
    # in appropriate set
    for i in range(0, len(data)):
        distance = []
        for j in range(0, k):
            subtracted = map(sub, centroids[j], data[i])
            squared = map(lambda x: x ** 2, subtracted)
            distance.append(math.sqrt(sum(squared)))

        min_indx, min_val = min(enumerate(distance), key = operator.itemgetter(1))
        sets[min_indx].append(data[i])

    # Make the new centroids based on sets

    centroids = []
    for i in sets:
        centroids.append(list(map(lambda x: sum(x)/float(len(x)), zip(*i))))

    # Check if the new set is the same as the old set
    if (sets != oldSet):
        sets, centroids = repeatedTrain(data, sets, centroids, 3)

    return sets, centroids


def classify(x, model):
    
    # Retrieve the keys(centroids) from the model
    centroids = model[0]
    types = model[1]
    test = x

    # Find which centroid the data is closest to
    distance = []
    for j in range(0, len(centroids)):
        subtracted = map(sub, centroids[j], test)
        squared = map(lambda x: x ** 2, subtracted)
        distance.append(math.sqrt(sum(squared)))

    min_indx, min_val = min(enumerate(distance), key = operator.itemgetter(1))

    return types[min_indx]
    


