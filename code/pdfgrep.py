#!/usr/bin/env python

from __future__ import division
import PyPDF2
import os
import sys
import threading
import Queue
import time

foundFilesList=[]
numOfPDFsFound=0

class workerThread(threading.Thread):
    def __init__(self, queue, repQueue, lock, keyword):
        threading.Thread.__init__(self)
        self.queue = queue
        self.reportQueue = repQueue
        self.lock = lock
        self.keyword = keyword 
        
    def searchkeyword(self, filename):
        
        #below you can call anycode you want
        #we have a basic task simulation example that executes in 0.1seconds
        pdfFileObj = open(filename,'rb')
        pdfReader = PyPDF2.PdfFileReader(pdfFileObj, strict=False)
        if pdfReader.isEncrypted:
            # print "The file is encrypted. Skipping"
            return 0
       
        text =""
        count=0
        try:
            num_pages = pdfReader.numPages
            #The while loop will read each page
            while count < num_pages:
                pageObj = pdfReader.getPage(count)
                text += pageObj.extractText()

                if text != "":
                    if self.keyword.lower() in text.lower():
                        foundFilesList.append(filename)                  
                        break
                count +=1
        except:
            pass
        
       
        with self.lock:
            percentage = ((self.reportQueue.qsize())/numOfPDFsFound)*100
            sys.stdout.flush()
            sys.stdout.write("\rSearching keword in file(s). Progress %s%%" %(percentage))
            sys.stdout.flush()

       
    def run(self):
        while True:
            item = self.queue.get()
            self.searchkeyword(item)
            #when you done with the task add it to the report queue
            self.reportQueue.put(item)
            self.queue.task_done()


def main():
    
    if len(sys.argv) < 3:
        print "Usage python pdfgrep.py folder keyword"
        sys.exit(1)
        
    path    = sys.argv[1]
    keyword = sys.argv[2] 
    
    
    #convert path to absolute path
    path = os.path.abspath(path)    
    
    #create an empty queue
    queue = Queue.Queue()
    #create a second queue that will be used for reporting and calculating percentage
    reportQueue = Queue.Queue()
    
    #create a lock for having serialized consolse output 
    lock = threading.Lock()
    
    #just get the current time in order to perform a subsctraction later
    start = time.time()


    #creation/preparation of the threads and their properties
    for i in range(5):
        t = workerThread(queue, reportQueue, lock, keyword)
        t.setDaemon(True)
        t.start()

    global numOfPDFsFound
    #addition of the filenames to the Queue
    for filename in os.listdir(path):
        if filename.endswith(".pdf"):
            numOfPDFsFound += 1
            filename = os.path.join(path, filename)
            queue.put(filename)

    #block until all items are completed
    queue.join()            
    
    print ('\nExecuted search in time: %s seconds' %(time.time() - start))
    
    print "Text \'%s\' found in the following files:" %keyword
    for filename in foundFilesList:
        print filename    


if __name__ == "__main__":
    main()
