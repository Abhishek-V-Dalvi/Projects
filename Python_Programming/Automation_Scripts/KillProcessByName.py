'''
Design a automation script which accepts process name and kill the process if it is running.

Usage : ProcInfo.py Notepad.exe
'''

import psutil
from sys import *
import schedule
import time

def KillProcess(Process_Name):
    flag = False
    for proc in psutil.process_iter([]):
        try:
            if Process_Name.lower() in proc.name().lower():
                proc.kill()
                flag = True

        except (psutil.NoSuchProcess,psutil.AccessDenied, psutil.ZombieProcess):
            pass
        
    if flag == True:
        print(Process_Name + " killed successfully.")

    else:
        print("No such process is running")

def main():
    print("Python Automation Script")
    print("Application name : " + argv[0])
    print("Use '-h' for help and '-u' for usage")

    if (len(argv) != 2):
        print("Error : Invalid number of argumenta")
        exit()

    if ((argv[1] == "-h") or (argv[1] == "-H")):
        print("This process is used to display information about the process if it is running whose name is provided by user.")
        exit()

    if ((argv[1] == "-u") or (argv[1] == "-U")):
        print("Usage : ApplicationName  Process_Name")
        print("Example : python xyz.py notepad.exe")
        exit()

    try:
        schedule.every(60).minutes.do(KillProcess,argv[1])

        while True:
            schedule.run_pending()
            time.sleep(1)

    except ValueError:
        print("Error : Invalid datatype of input")

    except Exception:
        print("Error : Invalid input")

if __name__ == "__main__":
    main()