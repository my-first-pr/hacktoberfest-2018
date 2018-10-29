/* My Name is Michael Ikechukwu Fortune
* aka De-benige on facebook based in 
* Nigeria, currently studying computer
* science, This's my first year on
* HacktoberFest! I am really excited 
* to get T-shirt
*/
<?php

   $result1 = stringToDisplay("hello word");
 echo $result1.'<br/>';
 
 $result2 = stringToDisplay(14);
 echo $result2.'<br/>';
 
 $result3 = stringToDisplay("hello");
 echo $result3.'<br/>';
 
 function stringToDisplay($storeString){
	 if(is_string($storeString)):
	 $display = strtoupper($storeString);
	 if ($display == 'HELLO WORD'){ return "HELLO WORD"; }else{ return "Error";} 
	 else: return 'Only string is accepted';
	 endif;
 }

 ?> 