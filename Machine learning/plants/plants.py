
import numpy as np
import pandas as pd

def sigmoid(a):
  return (1)/(pow(2.7182818,(-1)*(a))+1)

class Perceptron(object):
    """Perceptron classifier.

    Parameters
    ------------
    lr : float
      Learning rate (between 0.0 and 1.0)
    n_iter : int
      Passes over the training dataset.
    random_state : int
      Random number generator seed for random weight
      initialization.

    Attributes
    -----------
    w_ : 1d-array
      Weights after fitting.
    errors_ : list
      Number of misclassifications (updates) in each epoch.

    """
    def __init__(self,n_input ,lr=0.01, n_iter=50,random_state=1):
        rg = np.random.RandomState(1)
        self.lr = lr
        self.n_iter = n_iter
        self.random_state = random_state
        self.w_ = rg.normal(loc=0,scale=0.01 ,size=n_input +1)

    def fit(self, feat, ans):
      for _ in range(self.n_iter):
        for row in range(len(feat)):

          update = (ans[row]-self.predict(feat[row,:])) * self.lr
          self.w_[0] += update
          for n in range(len(self.w_)-1):
            self.w_[n+1] += update * feat[row,n]
      print (self.w_)
      
        

    def net_input(self, feat):
        """Calculate net input"""
        return np.dot(feat, self.w_[1:]) + self.w_[0]

    def predict(self, feat):
        """Return class label after unit step"""
        return sigmoid(self.net_input(feat))



data = pd.read_csv('https://archive.ics.uci.edu/ml/''machine-learning-databases/iris/iris.data', header=None)


labels = data.iloc[:100, 4].values
feat = data.iloc[:100,[0,2]].values
labels = np.where(labels == "Iris-setosa",1,0)


a = Perceptron(2,n_iter=100)
a.fit(feat,labels)

print(a.predict(feat[0]))
print(a.predict(feat[20]))
print(a.predict(feat[55]))
print(a.predict(feat[77]))