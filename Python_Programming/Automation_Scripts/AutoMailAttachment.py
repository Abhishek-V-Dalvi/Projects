import smtplib
from email.mime.text import MIMEText
from email.mime.multipart import MIMEMultipart
from email.mime.base import MIMEBase
from email import encoders
import os.path

email = 'abhi.dlv007@gmail.com'
password = input("Enter password : ")
send_to_email = 'abhidalvi195@gmail.com'
subject = 'Duplicate file removal log Today'
message = """
Hello sir,
Good morning.😀
I am sending this email with automated script and attaching one log file present in my secondary storage device.
Aayushya khup sundar aahe fakt programming jamal pahije....😎
Piyush siranchi krupa...🙏

Thanks & Regards,
Abhishek Dalvi
📱Mob: +91-8087450882
"""

file_location = 'F:\\Abhi\\Marvellous\\Python\\Assignment\\Answer\\Assignment - 11\\Log_Duplicate_Files_Removed_16_11_22_17_02_17.txt'

msg = MIMEMultipart()
msg['From'] = email
msg['To'] = send_to_email
msg['Subject'] = subject

msg.attach(MIMEText(message, 'plain'))

# Setup the attachment
filename = os.path.basename(file_location)
attachment = open(file_location, "rb")
part = MIMEBase('application', 'octet-stream')
part.set_payload(attachment.read())
encoders.encode_base64(part)
part.add_header('Content-Disposition', "attachment; filename= %s" % filename)

# Attach the attachment to the MIMEMultipart object
msg.attach(part)

server = smtplib.SMTP('smtp.gmail.com', 587)
server.starttls()
server.login(email, password)
text = msg.as_string()
server.sendmail(email, send_to_email, text)
server.quit()