from .base_activation import BaseActivation
import numpy as np


class ReLU(BaseActivation):
    @staticmethod
    def __single_forward(v):
        """
        return v if is greater than 0,
        otherwise return 0
        """
        return v if v >= 0. else 0.

    @staticmethod
    def __single_backward(v):
        """
        return 1 if is greater than 0,
        otherwise return 0
        """
        return 1 if v >= 0. else 0.

    @staticmethod
    def forward(value):
        """
        return forward calculation of ReLU
        """
        return np.vectorize(ReLU.__single_forward)(value)

    @staticmethod
    def backward(value):
        """
        return derivative calculation of ReLU
        """
        return np.vectorize(ReLU.__single_backward)(value)
