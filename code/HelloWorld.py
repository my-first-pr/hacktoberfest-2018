#code for Hello World detects python version and use the correct command accordingly

import sys

if float(sys.version) >= 3.:
    exec('print ("Hello World")')
else:
    exec('print "Hello World"')
