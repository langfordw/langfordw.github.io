### Desktop Wire-EDM

<div class="image-row"><img src="content/dwedm2_01.jpeg" style="max-width:80%"></div>

The two main thrusts of my renewed work on this project are the power electronics (pulse generator), and controls:

### [Past Work](https://langfordw.pages.cba.mit.edu/desktopWEDM/pastWork/)

### Recent Work:

### [Electronics](https://langfordw.pages.cba.mit.edu/desktopWEDM/electronics/)

### [Firmware](https://langfordw.pages.cba.mit.edu/desktopWEDM/firmware//)

### Controls

To control the Wire-EDM, we can't just simply use a standard g-code interpretter and machine controller since the motion of the axes needs to depend on how quickly/slowly the material is being eroded.

So, I plan to piggy-back off of some of [Jake](https://gitlab.cba.mit.edu/jakeread/mkstepper) and [Sam](https://gitlab.cba.mit.edu/calischs/step)'s recent stepper motor boards to implement the path planning and control.

This will involve things like the [Bresenham line algorithm](https://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm) to discretize non-rectilinear motions and map into movements of the individual motors. Fortunately, I suspect I won't have to worry too much about acceleration/jerk control given that this machining process is relatively slow. 

We can tell how much material has eroded and how large the gap between the wire and workpiece is by sampling the voltage across the spark capacitor. In the limit where the gap is large and there's no spark, this voltage will be the same as the voltage determined by the charge control circuitry. At the other limit, where the wire actually touches the workpiece, there is a short circuit and there's no voltage across the capacitor.

What I'm not sure about is exactly how fast I want to be able to step to react to changing gap voltages. Many circuits I've seen elsewhere use op-amps configured as a window comparator to servo the stepper motors based on the gap voltage. I will probably start by trying to implement this in firmware with something like an NRF52. With this microcontroller, I can use things like the PPI system to have events triggered automatically without bogging down the main-code.
