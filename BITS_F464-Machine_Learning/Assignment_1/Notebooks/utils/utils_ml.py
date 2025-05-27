import numpy as np
import math

def generate_confusion_matrix(y_pred: np.ndarray, y_true: np.ndarray):
    true_positives = 0 # pred is 1 and should be 1
    true_negatives = 0 # pred is 0 and should be 0
    false_positives = 0 # pred is 1 but it should be 0
    false_negatives = 0 # pred is 0 but it should be 1
    
    if y_pred.shape != y_true.shape:
        raise Exception("Shape not same")
    
    # I am assuming both are 1 x n for our case
    for index, predicted_value in enumerate(y_pred):
        actual_value = y_true[index]
        
        if predicted_value == 1 and actual_value == 1:
            true_positives += 1
        
        if predicted_value <= 0 and actual_value <= 0:
            true_negatives += 1
        
        if predicted_value == 1 and actual_value <= 0:
            false_positives += 1
            
        if predicted_value <= 0 and actual_value == 1:
            false_negatives += 1
    
    # print(f"{true_positives=}, {true_negatives=}, {false_positives=}, {false_negatives=}")
    if true_positives + true_negatives + false_positives + false_negatives == 0:
        accuracy = math.nan
    else:
        accuracy = (true_positives + true_negatives) / (true_positives + true_negatives + false_positives + false_negatives)
    
    if true_positives + false_positives == 0:
        precision = math.nan
    else:
        precision = (true_positives) / (true_positives + false_positives)
        
    if true_positives + false_negatives == 0:
        recall = math.nan
    else:
        recall = (true_positives) / (true_positives + false_negatives)
        
    if precision + recall == 0:
        f1_score = math.nan
    else:
        f1_score = (2 * precision * recall) / (precision + recall)
    
    return (accuracy, precision, recall, f1_score)