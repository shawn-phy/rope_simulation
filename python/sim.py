import ropesim
from matplotlib import pyplot as plt
import matplotlib.animation as animation

rope = ropesim.rope(0, 10, 0,0, 100)

fig, ax = plt.subplots()
line = ax.plot([], [], 'o-')

def init():
    ax.set_xlim(0, 10)
    ax.set_ylim(-5, 5)
    return line

def update(frame):
    rope.step()
    xdata = [p.x for p in rope._particles]
    ydata = [p.y for p in rope._particles]
    line.set_data(xdata, ydata)
    return line 

ani = animation.FuncAnimation(fig, update,frames=range(1000), init_func=init, interval=10, blit=True)
plt.show()

