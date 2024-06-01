from constant import DATA_FILE, NAME, CABIN, FARE, AGE, PASSENGER_ID, TICKET
from sklearn.metrics import mean_absolute_percentage_error, mean_squared_error, mean_absolute_error
from sklearn.preprocessing import StandardScaler
from sklearn.neural_network import MLPRegressor
from sklearn.svm import SVC
from sklearn.model_selection import KFold
from sklearn import linear_model
from sklearn.tree import DecisionTreeRegressor
import pandas as pd
import numpy as np

class ModelTrainer:
    def __init__(self, x_train, y_train, x_test, y_test):
        self.x_train = x_train
        self.y_train = y_train
        self.x_test = x_test
        self.y_test = y_test
        
        self.scaler = StandardScaler()
        
        self._scaled_x_train = self.scaler.fit_transform(x_train) 
        self._scaled_x_test = self.scaler.transform(x_test) 

    
    def train_and_measure(self, model):
        model.fit(self.x_train, self.y_train)
    
        y_received = model.predict(self.x_test)

        mse = mean_squared_error(self.y_test, y_received)
        mae = mean_absolute_error(self.y_test, y_received)
        mape = mean_absolute_percentage_error(self.y_test, y_received)

        return mse, mae, mape

    def train_and_measure_svm(self, model):
        model.fit(self._scaled_x_train, self.y_train)
    
        y_received = model.predict(self._scaled_x_test)

        mse = mean_squared_error(self.y_test, y_received)
        mae = mean_absolute_error(self.y_test, y_received)
        mape = mean_absolute_percentage_error(self.y_test, y_received)

        return mse, mae, mape


full_data = pd.read_csv(DATA_FILE)

full_data = full_data.drop(axis=1, columns=[PASSENGER_ID, NAME, TICKET, CABIN, FARE])

five_kfold = KFold(n_splits=5, random_state=0, shuffle=True)

tree_results = []
lasso_results = []

for index, (train_index, test_index) in enumerate(five_kfold.split(full_data)):
    tree_model = DecisionTreeRegressor(random_state=0)
    mlp_model = MLPRegressor(random_state=0, hidden_layer_sizes=(50,50,50,50), batch_size=80, )    
    lasso_model = linear_model.Lasso(alpha=0.1)
    svm_model = SVC(C=10e6, kernel='rbf') 
    
    y_train = full_data.values[train_index][:,3]
    x_train = full_data.values[train_index]
    x_train = np.delete(x_train, 3, 1)

    y_test = full_data.values[test_index][:,3]
    x_test = full_data.values[test_index]
    x_test = np.delete(x_test, 3, 1)
    
    trainer = ModelTrainer(x_test=x_test, x_train=x_train, y_test=y_test, y_train=y_train)
    
    mlp_mse, mlp_mae, mlp_mape = trainer.train_and_measure(model=mlp_model)
    tree_mse, tree_mae, tree_mape = trainer.train_and_measure(model=tree_model)
    lasso_mse, lasso_mae, lasso_mape = trainer.train_and_measure(model=lasso_model)
    svm_mse, svm_mae, svm_mape = trainer.train_and_measure_svm(model=svm_model)
    
    print('K-FOLD', index)
    print('lasso',lasso_mse,lasso_mae,lasso_mape)
    print('tree',tree_mse,tree_mae,tree_mape)
    print('mlp',mlp_mse,mlp_mae,mlp_mape)
    print('svm',svm_mse,svm_mae,svm_mape)
    print('')