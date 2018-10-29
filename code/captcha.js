var captcha = {
        1 : "a.jpg",2 : "b.jpg",3 : "c.jpg",4 : "d.jpg",5 : "e.jpg",
        6 : "f.jpg",7 : "g.jpg",8 : "h.jpg",9 : "i.jpg",10 : "j.jpg",
        11 : "k.jpg",12 : "l.jpg",13 : "m.jpg",14 : "n.jpg",15 : "o.jpg",
        16 : "p.jpg",17 : "q.jpg",18 : "r.jpg",19 : "s.jpg",20 : "t.jpg"
}

function shuffle(array) {
  var currentIndex = array.length, temporaryValue, randomIndex;

  // While there remain elements to shuffle...
  while (0 !== currentIndex) {

    // Pick a remaining element...
    randomIndex = Math.floor(Math.random() * currentIndex);
    currentIndex -= 1;

    // And swap it with the current element.
    temporaryValue = array[currentIndex];
    array[currentIndex] = array[randomIndex];
    array[randomIndex] = temporaryValue;
  }
 return array;
}

function getCaptcha(){
    var keyArray = Object.keys(captcha);

    keyArr = shuffle(keyArray);
    keyArr = shuffle(keyArray);

    for (var i = 0; i < keyArr.length/3; ++i) {
        var current = captcha[keyArr[i]];
        // if(Object.values(captcha).indexOf(current) > -1) 
        //         ++i;
        console.log(current);
    }
}
