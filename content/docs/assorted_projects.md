### Assorted Projects (MIT 2014-2016)

<div class="image-row">
    <a href="#micropillars" style="flex:1"><img src="content/micropillars/images/micropillars.png" ></a>
    <a href="#mechsim" style="flex:1.44"><img src="content/mechsim/images/design_tool.png" ></a>
    <a href="#pop-up" style="flex:1.33"><img src="content/popup/images/pop_up_voxel_close.jpg" ></a>
    <a href="#ocelot" style="flex:1.5"><img src="content/ocelot/images/ocelot1.jpeg" ></a>
</div>

<hr>

#### <a id="micropillars">Micropillar-based Programmable Force-Fields</a>

For a hands-on micro/nano fabrication class my teammates, Jifei Ou and Lining Yao, and I looked at ways to make programmable force fields to predictably convey and orient parts on a surface. By vibrating surfaces covered with arrays of oriented micropillars, we were able to move and control parts based on anisotropic friction.

We developed two different approaches to fabricate the surfaces:

In the first approach we used a DLP based SLA 3D printer to directly print the micropillars.
<div class="image-row"><img src="content/micropillars/images/3dp.png"></div>

The second approach involved laser micromachining an acrlyic mold using a 5-axis Excimer laser system and then casting the micropillar substrate using a PDMS replica-molding process.
<div class="image-row"><img src="content/micropillars/images/excimer.png"></div>

To vibrate the pillars, we used a piezo stack actuator. The 9mm piezo stack nominally produces a maximum stroke of approximately 9um. Using a flexural amplifier, which we fabricated using a wire-edm, we increased this stroke to approximately 150um (a little less than a 20x stroke amplification).

<div class="image-row"><img src="content/micropillars/images/setup.png"></div>

We patterned the surfaces such that objects placed on it would be pushed toward the center and off to one side. These videos the ability of the surface to both convey small parts and orient them.

<div align="center">
    <iframe width="375" height="281" src="https://www.youtube.com/embed/aGf3GkrV0PA?rel=0" frameborder="0" allowfullscreen></iframe>
    <iframe width="375" height="281" src="https://www.youtube.com/embed/zhB2rEYMmnI?rel=0" frameborder="0" allowfullscreen></iframe>
    <iframe width="375" height="281" src="https://www.youtube.com/embed/TdRUnPHMbIg?rel=0" frameborder="0" allowfullscreen></iframe>
    <iframe width="375" height="281" src="https://www.youtube.com/embed/o3c-S_0QF68?rel=0" frameborder="0" allowfullscreen></iframe>
</div>

We used a high speed camera to try to discern exactly what is going on. We found that the speed of conveyance was linear with both frequency and amplitude of vibration for both the PDMS and the 3D-printed pillars.

<div align="center">
    <iframe width="425" height="150" src="https://www.youtube.com/embed/ukDIYLs4cVs?rel=0" frameborder="0" allowfullscreen></iframe>
    <iframe width="425" height="150" src="https://www.youtube.com/embed/Y_J9JfLaveU?rel=0" frameborder="0" allowfullscreen></iframe>
</div>

More details about this project can be found in our write-up, <a href="content/micropillars/MicroNanoTermPaper.pdf">here</a>.

Jifei continued to develop this idea and ultimately turned it into a product and company, [OPT Industries](https://www.optindustries.com/)!

<hr>

#### <a id="mechsim">Mechsim: Compliant mechanism simulation</a>

For a computational structural design and optimization class, I developed a design and simulation tool for discretely assembled mechanisms.

My research in digital materials (in the Center for Bits and Atoms) looks to enable the "printing" complex systems in a single process. However, rather than achieving this through the use of additive-manufacturing, we're focusing on discrete assembly of individual building blocks.

One such application of this discrete assembly method is in the construction of mechanical mechanisms: with just four part-types (rigid, 1 degree-of-freedom, 2 degree-of-freedom, and vacant) a large diversity of mechansims can be assembled.

<div class="image-row"><img src="content/mechsim/images/assembly_architecture_alpha.png"></div>

Designing and simulating these kinds of assemblies with conventional solidmodeling tools can be tedious and innacurate (given the large deformations). For this project, I aimed to create a tool which puts design and simulation in very close proximity to enable fast iteration and exploration of the discrete assembly design space.

<div class="image-row"><img src="content/mechsim/images/design_tool.png"></div>

<div class="image-row"><img src="content/mechsim/images/opt_sequence_alpha.png"></div>

More details about this project can be found in our write-up, <a href="content/mechsim/Design and Optimization Tools for Discretely Assembled Mechansims – Final.pdf">here</a>.

<hr>

#### <a id="pop-up">Pop-up: Folding Based Microassembly</a>

The goal of this project was to leverage the PC-MEMS fabrication process to build a large number of voxels using 2D manufacturing processes.

<div class="image-row"><img src="content/popup/images/pop_up_voxel_slider_detailed2.gif"></div>

This involved detailing the design of an intricate laminate with rigid and flexible elements to define precise bend lines that could be actuated with a single degree-of-freedom to "pop-up" a three-dimensional object in a single action.

<div class="image-row"><img src="content/popup/images/detailed_laminate_design.png"></div>

Each layer was laser micromachined using an Oxford fiber laser system (with galvonometer). The individual layers were then laminated together using a thermoset adhesive in a series of operations.

<div class="image-row">
    <img src="content/popup/images/pop_up_voxel_test04.jpg">
    <img src="content/popup/images/pop_up_voxel_test02.jpg">
</div>

The final project was not fully-successful. You can see a video of us trying to pop open the voxel below.
<div align="center">
    <video width="720" height="405" controls="controls"><source src="content/popup/images/almost_works.mp4" type="video/mp4" /></video>
</div>

With a little help we were able to achieve a full folding:

<div class="image-row"><img src="content/popup/images/pop_up_voxel_test2_02.jpg"></div>

<hr>

#### <a id="ocelot">Ocelot</a>

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

<div class="image-row">
    <img src="content/ocelot/images/ocelot_plot2.png">
    <img src="content/ocelot/images/ocelot_plot.png">
</div>
