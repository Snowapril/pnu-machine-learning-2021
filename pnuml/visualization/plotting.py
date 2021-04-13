import matplotlib.pyplot as plt
import numpy as np


def visualize_loss(loss, save_path=None):
    """
    visualize loss up & down with matpoltlib
    """
    x = np.arange(len(loss))
    plt.plot(x, loss)
    plt.show()


def roc_curve(tp, fp, save_path=None):
    """
    visualize ROC Curve with given True positive
    and False positives
    """
    plt.grid()
    plt.axis()
    plt.plot(fp, tp, color='black')
    plt.show()
