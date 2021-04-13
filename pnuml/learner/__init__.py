from .kNN import KNN
from .regression import Regression

# if somebody does "from somepackage import *", this is what they will
# be able to access:
__all__ = [
    'KNN',
    'Regression',
]
