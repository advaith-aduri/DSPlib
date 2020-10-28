import sys
import matplotlib.pyplot as plt

class axis:
    def __init__(self, lst = []):
        self.data = lst.copy()
        self.size = 0
        
def plot_y():
    """
    Data piping order:
    1 - size
    2 - data
    3 - xlabel
    4 - ylabel
    5 - title
    """
    y = axis()
    y.size = int(sys.stdin.readline())
    for i in range(y.size):
        y.data.append(float(sys.stdin.readline()))
    
    xlabel = sys.stdin.readline()
    ylabel = sys.stdin.readline()
    title = sys.stdin.readline()

    plt.plot(y.data)
    plt.xlabel(xlabel)
    plt.ylabel(ylabel)
    plt.title(title)
    plt.show()


plot_y()
