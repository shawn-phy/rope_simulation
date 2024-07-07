import ropesim
from matplotlib import pyplot as plt
import matplotlib.animation as animation


rope = ropesim.rope(5, 1, 10, 0, 1000)

ropesim.gravity = 99.81
ropesim.dt = 0.1
ropesim.max_iterations = 100


fig, ax = plt.subplots(figsize=(20, 10))
line, = ax.plot([], [], 'o-', markersize=4)

# Set up text for displaying simulation parameters
text = ax.text(0.02, 0.95, '', transform=ax.transAxes)

def init():
    ax.set_xlim(-10, 20)
    ax.set_ylim(-20, 20) 
    ax.set_xlabel('X pos')
    ax.set_ylabel('Y pos')
    ax.set_title('Rope Simulation visualization')
    return line, text

def update(frame):
    rope.step()
    xdata = [p.x for p in rope._particles]
    ydata = [p.y for p in rope._particles]
    line.set_data(xdata, ydata)
    
    # Update text with simulation parameters
    info_text = f'Gravity: {ropesim.gravity:.2f}\ndt: {ropesim.dt:.4f}\nIterations: {ropesim.max_iterations}'
    text.set_text(info_text)
    
    return line, text

ani = animation.FuncAnimation(fig, update, frames=range(1000), init_func=init, interval=50, blit=True)
plt.show()