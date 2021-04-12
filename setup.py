from setuptools import setup
import os
import sys

_here = os.path.abspath(os.path.dirname(__file__))

if sys.version_info[0] < 3:
    with open(os.path.join(_here, 'README.md')) as f:
        long_description = f.read()
else:
    with open(os.path.join(_here, 'README.md'), encoding='utf-8') as f:
        long_description = f.read()

version = {}
with open(os.path.join(_here, 'pnuml', 'version.py')) as f:
    exec(f.read(), version)

setup(
    name='pnuml',
    version=version['__version__'],
    description=('Implementation of several machine learning algorithms,'
                 ' such as logistic-regression, k-Nearest-Neighbor, etc.'),
    long_description=long_description,
    author='Jihong Shin',
    author_email='sinjihng@gmail.com',
    url='https://github.com/snowapril/pnu-machine-learning-2021',
    license='MIT',
    packages=['pnuml'],
    install_requires=[]
    include_package_data=True,
    classifiers=['Programming Language :: Python :: 3.8'],
    )
