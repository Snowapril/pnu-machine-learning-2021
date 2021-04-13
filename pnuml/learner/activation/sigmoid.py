from .base_activation import BaseActivation
import numpy as np


class Sigmoid(BaseActivation):
    @staticmethod
    def forward(value):
        """
        return forward calculation of Sigmoid
        """
        return 1. / (1. + np.exp(-value))

    @staticmethod
    def backward(value):
        """
        return derivative calculation of Sigmoid
        """
        forward_value = Sigmoid.forward(value)
        return forward_value * (1. - forward_value)
