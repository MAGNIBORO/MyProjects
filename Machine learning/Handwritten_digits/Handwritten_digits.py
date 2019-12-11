
import random
import csv

#Traindata = open(r"D:\MIS_COSAS\MyProjects\Machine learning\Handwritten_digits\mnist_train.txt","r")
#Testdata = open(r"D:\MIS_COSAS\MyProjects\Machine learning\Handwritten_digits\mnist_test.txt","r")

Traindata = csv.reader(open(r"D:\MIS_COSAS\MyProjects\Machine learning\Handwritten_digits\mnist_train.txt","r"), delimiter=',')
Testdata = csv.reader(open(r"D:\MIS_COSAS\MyProjects\Machine learning\Handwritten_digits\mnist_test.txt","r"), delimiter=',')

N_IN_NEURONS = 28*28
N_HIDDEN_NEURONS = 16
N_OUT_NEURONS = 10

class Node:
    
    def __init__(self,number_neurons):
        self.weights = random_array(-1,1,number_neurons)
        self.bias = random_array(-1,1,1)[0]

    def calculate(self,in_values):
        self.value = sigmoid( prod_point (in_values,self.weights) - self.bias)
        return self.value
    
    def print(self):
        for x in range(0,len(self.weights)):
            print("the %d weight and bias is %f\n" % (x,self.weights[x]))
        print("the bias is %f\n" % (self.bias))


def random_array(low,high,number):
    a = []
    for x in range(0,number):
        a.append( random_number(low,high) )
    
    return a

def random_number(low,high):
    return (low + (high-low)*random.random())

def sigmoid(a):
    return 1/ ( pow(2.718281828,(-1)*a) + 1)

def prod_point(a,b):
    c=0
    for x in range(0,len(a)):
        c += float(a[x])*float(b[x])
    return c

outNeurons=[]
hiddenNeurons=[]
labels = []

print(pow(2,-3000))
for k in range(1,N_HIDDEN_NEURONS):
    hiddenNeurons.append(Node(N_IN_NEURONS))

for k in range(1,N_OUT_NEURONS):
    outNeurons.append(Node(N_HIDDEN_NEURONS))

for row in Traindata:
    labels.append(row[0])

    for node in hiddenNeurons:
        node.calculate(row[1:])

    if(Traindata.line_num==1000):
        break

print(labels)




