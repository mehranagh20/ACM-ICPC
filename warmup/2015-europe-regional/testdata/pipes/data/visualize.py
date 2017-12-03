#!/usr/bin/env python
header = """
\\documentclass[convert={density=300,size=800x800,outext=.png}]{standalone}
\\batchmode
\\usepackage{calc}
\\usepackage{ifthen}
\\usepackage{tikz}
\\usepackage{ifthen}
\\pagestyle{empty}
\\newlength{\\wdtotal}
\\newlength{\\httotal}
\\setlength{\\wdtotal}{1cm}
\\setlength{\\httotal}{1cm}
\\newsavebox{\\vis}
\\sbox{\\vis}{
\\begin{tikzpicture}
"""

footer = """
\\end{tikzpicture}
}
\\ifthenelse{\\wd\\vis > \\wdtotal}{\\setlength{\\wdtotal}{\\wd\\vis}}{}
\\ifthenelse{\\ht\\vis > \\httotal}{\\setlength{\\httotal}{\\ht\\vis}}{}
\\setlength{\\paperwidth}{2in+\\wdtotal}
\\setlength{\\paperheight}{2in+\\httotal}
\\textwidth = \\wdtotal
\\textheight = \\httotal
\\oddsidemargin = 0.0 in
\\evensidemargin = 0.0 in
\\topmargin = 0.0 in
\\headheight = 0.0 in
\\headsep = 0.0 in
\\parskip = 0.2in
\\parindent = 0.0in
\\begin{document}
\\usebox{\\vis}
\\end{document}
"""

def main():
    w,p = map(int, raw_input().split())
    print header
    for i in range(0,w):
        x,y = map(int, raw_input().split())
        print "\\node[circle,fill=red] (w%d) at (%d,%d) {};" % (i,x/10,y/10)
    for i in range(0,p):
        w,x,y = map(int, raw_input().split())
        print "\draw (w%d) -- (%d,%d);" % (w,x,y)
    print footer

if __name__ == "__main__":
    main();
