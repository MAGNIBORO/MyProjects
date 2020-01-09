
import numpy as np
import pandas as pd
from sklearn import datasets
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LogisticRegression
from sklearn.preprocessing import StandardScaler

iris = datasets.load_iris()
X = iris.data[:, [0,1,2, 3]]
y = iris.target


X_train,X_test,y_train,y_test = train_test_split(X,y,test_size=0.2,random_state=1,stratify=y)
std = StandardScaler()
std.fit(X_train)
X_train = std.transform(X_train)
X_test = std.transform(X_test)


ib = LogisticRegression(multi_class="ovr",random_state=1)
ia = LogisticRegression(multi_class="multinomial",random_state=1)

ib.fit(X_train,y_train)
ia.fit(X_train,y_train)


print(ib.score(X_test,y_test))
print(ia.score(X_test,y_test))