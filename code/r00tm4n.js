var even = function (arr) {
	var count;
	for (var i = 0; i < arr.length; i++) {
		if (arr[i]%2 == 0) {
			count ++;
		}
	}
	return even;
}

console.log(even([1,2,3,4,5,6,7,8,9]));