from constant import AGE
import pandas as pd
import numpy as np

def map_age_with_normalization(dataset:pd.DataFrame):
    mean = dataset[AGE].mean()
    std = dataset[AGE].std()
    list_isna = dataset[AGE].isna()

    for line in range(list_isna.shape[0]):
        if (list_isna[line] == True):
            rand_age = np.random.randint(mean - std, mean + std, 1)
            dataset.at[line,AGE] = rand_age
