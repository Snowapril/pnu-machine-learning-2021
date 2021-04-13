from abc import*


class BaseLearner(metaclass=ABCMeta):
    @abstractmethod
    def train_on_batch(self, batch_loader):
        """
        parameter tuning learning model with given training
        data set 
        """
        pass

    @abstractmethod
    def predict_on_batch(self, batch_loader):
        """
        make prediction with tuned parameter to given
        test dataset. 
        """
        pass

    @abstractmethod
    def model_summary(self):
        """
        print summary of this model
        """
        pass
