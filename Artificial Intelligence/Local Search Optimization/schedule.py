#File: schedule.py
#Author: Michael Neary & Max Morawski
#Description: represents a schedule of employees

from random import choice
from day import Day 
import sys

try:
    from prettytable import PrettyTable
except:
    pass

#represents a sequence of days as one cohesive schedule
class Schedule:

    #initializes a blank schedule given the numbers of workers and days
    def __init__(self, num_workers, num_days):
        self.num_workers = num_workers
        self.num_days = num_days

        self.workers = list(range(num_workers))
        self.schedule = []

        for d in range(num_days):
            day = Day(-1, -1, -1)
            self.schedule.append(day)

    def getNumWorkers(self):
        return self.num_workers;

    def getNumDays(self):
        return self.num_days

    def toFile(self, filename):
        with open(filename,"w") as f:
            for day in self.schedule:
                f.write(str(day) + "\n")
    
    #load schedule from file
    #this is mostly for testing
    def load(self, filename):
        with open(filename) as f:
            lines = f.readlines()
            self.num_workers = int(lines[0].strip())
            self.num_days = int(lines[1].strip())
            self.schedule = [None]*self.num_days


            for n,d in enumerate(lines[2:]):
                m,e,g = map(int, d.split(","))
                day = Day(m,e,g)
                self.schedule[n] = day
                self.num_workers = max([m,e,g,self.num_workers])
                
            self.workers = list(range(self.num_workers))

    #randomizes the current schedule
    def randomize(self):    
        for d in range(self.num_days):
            workerA = choice(self.workers)
            workerB = choice(self.workers)
            workerC = choice(self.workers)
            day = Day(workerA, workerB, workerC)
            self.schedule[d] = day

    #set schedule on day for a shift to be a specific employee
    def set(self, day, shift, worker):

        if type(worker) != int or worker < 0 or worker >= self.num_workers:
            msg = "{} is not a valid worker number for this schedule.".format(worker)
            raise ValueError(msg)

        if type(day) != int or day < 0 or day >= self.num_days:
            msg = "{} is not a valid day for this schedule.".format(day)
            raise ValueError(msg)

        self.schedule[day].set(shift, worker)
    
    #string representation of this schedule
    def __str__(self):

        if 'prettytable' not in sys.modules:
            out = ''
            for n,day in enumerate(self.schedule):
                out += str(n)+ ": " + str(day) + "\n"
        else:
            out = PrettyTable()
            out.add_column("", ["Morning","Evening","Graveyard"])

            for n, day in enumerate(self.schedule):
                out.add_column("Day: " + str(n), str(day).split(","))

        return str(out)

    def value1(self):
        # Count the number of shifts that have a unique worker each day
        score = 0
        for d in range(0, self.num_days):
            morning = self.schedule[d].getMorning()
            evening = self.schedule[d].getEvening()
            graveyard = self.schedule[d].getGraveyard()
            if (morning != graveyard):
                score += 1
            if (morning != evening):
                score += 1
            if (graveyard != evening):
                score += 1
        return score


    def value2(self):
        # Get the score from the first test
        score = self.value1()
        
        # Count the number of days with only even or only odd working
        for d in range(self.num_days):
            first = self.schedule[d].getMorning() % 2
            if (self.schedule[d].getEvening() % 2 == first):
                if (self.schedule[d].getGraveyard() % 2 == first):
                    score += 1

        return score

    def numShifts(self, worker, all_shifts):
        total = 0
        for i in all_shifts:
            if worker == i:
                total+=1
        return total


    def value3(self):
        # Get the score from the second test, which includes the first test
        score = self.value2()
        
        # Check and see if the morning following a graveyard is same worker
        graveyard = self.schedule[0].getGraveyard()
        for d in range(1, self.num_days):
            if (graveyard != self.schedule[d].getMorning()):
                score+= 1
            graveyard = self.schedule[d].getGraveyard()
            
        # Calculate the expected number of shifts per person
        expected_shifts = (self.num_days * 3) / self.num_workers
        
        # Get a list of all shifts
        all_shifts = []
        for d in range(0, self.num_days):
            all_shifts.append(self.schedule[d].getMorning())
            all_shifts.append(self.schedule[d].getEvening())
            all_shifts.append(self.schedule[d].getGraveyard())

        # Get the unique list of workers
        workers = list(set(all_shifts))
        for d in workers:
            actual_shifts = self.numShifts(d, all_shifts)
            if actual_shifts == expected_shifts:
                score+=1

        return score

