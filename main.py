from pnuml.data import DataLoader
from pnuml.learner import KNN, Regression
from pnuml.learner.utils import xavier_uniform_weight, minkowski_distance
from pnuml.learner.activation import Sigmoid
from pnuml.evaluator import summary_difference
import numpy as np
import sys
import os


def discretize_probability(val):
    """
    return 1 if given value is greater than 0.5,
    otherwise return 0
    """
    return 1. if val >= 0.5 else 0.


def build_regression(train_loader, test_loader):
    """
    Build regression learning scheme with given trainset
    and test regression model with testset
    """
    weights = xavier_uniform_weight([1, 4])
    model = Regression(weights, Sigmoid)

    model.train_on_batch(train_loader, epoch=100, lr=1e-3, lr_decay=1e-9)
    prediction = model.predict_on_batch(test_loader)
    prediction = np.vectorize(discretize_probability)(prediction)
    diff = summary_difference(prediction, test_loader.y.reshape(-1))
    print("Model Parameters: ", model.weight.reshape(-1))
    print("TP: {}\tFN: {}".format(diff["TP"], diff["FN"]))
    print("FP: {}\tTN: {}".format(diff["FP"], diff["TN"]))


def build_kNN(train_loader, test_loader):
    """
    Build k-nearest-neighbor learning scheme with given trainset
    and test k-NN model with testset
    """
    k = int(input("Enter the value for k: "))
    model = KNN(k, minkowski_distance)

    model.train_on_batch(train_loader)
    prediction = model.predict_on_batch(test_loader)
    prediction = np.vectorize(discretize_probability)(prediction)
    diff = summary_difference(prediction, test_loader.y.reshape(-1))
    print("TP: {}\tFN: {}".format(diff["TP"], diff["FN"]))
    print("FP: {}\tTN: {}".format(diff["FP"], diff["TN"]))


if __name__ == "__main__":
    print("Which learning algorithm do you want to use?")
    print(" 1. Logistic Regression")
    print(" 2. k-NN")
    algorithm_idx = int(input("Enter the number: "))

    train_path = input("Enter the filename of training data: ")
    test_path = input("Enter the filename of test data: ")

    datadir = os.path.abspath(os.path.dirname(__file__))
    train_set = np.genfromtxt(os.path.join(datadir, train_path), delimiter=',')
    test_set = np.genfromtxt(os.path.join(datadir, test_path), delimiter=',')

    train_loader = DataLoader(train_set[:, 0:3], train_set[:, 3])
    test_loader = DataLoader(test_set[:, 0:3], test_set[:, 3])

    if algorithm_idx == 1:
        build_regression(train_loader, test_loader)
    else:
        build_kNN(train_loader, test_loader)
