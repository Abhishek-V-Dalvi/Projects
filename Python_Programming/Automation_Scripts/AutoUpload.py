# Google OAuth 2.0 and OAuth consent screen
# authentication to googleapi services
# create oAuth client secret file

# https://console.cloud.google.com/


import os
from pydrive.auth import  GoogleAuth
from pydrive.drive import GoogleDrive

gauth = GoogleAuth()                #created object of GoogleAuth()
drive = GoogleDrive(gauth)          #created object of GoogleDrive()

folder = '1NTIPdlA4VksH6aUZl61wOiv1eiiPXe7r'                                    #folder id of google drive where files need to be upload
directory = "F:\\Desktop Backup 07102022\\Python\\Automation\\Auto Downloader"  #folder path of local drive

for f in os.listdir(directory):                                                 #travel the local directory
    filename = os.path.join(directory,f)
    gfile = drive.CreateFile({'parents' : [{'id' : folder}], 'title': f})
    gfile.SetContentFile(filename)
    gfile.Upload()