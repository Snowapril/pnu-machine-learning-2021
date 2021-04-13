from pnuml.data import DataLoader
import numpy as np


def test_prediction_evaluator():
    x = np.array([[1, 2], [3, 4], [5, 6], [7, 8]])
    y = np.array([[1], [2], [3], [4]])
    data_loader = DataLoader(x, y, batch_size=2)
    assert data_loader.x_shape == [2, 2]
    assert data_loader.y_shape == [2, 1]
