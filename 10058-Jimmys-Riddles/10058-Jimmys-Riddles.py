ver = ['hates', 'loves', 'knows', 'likes', 'hate', 'love', 'know', 'like']
non = ['tom', 'jerry', 'goofy', 'mickey', 'jimmy', 'dog', 'cat', 'mouse']
art = ['a', 'the']
act = non[:]
for i in art:
    for j in non:
        act.append(i + ' ' + j)
def is_active_list(str):
    str = str.rstrip().lstrip()
    l = str.rsplit('and', 1)
    for i in range(len(l)):
        l[i] = l[i].rstrip().lstrip()
    if len(l) == 0:
        return False
    if(len(l) == 1):
        return (l[0] in act)
    else:
        return is_active_list(l[0]) and l[1] in act

def is_action(str):
    str = str.rstrip().lstrip()
    for v in ver:
        if v in str:
            l = str.split(v)
            for i in range(len(l)):
                l[i] = l[i].rstrip().lstrip()
            if len(l) != 2:
                return False
            return is_active_list(l[0]) and is_active_list(l[1])
    return False

def is_statement(str):
    str = str.rstrip().lstrip()
    l = str.rsplit(',', 1)
    for i in range(len(l)):
        l[i] = l[i].rstrip().lstrip()
    if len(l) == 1:
        return is_action(l[0])
    elif len(l) == 2:
        return is_action(l[1]) and is_statement(l[0])
    else:
        return False

while True:
    try:
        str = input()
        a = 'YES I WILL' if is_statement(str) else "NO I WON'T"
        print(a)

    except:
        break
