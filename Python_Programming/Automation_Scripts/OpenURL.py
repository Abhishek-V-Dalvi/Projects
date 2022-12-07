from sys import *
import re
import webbrowser
from urllib.request import urlopen

def is_connected():
    try:
        urlopen('http://google.com',timeout=1)
        return True
    except URLError as err:
        return False

def Find(string):
    url = re.findall('http[s]?://(?:[a-zA-Z]|[0-9]|[$-_@.&+]|[!*\(\),]|(?:%[0-9a-fA-F][0-9a-fA-F]))+',string)
    return url

def WebLauncher(path):
    with open(path) as fp:
        for line in fp:
            url = Find(line)
            for str in url:
                webbrowser.open(str, new = 2)

def main():
    print("----------Automations using Python Programming----------")
    print("Automation name : ", argv[0])

    if (len(argv) != 2):
        print("Error : Insuficient arguments")
        print("Use -h for help")
        print("use -u for usage of script")
        exit()

    if ((argv[1] == "-h") or (argv[1] == "-H")):
        print("Help : This script is used to open all URL's present in one file")
        exit()

    elif ((argv[1] == "-u") or (argv[1] == "-U")):
        print("Usage : Provide 2 number of arguments as")
        print("First argument as    : Application_Name")
        print("Second argument as   : Aboslute_path_of_file")
        exit()

    else:
        try:
            connected = is_connected()

            if connected:
                WebLauncher(argv[1])
            else:
                print("Unable to connect to internet.")

        except ValueError:
            print("Error : Invalid datatype of input")

        except Exception as e:
            print("Error : Invalid input",e)

if __name__ == "__main__":
    main()