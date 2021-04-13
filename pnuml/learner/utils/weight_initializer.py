import numpy as np


def xavier_uniform_weight(shape, seed=0):
    """
    initialize weight matrix with xavier_uniform_initializer.
    matrix size will be shape arguments
    """
    np.random.seed(seed)
    scale = 1 / max(1., np.sum(shape) / 2.)
    limit = np.sqrt(scale * 3.)
    return np.random.uniform(-limit, limit, size=shape)


def zero_weight(shape):
    """
    return zero matrix with size=shape
    """
    return np.zeros(shape=shape)
