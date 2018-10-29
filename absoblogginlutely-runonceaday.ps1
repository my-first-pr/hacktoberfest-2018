#Assumes that c:\temp exists on your machine
#Add this to your $profile file

if (test-path ("c:\temp\powershelllogs-" + $env:username + (get-date -uformat "%y%m%d") + "*.txt")) {$alreadyrun = $true}
$transcriptlog = "c:\temp\powershelllogs-" + $env:username + (get-date -uformat "%y%m%d-%T") + ".txt"
start-transcript $transcriptlog
 $host.ui.rawui.WindowTitle = $transcriptlog
 
if (!$alreadyrun) {
    #Anything in this script block will only run once per day
    #Code to check Packt's free book of the day
    #code to check if software updates via chocolately are required
    #choco outdated
    write-host "To update all chocolately packages... cup all -y "
}