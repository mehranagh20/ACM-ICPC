# -*- coding: utf-8 -*-
"""
Created on Fri Oct 09 11:06:44 2015

@author: z002pf5y
"""

import numpy as np

class test_generator(object):
    
    def __init__(self):
        self.num_test = 0
    
    """
        Random test
    """    
    def random (self, name, n, k):
        ref = np.zeros ((k, 2), 'uint32')
        atlas = np.zeros ((k, n, 2), 'uint32')
        lens = np.zeros ((k), 'uint32')
        
        v = np.zeros ((n,2), 'uint32')
        
        for i in range (0, k):
            ref[i][0] = 20000 + np.random.randint (10000)
            ref[i][1] = ref[i][0] + 1000 + np.random.randint (10000)
            atlas[i][0][0] = ref[i][0]
            atlas[i][0][1] = ref[i][1]
            lens[i] += 1            
            
        for i in range (k, n):
            pool = np.random.randint (k)
            
            left_bias = np.random.randint (10000)
            right_bias = np.random.randint (10000)
            
            atlas[pool][lens[pool]][0] = ref[pool][0] - left_bias
            atlas[pool][lens[pool]][1] = ref[pool][1] + right_bias

            lens[pool] += 1
                        
        p = 0
        for i in range (0, k):
            for j in range (0, lens[i]):
                v[p] = atlas[i][j]
                p += 1
    
        if p != n:
            raise ValueError ('Wrong interval number in random test')
        
        ans = self.generateOutput (n, k, v)
        
        if ans != 0:
            self.gen_input (name, n, k, v)
            self.gen_output (name, ans)
            self.num_test += 1
        else:
            raise ValueError('Random test failed: ' + str(n) + ' ' + str(k))
            
    """
        Sequence of non-overlapping intervals
    """        
    def unique (self, name, n, k):
        v = np.zeros ((n,2), 'uint32')
        
        jump = 113
        size = 91
        
        for i in range (0, n):
            v[i][0] = (i + 1) * jump
            v[i][1] = (i + 1) * jump + size
            
        ans = self.generateOutput (n, k, v)
        
        if ans != 0:
            self.gen_input (name, n, k, v)
            self.gen_output (name, ans)
            self.num_test += 1
        else:
            raise ValueError('Unique test failed: ' + str(n) + ' ' + str(k))
        
    """
        Staircase structured test
    """
    def staircase (self, name, n, k):
        v = np.zeros ((n,2), 'uint32')
        overlap = int(n / k) + 5
        
        for i in range (0, n):
            v[i][0] = i + 1
            v[i][1] = i + overlap + 1
            
        ans = self.generateOutput (n, k, v)
            
        if ans != 0:
            self.gen_input (name, n, k, v)
            self.gen_output (name, ans)
            self.num_test += 1
        else:
            raise ValueError('Staircaise test failed: ' + str(n) + ' ' + str(k))
                
    """
        pyramid shaped sequence of self including intervals
    """
    def pyramid (self, name, n, k):
        v = np.zeros ((n,2), 'uint32')
        
        for i in range (0, n):
            v[i][0] = 1
            v[i][1] = 2 * (i + 1)
            
        ans = self.generateOutput (n, k, v)
        
        if ans != 0:
            self.gen_input (name, n, k, v)
            self.gen_output (name, ans)
            self.num_test += 1
        else:
            raise ValueError('Pyramid test failed: ' + str(n) + ' ' + str(k))


    """
        Unbalanced random
    """
    def unbalanced_random (self, name, n, k):
        ref = np.zeros ((k, 2), 'uint32')
        atlas = np.zeros ((k, n, 2), 'uint32')
        lens = np.zeros ((k), 'uint32')
        
        v = np.zeros ((n,2), 'uint32')
        
        for i in range (0, k):
            ref[i][0] = 20 + np.random.randint (500)
            ref[i][1] = ref[i][0] + 100 + np.random.randint (500)
            atlas[i][0][0] = ref[i][0]
            atlas[i][0][1] = ref[i][1]
            lens[i] += 1
        
        for i in range (k, n):
            pool = np.random.randint (k)
            
            left_bias = np.random.randint (20)
            right_bias = np.random.randint (98000)
            
            atlas[pool][lens[pool]][0] = ref[pool][0] - left_bias
            atlas[pool][lens[pool]][1] = ref[pool][1] + right_bias
            
            lens[pool] += 1

        p = 0
        for i in range (0, k):
            for j in range (0, lens[i]):
                v[p] = atlas[i][j]
                p += 1

        if p != n:
            raise ValueError ('Wrong interval number in random test')
        
        ans = self.generateOutput (n, k, v)

        if ans != 0:
            self.gen_input (name, n, k, v)
            self.gen_output (name, ans)
            self.num_test += 1
        else:
            raise ValueError('Random test failed: ' + str(n) + ' ' + str(k))

    

    """
        Write input file
    """            
    def gen_input (self, name, n, k, v, subs = True):
        if subs:
            subfolder = '../data/local/'
        else:
            subfolder = ''
        
        with open (subfolder + name + '.in', 'w') as in_file:
            in_file.write (str(n) + ' ' +  str(k) + '\n')
            for i in range (0, n):
                in_file.write (str(v[i][0]) + ' ' + str(v[i][1]) + '\n')
         
    """
        Write output file
    """
    def gen_output (self, name, ans):
        subfolder = '../data/local/'
        
        with open (subfolder + name + '.ans', 'w') as out_file:
            out_file.write(str(ans) + '\n')
        
    
    """
        Generate expected output for given input
    """
    def generateOutput (self, n, k, v):
        import os
        import subprocess
        
        if os.path.exists('current.ans'):
            os.remove ('current.ans')
        
        self.gen_input ('current', n, k, v, False)

        resample_args = [os.path.join(os.getcwd(), "florin")]
        process = subprocess.Popen (resample_args)
        process.wait()
        
        if not os.path.exists ('current.ans'):
            raise ValueError ('Current output file missing.')        
        
        with open ('current.ans', 'r') as file:
            line = file.readline ()
            ans = int (line)
            return ans


    def generate_tests(self):
        """
        self.random ('small_random1', 2, 2)
        self.random ('small_random2', 10, 4)
        self.random ('small_random3', 15, 10)
        self.random ('small_random4', 18, 18)
        self.random ('small_random5', 20, 2)
        self.random ('small_random6', 20, 15)
        
        self.random ('medium_random1', 50, 2)
        self.random ('medium_random2', 50, 45)
        self.random ('medium_random3', 50, 30)
        self.random ('medium_random4', 50, 47)
        self.random ('medium_random5', 80, 40)
        self.random ('medium_random6', 80, 80)
        
        self.random ('large_random1', 180, 10)
        self.random ('large_random2', 200, 20)
        self.random ('large_random3', 200, 100)
        self.random ('large_random4', 180, 100)
        self.random ('large_random5', 200, 190)
        self.random ('large_random6', 200, 200)
        
        # pyramid, staircaise, unique
        
        self.pyramid ('pyramid1', 5, 5)
        self.pyramid ('pyramid2', 20, 5)
        self.pyramid ('pyramid3', 80, 40)
        self.pyramid ('pyramid4', 200, 1)
        self.pyramid ('pyramid5', 200, 194)
        self.pyramid ('pyramid6', 180, 180)
        self.pyramid ('pyramid7', 150, 144)
        self.pyramid ('pyramid8', 200, 20)
        self.pyramid ('pyramid9', 200, 44)
        self.pyramid ('pyramid10', 200, 81)
                
        
        
        self.staircase ('staircaise1', 5, 5)
        self.staircase ('staircaise2', 20, 5)
        self.staircase ('staircaise3', 180, 5)
        self.staircase ('staircaise4', 200, 100)
        self.staircase ('staircaise5', 200, 200)
        
        self.unique ('unique_small', 4, 4)
        self.unique ('unique_small', 200, 200)
        """
        
        self.unbalanced_random ('unbalanced1', 70, 35)
        self.unbalanced_random ('unbalanced2', 100, 15)
        self.unbalanced_random ('unbalanced3', 80, 40)
        self.unbalanced_random ('unbalanced4', 100, 25)
        self.unbalanced_random ('unbalanced5', 100, 50)
        self.unbalanced_random ('unbalanced6', 150, 100)
        self.unbalanced_random ('unbalanced7', 200, 2)
        self.unbalanced_random ('unbalanced8', 200, 50)
        
        
        import os
        os.remove ('current.in')
        os.remove ('current.ans')

        print "Number of generated tests: ", self.num_test

if __name__ == "__main__":
    test_generator().generate_tests()      