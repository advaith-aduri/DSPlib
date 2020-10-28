import sys
import matplotlib.pyplot as plt

class axis:
    def __init__(self, lst = []):
        self.data = lst.copy()
        self.size = 0


def plot_ny():
    size = int(sys.stdin.readline())
    for i in range(size):
        x = axis()
        x.size = int(sys.stdin.readline())
        for j in range(x.size):
            x.data.append(float(sys.stdin.readline()))
        plt.plot(x.data)
    
    xlabel = sys.stdin.readline()
    ylabel = sys.stdin.readline()
    title = sys.stdin.readline()

    plt.xlabel(xlabel)
    plt.ylabel(ylabel)
    plt.title(title)
    plt.autoscale()
    plt.show()


plot_ny()
