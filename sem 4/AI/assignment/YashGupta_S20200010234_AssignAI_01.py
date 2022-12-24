# YASH GUPTA
# S20200010234

import random
import math
p = int(input("Enter the population size : "))
c = int(input("Enter the crossover type(0 for one point and 1 for two point) : "))
m = int(input("Enter the mutation type(0 for bit flip and 1 for swap mutation) : "))
t = int(input("Enter the termination condition(0 for no improvement for x iteration and 1 for predefined i iterations) : "))


populations = ([[random.randint(0, 1) for x in range(5)] for i in range(p)])
fittest = []
parents = []
print("\nInitial Population: \n",populations)


def fitness_value():
    global populations, fittest
    fit_value = []
    print("\nDecimal Values: \n")
    for i in range(len(populations)):
        decimal_value = 0

        for j in range(0, 5):
            decimal_value += populations[i][j]*(2**(4-j))
        print(decimal_value)
        fit_value.append(decimal_value**2)
    print("\nFitness Score: \n",fit_value)
    fit_value, populations = zip(*sorted(zip(fit_value, populations), reverse=True))
    fittest.append(fit_value[0])

def selectparent():
    global parents
    parents=populations[0:2]
    print("\nSelected Parents: \n",parents)

def crossover() :
    global parents
    
    if c == 0:
        cross_point = random.randint(0,4)
        parents =parents + tuple([(parents[1][0:cross_point +1] +parents[0][cross_point+1:5])])
        parents =parents + tuple([(parents[0][0:cross_point +1] +parents[1][cross_point+1:5])])
    elif c == 1:
        cross_point_1 = random.randint(0,4)
        cross_point_2 = cross_point_1
        while cross_point_1 >= cross_point_2:
            cross_point_2 = random.randint(0,4)
        parents =parents + tuple([(parents[1][0:cross_point_1 +1] +parents[0][cross_point_1+1:cross_point_2+1] +parents[0][cross_point_2+1:5])])
        parents =parents + tuple([(parents[0][0:cross_point_1 +1] +parents[1][cross_point_1+1:cross_point_2+1] +parents[1][cross_point_2+1:5])])
    else:
        print("Invalid crossover type")
    print("\nAfter Crossover: \n",parents)

def mutation() :
    global populations, parents
    if m == 0 :
        x = random.randint(0,3)
        y = random.randint(0,4)
        parents[x][y] = 1-parents[x][y]
    if m == 1:
        x = random.randint(0,3)
        y1 = random.randint(0,4)
        y2 = y1
        while y1 == y2:
            y2 = random.randint(0,4)
        parents[x][y1], parents[x][y2] = parents[x][y2], parents[x][y1]
    populations = parents
    print("\nAfter Mutation: \n",populations)

def DecimalToBinary(num):
     
    if num >= 1:
        DecimalToBinary(num // 2)
    print(num % 2, end = '')

if t==0:
    x = int(input("Enter the number of iterations : "))
    fitness_value()
    selectparent()
    crossover()
    mutation()
    fitness_value()
    count=0
    i=0
    while count<x:
        if fittest[i]<fittest[i+1]:
            selectparent()
            crossover()
            mutation()
            fitness_value()
            count=0
        else:
            selectparent()
            crossover()
            mutation()
            fitness_value()
            count+=1
        i+=1
    print("\nSolution: \n")
    DecimalToBinary(int(math.sqrt(max(fittest))))
elif t==1:
    i = int(input("Enter the number of iterations : "))
    fitness_value()
    for j in range(i):
        selectparent()
        crossover()
        mutation()
        fitness_value()
    print("\nSolution: \n")
    DecimalToBinary(int(math.sqrt(fittest[-1])))
else:
    print("Invalid termination condition")
    exit()