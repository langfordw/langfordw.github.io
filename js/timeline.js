const timelineEntries = [
    { name: 'MakerBot', start: 2009, end: 2011, anchor: 2010.25, image: 'content/timeline/makerbot.png', className: 'makerbot' },
    { name: 'Tufts', start: 2009, end: 2012, anchor: 2010.5, image: 'content/timeline/tufts.png', className: 'tufts' },
    { name: 'MIT', start: 2012, end: 2016, anchor: 2015.65, image: 'content/timeline/mit.png', className: 'mit' },
    { name: 'CBA', start: 2016, end: 2019, anchor: 2016.6, image: 'content/timeline/cba.png', className: 'cba' },
    { name: 'Fab Lab', start: 2013, end: 2017, anchor: 2014.1, image: 'content/timeline/fablab.png', className: 'fablab' },
    { name: 'Volta Labs', start: 2019, end: 2023, anchor: 2020.6, image: 'content/timeline/volta.png', className: 'volta' },
    { name: 'Formlabs', start: 2023, end: 2026, anchor: 2024, image: 'content/timeline/formlabs.png', className: 'formlabs' },
];

function renderTimeline(container) {
    const assetPrefix = location.pathname.endsWith('/content/timeline.html') ? '../' : '';
    const firstYear = 2006;
    const lastYear = 2026;
    const yearRange = lastYear - firstYear;

    container.innerHTML = `
        <div class="timeline-track" role="img" aria-label="Work and education timeline from 2009 to the present">
            <img class="timeline-portrait" src="${assetPrefix}content/timeline/portrait.png" alt="Portrait of Will Langford">
            <div class="timeline-segment timeline-segment-1"></div>
            <div class="timeline-segment timeline-segment-2"></div>
            <div class="timeline-segment timeline-segment-3"></div>
            <div class="timeline-segment timeline-segment-4"></div>
            ${timelineEntries.map(entry => {
                const start = ((entry.start - firstYear) / yearRange) * 100;
                const width = ((entry.end - entry.start) / yearRange) * 100;
                const image = entry.image ? `<img src="${assetPrefix}${entry.image}" alt="${entry.name}">` : '';
                const anchor = ((entry.anchor - entry.start) / (entry.end - entry.start)) * 100;
                return `<div class="timeline-entry ${entry.className}" style="left: ${start}%; width: ${width}%; --anchor: ${anchor}%">
                    <div class="timeline-mark">
                        ${image}
                        <span>${entry.name}</span>
                    </div>
                </div>`;
            }).join('')}
            <div class="timeline-year year-2008">2008</div>
            <div class="timeline-year year-2012">2012</div>
            <div class="timeline-year year-2019">2019</div>
            <div class="timeline-year year-2023">2023</div>
        </div>`;
}

document.querySelectorAll('#timeline-container').forEach(renderTimeline);
