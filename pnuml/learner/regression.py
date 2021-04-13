from pnuml.learner.base_learner import BaseLearner
import numpy as np
import pprint


class Regression(BaseLearner):
    def __init__(self, weight, activation, **kwargs):
        """
        configure regression model
        param weight : weight **w** of the model
        param activation : can be ReLU or Sigmoid or TanH
        """
        super().__init__()
        self.weight = weight
        self.activation = activation

    def train_on_batch(self, batch_loader, epoch, lr=1e-2, lr_decay=1e-9):
        """
        train weight parameter of the model with given dataset generator.
        learing rate can be decayed with given lr_decay arguments.
        whole training process iterated with count epoch.
        """
        if self.weight.shape[-1] != batch_loader.x_shape[-1] + 1:
            raise ValueError("weight and input x shape + pad(1) must matched\n"
                             "Weight shape {}, input x shape {}".format(
                                self.weight.shape, batch_loader.x_shape))
        loss = []
        for _ in range(epoch):
            for (x, y) in batch_loader:
                x = np.pad(x, ((0, 0), (1, 0)), 'constant', constant_values=1)
                g = np.matmul(self.weight, x.T)
                h_w = self.activation.forward(g)
                loss.append(np.sum(y * np.log(h_w) +
                                   (1. - y) * np.log(1. - h_w)))
                self.weight = self.weight + lr * (y - h_w) * x
                lr -= lr * lr_decay
        return loss

    def predict_on_batch(self, batch_loader):
        """
        make prediction with trained weight value to the given
        test dataset generator.
        return prediction probabilities.
        """
        prediction = []
        for (x, y) in batch_loader:
            x = np.pad(x, ((0, 0), (1, 0)), 'constant', constant_values=1)
            g = np.matmul(self.weight, x.T)
            h_w = self.activation.forward(g)
            prediction.append(h_w)

        return np.array(prediction).reshape(-1)

    def model_summary(self):
        """
        print summary of this model
        """
        pprint.pprint("weight : {}".format(self.weight))
        pprint.pprint("activation : {}".format(self.activation))
