from sys import *
import os
import schedule
import datetime
import time
import sqlite3
'''
This module is used to integrate SQLITE data base with python. It is standardize DB-API. Module comes after python version
2.5 and above.
'''
def DeleteBrowsingHistory(url1, Log_Dir = "HistoryLog"):
    if not os.path.exists(Log_Dir):
        try:
            os.mkdir(Log_Dir)
        except:
            pass
    flag = os.path.isabs(Log_Dir)
    if flag == False:
        path = os.path.abspath(Log_Dir)
    log_path = os.path.join(path,"Deleted_History_Log_%s.log"%datetime.datetime.now().strftime("%d_%m_%y_%H_%M_%S"))
    print("Check log file in directory loacated at : ",log_path)
    separator = "-" * 80

    fd = open(log_path,'w')
    fd.write(separator+'\n')
    fd.write("Deleted History on : %s"%datetime.datetime.now() + '\n')
    fd.write(separator+'\n')

    #connect method is used to connect with our database named as History on the below mentioned path
    #We need to provide absolute path otherwise it will search in curent directory
    #Created the object conn returned by connect method
    conn = sqlite3.connect("C:\\Users\\lenovo\\AppData\\Local\\Google\\Chrome\\User Data\\Default\\History")

    #To point out in our database cursor method is used
    #It points one set of record at a time
    #Cursor is used to traverse the records in database
    c = conn.cursor()

    id = 0

    result = True
    while result:
        result = False

        #Empty list
        ids = []

        #In bracket SQLITE query same like MySQL ex: "Select rollno from student where marks>60"
        #id - It is the primary key here
        #slecting url from many urls where our input string is exist
        #Execute is used to pass query to DB
        #Place holder can be used instead {}
        for rows in c.execute("SELECT id,url FROM urls WHERE url LIKE '%{}%'".format(url1)):
            fd.write(str(rows)+'\n')
            id = rows[0]

            #append search result in the empty list of ids
            ids.append((id,))

        #Below command will delete the search history. IF there are more than 1 search result then many word will delete all search results
        #Need to give query as a parameter
        # it is same like iterator of execte function
        c.executemany('DELETE from urls WHERE id = ?',ids)

        # This method will execute the given command
        conn.commit()

    # Like SMTP and fileIO we need to close the connection with our DB
    conn.close()
    fd.close()
    print("History of "+ url1 +" successfuly deleted at: " + time.ctime())

def main():
    print("----------Automations using Python Programming----------")
    print("Automation script started with name : ",argv[0])

    if(len(argv) != 2):
        print("Error : Insuficient arguments")
        print("Use -h for help")
        print("use -u for usage of script")
        exit()
        
    if((argv[1] == "-h") or (argv[1] == "-H")):
        print("Help : This script is used to clear browsing history of a perticular website")
        exit()

    elif ((argv[1] == "-u") or (argv[1] == "-U")):
        print("Usage : Provide 2 number of arguments as")
        print("First argument as    : Application_Name")
        print("Second argument as   : Facebook")
        print("Example : python Application_Name Facebook")
        exit()

    else:
        try:
            schedule.every().day.at("06:00:00").do(DeleteBrowsingHistory,argv[1])
            #schedule.every(10).seconds.do(DeleteBrowsingHistory,argv[1])
            while (True):
                schedule.run_pending()
                time.sleep(1)
                
        except Exception as e:
            print(e)

if __name__ == "__main__":
    main()