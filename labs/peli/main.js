// const Http = new XMLHttpRequest();
// const url='https://api.onepeloton.com/api/v2/ride/archived?browse_category=cycling&content_format=audio,video&limit=18&page=0&super_genre_id=3ee05f39e1dd477facbb9ac8c27c89c3&class_type_id=f10471dcd6a34e5f8ed54eb634b5df19&instructor_id=2e57092bee334c8c8dcb9fe16ba5308c&duration=2700&sort_by=original_air_time&desc=true';
// Http.open("GET", url);
// Http.send();
// Http.onreadystatechange=(e)=>{
// console.log(Http.responseText)
// }

var requestString = "https://api.onepeloton.com/api/v2/ride/archived?browse_category=cycling&content_format=audio,video&page=0"
var limit = 5;

// "https://api.onepeloton.com/api/ride/b39c0d56ece1466f9f0c76e6ae4009b0/details"
var detailsString = "https://api.onepeloton.com/api/ride/b39c0d56ece1466f9f0c76e6ae4009b0/details"

requestString += "&limit="+limit;

$.ajax({
    type: 'GET',
    url: requestString,
    headers: {
        "peloton-platform": "web"
    },
    xhrFields: {
         withCredentials: true
    }
}).done(function(data) { 
    console.log(data);
    display(data);
});

// $.get(requestString).done(function (data) {
//     console.log(data);
//     display(data);
// });



function findInstructorNameById(data,instructor_id) {
	var instructors = data.instructors;
	var instructorName = ""
	for (var i = 0; i < instructors.length; i++) {
		if (instructors[i].id == instructor_id) {
			 instructorName = instructors[i].first_name + " " + instructors[i].last_name;
		}
	}
	if (instructorName == "") {
		console.warn("instructor" + instructor_id + " not found")
		return;
	} else {
		return instructorName;
	}
}

function display(data) {
	var raw_classes = data.data;

	var sort_by="recent";
	var durationRange = [601,1800];

	// temporary array holds objects with position and sort-value
	var mapped = raw_classes.map(function(el, i) {
		if (sort_by == "rating") { 
			return { index: i, value: el.overall_rating_avg } 
		} else if (sort_by == "recent") { 
			return { index: i, value: el.scheduled_start_time } 
		} else if (sort_by == "views") { 
			return { index: i, value: el.total_workouts } 
		} else { 
			return null;
		}
	})

	// sorting the mapped array containing the reduced values
	mapped.sort(function(a, b) {
	  if (a.value > b.value) {
	    return -1;
	  }
	  if (a.value < b.value) {
	    return 11;
	  }
	  return 0;
	});

	// container for the resulting order
	var classes = mapped.map(function(el){
	  return raw_classes[el.index];
	});

	for (var i=0; i < classes.length; i++) {
		if (classes[i].duration <= durationRange[1] && classes[i].duration >= durationRange[0]) {
			console.log(classes[i])

			var link = document.createElement("a");
			link.href = "https://members.onepeloton.com/classes/cycling?classId="+classes[i].id+"&modal=classDetailsModal";

			var classDiv = document.createElement("div");
			classDiv.style.width = "30%";
			classDiv.style.height = "350px";
			// classDiv.style.background = "red";
			// classDiv.style.color = "white";
			// classDiv.innerHTML = classes[i].title;

			var titleDiv = document.createElement("div");
			titleDiv.width="200px";
			titleDiv.height="100%";
			titleDiv.background="blue";
			titleDiv.innerHTML = classes[i].title + "<br>" + findInstructorNameById(data,classes[i].instructor_id) + "<br>" + classes[i].description + "<br>" + classes[i].overall_rating_avg + "<br>" + classes[i].total_workouts;
			
			var img = document.createElement("img");
			img.src = classes[i].image_url;
			img.style.height = "200px";

			classDiv.appendChild(titleDiv);
			classDiv.appendChild(img);
			link.appendChild(classDiv);

			document.getElementById("main").appendChild(link);
		}
	}
}

// $.ajax({
//     xhrFields: {
//         // withCredentials: true,
//         browse_category: "cycling",
//         content_format: "audio,video",
//         limit: 50,
//         page: 1
//     },
//     type: "GET",
//     url: "https://api.onepeloton.com/api/v2/ride/archived"
// }).done(function (data) {
//     console.log(data);
// });