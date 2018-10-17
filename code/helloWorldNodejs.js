var express = require('express');
var app = express();

app.get('/', function (req, res) {

  res.send('Hola Mundo!');

});

app.listen(3030, function () {
	
  console.log('Ejemplo APP, escuchando por puerto 3030!');
  
});