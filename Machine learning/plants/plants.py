
import numpy as np
import pandas as pd

def sigmoid(a):
  return (1)/(pow(2.7182818,(-1)*(a))+1)

class Cell(object):
    def __init__(self,n_input ,lr=0.01, n_iter=50,random_state=1):
        rg = np.random.RandomState(1)
        self.lr = lr
        self.n_iter = n_iter
        self.random_state = random_state
        self.w_ = rg.normal(loc=0,scale=0.01 ,size=n_input +1)

    def fit(self, feat, ans):
      for _ in range(self.n_iter):
        for row in range(len(feat)):

          update = pow(ans[row]-self.predict(feat[row,:]),2) * self.lr/2
          self.w_[0] += update
          for n in range(len(self.w_)-1):
            self.w_[n+1] += 2*update * feat[row,n]
      print (self.w_)
      
        

    def net_input(self, feat):
        """Calculate net input"""
        return np.dot(feat, self.w_[1:]) + self.w_[0]

    def predict(self, feat):
        """Return class label after unit step"""
        return sigmoid(self.net_input(feat))



data = pd.read_csv('https://archive.ics.uci.edu/ml/''machine-learning-databases/iris/iris.data', header=None)
data = data.sample(frac=1)
labels = data.iloc[:, 4].values
feat = data.iloc[:,:4].values



#labels2 = np.where(labels == "Iris-versicolor",1,0)
labels1 = np.where(labels == "Iris-setosa",1,0)
#labels3 = np.where(labels == "Iris-virginica",1,0)


a = Perceptron(4,n_iter=100)
a.fit(feat,labels1)


print(a.predict(feat[133]))
print(a.predict(feat[77]))
print(a.predict(feat[12]))