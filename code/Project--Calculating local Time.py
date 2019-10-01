#introduction to project
print("The Project undertaking at the six weeks python program at Igbogbo center\
 Ikorodu lagos Nigeria\nkudos and a big thank you to the facilitator, Mr Ben and the entire crew\
 of the program")
print("The Project is on Calculation of LOCAL TIME")


print("kindly press A or B")
display=str(input("A To calculate Distance in latitude on same longitude\nB To calculate local time of places\nResponse: "))
print(display)

n="north"
s="south"
e="east"
w="west"
d="degree"
x=111
km="kilo meters"
a=4
b=60
c=1
k=15
o="Greenwich meridien"
h="hours"
def time():
    time=input("enter a time in the hh:mm format")
    timeArray=time.split(":")
    hours=int(timeArray[0])
    minutes=int(timeArray[1])
    ampm=""
    if hours==12:
        ampm="pm"
    elif hours==0:
        ampm="am"
        hours=12
    elif hours>=12:
        ampm="pm"
        hours=hours-12
    else:
        ampm="am"
        
    print(str(hours)+":"+str(minutes)+""+ampm)


t=time()

if display.upper()=="A":
    print("\t This is the Platform for the calculations of distance in latitude on same longitude:\n ")
    
    print("To calculate latitude distance where both are north of the equator")
    latitude1=int(input("Enter the first degree in latitude?:  "))
    latitude1_degree=str(input(" north\n south\n east\n west\n response: "))
    latitude1_location=input("enter the location of latitude1: ")
    latitude2=int(input("Enter the second degree in latitude?:  ",))
    latitude2_degree=str(input(" north\n south\n east\n west\n response: "))
    latitude2_location=input("enter the location of latitude2: ")
    longitude1=int(input("Enter the degree inlongitude?:  "))
    print("The inputed latitude of location one is: ",latitude1,d, \
          latitude1_degree, "in" ,latitude1_location)
    print("The inputed latitude of location one is: ", latitude2,d, \
          latitude2_degree,"in",latitude2_location)
    print("The inputed longitude is: ",longitude1,d)
    latitude=input("1 for latitude where both locations are north\n2 \
latitude where both locations\
    \nare south\n3 latitude on both north and south of the equator\nresponse")

    if latitude=="1":
        print("both locations are: ", n)
        if latitude1>latitude2:
            largest1=latitude1
            output1=largest1-latitude2
            output2=output1*x
            print("distance between the 2 latitudes is: ", output2,km)

        elif latitude2>latitude1:
        
            largest2=latitude2
            output1=largest2-latitude1
            output2=output1*x
            print("distance between the 2 latitudes is: ", output2,km)

        else:
            print()
    if latitude=="2":
        print("both locations are: ", s)
        if latitude1>latitude2:
            largest1=latitude1
            output1=largest1-latitude2
            output2=output1*x
            print("distance between the 2 latitudes is: ", output2,km)
            
        elif latitude2>latitude1:
            largest1=latitude2
            output1=largest1-latitude1
            output2=output1*x
            print("distance between the 2 latitudes is: ", output2,km)


    if latitude=="3":
        print("To calculate latitude distance where both are north\
and south of the equator")
        print("different Hemishere")
            
        output1=latitude1+latitude2
        print(output1)
        output2=output1*x
        print("distance between the 2 latitudes is: ", output2,km)

    
    else:
        print()
        

elif display.upper()=="B":
    print("\t This is the Platform is to calculate local time of \
places world wide:\n ")
    longitude1=int(input("Enter the first degree in longitude?:  "))
    longitude1_degree=str(input(" north\n south\n east\n west\n \
Greenwich meridien\n response: ")) 
        
    

    location1=input("enter the first location: ")    
    longitude2=int(input("Enter the second degree in longitude?:  ",))
    longitude2_degree=str(input(" north\n south\n east\n west\n \
Greenwich meridien\n response: "))
    time2=float(input("kindly input time:  "))
    location2=input("enter the second location: ")

    print("The inputed data for location one is: ",longitude1,d, \
          longitude1_degree, "at" ,t,  location1)
    print("The inputed data for location two is: ",longitude2,d, \
          longitude2_degree, "at" ,time2,  location2)
    
    print("kindly press A or B")
    display=str(input("1 To calculate time east from greenwich \
meridien \n2 To calculate time west of Greenwich meridien\
    \n3 to calculate time across the greenwich meridien  \nResponse: "))
    print(display)

    if display=="1":
        print("both", e,"of",o)        
        if longitude1>longitude2:
            
            largest=longitude1
            output1=largest-longitude2
            output2=((output1*a)/b)*c
            print(location1, "is", output2, h,"away")
            output3=t-output2
            print("time in ",location2, " is ", output3)
        else:
            longitude2>longitude1
            largest=longitude2
            output1=largest-longitude1
            output2=((output1*a)/b)*c
            print(location1, "is", output2, h,"away")
            output3=t-output2
            print("time in ",location2, " is ", output3)
                        

    if display=="2":
        print("both", w,"of",o)
        
    
        if longitude1>longitude2:
            
                    
            largest=longitude1
            output1=largest-longitude2
            output2=((output1*a)/b)*c
            print(location1, "is", output2, h,"away")
            output3=t-output2
            print("time in ",location2, " is ", output3)
        else:
            longitude2>longitude1
            largest=longitude2
            output1=largest-longitude1
            output2=((output1*a)/b)*c
            print(location1, "is", output2, h,"away")
            output3=t-output2
            print("time in ",location2, " is ", output3)
                            

    if display=="3":
        print("both on different hemisphere: ")
        output1=longitude1+longitude2
        output2=(output1/k)*c
        print(location1, "is", output2, h,"away")
        output3=t+output2
        print("time is gained tending east:  ",location2, " is ", output3)
