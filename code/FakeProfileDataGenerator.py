#!/usr/bin/python

"""
Python script that generates and stores fake data in JSON object.Python
This data can be used for web/application development for unit testing etc.
"""

__author__ = "github.com/mohit4"
__version__ = "1.0.0"
__maintainer__ = ["github.com/mani1soni","github.com/mohit4"]

import sys
import json
import datetime
from faker import Faker

# method to generate fake data
def generate_fake_data(no_of_profiles):
  try:
    # creating object for fake data generation
    fakegen = Faker()
    # creating a file to store json data
    now = str(datetime.datetime.now())
    file_name = 'fakeprofiles_'+'_'.join([now[:4],now[5:7],now[8:10]])+'_'+''.join([now[11:13],now[14:16],now[17:19]])+'.json'
    print "Populating file ", file_name
    
    # to hold our data dictionary
    data = {}
    
    for i in range(no_of_profiles):
      # working on generating fake data
      fake_profile = fakegen.profile()
      fake_profile['birthdate'] = str(fake_profile['birthdate'])
      fake_profile['current_location'] = float(fake_profile['current_location'][0]),float(fake_profile['current_location'][1])
      # working on fake credit card details
      fake_card_details = {'provider':fakegen.credit_card_provider(),'number':fakegen.credit_card_number(),'CV2':fakegen.credit_card_security_code(),'expire':fakegen.credit_card_expire()}
      fake_profile['credit_card'] = fake_card_details
      data[i] = fake_profile
    # writting all data to json file
    with open(file_name,'w') as fileObj:
      json.dump(data, fileObj)
    print "Finished writing data to file."
  except Exception as e:
    print "Unable to run Error :", str(e)

if __name__ == "__main__":
  # check if there are command line arguments
  if len(sys.argv) == 2:
    no_of_profiles = int(sys.argv[1])
  else:
    no_of_profiles = 5
  # else use the default value
  generate_fake_data(no_of_profiles)
  print "Fake data generated for %d people."%(no_of_profiles)
