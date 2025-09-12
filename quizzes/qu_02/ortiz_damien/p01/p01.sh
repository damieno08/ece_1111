#!/bin/bash

#Script will take in a text file then split it into words, sort it alphabetically, count the occurence of each word, then print the results

# Check if a filename argument is provided
if [ $# -ne 1 ]; then
    echo "Usage: $0 filename"
    exit 1
fi

# Store the filename
FILE="$1"

# Verify the file exists
if [ ! -f "$FILE" ]; then
    echo "File not found: $FILE"
    exit 1
fi

# Process the file: split into words, uppercase, sort, count, and print
tr -s '[:space:]' '\n' < "$FILE" | \
tr '[:lower:]' '[:upper:]' | \
sort | \
uniq -c | \
sort -nr | \
awk '{print $1, $2}'

#End of File
