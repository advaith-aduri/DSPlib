import sys
import matplotlib.pyplot as plt

class axis:
    def __init__(self, lst = []):
        self.data = lst.copy()
        self.size = 0

def plot_xy():
    """
    Data piping order:
    1 - x size
    2 - x data
    3 - y size
    4 - y data
    5 - xlabel
    6 - ylabel
    7 - title
    """
    x = axis()
    y = axis()
    x.size = int(sys.stdin.readline())
    for i in range(x.size):
        x.data.append(float(sys.stdin.readline()))

    y.size = int(sys.stdin.readline())
    for i in range(y.size):
        y.data.append(float(sys.stdin.readline()))
        
    xlabel = sys.stdin.readline()
    ylabel = sys.stdin.readline()
    title = sys.stdin.readline()

    plt.plot(x.data, y.data)
    plt.xlabel(xlabel)
    plt.ylabel(ylabel)
    plt.title(title)
    plt.show()

plot_xy()
