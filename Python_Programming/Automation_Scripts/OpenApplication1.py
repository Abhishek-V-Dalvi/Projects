import subprocess
import os

def OpenApplicationX(id):
	if(id == 'ls'):
		print("""
		1	-	notepad				
		2	-	snippingtool		
		3	-	adobereader
		4	-	googlechrome		
		5	-	edge				
		6	-	vscode
		7	-	notepad++			
		8	-	pycharm				
		10	-	zoom
		11	-	word				
		12	-	ppt					
		13	-	excel
		14	-	paint				
		15	-	Calculator			
		16	-	controlpanel
		17	-	gomplayer			
		18	-	mediaplayer			
		0	-	exit
		""")

	elif(id == '1') or (id.lower() == 'notepad'):
		subprocess.call(r"C:\Windows\System32\notepad.exe")
		print("notepad open successfully")
		print(" ")

	elif(id == '2') or (id.lower() == 'snippingtool'):
		subprocess.call(r"C:\Windows\System32\SnippingTool.exe")
		print("SnippingTool open successfully")
		print(" ")

	elif (id == '3') or (id.lower() == 'adobereader'):
		subprocess.call(r"C:\Program Files\Adobe\Acrobat DC\Acrobat\Acrobat.exe")
		print("AdobeAcrobatReader open successfully")
		print(" ")

	elif (id == '4') or (id.lower() == 'googlechrome'):
		subprocess.call(r"C:\Program Files (x86)\Google\Chrome\Application\chrome.exe")
		print("Google chrome open successfully")
		print(" ")

	elif (id == '5') or (id.lower() == 'edge'):
		subprocess.call(r"C:\Program Files (x86)\Microsoft\Edge\Application\msedge.exe")
		print("Microsoft edge open successfully")
		print(" ")

	elif (id == '6') or (id.lower() == 'vscode'):
		subprocess.call(r"C:\Users\lenovo\AppData\Local\Programs\Microsoft VS Code\Code.exe")
		print("Microsoft Visual Studio Code open successfully")
		print(" ")

	elif (id == '7') or (id.lower() == 'notepad++'):
		subprocess.call(r"C:\Program Files\Notepad++\notepad++.exe")
		print("Notepad++ open successfully")
		print(" ")

	elif (id == '8') or (id.lower() == 'pycharm'):
		subprocess.call(r"C:\Program Files\JetBrains\PyCharm Community Edition 2022.2.3\bin\pycharm64.exe")
		print("PyCharm open successfully")
		print(" ")

	elif (id == '10') or (id.lower() == 'zoom'):
		subprocess.call(r"C:\Users\lenovo\AppData\Roaming\Zoom\bin\Zoom.exe")
		print("Zoom open successfully")
		print(" ")

	elif (id == '11') or (id.lower() == 'word'):
		subprocess.call(r"C:\Program Files (x86)\Microsoft Office\root\Office16\WINWORD.exe")
		print("Microsofr Word open successfully")
		print(" ")

	elif (id == '12') or (id.lower() == 'ppt'):
		subprocess.call(r"C:\Program Files (x86)\Microsoft Office\root\Office16\POWERPNT.EXE")
		print("Microsofr PowerPoint open successfully")
		print(" ")

	elif (id == '13') or (id.lower() == 'excel'):
		subprocess.call(r"C:\Program Files (x86)\Microsoft Office\root\Office16\EXCEL.EXE")
		print("Microsofr Excel open successfully")
		print(" ")

	elif (id == '14') or (id.lower() == 'paint'):
		subprocess.call(r"C:\Windows\System32\mspaint.exe")
		print("Microsofr Paint open successfully")
		print(" ")

	elif (id == '15') or (id.lower() == 'calculator'):
		subprocess.call(r"C:\Windows\System32\calc.exe")
		print("Calculator open successfully")
		print(" ")

	elif (id == '16') or (id.lower() == 'controlpanel'):
		subprocess.call(r"C:\Windows\System32\control.exe")
		print("Control panel open successfully")
		print(" ")

	elif (id == '17') or (id.lower() == 'gomplayer'):
		subprocess.call(r"C:\Program Files (x86)\GOM\GOMPlayer\GOM.exe")
		print("GOM player open successfully")
		print(" ")

	elif (id == '18') or (id.lower() == 'mediaplayer'):
		subprocess.call(r"C:\Program Files (x86)\Windows Media Player\wmplayer.exe")
		print("Windows media player open successfully")
		print(" ")

	elif (id == '0')or (id.lower() == 'exit'):
		exit()

	else:
		print("Invalid input. Please try again.")
		print(" ")

def main():
	print(" =================================== Python Script for App opening is running ===================================")
	print("")
	print(" This application is use to open below apps")

	print("")
	print("""	\n\t1 - notepad \t\t2 - snippingtool \t3 - adobereader 
				\n\t4 - googlechrome \t5 - edge \t\t6 - vscode
				\n\t7 - notepad++ \t\t8 - pycharm \t\t10 - zoom
				\n\t11 - word \t\t12 - ppt \t\t13 - excel
				\n\t14 - paint \t\t15 - Calculator \t16 - controlpanel
				\n\t17 - gomplayer \t\t18 - mediaplayer \t0 - exit
			""")
	print("")
	print(" Enter number or text to open the application")
	print(" Enter 'ls' for list of applications")
	print(" ================================================================================================================")

	while True:
		input_App = input("Enter the application name or id : ")
		OpenApplicationX(input_App)

if __name__ == "__main__":
	main()