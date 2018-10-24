import time

def tic():
    global startTime
    startTime = time.time()

def toc():
    if 'startTime' in globals():
        # print("Elapsed time %.2f sec." % (time.time() - startTime))
        return "Elapsed time %.2f sec." % (time.time() - startTime)
    else:
        print ("Toc: start time not set")
        return 0