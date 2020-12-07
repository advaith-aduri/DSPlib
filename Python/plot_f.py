import sys
import matplotlib.pyplot as plt
from math import floor
from os import fork


class axis:
    def __init__(self, lst = []):
        self.data = lst.copy()
        self.size = 0

def plot_f():
    """
    Data piping order:
    1 - Sampling Frequency
    2 - size
    3 - data(magnitude)
    4 - data(angle)
    """
    Fs = float(sys.stdin.readline())
    mag = axis()
    ang = axis()
    mag.size = int(sys.stdin.readline())
    ang.size = mag.size

    for i in range(mag.size):
        mag.data.append(float(sys.stdin.readline()))
    
    for i in range(ang.size):
        ang.data.append(float(sys.stdin.readline()))
    

    mag.data = mag.data[0:floor(mag.size/2)]
    ang.data = ang.data[0:floor(ang.size/2)]
    f = [i * (Fs/mag.size) for i in range(floor(mag.size/2))]
    
    fig,ax = plt.subplots(2)
    ax[0].plot(f,mag.data)
    ax[0].set_title("Magnitude")
    ax[0].set_xlabel("Frequency")
    ax[0].set_ylabel("Amplitude")
    ax[1].plot(f,ang.data)
    ax[1].set_title("Phase Angle")
    ax[1].set_xlabel("Frequency")
    ax[1].set_ylabel("Amplitude")
    plt.tight_layout()
    plt.show()

n = fork()
if n == 0:
    plot_f()
