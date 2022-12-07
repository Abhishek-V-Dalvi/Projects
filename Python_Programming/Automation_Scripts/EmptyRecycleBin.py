import os
from sys import *
import winshell

def PrintRecycleBin(path = "C:\$Recycle.Bin\S-1-5-21-1938124233-1647532357-726391834-1001"):
    for dirName, subDir, fileName in os.walk(path):
        for file  in fileName:
            print(file)

def main():
    print("-----Automation script started-----")
    print("Use '-h' for help and '-u' for usage")


    if (len(argv) > 2):
        print("Invalid number of argument")
        exit()

    elif (len(argv) == 2):
        if((argv[1] == '-h') or (argv[1] == '-H')):
            print("HELP : This script is used to empty recycle bin")
            exit()

        if (argv[1] == '-u') or (argv[1] == '-U'):
            print("Usage : python Application_Name")
            exit()
    else:
        try:
            #winshell.recycle_bin().empty(confirm=True, show_progress=True, sound=True)
            PrintRecycleBin()

        except Exception as e:
            print(e)

if __name__ == "__main__":
    main()
    