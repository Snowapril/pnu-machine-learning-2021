import numpy as np


class DataLoader:
    def __init__(self, x, y, batch_size=1):
        """
        partition given dataset x and y into groups with size=batch_size
        """
        self.batch_size = batch_size
        self.x = np.array([[x[i] for i in range(idx, idx+batch_size)]
                          for idx in range(int(len(x) / batch_size))])
        self.y = np.array([[y[i] for i in range(idx, idx+batch_size)]
                           for idx in range(int(len(y) / batch_size))])
        self.size = min(len(self.x), len(self.y))
        self.x_shape = [batch_size, x.shape[-1]]
        self.y_shape = [batch_size, y.shape[-1]]

    def __iter__(self):
        """
        initialize inteation index
        """
        self.index = 0
        return self

    def __next__(self):
        """
        return tuple of x and y batch
        """
        if self.index >= self.size:
            raise StopIteration
        x = self.x[self.index]
        y = self.y[self.index]
        self.index += 1
        return (x, y)
