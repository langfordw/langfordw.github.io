const data = { 
    dots: [
    { top: 20, left: 52, content: 'rtf.md', title: 'Rapid Task Force for System Integration', image: 'content/rtf/rtf_meeting.png' },
    { top: 25, left: 70, content: 'planning.md', title: 'An iterative and collaborative approach to planning', image: 'content/planning/planning.png' },
    { top: 50, left: 30, content: 'discrete_robotic_construction.md', title: 'Discrete Robotic Construction', image: 'content/discrete_robotic_construction/walker.gif' },
    { top: 45, left: 40, content: 'electronic_digital_materials.md', title: 'Electronic Digital Materials & Assemblers', image: 'content/electronic_digital_materials/images/digital_assembler.jpeg' },
    { top: 65, left: 45, content: 'makerbot.md', title: 'Makerbot Industries', image: 'content/makerbot/globe_small_1.png' },
    { top: 25, left: 30, content: 'assorted_projects.md', title: 'Assorted Projects', image: 'content/assorted_projects/ocelot/images/ocelot1.jpeg' },
    { top: 30, left: 25, content: 'machine_building.md', title: 'Machine Building', image: 'content/machine_building/wire_edm/dwedm2_01.jpeg' },
    { top: 25, left: 45, content: 'fablabs.md', title: 'Fablabs', image: 'content/fablabs/armenia/hardworkers.jpg' },
    { top: 45, left: 60, content: 'tufts_robotics_club.md', title: 'Tufts Robotics Club', image: 'content/tufts_robotics_club/sumo_collaboration.jpeg' }, 
    { top: 55, left: 50, content: 'papers_and_patents.md', title: 'Papers and Patents', image: 'content/papers_and_patents/patent.png' }, 
]}

const templateSource = `
  <div class="venn-diagram">
    <div id="circles">
      <div class="circle circle-build"></div>
      <div class="circle circle-lead"></div>
      <div class="circle circle-innovate"></div>
    </div>
    {{#each dots}}
    <div id="dot-{{@index}}" class="dot-container" style="top: {{top}}%; left: {{left}}%;" onclick="handleContentDisplay('{{content}}',{{@index}})">
      <div class="dot"></div>
      <div class="dot-content">
        <h4>{{title}}</h4>
        <img src="{{image}}">
      </div>
    </div>
    {{/each}}
    <div class="label-build">BUILD</div>
    <div class="label-lead">LEAD</div>
    <div class="label-innovate">INNOVATE</div>
  </div>
  <div class="dot-content-list">
    {{#each dots}}
    <div id="listitem-{{@index}}" class="dot-content-list-item" onclick="handleContentDisplay('{{content}}',{{@index}})">
      <h4>{{title}}</h4>
    </div>
    {{/each}}
  </div>
`;

const template = Handlebars.compile(templateSource);
const renderedHtml = template(data);

document.getElementById('venn-container').innerHTML = renderedHtml;
  