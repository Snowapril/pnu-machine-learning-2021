import matplotlib.pyplot as plt
import numpy as np


def visualize_loss(loss, save_path=None):
    """
    visualize loss up & down with matpoltlib
    """
    x = np.arange(len(loss))
    plt.plot(x, loss)
    plt.show()
