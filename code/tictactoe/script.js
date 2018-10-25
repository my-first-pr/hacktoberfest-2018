/* Sharif */
window.onload=function(){
      
    $(document).ready(function() {
        var moves = 0;
      var currentPlayer = "X";
      var message = "Start";
      setMessage("Welcome! You play X and start first.");
    
    function checkFreeCell(cell){
        return !$(cell).hasClass("O") && !$(cell).hasClass("X");
    };
    
    function getCellCoord(index){
        return $("#cellindex" + index);
    };
    
    function getWinnningCombinaion(x,y,z, currentPlayer){
        var match = false;
      if(getCellCoord(x).hasClass(currentPlayer) && getCellCoord(y).hasClass(currentPlayer) && getCellCoord(z).hasClass(currentPlayer)) {
      match = true;
      }
      return match;
    };
    
    function checkWin(currentPlayer){
        var haswinner = false;
      if (getWinnningCombinaion(0,1,2, currentPlayer) ||
              getWinnningCombinaion(3,4,5, currentPlayer) ||
            getWinnningCombinaion(6,7,8, currentPlayer) ||
            getWinnningCombinaion(0,3,6, currentPlayer) ||
            getWinnningCombinaion(1,4,7, currentPlayer) ||
            getWinnningCombinaion(2,5,8, currentPlayer) ||
            getWinnningCombinaion(0,4,8, currentPlayer) ||
            getWinnningCombinaion(2,4,6, currentPlayer) ) {
        haswinner = true;
        }
        return haswinner;
    };
    
    function isGameOver(){
        var gameover = false;
      if(checkWin(currentPlayer)){
          gameover = true
        setMessage(currentPlayer + " won the game!");
      } else if(!(checkWin(currentPlayer)) && (moves === 9)){
          gameover = true;
        setMessage("It's tie Game");
      };
      return gameover;
    };
    
    function switchMove(){
    if(!isGameOver()){
        if(!checkWin(currentPlayer) || !(checkWin(currentPlayer)) && !(moves === 9)) {
          currentPlayer = (currentPlayer === "X") ? "O" : "X";
          setMessage(currentPlayer + "'s Turn Now");
        };
      };
    };
    
    function makeRndMove(){
        if(!isGameOver()){
          var canMove = false;
            while (!canMove) {
              var indx = (Math.floor(Math.random() * 8));
              var freeCell = getCellCoord(indx);
              if(checkFreeCell(freeCell)) {
                canMove = true;
                //makeMove(freeCell, currentPlayer);
                freeCell.addClass(currentPlayer);
                switchMove();
                moves++;
                $(".movescount").html(moves);
              };
            };
        };
      };
      
    function makeMove($this, currentPlayer){
        // need to check game status here
        if(!isGameOver()){
          $this.addClass(currentPlayer);
          $this.text(currentPlayer);
          switchMove();
          isGameOver();
          moves++;
          setTimeout(makeRndMove, 500);
          $(".movescount").html(moves);
         } else {
           setMessage("This Game is ended.")
         };
    };
    
    $(".cell").click(function() {
        if(checkFreeCell($(this))){
          makeMove($(this), currentPlayer);
        //setTimeout(makeRndMove, 300);
        };
    });
    
    $("#reset").click(function(){
        location.reload()    
    });
    
      function setMessage(message){
        $(".status").text(message);
      };
    });
    
        }
    