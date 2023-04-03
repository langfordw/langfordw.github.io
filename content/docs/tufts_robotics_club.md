### Tufts Robotics Club

#### Trinity Firefighting Competitions (2010-2012)

The Tufts Robotics Club competed in the <a href="http://www.trincoll.edu/events/robot/">Trinity Firefighting Competition</a> for three years (2010 through 2012). I led the team each year as we developed mobile robots to navigate a maze, find a candle, and extinguish it.

We built a total of three robots over the three years: The Precipitating Pachyderm, JumboShrimp, and Jumbotron (all named after the Tufts University mascot: Jumbo, the elephant).

<div class="image-row">
    <img src="http://farm6.staticflickr.com/5105/5589937339_188f872503_z.jpg">
    <img src="http://farm6.staticflickr.com/5303/5592029001_bb9c67663e_z.jpg">
</div>

The robots are equipped with most of the same sensors: a number of IR distance sensors, an IR photodiode to detect the flame, IR line sensors, and encoders on the wheels. The algorithm that the robots use looks something like this:

```
follow left wall
if there's a line on the floor
    align to line and check for flame
    if there's a flame
        go and extinguish it
    else
        turn around
```

Of course there's a lot more complexity in terms of executing each command and there are many cases that have to be accounted for (like switching walls to follow so the robot can search an island room).

The Trinity Firefighting Competition also features a written exam called the Olympiad Exam which teams take as a group. The exam tests problem solving ability specifically in the context of robotics. For example, you may be asked to optimize the delivery order of sushi-carrying robots given constraints on how many robots can fit in each room.

We turned out to be really good at this and got first place on the Olympiad Exam two years in a row (and tied for second place our first year).

<div class="image-row">
    <img src="content/tufts_robotics_club/2012_trinity_firefighting_success.jpg" style="max-width:80%">
</div>

#### Sumo Robotics Workshop (2010)

<div class="image-row">
    <img src="content/tufts_robotics_club/sumo_collaboration.jpeg" width="400">
</div>

In Winter 2010 I rallied members of my robotics club to design and build 3D printed sumobots with me. Over winter break I designed the main chassis of the robot and let club members design and 3D print their own front-scoops (the front section of the robot). In February we all got together and put the robots together. The Tufts Web Communications Blog wrote a <a href="http://enews.tufts.edu/stories/1642/2010/03/31/WillLangford">short article</a> about our mini-competition and made this video:

<div class="image-row">
    <iframe src="http://www.youtube.com/embed/Jp-x0tJwwCU" frameborder="0" allowfullscreen style="max-width:100%"></iframe>
</div>

The sumobots themselves are pretty simple. They've got two DC motors, an Arduino, some distance sensors, line sensors, and a custom designed robotics shield for the Arduino. You can download the 3D printed parts from <a href="http://www.thingiverse.com/thing:1548">Thingiverse</a>.

<div class="image-row">
    <img src="content/tufts_robotics_club/sumobot.jpeg">
    <img src="content/tufts_robotics_club/sumobot_pcb.jpeg">
</div>

The "Arduino Robot Shield" is a custom Arduino shield I've designed to make building robots (such as the sumobot) super easy. It includes all the additional circuitry needed to run two (relatively) low-power DC motors as well as screw terminals for inputs and outputs.


It's gone through a bunch of iterations since Winter 2010 and I think has finally settled on a stable design (v4.0).

<div class="image-row" style="max-height:80%">
    <img src="content/tufts_robotics_club/sumobot_pcb_design.jpeg">
    <img src="content/tufts_robotics_club/robot_shield_v4.0.png">
</div>

I designed a derivative of the robot shield for use in a mechatronics course I worked as a teaching assistant for. The students needed a way to quickly and easily interface Lego NXT components (sensors/motors) with the Arduino. The Arduino2NXT Shield does just this by including all of the H-bridge functionality of the Robot Shield but with a dedicated breadboard space and NXT connection terminals for motors and sensors.

<div class="image-row">
    <img src="content/tufts_robotics_club/arduino2nxt.png">
    <img src="content/tufts_robotics_club/arduino2nxt_with_motors.png">
</div>

#### Bloombot, 2009

Bloombot is an personal automated hydroponic growing system. I entered it, with help from others in the Tufts Robotics Club, in the <a href="http://ricc.wpi.edu/">RICC Competition (Robotics Innovations Competition and Conference)</a> at Worcester Polytechnic Institue. The theme of the competition was to develop innovative robotic solutions to improve people's quality of life. My goal was to create a system that made growing plants and herbs in the home throughout the year easier.

<div class="image-row">
    <img src="content/tufts_robotics_club/bloombot.jpg">
    <img src="http://farm3.staticflickr.com/2549/4096958429_a3e7b430ff_z.jpg?zz=1">
</div>

Bloombot uses a method of hydroponics called deep water culture in which the plant roots are suspended in a highly oxygenated nutrient solution. This allows for a highly efficient transfer of nutrients directly from the water solution to the roots.


The system features a number of sensors which detect water level and light intensity. The whole system is controlled over the internet via Twitter such that a user can simply tweet @Bloombot to turn the lights or pump on or off. Bloombot will also send a tweet if it detects a change in its state (e.g., one of the lights went out unexpectedly or the water level dropped below a certain level).

<div class="image-row">
    <img src="http://farm5.staticflickr.com/4070/4515065677_d1fcb230ce_b.jpg">
    <img src="http://farm3.staticflickr.com/2671/4079356190_cf9219fa61.jpg">
</div>

Design files for the enclosure are posted on <a href="http://www.thingiverse.com/thing:1190">Thingiverse</a> and you can read a bit more about the project on the <a href="https://sites.google.com/site/tuftsroboticsclub/current-projects/bloombot">Tufts Robotics Club website</a>.