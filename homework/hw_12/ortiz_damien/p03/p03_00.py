# Imports:
#
import re
import sys
from collections import defaultdict


# define class
#
class WordCounter:

    # constructor which gives a filename and dictionary of frequencies
    #
    def __init__(self, filename):
        self.filename = filename
        self.freq = defaultdict(int)

    # function to find word frequencies
    #
    def compute_word_frequencies(self):

        # open the file and compute counts
        #
        with open(self.filename, 'r') as f:

            for line in f:
                # split on non-alphanumeric characters
                #
                words = re.split(r'[^A-Za-z0-9]+', line)
                for word in words:
                    if word:
                        word_lower = word.lower()
                        
                        # increase frequency count if found
                        #
                        self.freq[word_lower] += 1

        # return frequency value
        #
        return self.freq

    # function to print word count
    #
    def print_frequencies(self, ascending=True):

        # sort the word count in ascending order
        #
        sorted_items = sorted(self.freq.items(),
                              key=lambda x: x[1],
                              reverse=not ascending)
        # print the word count
        #
        for word, count in sorted_items:
            print(f"{word}: {count}")

# end of file
