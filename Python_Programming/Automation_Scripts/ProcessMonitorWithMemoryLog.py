import os
import psutil
import time
from sys import *
import datetime


def ProcessDisplay(log_dir = "AbhiLog"):
    listprocess = []

    if not os.path.exists(log_dir):
        try:
            os.mkdir(log_dir)
        except:
            pass

    separator = "-" * 80

    log_path = os.path.join(log_dir,"AbhishekProcessLog%s.log"%(datetime.datetime.now().strftime("%d_%m_%y_%H_%M_%S")))
    f = open(log_path,'w')
    f.write(separator + "\n")
    f.write("Abhishek's PC Process Log : "+time.ctime() + "\n")
    f.write(separator + "\n")

    for proc in psutil.process_iter():
        try:
            pinfo = proc.as_dict(attrs = ['pid','name','username'])
            vms = proc.memory_info().vms / (1024*1024)
            pinfo['vms'] = vms
            listprocess.append(pinfo);
        except (psutil.NoSuchProcess,psutil.AccessDenied, psutil.ZombieProcess):
            pass

    for element in listprocess:
            f.write("%s\n"%element)

def main():
    print("Python Automation Script")
    print("Application name : "+argv[0])

    if(len(argv) != 2):
        print("Error : Invalid number of argumenta")
        exit()

    if ((argv[1] == "-h") or (argv[1] == "-H")):
        print("This process is used to record log of running processess")
        exit()

    if ((argv[1] == "-u") or (argv[1] == "-U")):
        print("Usage : ApplicationName AbsolutePath_of_Directory")
        exit()

    try:
        ProcessDisplay(argv[1])

    except ValueError:
        print("Error : Invalid datatype of input")

    except Exception:
        print("Error : Invalid input")

if __name__ == "__main__":
    main()