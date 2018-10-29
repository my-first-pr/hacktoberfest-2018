const apiKey = require("./api.json");

const https = require("https");

var country ="IN";

require("http");

function weather(loc)
{
	try{
		loc =loc+','+country;

		let body ="";
		const request= https.get(`https://api.openweathermap.org/data/2.5/weather?q=${loc}&appid=${apiKey.Key}`,response => 
		{
			response.on('data', data =>
			{
				body += data.toString();
			});
			response.on('end', () => 
			{
				var weatherData = JSON.parse(body);
				var message = `Temprature at ${weatherData.name} is:${weatherData.main.temp-273}\u00B0 C`;
				console.log(message);
			});
		});
	}

	catch(error)
	{
		console.error(error.message);
	}
}


loc = process.argv.slice(2);
loc.forEach(weather);
weather(loc);

