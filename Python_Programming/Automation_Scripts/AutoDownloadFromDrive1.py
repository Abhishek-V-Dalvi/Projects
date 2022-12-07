# Google OAuth 2.0 and OAuth consent screen
# authentication to googleapi services
# create oAuth client secret file
# https://console.cloud.google.com/

import os
import hashlib
from pydrive.auth import  GoogleAuth
from pydrive.drive import GoogleDrive
import schedule
import time
from sys import *


def HashFile(path,blocksize = 1024):            #This function is used to calculate checksum
    fd = open(path,'rb')
    hasher = hashlib.md5()
    buf = fd.read(blocksize)

    while(len(buf) > 0):
        hasher.update(buf)
        buf = fd.read(blocksize)
    fd.close()
    return hasher.hexdigest()

def Download_Drive(download_dir):
    # Checking the directory setup i.e. path and existance
    path = download_dir
    flag = os.path.isabs(download_dir)

    if flag == False:
        path = os.path.abspath(download_dir)

    exists = os.path.isdir(path)
    directory = path
    local_checksum = []     #Empty list to store checksum of present file

    if exists:
        for dirName, subDir, fileName in os.walk(path):
            for file in fileName:
                path = os.path.join(download_dir, file)
                file_hash = HashFile(path)
                if not file_hash in local_checksum:
                    local_checksum.append(file_hash)
    else:
        print("Invalid path given to store downloaded file.")
        exit()

    #Downloading setup from drive

    gauth = GoogleAuth()                #created object of GoogleAuth()
    drive = GoogleDrive(gauth)          #created object of GoogleDrive()

    folder = '1diJni37T3jCzdd7hZQm17JVqnBGKeWZy'              #folder id of google drive from where files need to be download
    file_list = drive.ListFile({'q': f"'{folder}' in parents and trashed = false"}).GetList()

    for index, file in enumerate(file_list):
        checksum = file['md5Checksum']
        if checksum in local_checksum:
            print(index+1, 'file already present : ',file['title'])
        else:
            file.GetContentFile(file['title'])
            print(index+1, 'file downloaded : ', file['title'])

def main():
    print("-----Automation script started-----")
    print("Application name : ", argv[0])
    print("Use '-h' for HELP and '-u' for USAGE of script")

    if (len(argv) != 2):
        print("Invalid number of arguments. Needs 2 given ", len(argv))
        exit()

    if (argv[1] == '-h' or argv[1] == '-H'):
        print("Help : This script is used to download all files present in the google drive & store that file in specified directory by user")
        exit()

    if (argv[1] == '-u' or argv[1] == '-U'):
        print("Usage : Required two arguments")
        print("First argument   : Application_Name")
        print("Second argument  : Abs_Path_Of_Download_Directory")
        exit()



    download_dir = argv[1]

    try:
        #schedule.every().tuesday.at("11:00").do(Download_Drive,download_dir)
        schedule.every(30).seconds.do(Download_Drive, download_dir)

        while True:
            schedule.run_pending()
            time.sleep(1)
            
    except Exception as e:
        print(e)

if __name__ == "__main__":
    main()