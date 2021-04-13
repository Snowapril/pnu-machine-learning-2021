from .base_activation import BaseActivation
import numpy as np


class TanH(BaseActivation):
    @staticmethod
    def forward(value):
        """
        return forward calculation of TanH
        """
        return np.tanh(value)

    @staticmethod
    def backward(value):
        """
        return derivative calculation of TanH
        """
        tanh_forward = TanH.forward()
        return 1. - tanh_forward * tanh_forward
