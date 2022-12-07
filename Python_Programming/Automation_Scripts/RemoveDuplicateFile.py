'''
Design a automation script which performs following task.

Accept directory name from user and delete all duplicatefiles from the specified directory by considering the checksum
of files.
Create one directory named as Marvellous and inside that directory create log file which maintains all names of duplicate
files which are deleted.
Name of log file should contains the date and time at which the file gets created.
Accept duration in minutes from the user and perform task of duplicate file removal after the specific time interval.
Accept mail id from user and send the attachment of the log file.
Mail body contains statistics about the operation od duplicate file removal.

Mail body should contains below things :
    1. Starting time of scanning
    2. Tootal number of file scanned
    3. Total number of duplicate files found

Consider below command line option for the given script

DuplicateFileRemoval.py E:/Data/Demo/Demo 50 marvellousinfosystem@gmail.com

-   DuplicateFileRemoval.py -   Name of python automation script
-   E:/Data/Demo            -   Absolute path of directory which may contains duplicate files
-   50                      -   Time interval of script in minutes
-   marvellousinfosystem@gmail.com - Mail ID of the receiver

'''
from sys import *
import os
import hashlib
import datetime
import schedule
import time
import re
import smtplib
from email.mime.text import MIMEText
from email.mime.multipart import MIMEMultipart
from email.mime.base import MIMEBase
from email import encoders
import socket
import glob

def SystemDetails():
    sys_details_list = []
    ## getting hostname using socket.gethostname() method
    hostname = socket.gethostname()
    sys_details_list.append(hostname)

    ## getting the IP address using socket.gethostbyname() method
    ip_address = socket.gethostbyname(hostname)
    sys_details_list.append(ip_address)

    return sys_details_list

def LatestFile(Dir_path):
    list_of_files = glob.glob(Dir_path+"\\*")  # * means all if need specific format then *.csv
    latest_file = max(list_of_files, key=os.path.getctime)
    return latest_file

def ValidateEmailID(email):
    regex = '([A-Za-z0-9]+[.-_])*[A-Za-z0-9]+@[A-Za-z-]+(\.[A-Z|a-z]{2,})+'      #r'\b[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.[A-Z|a-z]{2,}\b'

    if (re.fullmatch(regex, email)):
        return True
    else:
        return False

def SendLog(Operated_Dir, Recepient_ID,Log_Dir = "Marvellous"):
    # Checking the absolute path
    flag = os.path.isabs(Log_Dir)
    flag1 = os.path.isabs(Operated_Dir)
    if flag == False:
        Log_Dir = os.path.abspath(Log_Dir)
    if flag1 == False:
        Operated_Path = os.path.abspath(Operated_Dir)

    latest_file = LatestFile(Log_Dir)

    Machine_details = SystemDetails()

    bRet = ValidateEmailID(Recepient_ID)
    User_Name = Recepient_ID.split('@')

    if bRet == True:
        email = 'abhi.dlv007@gmail.com'
        password = input("Enter your email password : ")

        # Email Body formation
        subject = ("Duplicate files Log on %s sent by Automated script" % datetime.datetime.now())
        message = """
            <html>
                <body>
                    <p>Dear $(User_Name),<br><br>
                    
                    Please find attached log of duplicate files present in the $(Directory) directory of below system.<br>
                    Hostname = $(Hostname)<br>
                    IP_Address = $(IP_Address)<br>
                    Operated Directory Path : $(Path)
                    
                    <p style="color:red;"><b><i>This is system generated mail and do not reply to this mail</i></b><br></p>
                    <p style="color:blue;"><b><i>For more details contact undersigned</i></b><br></p>

                    Thanks & Regards,<br>
                    Abhishek Dalvi<br>
                    📱Mob: +91-8087450882<br>
                    </p>
                </body>
            </html>
            """
        message = message.replace("$(User_Name)", User_Name[0])
        message = message.replace("$(Hostname)", Machine_details[0])
        message = message.replace("$(IP_Address)", Machine_details[1])
        message = message.replace("$(Directory)",Operated_Dir)
        message = message.replace("$(Path)", Operated_Path)

        # email.mime is the python inbuilt email API
        msg = MIMEMultipart()  # creating object
        msg['From'] = email
        msg['To'] = Recepient_ID
        msg['Subject'] = subject
        msg.attach(MIMEText(message, 'html'))

        # Setup for the attachment
        path = latest_file
        try:
            with open(path, "rb") as f:
                file_name = f.name
                part = MIMEBase('application', 'octet-stream')
                part.set_payload(f.read())
                encoders.encode_base64(part)
                part.add_header('Content-Disposition', "attachment; filename= %s" % file_name)
                # Attach the attachment to the MIMEMultipart object
                msg.attach(part)
        except Exception:
            print("Could not attach file %s" % file_name)

        # initialize connection to our email server, gmail here
        server = smtplib.SMTP('smtp.gmail.com', 587)

        # starttls (Transport Layer Security). All SMTP commands will be encrypted which provides  extra layer of seurity.
        server.starttls()

        # Login with email id and password
        server.login(email, password)

        try:
            # mail sending and its parameters
            server.sendmail(from_addr=email, to_addrs=Recepient_ID, msg=msg.as_string())
            print('Email to {} successfully sent!\n'.format(Recepient_ID))

        except Exception as e:
            print('Error : Email to {} could not be sent :( because {}\n'.format(Recepient_ID, str(e)))

        # SMTP Connection close
        server.quit()

    else:
        print("Error : Enter correct Email_ID. Mail can not be sent.")

def RemoveDuplicate(Dict,Log_Dir_Name = "Marvellous"):
    if not os.path.exists(Log_Dir_Name):
        try:
            os.mkdir(Log_Dir_Name)
        except:
            pass
    flag = os.path.isabs(Log_Dir_Name)
    if flag == False:
        path = os.path.abspath(Log_Dir_Name)
    log_path = os.path.join(path,"Deleted_File_Log_%s.log"%datetime.datetime.now().strftime("%d_%m_%y_%H_%M_%S"))
    print("Check log file in directory loacated at : ",log_path)
    separator = "-" * 80

    fd = open(log_path,'w')
    fd.write(separator+'\n')
    fd.write("Deleted file names on : %s"%datetime.datetime.now() + '\n')
    fd.write(separator+'\n')

    results = list(filter(lambda x: len(x) > 1, Dict.values()))
    DupFileCount = 0

    if len(results) >= 1:
        confirm = input("Do you realy want to delete duplicate files : Press 'Y' for yes and 'N' for no : ")
        if(confirm == 'Y') or (confirm == 'y'):
            for result in results:
                for subresult in result:
                    DupFileCount += 1
                    if(DupFileCount > 1):
                        os.remove(subresult)
                        fd.write(subresult+'\n')
                DupFileCount = 0
        elif(confirm == 'N') or (confirm == 'n'):
            print("Removal process terminated by user\n")
            exit()
    else:
        fd.write("No duplicate files found\n")
    fd.close()
    
def HashFile(path,blocksize = 1024):
    fd = open(path,'rb')
    hasher = hashlib.md5()
    buf = fd.read(blocksize)

    while(len(buf) > 0):
        hasher.update(buf)
        buf = fd.read(blocksize)
    fd.close()
    return hasher.hexdigest()

def FindDuplicates(Dir_Name):

    flag = os.path.isabs(Dir_Name)
    
    if flag == False:
        path = os.path.abspath(Dir_Name)

    exists = os.path.isdir(path)
    Duplicates = {}
    
    if exists:
        for dirName,subDir,fileName in os.walk(path):
            for file in fileName:
                path = os.path.join(dirName,file)
                file_hash = HashFile(path)
                if file_hash in Duplicates:
                    Duplicates[file_hash].append(path)
                else:
                    Duplicates[file_hash] = [path]
        RemoveDuplicate(Duplicates)
    else:
        print("Invalid path")

def main():
    print("-----Automation script started-----")
    print("Application name : ",argv[0])
    print("Use '-h' for HELP and '-u' for USAGE of script")

    if(len(argv) > 1):

        if(argv[1] == '-h' or argv[1] == '-H'):
            print("Help : This script is used to delete all duplicate files present in the specified directory path and creat log & send the log on speicified email id. We can schedule this script after every X minutes that specified by user")
            exit()

        if (argv[1] == '-u' or argv[1] == '-U'):
            print("Usage : python Application_Name Diectory_Name Schedule_Time_In_Minutes Recepient_Email_ID")
            print("Example : python xyz.py \"E:Data\Demo\" 60 abcde@jkl.com")
            exit()

        if(len(argv) != 4):
            print("Invalid number of arguments. Needs 4 given ",len(argv))
            exit()

        try:
            schedule.every(int(argv[2])).minutes.do(FindDuplicates,argv[1])
            schedule.every(int(argv[2])).minutes.do(SendLog, argv[1], argv[3])

            while (True):
                schedule.run_pending()
                time.sleep(1)

        except ValueError:
            print("Error : Invalid datatype of input")

        except Exception as E:
            print("Error : Invalid input ", E)

if __name__ == "__main__":
    main()