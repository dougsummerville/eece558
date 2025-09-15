#!/bin/python3

import argparse
import os

parser = argparse.ArgumentParser(description='A tool to submit files for grading.')
parser.add_argument('files', metavar='FILE(s)', nargs='+', help='a list of files to submit')

args = parser.parse_args()
directories = ("./","drivers/","src")
separator = "\n############################################################\n"

print(args.files)
lines=[]
for f in args.files:
    fname="not found"
    for d in directories:
        if os.path.exists(d+f):
           fname = d+f
           break
    if fname == "not found":
        print(f"Can't find file {f} in {directories}")
        sys.exit(1)
    lines.append(separator)
    lines.append(fname+"\n")
    lines.append(separator)
    with open(fname, 'r') as file:
        for line in file:
            lines.append(line)
        file.close()

with open("submit.txt", 'w') as file:
    file.writelines(lines)
    file.close()
