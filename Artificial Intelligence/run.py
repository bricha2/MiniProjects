from train import trainModel
from test import testModel
from datetime import datetime

def main():
    startTime = datetime.now()
    train_data, train_labels, bestN, bestK = trainModel()
    print('finished training the model', datetime.now() - startTime)
    carList = testModel(train_data, train_labels, bestN, bestK)
    print('finished', datetime.now() - startTime)
    
    print(carList)
    return carList

main()