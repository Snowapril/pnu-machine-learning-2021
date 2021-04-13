import numpy as np


def minkowski_distance(group1, group2, p=2):
    """
    return minkowski_distance between two elements group
    """
    group1 = group1.reshape(-1)
    group2 = group2.reshape(-1)
    dist_sum = 0.
    for (x1, x2) in (zip(group1, group2)):
        abs_diff = abs(x1 - x2)
        dist_sum += abs_diff ** p
    return dist_sum ** (1./p)
