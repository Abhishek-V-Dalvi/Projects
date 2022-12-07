import psutil

def ProcessDisplay():
    listpeocess = []

    for proc in psutil.process_iter():
        try:
            pinfo = proc.as_dict(attrs = ['pid','name','username'])
            pinfo['vms'] = proc.memory_info().vms / (1024*1024)

            listpeocess.append(pinfo);

        except (psutil.NoSuchProcess,psutil.AccessDenied, psutil.ZombieProcess):
            pass

    return listpeocess

def main():
    print("Python Automation Script")
    print("Process Monitor With Memory")

    listprocess = ProcessDisplay()

    for elem in listprocess:
        print(elem)

if __name__ == "__main__":
    main()