# Google OAuth 2.0 and OAuth consent screen
# authentication to googleapi services
# create oAuth client secret file
# https://console.cloud.google.com/

import os
from pydrive.auth import  GoogleAuth
from pydrive.drive import GoogleDrive

gauth = GoogleAuth()                #created object of GoogleAuth()
drive = GoogleDrive(gauth)          #created object of GoogleDrive()

folder = '1diJni37T3jCzdd7hZQm17JVqnBGKeWZy'                                    #folder id of google drive from where files need to be download
directory = "F:\\Desktop Backup 07102022\\Python\\Automation\\Auto Downloader"  #folder path of local drive


file_list = drive.ListFile({'q': f"'{folder}' in parents and trashed = false"}).GetList()
for index, file in enumerate(file_list):
    path = os.path.join(directory,file['title'])
    if os.path.exists(path):
        print(index+1, 'file already present : ',file['title'])
    else:
        file.GetContentFile(file['title'])
        print(index+1, 'file downloaded : ', file['title'])
