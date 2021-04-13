from abc import *


class BaseActivation(metaclass=ABCMeta):
    @staticmethod
    @abstractmethod
    def forward(value):
        pass

    @staticmethod
    @abstractmethod
    def backward(value):
        pass
