from pnuml.evaluator import summary_difference


def test_prediction_evaluator():
    prediction = [1, 0, 1, 0]
    label = [1, 1, 1, 1]
    assert summary_difference(prediction, label) == {"TP": 2, "TN": 0,
                                                     "FP": 0, "FN": 2}
