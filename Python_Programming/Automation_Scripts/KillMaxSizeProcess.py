import psutil
from sys import *
import os
import datetime
import signal

def KillMaxSizeProc(listprocess1,Dir_Name):
    if not os.path.exists(Dir_Name):
        try:
            os.mkdir(Dir_Name)
        except:
            pass
    flag = os.path.isabs(Dir_Name)
    if flag == False:
        path = os.path.abspath(Dir_Name)

    log_path = os.path.join(Dir_Name,"AbhiProcessLog%s.log"%(datetime.datetime.now().strftime("%d_%m_%y_%H_%M_%S")))

    separator = "-" * 65

    fd = open(log_path,'w')
    fd.write(separator+'\n')
    fd.write("Running process on System on : %s"%datetime.datetime.now() + '\n')
    fd.write(separator + '\n')

    for elem in listprocess1:
        fd.write("%s\n"%elem)
    fd.write("\n\nKilled process with maximum  memory usage is mentioned below -\n ")
    delete_process = listprocess1[0]
    delete_pid = listprocess1[0]['pid']

    os.kill(delete_pid,signal.SIGINT)

    fd.write("%s"%delete_process)
    fd.close()

def UserInitiatedProcList():
    listprocess = []
    user = os.getlogin()

    for proc in psutil.process_iter([]):
        try:
            pinfo = proc.as_dict(attrs = ['pid','name','username'])
            pinfo['vms'] = proc.memory_info().vms / (1024*1024)
    
            try:
                if user in pinfo['username']:
                    listprocess.append(pinfo)
            except TypeError as t:
                pass

        except (psutil.NoSuchProcess,psutil.AccessDenied, psutil.ZombieProcess):
            pass
    listprocess = sorted(listprocess, key=lambda procObj: procObj['vms'], reverse=True)
    return listprocess

def main():
    print("Python Automation Script")
    print("Application name : " + argv[0])
    print("Use '-h' for help and '-u' for usage")

    if (len(argv) != 2):
        print("Error : Invalid number of argumenta")
        exit()

    if ((argv[1] == "-h") or (argv[1] == "-H")):
        print("This application is used to kill max size process running on the system which is initiated by user and create a log file of all the running processes.")
        exit()

    if ((argv[1] == "-u") or (argv[1] == "-U")):
        print("Usage : Application need two arguments")
        print("First Argument : Application_Name")
        print("Second Argument : AbsolutePath_of_Directory")
        print("Example : python xyz.py Demo")
        exit()

    try:
        Result = UserInitiatedProcList()
        KillMaxSizeProc(Result,argv[1])

    except ValueError:
        print("Error : Invalid datatype of input")

    except Exception:
        print("Error : Invalid input")

if __name__ == "__main__":
    main()