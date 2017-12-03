import sys
import random

MAX_R = 1000
MAX_D = 25
MAX_K = 20
MAX_C = 2000
MAX_B = 100

case_no = 1

def next_file(suffix=None, desc=None):
    global case_no
    basename = '%02d' % case_no if suffix is None else '%02d-%s' % (case_no, suffix)
    f = open(basename + '.in', 'w')
    if desc is not None:
        with open(basename + '.desc', 'w') as df:
            df.write('%s\n' % desc)
    case_no += 1
    return f

def write_case(ingreds, starters, mains, desserts, conflicts, suffix=None, desc=None):
    f = next_file(suffix, desc)
    f.write('%d %d %d %d %d\n' % (len(ingreds), len(starters), len(mains), len(desserts), len(conflicts)))
    f.write('%s\n' % ' '.join(map(str, ingreds)))
    for d in starters + mains + desserts:
        f.write('%d %s\n' % (len(d), ' '.join(map(str, d))))
    for (a,b) in conflicts:
        f.write('%d %d\n' % (a,b))
    f.close()


def random_dish(r, min_k, max_k):
    idxs = range(1,r+1)
    k = random.randint(min_k, max_k)
    random.shuffle(idxs)
    return idxs[:k]

def gen_random(r, s, m, d, c, max_b, max_k, min_b=1, min_k=1):
    ingreds = [random.randint(min_b, max_b) for i in range(r)]
    dishes = [random_dish(r, min_k, max_k) for i in range(s+m+d)]
    conf = []
    for i in range(c):
        while True:
            t1 = random.randint(0,2)
            t2 = (t1+random.randint(1,2)) % 3
            a = random.randint(1, [s,m,d][t1]) + [0,s,s+m][t1]
            b = random.randint(1, [s,m,d][t2]) + [0,s,s+m][t2]
            if (a,b) not in conf and (b,a) not in conf:
                break
        conf.append((a,b))
    write_case(ingreds, dishes[:s], dishes[s:s+m], dishes[s+m:], conf, suffix='random', desc='random case with %d ingreds, %d starters, %d mains, %d desserts, %d conflicts' % (r, s, m, d, c))

def gen_special():
    # answer = 10^18
    ingreds = [5]*18 + [2]*18
    random.shuffle(ingreds)
    s = m = d = 1
    starters = [list(set(range(1,13) + random_dish(len(ingreds), 1, MAX_K-12))) for i in range(s)]
    mains = [list(set(range(13,25) + random_dish(len(ingreds), 1, MAX_K-12))) for i in range(m)]
    desserts = [list(set(range(25,37) + random_dish(len(ingreds), 1, MAX_K-12))) for i in range(d)]
    write_case(ingreds, starters, mains, desserts, [], suffix='maxans', desc='answer = 10^18')

    # answer = 19*10^18 (19 terms of value 10^18, should take out some overflow errs)
    ingreds = [5]*18 + [2]*18
    random.shuffle(ingreds)
    ingres = ingreds + [1]*42
    s = 1
    m = 1
    d = 19
    starters = [list(set(range(1,13) + random_dish(len(ingreds), 1, MAX_K-12))) for i in range(s)]
    mains = [list(set(range(13,25) + random_dish(len(ingreds), 1, MAX_K-12))) for i in range(m)]
    desserts = [list(set(range(25,37) + random_dish(len(ingreds), 1, MAX_K-12))) for i in range(d)]
    write_case(ingreds, starters, mains, desserts, [], suffix='overflow', desc='answer = 19*10^18 -- 19 terms of value 10^18')

    # answer = 10^18 (but with 25x25x25 dish combos)
    # note this has a bunch of constants hard-coded to MAX_D=25
    ingreds = [5]*12 + [2]*18
    random.shuffle(ingreds)
    ingreds = ingreds + [1]*123
    s = m = d = MAX_D
    starters = [list(set(range(1,11) + random_dish(len(ingreds), 1, MAX_K-10))) for i in range(s)]
    mains = [list(set(range(11,21) + random_dish(len(ingreds), 1, MAX_K-10))) for i in range(m)]
    desserts = [list(set(range(21,31) + random_dish(len(ingreds), 1, MAX_K-10))) for i in range(d)]
    write_case(ingreds, starters, mains, desserts, [], suffix='maxans', desc='ans = 10^18, coming from 25^3 different dish combos')

    # answer = 10^18+1
    ingreds = [5]*18 + [2]*18
    random.shuffle(ingreds)
    ingreds = ingreds + [1]*(3*MAX_K)
    s = m = d = 1
    starters = [list(set(range(1,13) + random_dish(len(ingreds), 1, MAX_K-12))) for i in range(s)] + [range(37, 37+MAX_K)]
    mains = [list(set(range(13,25) + random_dish(len(ingreds), 1, MAX_K-12))) for i in range(m)] + [range(37+MAX_K, 37+2*MAX_K)]
    desserts = [list(set(range(25,37) + random_dish(len(ingreds), 1, MAX_K-12))) for i in range(d)] + [range(37+2*MAX_K, 37+3*MAX_K)]
    conf = [(1,4), (6, 3), (2, 5)]
    write_case(ingreds, starters, mains, desserts, conf, suffix='overflow', desc='ans = 10^18 + 1')

    gen_1875()

    # overflow, but all partial products when multiplied as longs are
    # within range
    ingreds = [92, 92, 92, 92, 79, 92, 92, 92, 92, 92]
    starters = [random_dish(len(ingreds), 1, MAX_K)]
    mains = [range(1, len(ingreds)+1)]
    desserts = [random_dish(len(ingreds), 1, MAX_K)]
    write_case(ingreds, starters, mains, desserts, [], suffix='overflow', desc='overflow, but when computing with signed 64-bit integers,\neach partial product is larger than the previous, and smaller than 10^18')

    # similar case as before but kills a solution that (for whatever
    # reason...) multplies the numbers from largest to smallest
    ingreds = [38, 38, 38, 38, 38, 80, 38, 38, 38, 38, 38, 38]
    write_case(ingreds, starters, mains, desserts, [], suffix='overflow', desc='overflow, but when computing with signed 64-bit integers,\neach partial product is larger than the previous, and smaller than 10^18')



def gen_1875():
    # answer = 0
    ingreds = [1]*1
    starters = [[1]]*25
    mains = starters
    desserts = starters
    
    conf=[];
    for i in range(1,26): 
	for j in range(1,26): 
            conf.extend([(i,j+25), (i,j+50), (i+25, j+50)])

    write_case(ingreds, starters, mains, desserts, conf, suffix='maxconf', desc='all pairs of dishes in conflict')


random.seed(42)

gen_special()

gen_random(17, 5, 9, 8, 23, 5, 11)
for i in range(25):
    r = random.randint(1, MAX_R)
    s = random.randint(1, MAX_D)
    m = random.randint(1, MAX_D)
    d = random.randint(1, MAX_D)
    max_c = min(s*m+m*d+s*d, MAX_C)
    c = random.randint(0, max_c)
    max_b = random.randint(1, 20)
    max_k = random.randint(1, MAX_K)
    gen_random(r, s, m, d, c, max_b, max_k)

gen_random(MAX_R, MAX_D, MAX_D, MAX_D, 0, 2, MAX_K, min_k=MAX_K)
gen_random(MAX_R, MAX_D, MAX_D, MAX_D, 0, MAX_B, MAX_K, min_k=MAX_K, min_b=MAX_B)
gen_random(MAX_R, MAX_D, MAX_D, MAX_D, MAX_D*MAX_D*3/2, 2, MAX_K, min_k=MAX_K)
gen_random(MAX_R, MAX_D, MAX_D, MAX_D, MAX_D*MAX_D*3/2, MAX_B, MAX_K, min_k=MAX_K, min_b=MAX_B)
gen_random(MAX_R, MAX_D, MAX_D, MAX_D, MAX_D*MAX_D*3-3*MAX_D, 2, MAX_K, min_k=MAX_K)
gen_random(MAX_R, MAX_D, MAX_D, MAX_D, MAX_D*MAX_D*3-3*MAX_D, MAX_B, MAX_K, min_k=MAX_K, min_b=MAX_B)
