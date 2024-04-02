import pandas as pd
from constant import DATA_FILE, AGE, EMBARKED, FARE, SEX, PORTS, GENDERS, ZERO_FARE, COMMON_VALUE, TRAIN_FILE, TEST_FILE, GENDER_FILE, PASSENGER_ID, NAME
from age_setter import map_age_with_normalization

def extract_raw_data():
    data_train = pd.read_csv(TRAIN_FILE)
    data_test = pd.read_csv(TEST_FILE)
    data_result = pd.read_csv(GENDER_FILE)

    data_test = data_test.merge(data_result, on=PASSENGER_ID)

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

def data_preprocessing(map_age):
    def prepare_age(data:pd.DataFrame):
        map_age(data)
        set_age_as_int(data)

    raw_data = extract_raw_data()
    
    set_common_embarked(raw_data)
    set_common_fare(raw_data)
    map_gender(raw_data)
    map_ports(raw_data)
    
    prepare_age(raw_data)
        
    raw_data.to_csv(DATA_FILE, index=False)
    
    
if __name__ == '__main__':
    data_preprocessing(map_age=map_age_with_normalization)