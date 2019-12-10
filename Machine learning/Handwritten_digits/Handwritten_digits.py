
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
    return 1/(pow(2.718281828,-a) + 1)

def prod_point(a,b):
    c=0
    for x in range(0,len(a)):
        c += a[x]*b[x]
    return c


"""b = random_array(-1,1,N_IN_NEURONS)
pepe = Node(N_IN_NEURONS)
pepe.print()
print(pepe.calculate(b))
"""

"print(Traindata.read())"

#first_layer = first_layer.append(Node(N_IN_NEURONS))

piola = Node(N_IN_NEURONS)
labels = []
for row in Traindata:
    labels.append(row[0])
    for x in range(1,len(row)):
        piola.weights[x-1] = row[x]

    if(Traindata.line_num==1000):
        break

print("hola")


