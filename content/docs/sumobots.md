<link rel="stylesheet" type="text/css" href="../../style.css">

### Tufts Robotics Club - Sumo Robotics Workshop (2010)

<div class="image-row">
    <img src="content/sumo/sumo_collaboration.jpeg" width="400">
</div>

In Winter 2010 I rallied members of my robotics club to design and build 3D printed sumobots with me. Over winter break I designed the main chassis of the robot and let club members design and 3D print their own front-scoops (the front section of the robot). In February we all got together and put the robots together. The Tufts Web Communications Blog wrote a <a href="http://enews.tufts.edu/stories/1642/2010/03/31/WillLangford">short article</a> about our mini-competition and made this video:

<div class="image-row">
    <iframe width="700" height="395" src="http://www.youtube.com/embed/Jp-x0tJwwCU" frameborder="0" allowfullscreen></iframe>
</div>

The sumobots themselves are pretty simple. They've got two DC motors, an Arduino, some distance sensors, line sensors, and a custom designed robotics shield for the Arduino. You can download the 3D printed parts from <a href="http://www.thingiverse.com/thing:1548">Thingiverse</a>.

<div class="image-row">
    <img src="content/sumo/sumobot.jpeg">
    <img src="content/sumo/sumobot_pcb.jpeg">
</div>

The "Arduino Robot Shield" is a custom Arduino shield I've designed to make building robots (such as the sumobot) super easy. It includes all the additional circuitry needed to run two (relatively) low-power DC motors as well as screw terminals for inputs and outputs.


It's gone through a bunch of iterations since Winter 2010 and I think has finally settled on a stable design (v4.0).

<div class="image-row" style="max-height:80%">
    <img src="content/sumo/sumobot_pcb_design.jpeg">
    <img src="content/sumo/robot_shield_v4.0.png">
</div>

I designed a derivative of the robot shield for use in a mechatronics course I worked as a teaching assistant for. The students needed a way to quickly and easily interface Lego NXT components (sensors/motors) with the Arduino. The Arduino2NXT Shield does just this by including all of the H-bridge functionality of the Robot Shield but with a dedicated breadboard space and NXT connection terminals for motors and sensors.

<div class="image-row">
    <img src="content/sumo/arduino2nxt.png">
    <img src="content/sumo/arduino2nxt_with_motors.png">
</div>