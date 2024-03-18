import graphviz
import pandas as pd
import constant as c
from matplotlib import pyplot as plt
from preprocessing import data_preprocessing
from tree_making import train_decision_tree
from age_setter import map_age_with_normalization, resume_age_in_seven_parts
from sklearn.tree import DecisionTreeClassifier
from sklearn import tree

RUN_DATA_PROCESSING = False


MAX_DEPTHS = list(range(1,20))

SPLITTERS = ['best', 'random']

CRITERIONS = ['entropy', 'gini']

MIN_SAMPLES_SPLITS = list(range(2,20))

REMOVE_GROUPS = [[], [c.SIB_SP], [c.AGE], [c.AGE, c.SIB_SP]]

if __name__ == '__main__':
    decision_tree_classifier = DecisionTreeClassifier(random_state=0,  max_depth=1)

    first_accuracy, second_accuracy,attributes = train_decision_tree(to_remove=[], decision_tree_classifier=decision_tree_classifier)

    dot_data = tree.export_graphviz(decision_tree_classifier,
                                    feature_names=attributes,
                                    class_names=['0','1'],
                                    filled=True)
    graph = graphviz.Source(dot_data, format="png")

    graph.render(filename='out')

    if RUN_DATA_PROCESSING:
        data_preprocessing(resume_age=resume_age_in_seven_parts, map_age=map_age_with_normalization, map_age_together=True)

    cases = []

    for max_depth in MAX_DEPTHS:
        for splitter in SPLITTERS:
            for criterion in CRITERIONS:
                for min_sample_split in MIN_SAMPLES_SPLITS:
                    for to_remove in REMOVE_GROUPS:
                        decision_tree_classifier = DecisionTreeClassifier(random_state=0, splitter=splitter ,criterion=criterion, max_depth=max_depth, min_samples_split=min_sample_split)
                        
                        first_accuracy, second_accuracy = train_decision_tree(to_remove=to_remove, decision_tree_classifier=decision_tree_classifier)
                        
                        cases.append((second_accuracy, max_depth, splitter, criterion, min_sample_split, to_remove))


    cases.sort(key=lambda values:values[0], reverse=True)
    
    for test_case in cases:
        weight = test_case[0]
        
        if weight > 0.9:
            print(*test_case)