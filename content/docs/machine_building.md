### Machine Building

<div class="image-row">
    <a href="#edm" style="flex:1.5"><img src="content/dwedm2_01.jpeg" ></a>
    <a href="#instron" style="flex:1.33"><img src="content/tabletopinstron/images/instron_far.jpg" ></a>
    <a href="#punchpress" style="flex:1.26"><img src="content/machine_building/automated_punch_press.png" ></a>
</div>

<hr>

#### <a id="edm">Desktop Wire-EDM</a>

I built a desktop-scale Wire-EDM as a class project for [How To Make Soomething That Makes Almost Anythin](https://fab.cba.mit.edu/classes/865.15/index.html).

While at MIT, I was fortunate enough to have completely unrestricted to a [top-of-the-line Wire-EDM](http://cba.mit.edu/tools/index.html). It became a big part of my workflow for making parts and how I thought about making things. This inspired me to see if it might be possible to replicate the functionality in a desktop form-factor.

<div class="image-row"><img src="content/dwedm2_01.jpeg"></div>

I worked on this machine in two major spurts. In the first spurt, I largely focused on the mechanical design of the machine.

##### [Past Work](https://langfordw.pages.cba.mit.edu/desktopWEDM/pastWork/)

The second thrust focused on the power electronics (pulse generator), and controls:

##### [Electronics](https://langfordw.pages.cba.mit.edu/desktopWEDM/electronics/)

##### [Firmware](https://langfordw.pages.cba.mit.edu/desktopWEDM/firmware//)

More (scattered) documentation can be found throughout my [HTMSTMAA build log](https://fab.cba.mit.edu/classes/865.15/people/will.langford/index.html).

<hr>

#### <a id="instron">Tabletop Instron</a>

I made a table-top instron to explore very small force-displacement relationships.

<div class="image-row">
    <img src="content/tabletopinstron/images/instron_far.jpg">
</div>

##### Motion Stage

For the motion stage, I'm relying on the ubiquity of <a href="https://www.thorlabs.com/newgrouppage9.cfm?objectgroup_id=10211">precision micrometer stages</a> just lying around our lab. By boring out a helical coupling, I can very easily attach the end of the micrometer to a stepper motor. This setup allows for very fine position control: every 1/16 microstep of the stepper motor results in 0.198um of linear motion.

In order to ensure smooth motion, I've implemented a method for accelerating and decelerating the stepper that's discussed in [this paper](http://www.hwml.com/leibramp.pdf). This is the simplest and cheapest (computationally) stepper acceleration algorithm that I've come across. I implement it with a basic finite step machine that keeps track of whether the stepper is acclerating, decelerating, steadily-moving, or stopped. Then, in a timer interrupt which triggers at 256 Hz, I update the step delay depending on this state. Each step is periodially toggled by checking `if (micros()-last_time > step_delay)`.

##### Load Cell

I'm using the load cell out of a <a href="https://www.amazon.com/American-Weigh-GEMINI-20-Portable-MilliGram/dp/B0012TDNAM/">low cost milligram scale</a> which has a range of 20g and a purported resolution of 1mg.

<div class="image-row">
    <img src="content/tabletopinstron/images/instron_close.jpg">
    <img src="content/tabletopinstron/images/instron_circuits.jpg">
</div>

Instead of relying on their electronics with unknown resolution and calibration, I'm using my own 24-bit ADC and amplifier (<a href="http://www.ti.com/product/ADS1231">TI ADS1231</a>) to read the load cell. By oversampling 16x and decimating (see <a href="http://www.atmel.com/images/doc8003.pdf">this nice app note</a>), I can achieve better than 10mg resolution with noise on the order of 1mg (I think the original 1mg spec was a bit of a stretch).
	
##### Interface

To interface with the hardware, I built a javascript/node interface. The interface extends the [javascript serial monitor](https://gitlab.cba.mit.edu/langfordw/javascriptSerialMonitor) that I made previously. It's essentially a fancy serial monitor that enables commands to be sent to the machine and for data to be read back and plotted in realtime. <a href="https://langfordw.pages.cba.mit.edu/table_top_instron/js_interface">Try it out.</a>

<div class="image-row">
    <img src="content/tabletopinstron/images/table_top_instron_usability_gif.gif">
</div>

For plotting I'm using [plotlyjs](https://plot.ly/javascript/) and for webcam streaming and recording I'm using [videojs-record](https://github.com/collab-project/videojs-record) (which is great, except that changing the size/resolution of the capture appears to be broken at the moment).

#### Applications

I'm using this machine to characterize the stiffness of small-scale flexural mechanisms, as well as the force output from electromagnetic actuators.

<div class="image-row"><img src="content/tabletopinstron/images/sarrus_stiffness.gif"></div>

<hr>

#### <a id="punchpress">Automated Punch-Press</a>

I built an automated small-scale punch press in order to stamp out fiberglass parts for my electronic digital materials research.

This machine was a first project to get to know our new Wire-EDM machine. Everything except for the large steel uprights were cut on the Wire-EDM.

The machine uses a force amplifying linkage to translate the large displacement of the input handle into a small, but strong, displacement of the punch. 

<div class="image-row">
    <img src="content/machine_building/automated_punch_press.png">
</div>

An additional stepper motor is positioned to automatically advance the strip of material between each punch operation. 

<div class="image-row">
    <img src="content/electronic_digital_materials/images/punch_press_close.jpg">
    <img src="content/electronic_digital_materials/images/punch_press_part.jpg">
</div>

##### Interface

For the touchscreen interface I used a Raspberry Pi (v2) with a little 2.8" capactive touchscreen. The interface is just javascript in the browser and the Pi runs a node server to talk between the browser and an attached A-star microcontroller which controls the stepper motors.

The touchscreen isn't quite as nice as a touchscreen you'd find on a smartphone (for one, it's not multi-touch) but it's remarkably capable given how inexpensive it is. The Pi is hooked up to the wifi so this setup also allows me to control the machine remotely from anywhere.

The code is [here](https://github.com/langfordw/punch_press_interface).

<div align="center">
    <iframe width="100%" height="600px" src="https://www.youtube.com/embed/YzUhlqh1Msk" title="" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>
</div>

