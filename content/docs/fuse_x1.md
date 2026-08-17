### Formlabs Fuse X1

These days I spend most of my time working on the Fuse X1, Formlabs' next-generation industrial SLS 3D printer.

<div class="image-row">
	<img src="content/fusex1/fusex1.jpg" alt="Fuse X1">
</div>

I originally joined the program to lead embedded systems development, but my role has steadily expanded as the printer has moved from early architecture through integration and toward production. Today my work spans embedded architecture, system integration, print performance, and many of the messy cross-disciplinary problems that appear when you try to make a complicated physical product actually work reliably.

That last part is probably what I enjoy most. An industrial 3D printer sits at the intersection of electronics, software, controls, optics, thermal systems, mechanics, materials, and a surprisingly complicated physical process. The hardest problems rarely belong cleanly to one of those disciplines. I spend a lot of my time figuring out which problems matter most, helping teams make sense of what the machine is telling us, and then diving as deep as necessary to get to a solution.

<div class="image-row">
	<img src="content/fusex1/preform.jpg" alt="Preparing a Fuse X1 print in PreForm">
	<img src="content/fusex1/priming.jpg" alt="Priming a Fuse X1 printer">
</div>

One example is Print Intelligence. I started exploring whether we could use data from the printer to recognize and respond to failures while a print was still running. What began as a small feasibility study became a six-month push from initial idea to a production feature enabled by default across the fleet. Along the way I worked on the business case, data collection and annotation, algorithm and system architecture, testing, tuning, and ultimately getting the feature released into the product.

A different part of the job is creating ways for the broader team to converge on a working product. I run our daily print-success triage, where engineers across disciplines work through issues from both our internal printers and beta customers, as well as a weekly program-wide review focused on the hardware risks most likely to prevent us from shipping. I also built the tooling we use to track part quality throughout development; a team of engineers, technicians, and product managers has now used it to assess more than 20,000 individual printed parts.

I like operating at that boundary between architecture and debugging—keeping the entire product in view while still being willing to dig into the data, physics, software, or hardware when that's what it takes to move the machine forward. Fuse X1 has been an especially fun version of that problem: taking a very complicated system from a collection of ideas and prototypes toward something that can repeatedly make good parts in the real world.
