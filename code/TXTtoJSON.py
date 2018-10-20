#!/usr/bin/env python
"""This module converts TAB-separated culumns of text in a .txt file to a standard .JSON file"""
import re
import os


def main():
    """finds .txt file names and hands to convert"""
    fileNames = os.listdir()
    print("Searching for text files...")
    for name in fileNames:
        if ".txt" in name:
            convert(name)
    input("Conversion is complete.\nPRESS ENTER TO EXIT")


def convert(File):
    """gets the name of .txt (input file) and outputs .json file"""
    # Openning input & output files
    with open((File), "r", encoding="utf-16") as source:
        with open((File[0:-4] + ".json"), "w", encoding="utf-16") as destination:
            # Reading and putting lines from input together
            contents = source.readlines()
            contents = "".join(contents)
            # Formatting the text
            contents = re.sub(r'	', '", "', contents)
            contents = re.sub(r'\n', '"],\n["', contents)
            contents = '[\n["' + contents + '\n]'
            contents = re.sub(r',\n\["\n]', '\n]', contents)
            # Fixing errors
            contents = re.sub(r'""', '"', contents)
            contents = re.sub(r'\[",', '["",', contents)
            # BEAUTIFICATION
            contents = re.sub(r'\n\["', '\n	["', contents)
            # Writing to output
            destination.write(contents)


if __name__ == '__main__':
    main()
