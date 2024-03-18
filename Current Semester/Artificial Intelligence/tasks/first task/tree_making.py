from sklearn.metrics import accuracy_score
from sklearn.tree import DecisionTreeClassifier
from sklearn.metrics import balanced_accuracy_score
import pandas as pd
from constant import NEW_TEST_FILE, NEW_TRAIN_FILE, RESULT_FILE, SURVIVED, PASSENGER_ID, NAME, TICKET, IS_TEST_COLUMN, CABIN

DEFAULT_REMOVE_COLUMNS = [PASSENGER_ID, NAME, TICKET, IS_TEST_COLUMN, CABIN]

def train_decision_tree(decision_tree_classifier:DecisionTreeClassifier, to_remove=list[str] ):
    data_train = pd.read_csv(NEW_TRAIN_FILE)
    data_test = pd.read_csv(NEW_TEST_FILE)
    data_result = pd.read_csv(RESULT_FILE)

    to_remove_columns = [SURVIVED,*DEFAULT_REMOVE_COLUMNS, *to_remove]

    filtered_data_train = data_train.drop(to_remove_columns, axis=1)

    input_data = filtered_data_train.values

    output_data = data_train[SURVIVED].values

    decision_tree_classifier.fit(input_data, output_data)
    
    input_test_data = data_test.drop(to_remove_columns, axis=1).values
    
    predicted_output_data = decision_tree_classifier.predict(input_test_data)
    
    expected_output_data = data_result[SURVIVED].values

    accuracy_score_result = accuracy_score(expected_output_data, predicted_output_data)
    
    balanced_accuracy_score_result = balanced_accuracy_score(expected_output_data, predicted_output_data)
    
    return accuracy_score_result, balanced_accuracy_score_result, filtered_data_train.columns.values.tolist()
