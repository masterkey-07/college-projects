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

def resume_age_in_seven_parts(dataset:pd.DataFrame):
   dataset[AGE] = dataset[AGE].astype(int)
   dataset.loc[ dataset[AGE] <= 11, AGE] = 0
   dataset.loc[(dataset[AGE] > 11) & (dataset[AGE] <= 18), AGE] = 1
   dataset.loc[(dataset[AGE] > 18) & (dataset[AGE] <= 22), AGE] = 2
   dataset.loc[(dataset[AGE] > 22) & (dataset[AGE] <= 27), AGE] = 3
   dataset.loc[(dataset[AGE] > 27) & (dataset[AGE] <= 33), AGE] = 4
   dataset.loc[(dataset[AGE] > 33) & (dataset[AGE] <= 40), AGE] = 5
   dataset.loc[(dataset[AGE] > 40) & (dataset[AGE] <= 66), AGE] = 6
   dataset.loc[ dataset[AGE] > 66, AGE] = 6
