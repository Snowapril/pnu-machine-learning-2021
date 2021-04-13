import numpy as np
import matplotlib.pyplot as plt


def summary_difference(prediction, label):
    """
    This summary only works in two-case classes prediction.
    Summarize difference in prediction and label set into
    dictionary with counts FP, FN, TP and TN
    and return it.
    """
    diff = {"TN": 0, "FN": 0, "FP": 0, "TP": 0}
    diff_label = ["TN", "FN", "FP", "TP"]

    for (y_hat, y) in zip(prediction, label):
        idx = int(y_hat) * 2 + int(y)
        diff[diff_label[idx]] += 1

    return diff
