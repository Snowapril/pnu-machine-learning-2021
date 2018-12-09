from .version import __version__
from .module1 import shout_and_repeat
from .module2 import my_add

# if somebody does "from somepackage import *", this is what they will
# be able to access:
__all__ = [
    'shout_and_repeat',
    'my_add',
]
