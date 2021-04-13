from pnuml.learner.activation import ReLU, TanH, Sigmoid


def test_sigmoid():
    assert Sigmoid.forward(0) == 0.5


def test_relu():
    assert ReLU.forward(5) == 5
    assert ReLU.forward(-5) == 0
    assert ReLU.backward(5) == 1
    assert ReLU.backward(-5) == 0


def test_tanh():
    assert TanH.forward(0.) == 0.
