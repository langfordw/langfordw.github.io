<link rel="stylesheet" type="text/css" href="../../style.css">

### Ocelot, 2014

I took a bio-inspired robotics class taught by <a href="http://biomimetics.mit.edu/">Sangbae Kim</a>, and together fellow CBA'er <a href="http://www.mit.edu/~calisch/">Sam Calish</a>, we built Ocelot, a three degree-of-freedom bounding robot. By controlling the extension/contraction of the front and hind legs as well as the flexion of the spine, the robot can run at up to 1.5 bodylengths per second.

<div class="image-row">
    <img src="content/ocelot/images/ocelot1.jpeg" style="max-width:80%">
</div>
<div class="image-row">
    <img src="content/ocelot/images/ocelot2.jpeg">
    <img src="content/ocelot/images/ocelot3.jpeg">
</div>

<p>The robot was inspired by the observation that most animals that bound do so with only three distinct degrees-of-freedom (they have many more than three joints but they're timed synchronously).</p>

<div class="image-row">
    <img src="content/ocelot/images/ocelot_dimensioned.png" style="max-width:80%">
</div>

We fabricated the vast majority of the robot in a day using the Shopbot Desktop CNC router and a Makerbot 3D printer. The robot is primarily made of machined delrin and shoulder bolts are used for each joint.

<div class="image-row">
    <img src="content/ocelot/images/ocelot_fabrication.png" style="max-width:80%">
</div>

The robot uses three brushed DC motors with encoders. The motor drivers also sense the current draw of the motor which enables us to implement a low-level torque control loop around which we control the position of each joint via a cyclic waveform (that's sinusoid-eque).

<div class="image-row"><img src="content/ocelot/images/ocelot_test_setup.png" style="max-width:80%"></div>

Finally, here are high-speed videos of the robot running. By changing the phase of the spine with respect to the legs we can control the direction that the robot runs in. Furthermore, by varying the spine apmplitude we can vary the speed of the robot.
<!-- <div class="image-row">
    <iframe width="375" height="281" src="http://www.youtube.com/embed/l4f-RfuEwAo?rel=0" frameborder="0" allowfullscreen></iframe>
    <iframe width="375" height="281" src="http://www.youtube.com/embed/anVZkojTozs?rel=0" frameborder="0" allowfullscreen></iframe>
</div> -->

<div class="image-row">
    <img src="content/ocelot/images/ocelot_plot2.png">
    <img src="content/ocelot/images/ocelot_plot.png">
</div>
