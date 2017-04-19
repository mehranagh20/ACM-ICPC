import re
while True:
    str = input()
    if str == "*":
        break
    str = str.lstrip().rstrip()
    if re.match("^(([+-]?\d+)(\.\d+)?([eE][-+]?\d+)?)$",str) and ('.' in str or 'e' in str or 'E' in str):
        print("%s is legal." % (str))
    else:
        print("%s is illegal." % (str))
