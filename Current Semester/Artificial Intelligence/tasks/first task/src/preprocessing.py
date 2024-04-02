import pandas as pd
from constant import NEW_TEST_FILE, NEW_TRAIN_FILE, AGE, EMBARKED, FARE, SEX, IS_TEST_COLUMN, PORTS, GENDERS, ZERO_FARE, COMMON_VALUE, TRAIN_FILE, TEST_FILE, RESULT_FILE, PASSENGER_ID, NAME

def extract_raw_data():
    data_train = pd.read_csv(TRAIN_FILE)
    data_test = pd.read_csv(TEST_FILE)
    data_result = pd.read_csv(RESULT_FILE)

    data_test = data_test.merge(data_result, on=PASSENGER_ID)

    data_train[IS_TEST_COLUMN] = False    
    data_test[IS_TEST_COLUMN] = True    

    return pd.concat([data_train, data_test], ignore_index=True)

def set_common_embarked(dataset:pd.DataFrame):
    dataset[EMBARKED] = dataset[EMBARKED].fillna(COMMON_VALUE)


def set_common_fare(dataset:pd.DataFrame):
    dataset[FARE] = dataset[FARE].fillna(ZERO_FARE)
    dataset[FARE] = dataset[FARE].astype(int)
    
def map_gender(dataset:pd.DataFrame):
    dataset[SEX] = dataset[SEX].map(GENDERS)
    
def map_ports(dataset:pd.DataFrame):
    dataset[EMBARKED] = dataset[EMBARKED].map(PORTS)

def set_age_as_int(dataset:pd.DataFrame):
    dataset[AGE] = dataset[AGE].astype(int)

def data_preprocessing(resume_age, map_age, map_age_together:bool = True, change_data:bool = False, mix_by:str = NAME):
    def prepare_age(data:pd.DataFrame):
        map_age(data)
        set_age_as_int(data)

        if resume_age:
            resume_age(data)
    
    raw_data = extract_raw_data()
    
    set_common_embarked(raw_data)
    set_common_fare(raw_data)
    map_gender(raw_data)
    map_ports(raw_data)
    
    if map_age_together:
        prepare_age(raw_data)
    
    new_data_test:pd.DataFrame = None
    new_data_train:pd.DataFrame = None
    
    if change_data:
        sorted_data = raw_data.sort_values(by=mix_by)
        
        new_data_train = sorted_data[:891]
        new_data_test = sorted_data[891:]
    else:
        new_data_test = raw_data[raw_data[IS_TEST_COLUMN] == True].reset_index()
        new_data_train = raw_data[raw_data[IS_TEST_COLUMN] == False].reset_index()
    
    if not map_age_together:
         prepare_age(new_data_test)
         prepare_age(new_data_train)
    
    new_data_train.to_csv(NEW_TRAIN_FILE, index=False)
    new_data_test.to_csv(NEW_TEST_FILE, index=False)