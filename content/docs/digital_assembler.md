<link rel="stylesheet" type="text/css" href="../../style.css">

### Digital Assembler

*(aka stapler assembler)*

As part of my research at the Center for Bits and Atoms, I developed automated assembly methods for building structures and devices from individual standardized parts.

This went through a number of iterations before it converged on this 4-axis machine which I call the stapler assembler. You can think of it as a 3D printer with a stapler instead of an extruder. The machine was designed to take advantage of precision CNC-routed parts made from HDPE. These were reinforced with steel bars, requiring only a small amount of manual machining.

<div class="image-row">
    <img src="content/stapler/images/assembler_gantry02.jpg">
    <img src="content/stapler/images/dual_stapler_section.png">
</div>

The assembler has two toolheads: one for conductive parts, and one for insulating parts. Features on the toolhead enable it to align to the structure as it deposits a part. This lets the assembler place the parts more precisely than it can position. Furthermore, relative to continuous (analog) fabrication processes, the detection and correction of errors is far simpler with this discrete assembly process. 

<div class="image-row">
    <img src="content/stapler/images/worm_gear_stapler01.jpg">
    <img src="content/stapler/images/worm_gear_stapler_hand.jpg">
</div>

The path planning is done with a custom software tool developed by [Amanda Ghassaei](https://github.com/amandaghassaei/DMDesign). The software allows the user to place blocks of material, simulate their electronic performance, and then streams the g-code to the assembler.

Here is a video showing the assembler in action:

<div class="image-row">
    <video src="content/stapler/video/dual_stapler_cut2_small.mp4" controls width="80%">
</div>

To demonstrate the repeatability of the assembly process I assembled three identical capacitors (shown below) and compared their electrical performance. They measure within 1% of their mean value and are within 5% of the simulated capacitance without any calibration or tuning.

<div class="image-row">
    <img src="content/stapler/images/dual_stapler_2capacitors.png">
    <img src="content/stapler/images/stapler_capacitors01_alpha.png">
</div>

[This paper](http://www.cba.mit.edu/docs/papers/16.07.msec.stapler.pdf), presented at the ASME MSEC 2016 conference, provides more details about this work.













