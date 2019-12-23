
import numpy as np
import pandas as pd
import time
import os

rgen = np.random.RandomState(int(time.time()))
os.chdir(r"D:\MIS_COSAS\MyProjects\Machine learning\Handwritten_digits")
data = pd.read_csv("mnist_test.txt")

def sigmoid(a):
    return (1)/(pow(2.7182818,(-1)*(a))+1)

def min_sq(number,predicted):
    a=[]
    for k in range(10):
        if (k == number):
            a.append(pow( (1 - predicted[k]) ,2))
        else:
            a.append(pow( (predicted[k]) ,2))
    a = np.array(a)
    return a

class Cell:

    def __init__(self,n_inputs):
        self.w = rgen.normal(0,0.01,n_inputs)
        self.b = rgen.normal(0,0.01,1)
    def compute(self,X):
        return sigmoid(self.dot(X))
    def dot(self,X):
        return np.dot(self.w,X) + self.b


class Cell_array:
    def __init__(self,n_cells,n_inputs):
        self.cells=[]
        for k in range(n_cells):
            self.cells.append(Cell(n_inputs))
    def compute(self,X):
        a = []
        for cell in self.cells:
           a.append(cell.compute(X))
        a = np.array(a)
        return a
 #"""def fit (self,X):
 #       a = []
 #       for row in range(len(X.index)):
 #           self.compute(X.iloc[row,:])
 #   def train(self,X):
  #      ans = X.iloc[:,0]
  #      errors = (ans - self.fit( X.iloc[:,1:] ) )**2 """



inLayer = Cell_array(16,28*28)
midLayer = Cell_array(16,16)
outLayer = Cell_array(10,16)


total = np.zeros(10)

#for 
for row in range(25):
        aux = inLayer.compute(data.iloc[row,1:])
    #  a = time.time()
        aux = midLayer.compute(aux)
        result_final = outLayer.compute(aux)
        errors = min_sq(data.iloc[row,0] , result_final)
        total =+ errors
        print(total)
    #  print(time.time()-a)

    #  weight adjust(total/(len(X.index)))








