from schedule import Schedule
import random
from random import randint
import itertools
import math
from math import exp
import copy

def HillClimb(schedule):
    current = copy.deepcopy(schedule)
    val = current.value3()
    days = current.getNumDays()
    workers = current.getNumWorkers()
    shifts = ["morning", "evening", "graveyard"]
    betterState = True
    iterations = 0
    while (betterState):
        neighbor = copy.deepcopy(current)
        
        # randomly select a day to change
        dayIndx = randint(0, days-1)
        
        # randomly select a shift to change
        shiftIndx = randint(0, 2)
        theShift = shifts[shiftIndx]
        
        # randomly select a worker to change
        workerInd = randint(0, workers-1)
        
        neighbor.set(dayIndx, theShift, workerInd)
        
        neighbor_val = neighbor.value3()

        iterations += 1

        if (neighbor_val > val):
            current = copy.deepcopy(neighbor)
            val = neighbor_val
            iterations = 0
            
        else:
            if iterations > 100:
                betterState = False

        return current

def newTemp(time):
    return 1000 - time

# Given a schedule, this will return a schedule optimized
# using simulated annealing
def simulatedAnnealing(schedule):
    
    current = copy.deepcopy(schedule)
    val = current.value3()
    days = current.getNumDays()
    workers = current.getNumWorkers()
    shifts = ["morning", "evening", "graveyard"]
    
    for i in itertools.count():
        
        neighbor = copy.deepcopy(current)
        
        T = newTemp(i)
        if (T==0):
            return current

        neighbor = copy.deepcopy(current)

        # randomly select a day to change
        dayIndx = randint(0, days-1)

        # randomly select a shift to change
        shiftIndx = randint(0, 2)
        theShift = shifts[shiftIndx]

        # randomly select a worker to change
        workerInd = randint(0, workers-1)
        neighbor.set(dayIndx, theShift, workerInd)
        neighbor_val = neighbor.value3()

        E = neighbor_val - val
        if E >0:
            current = copy.deepcopy(neighbor)
        else:
            probability = math.exp(E/T) 
            if (random.random() < probability):
                current = copy.deepcopy(neighbor)

def main():
    
    temp = Schedule(0, 0)
    temp.load("sch1.txt")

    print("Sch1: ")
    print(temp)

    print("Sch1 scores:")
    print("Val1: ", temp.value1())


    print("Val2: ", temp.value2())
    print("Val3: ", temp.value3())

    print("Hill Climbing: ")
    hill = HillClimb(temp)
    print("Val1: ", hill.value1())
    print("Val2: ", hill.value2())
    print("Val3: ", hill.value3())

    print("Simulated Annealing: ")
    simul = simulatedAnnealing(temp)
    print("Val1: ", simul.value1())
    print("Val2: ", simul.value2())
    print("Val3: ", simul.value3())

    print()

    temp.load("sch2.txt")

    print("Sch2: ")
    print(temp)

    print("Sch2 scores:")
    print("Val1: ", temp.value1())
    print("Val2: ", temp.value2())
    print("Val3: ", temp.value3())

    print("Hill Climbing: ")
    hill = HillClimb(temp)
    print("Val1: ", hill.value1())
    print("Val2: ", hill.value2())
    print("Val3: ", hill.value3())

    print("Simulated Annealing: ")
    simul = simulatedAnnealing(temp)
    print("Val1: ", simul.value1())
    print("Val2: ", simul.value2())
    print("Val3: ", simul.value3())



if __name__ == "__main__":
    main()
