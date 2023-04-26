const request = require('request');
request('https://api.onepeloton.com/api/v2/ride/archived?browse_category=cycling&content_format=audio,video&page=0', function (error, response, body) {
  // console.log('error:', error); // Print the error if one occurred
  // console.log('statusCode:', response && response.statusCode); // Print the response status code if a response was received
  // console.log('body:', body); // Print the HTML for the Google homepage.
  console.log(JSON.parse(body));
});