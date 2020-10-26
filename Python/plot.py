import sys
import matplotlib.pyplot as pyplot

class axis:
    def __init__(self, lst = []):
        self.data = lst
        self.size = 0

v = int(sys.stdin.readline())

if (v == 1):
    y = axis()
    y.size = int(sys.stdin.readline())
    for i in range(y.size):
        y.data.append(float(sys.stdin.readline()))
    
    plt.plot(y.data)
    plt.show()
elif (v == 2):
    x = axis()
    y = axis()
    x.size = int(sys.stdin.readline())
    for i in range(x.size):
        x.data.append(float(sys.stdin.readline()))
    
    y.size = int(sys.stdin.readline())
    for i in range(y.size):
        y.data.append(float(sys.stdin.readline()))
    
    plt.plot(x.data, y.data)
