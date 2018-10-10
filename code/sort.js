function (arr) {
    function swap(i, j) {
        let temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    let n = arr.length;
    let sw = true;
    let x = 0;
    while (sw) {
        sw = false;
        x = x + 1;
        for (let i = 1;i<=(n-x);i++) {
            if (arr[i - 1] > arr[i]) {
                swap(i - 1, i);
                sw = true;
            }
        }

    }
    return arr
}
