from pnuml.learner.base_learner import BaseLearner
import numpy as np
import pprint


class KNN(BaseLearner):
    def __init__(self, k, distance_metric, **kwargs):
        """
        configure k-nearest-neighbor model
        param distance_metric : function that returns distance between
                                two elements set
        """
        super().__init__()
        self.x = np.array([])
        self.y = np.array([])
        self.K = k
        self.distance_metric = distance_metric

    def train_on_batch(self, batch_loader):
        """
        just memorize training set
        """
        self.x = np.array(batch_loader.x)
        self.y = np.array(batch_loader.y)

    def predict_on_batch(self, batch_loader):
        """
        query the k nearest-neighbors with given dataset.
        make prediction it's average value of queried values
        """
        prediction = []
        for (x, y) in batch_loader:
            dist_arr = np.array([self.distance_metric(_x, x) for _x in self.x])
            idx = np.argpartition(dist_arr, self.K - 1)[:self.K]
            knn_label = self.y[idx].reshape(-1)
            prediction.append(np.sum(knn_label) / self.K)
        return prediction

    def model_summary(self):
        """
        print summary of this model
        """
        pprint.pprint("K : {}".format(self.K))
        pprint.pprint("distance metric : {}".format(
                      self.distance_metric.__name__))
