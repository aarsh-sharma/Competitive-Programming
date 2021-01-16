import os
from os import listdir, mkdir, rename
from os.path import isfile, isdir, join

def makeFolderName(fileName):
    folderName = ''
    for ch in fileName:
        if (ch.isdigit()):
            folderName += ch
        else:
            break;

    return folderName

cwd = os.getcwd()

'''
To make folder for each contest file and move file to that folder
'''

for f in listdir(cwd):
    if isfile(f):
        print(f)
        folderName = makeFolderName(f)

        if (isdir(folderName) == False):
            mkdir(folderName)

        rename(f, join(folderName, f))

print('Thank you for using Folderize CF')


'''
To move all contest folders to a common folder
'''

for f in listdir(cwd):
    if isdir(f):
        print(f)
        if f.isdigit():
            rename(f, join('Contests', f))

