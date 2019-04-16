import numpy as np
import random
from sklearn.model_selection import train_test_split
from scipy.stats import multivariate_normal
from sklearn.metrics import accuracy_score
from scipy.spatial import distance
from collections import Counter
import matplotlib.pyplot as plt
from sklearn.metrics import confusion_matrix
import seaborn as sns

data_train = np.load('data_train.npy')
ground_truth = np.load('ground_truth.npy')
ground_truth_coord = ground_truth[:,:2]

def getRandomCoords(X, Y, invalidList):
    fits = False
    while (not fits):
        x = random.randint(0,X-1)
        y = random.randint(0,Y-1)
        
        # Determine how close that X, Y is to the list of invalid options
        differenceX = abs(invalidList[:,0]-x)
        differenceY = abs(invalidList[:,1]-y)
        difference = [sum(x) for x in zip(differenceX, differenceY)]
        if (any(x > 20 for x in difference)):
            fits = True
    return x, y

def getRGB(coordinateList, dataset):
    target_RGB = []
    for i in range(len(coordinateList)):
        current_object = coordinateList[i]
        current_RGB = dataset[current_object[1],current_object[0]].tolist()
        target_RGB.append(current_RGB)
    return np.array(target_RGB)

def KNN(trainingData, testData, labels, K):
    predicted_labels = []
    # For each row in testData 
    for i in range(len(testData)):
        currentTest = testData[i,:]
        distToTrain = []
        # Get distance to all training data rows
        for j in range(len(trainingData)):
            currentTrain = trainingData[j,:]
            dist = distance.euclidean(currentTest, currentTrain)
            distToTrain.append(dist)
            
        # Sort the distances from smallest to largest
        ind = np.argsort(distToTrain)
        
        # Get the top K indices
        topK = ind[0:K]
        
        # Find the most popular label for those K indices.
        topLabels = labels[topK]
        most_common,num_most_common = Counter(topLabels).most_common(1)[0] # 4, 6 times
        predicted_labels.append(most_common)
    return predicted_labels

def getSingleKNN(dataPoint, trainingData, trainingLabels, K):
    distToTrain = []
    for j in range(len(trainingData)):
        currentTrain = trainingData[j,:]
        dist = distance.euclidean(dataPoint, currentTrain)
        distToTrain.append(dist)
            
    # Sort the distances from smallest to largest
    ind = np.argsort(distToTrain)
        
    # Get the top K indices
    topK = ind[0:K]
        
    # Find the most popular label for those K indices.
    topLabels = trainingLabels[topK]
    most_common,num_most_common = Counter(topLabels).most_common(1)[0] # 4, 6 times
    return most_common

def findNeighbors(dataset, X, Y, step):
    theList = []
    for i in range(-step,step):
        for j in range(-step, step):
            theList.append([X+i, Y+j])
    return theList

def plotKResults(k_range, k_avg, k_var):
    # Plot the K results
    # create stacked errorbars:
    plt.errorbar(k_range, k_avg, k_var, fmt='ok', lw=3)
    plt.xlabel('K')
    plt.ylabel('Fractional Accuracy')
    plt.title('Identifying Optimal K for KNN')
    plt.savefig('bestK.png')
    return

def plotNResults(N_range, n_avg, n_var):
    # Plot the N Results
    # create stacked errorbars:
    plt.errorbar(N_range, N_avg, N_var, fmt='ok', lw=3)
    plt.xlabel('Neighbors')
    plt.ylabel('Fractional Accuracy')
    plt.title('Identifying Optimal Neighbors to Consider as Car')
    plt.savefig('bestN.png')
    return

def plotKConfusion(bestK):
    red_coords = ground_truth_coord

    # Retrieve RGB values for each of the target truth values
    red_RGB = getRGB(red_coords, data_train)

    # Randomly select pixels in the dataset that are not too close to the ground_truth points
    notRed_coords = []
    for i in range(len(red_coords)):
        x_rand, y_rand = getRandomCoords(len(data_train[0]), len(data_train), red_coords)
        notRed_coords.append([x_rand, y_rand])

    # Find the corresponding RGB valuees
    notRed_RGB = getRGB(notRed_coords, data_train)

    # Add the red and notRed data into the training data
    training_data = np.append(red_RGB, notRed_RGB, axis=0)
    training_labels = np.array(['red']*len(red_RGB) + ['notRed']*len(notRed_RGB))

    # For that best K, plot the predicted vs actual values
    X_train, X_valid, label_train, label_valid = train_test_split(training_data, training_labels, test_size = 0.5, random_state = 20)
    train_classes = np.sort(np.unique(training_labels))

    # KNN - Make predictions
    predictions = KNN(X_train, X_valid, label_train, bestK)
    accuracy_score(label_valid, predictions)

    K_matrix = confusion_matrix(label_valid, predictions)
    sns.heatmap(K_matrix.T, square=True, annot=True, fmt='d', cbar=False,
                xticklabels=['Red', 'NotRed'],
                yticklabels=['Red', 'NotRed'])
    plt.xlabel('true label')
    plt.ylabel('predicted label');
    plt.title('Confusion Matrix for Best K (k = 7)')
    plt.savefig('bestK_confMat.png')
    return

def plotNConfusion(bestN, bestK):
    # Put all neighbors into a list
    red_coords = []
    for i in ground_truth_coord:
        red_coords += findNeighbors(data_train, i[1], i[0], bestN)
    red_coords = np.array(red_coords)

    # Retrieve RGB values for each of the target truth values
    red_RGB = getRGB(red_coords, data_train)

    # Randomly select pixels in the dataset that are not too close to the ground_truth points
    notRed_coords = []
    for i in range(len(red_coords)):
        x_rand, y_rand = getRandomCoords(len(data_train[0]), len(data_train), red_coords)
        notRed_coords.append([x_rand, y_rand])

    # Find the corresponding RGB valuees
    notRed_RGB = getRGB(notRed_coords, data_train)

    # Add the red and notRed data into the training data
    training_data = np.append(red_RGB, notRed_RGB, axis=0)
    training_labels = np.array(['red']*len(red_RGB) + ['notRed']*len(notRed_RGB))

    # For that best K, plot the predicted vs actual values
    X_train, X_valid, label_train, label_valid = train_test_split(training_data, training_labels, test_size = 0.5, random_state = 20)
    train_classes = np.sort(np.unique(training_labels))

    # KNN - Make predictions
    predictions = KNN(X_train, X_valid, label_train, bestK)
    accuracy_score(label_valid, predictions)

    K_matrix = confusion_matrix(label_valid, predictions)
    sns.heatmap(K_matrix.T, square=True, annot=True, fmt='d', cbar=False,
                xticklabels=['Red', 'NotRed'],
                yticklabels=['Red', 'NotRed'])
    plt.xlabel('true label')
    plt.ylabel('predicted label');
    plt.title('Confusion Matrix for Best N (N = 4)')
    plt.savefig('bestN_confMat.png')

def getBestK():
    # Find the best k value
    accuracyTable = []
    for M in range(5,25,5):
        accuracyRow = []
        for k in range(5,21,2):
            red_coords = ground_truth_coord

            # Retrieve RGB values for each of the target truth values
            red_RGB = getRGB(red_coords, data_train)

            # Randomly select pixels in the dataset that are not too close to the ground_truth points
            notRed_coords = []
            for i in range(len(red_coords)):
                x_rand, y_rand = getRandomCoords(len(data_train[0]), len(data_train), red_coords)
                notRed_coords.append([x_rand, y_rand])

            # Find the corresponding RGB valuees
            notRed_RGB = getRGB(notRed_coords, data_train)

            # Add the red and notRed data into the training data
            training_data = np.append(red_RGB, notRed_RGB, axis=0)
            training_labels = np.array(['red']*len(red_RGB) + ['notRed']*len(notRed_RGB))

            # Conduct Cross Validation 
            # split the rows
            X_train, X_valid, label_train, label_valid = train_test_split(training_data, training_labels, test_size = 0.33, random_state = M)
            train_classes = np.sort(np.unique(training_labels))

            """ ==== KNN Predict the classes  && Accuracies ===="""
            predictions = KNN(X_train, X_valid, label_train, k)
            accuracyRow.append(accuracy_score(label_valid, predictions))
        accuracyTable.append(accuracyRow)
    accuracyTable = np.array(accuracyTable)
    
    k_range = list(range(5, 21, 2))

    # Find the average accuracy for each K value
    k_avg = np.mean(accuracyTable, axis=0)
    k_avgInd = sorted(range(len(k_avg)), key=lambda i: k_avg[i])
    k_avgInd = k_avgInd[::-1]

    # Find the variance for each K value
    k_var = np.var(accuracyTable, axis=0)
    k_varInd = sorted(range(len(k_var)), key=lambda i: k_var[i])
    
    # plotKResults(k_range, k_avg, k_var)
    
    # Find the index with the highest K value and the lowest variance
    bestK=-1
    for i in range(len(k_avg)):
        for k in range(i + 1):
            for j in range(i + 1):
                if (k_avgInd[k] == k_varInd[j]):
                    bestK = k_avgInd[k]
                    break
            if (bestK != -1):
                break
        if (bestK != -1):
            break

    bestK = k_range[bestK]
    
    #plotKConfusion(bestK)
    
    return bestK

def getBestN(bestK):
    accuracyTable = []
    for M in range(5,25,5):
        accuracyRow = []
        for N in range(3,8):

            # Put all neighbors into a list
            red_coords = []
            for i in ground_truth_coord:
                red_coords += findNeighbors(data_train, i[1], i[0], N)
            red_coords = np.array(red_coords)

            # Retrieve RGB values for each of the target truth values
            red_RGB = getRGB(red_coords, data_train)

            # Randomly select pixels in the dataset that are not too close to the ground_truth points
            notRed_coords = []
            for i in range(len(red_coords)):
                x_rand, y_rand = getRandomCoords(len(data_train[0]), len(data_train), red_coords)
                notRed_coords.append([x_rand, y_rand])

            # Find the corresponding RGB valuees
            notRed_RGB = getRGB(notRed_coords, data_train)

            # Add the red and notRed data into the training data
            training_data = np.append(red_RGB, notRed_RGB, axis=0)
            training_labels = np.array(['red']*len(red_RGB) + ['notRed']*len(notRed_RGB))

            # Conduct Cross Validation 
            # split the rows
            X_train, X_valid, label_train, label_valid = train_test_split(training_data, training_labels, test_size = 0.33, random_state = M)
            train_classes = np.sort(np.unique(training_labels))

            # Use KNN to get predictions
            predictions = KNN(X_train, X_valid, label_train, bestK)
            accuracyRow.append(accuracy_score(label_valid, predictions))
        accuracyTable.append(accuracyRow)
    
    N_range = list(range(3,8))

    # Find the average accuracy for each K value
    N_avg = np.mean(accuracyTable, axis=0)
    N_avgInd = sorted(range(len(N_avg)), key=lambda i: N_avg[i])
    N_avgInd = N_avgInd[::-1]

    # Find the variance for each K value
    N_var = np.var(accuracyTable, axis=0)
    N_varInd = sorted(range(len(N_var)), key=lambda i: N_var[i])
    
    #plotNConfusion(bestN, bestK)
    return bestN
    
def trainModel():
    bestK = getBestK()
    #bestN = getBestN(bestK)
    bestN = 4
    
    red_coords = []
    for i in ground_truth_coord:
        red_coords += findNeighbors(data_train, i[1], i[0], bestN)
    red_coords = np.array(red_coords)

    # Retrieve RGB values for each of the target truth values
    red_RGB = getRGB(red_coords, data_train)

    # Randomly select pixels in the dataset that are not too close to the ground_truth points
    notRed_coords = []
    for i in range(len(red_coords)):
        x_rand, y_rand = getRandomCoords(len(data_train[0]), len(data_train), red_coords)
        notRed_coords.append([x_rand, y_rand])

    # Find the corresponding RGB valuees
    notRed_RGB = getRGB(notRed_coords, data_train)

    # Add the red and notRed data into the training data
    training_data = np.append(red_RGB, notRed_RGB, axis=0)
    training_labels = np.array(['red']*len(red_RGB) + ['notRed']*len(notRed_RGB))

    return training_data, training_labels, bestN, bestK   