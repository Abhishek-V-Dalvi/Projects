from sys import *
import time
import winshell
import schedule

def EmptyBin():
    winshell.recycle_bin().empty(confirm=True, show_progress=True, sound=True)

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
            #schedule.every().day.at("11:00:00").do(EmptyBin)
            schedule.every(10).seconds.do(EmptyBin)
            while (True):
                schedule.run_pending()
                time.sleep(1)

        except Exception as e:
            print(e)

if __name__ == "__main__":
    main()