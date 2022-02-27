import requests

data = requests.get("https://commandweb.herokuapp.com/versions/")

json_data = data.json()

length = len(json_data)

newWorkingversion = json_data[length-1]["workingVersion"]

f = open("versionCC.txt", "r")
existVersion = f.read()
f.close()

if (newWorkingversion == existVersion):
    print("No need to update")

else:
    w = open("newVersion.txt", "w")
    w.write(newWorkingversion)
    w.close()