import numpy as np
from train import getSingleKNN, findNeighbors, getRGB, KNN
data_test = np.load('data_test.npy')

def testModel(training_data, training_labels, bestN, bestK):
    foundCars = []
    for i in range(1125, 1225, bestN):
        for j in range(100, 205, bestN):
            this_RGB = np.array(data_test[j,i])

            # Check if this location is red
            theLabel = getSingleKNN(this_RGB, training_data, training_labels, bestK)

            if (theLabel == 'red'):
                # If the location is red, check if neighbors are also red
                neighbors = findNeighbors(data_test, i, j, bestN)

                # Get neighbor RGBs
                neighbors_RGB = getRGB(neighbors, data_test)

                # Check if neighbors are red
                neighborPredictions = KNN(training_data, neighbors_RGB, training_labels, bestK)
                percentNeighborsRed = neighborPredictions.count('red')/len(neighborPredictions)

                # If 70% of neighboring pixels are red, this is a car
                if (percentNeighborsRed > 0.50):
                    foundCars.append([i,j])
    return foundCars
