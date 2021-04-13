from pnuml.learner.utils import minkowski_distance
import math
import numpy as np


def test_minkowski_distance():
    assert minkowski_distance(np.array([0, 0, 0]),
                              np.array([1, 1, 1]), 2) == math.sqrt(3)
