import smtplib
from email.mime.text import MIMEText
from email.mime.multipart import MIMEMultipart
from email.mime.base import MIMEBase
from email import encoders
import os
from sys import *

def Send_Email(Dir_Name):
    email = 'abhi.dlv007@gmail.com'
    password = input("Enter password : ")
    Receipient_list = ["abhidalvi195@gmail.com"]       #This list contains multiple receipients email id
    subject = 'Email by Automation Script Multiple receipients and attachments'
    message = """
    <html>
        <body>
            <p>Hello sir,<br>
            Good afternoon.😀<br>
            I am sending this email to multiple receipients with automated script and attaching multiple files present in my secondary storage device.<br>
            Folder name is taken from user with commad line argument<br>
            <p style="color:blue;"><b><i>Aayushya khup sundar aahe fakt programming jamal pahije....😎</i></b><br></p>
            <p style="color:blue;"><b><i>Piyush siranchi krupa...🙏</i></b><br></p>
    
            Thanks & Regards,<br>
            Abhishek Dalvi<br>
            📱Mob: +91-8087450882<br>
            </p>
        </body>
    </html>
    
    """
    flag = os.path.isabs(Dir_Name)
    if flag == False:
        file_location = os.path.abspath(Dir_Name)

    msg = MIMEMultipart()
    msg['From'] = email
    msg['To'] = ', '.join(Receipient_list)  #To insert multiple email id's with separated by ','
    msg['Subject'] = subject

    msg.attach(MIMEText(message, 'html'))

    # Setup for the attachment
    for each_file in os.listdir(file_location):
        path = os.path.join(file_location,each_file)    #Each file path in path variable
        try:
            with open(path,"rb") as f:
                file_name = f.name
                part = MIMEBase('application', 'octet-stream')
                part.set_payload(f.read())
                encoders.encode_base64(part)
                part.add_header('Content-Disposition', "attachment; filename= %s" % file_name)
                # Attach the attachment to the MIMEMultipart object
                msg.attach(part)
        except Exception:
            print("Could not attach file %s" %file_name)

    # initialize connection to our email server, gmail here
    server = smtplib.SMTP('smtp.gmail.com', 587)

    #starttls (Transport Layer Security). All SMTP commands will be encrypted which provides  extra layer of seurity.
    server.starttls()

    # Login with email id and password
    server.login(email, password)

    #mail sending and its parameters
    server.sendmail(from_addr= email,to_addrs=Receipient_list, msg=msg.as_string())

    #SMTP Connection close
    server.quit()

    print("Email sent")

def main():

    print("Automation script started with name : ", argv[0])

    if ((len(argv) != 2)):
        print("Error : Invalid number of arguments")
        print("Use -h for help and use -u for usage of the script")
        exit()

    if ((argv[1] == "-h") or (argv[1] == "-H")):
        print(
            "Help : This script is used to send email automatically through script.")
        exit()

    elif ((argv[1] == "-u") or (argv[1] == "-U")):
        print("Usage : Provide 1 number of arguments as")
        print("First Argument as : <Application_Name>")
        print("Second Argument as : <Directory_Path>")
        print("Example : python xyz.py \"Demo\"")
        exit()

    else:
        try:
            Send_Email(argv[1])

        except ValueError:
            print("Error : Invalid datatype of input")

        except Exception:
            print("Error : Invalid input")

if __name__ == "__main__":
    main()