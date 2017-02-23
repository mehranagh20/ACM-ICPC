import re
while True:
    try:
        str = re.sub("[^a-zA-Z]", " ", input())
        print(len(str.split()))
    except:
        break
