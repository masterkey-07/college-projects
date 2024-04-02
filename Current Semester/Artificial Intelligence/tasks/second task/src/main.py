from constant import DATA_FILE, NAME, CABIN, FARE, AGE, PASSENGER_ID, TICKET
from sklearn.metrics import mean_absolute_percentage_error, mean_squared_error, mean_absolute_error
from sklearn.model_selection import KFold
from sklearn import linear_model
from sklearn.tree import DecisionTreeRegressor
import pandas as pd
import numpy as np

full_data = pd.read_csv(DATA_FILE)

full_data = full_data.drop(axis=1, columns=[PASSENGER_ID, NAME, TICKET, CABIN, FARE])

five_kfold = KFold(n_splits=5, random_state=0, shuffle=True)


tree_results = []
lasso_results = []

for _, (train_index, test_index) in enumerate(five_kfold.split(full_data)):
    decision_tree = DecisionTreeRegressor(random_state=0)
    lasso_model = linear_model.Lasso(alpha=0.1)
    
    Y_train = full_data.values[train_index][:,3]
    X_train = full_data.values[train_index]
    X_train = np.delete(X_train, 3, 1)

    Y_test = full_data.values[test_index][:,3]
    X_test = full_data.values[test_index]
    X_test = np.delete(X_test, 3, 1)
    
    lasso_model.fit(X_train, Y_train)
    decision_tree.fit(X_train, Y_train)
    
    lasso_y_received = lasso_model.predict(X_test)

    lasso_mse = mean_squared_error(Y_test, lasso_y_received)
    lasso_mae = mean_absolute_error(Y_test, lasso_y_received)
    lasso_mape = mean_absolute_percentage_error(Y_test, lasso_y_received)
    
    tree_results.append((lasso_mse, lasso_mae, lasso_mape))
    
    tree_y_received = decision_tree.predict(X_test)

    tree_mse = mean_squared_error(Y_test, tree_y_received)
    tree_mae = mean_absolute_error(Y_test, tree_y_received)
    tree_mape = mean_absolute_percentage_error(Y_test, tree_y_received)
    
    tree_results.append((tree_mse, tree_mae, tree_mape))