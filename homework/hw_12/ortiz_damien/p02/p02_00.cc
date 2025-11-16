
// include files
//
#include "p02.h"
#include <cstdio>
#include <cctype>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <iostream>

// constructor
//
ComputeWordFrequencies::ComputeWordFrequencies(const std::string &file)
    : filename(file) {}

// parse file into words
//
void ComputeWordFrequencies::parseFile() {

  // check if file exists then print error if not
  //
  FILE* fp = fopen(filename.c_str(), "r");
  if (!fp) {
    fprintf(stderr,"Error: cannot open file "); 
    return;
  }

  // convert lines into words based on whitespace
  //
  std::string word;
  int c;
  while ((c = fgetc(fp)) != EOF) {
    if (std::isalnum(c)) {
      word += std::tolower(c);
    } else if (!word.empty()) {
      freq[word]++;
            word.clear();
    }
  }
  if (!word.empty()) {
    freq[word]++;
  }

  // close file
  //
  fclose(fp);
}

// comparison function for sorting ascending
//
bool ComputeWordFrequencies::compareAsc(					
    const std::pair<std::string,int> &a,
    const std::pair<std::string,int> &b)
{

  // compare frequencies and put in ascending order
  //
  return a.second < b.second; 
}

// print word frequencies
//
void ComputeWordFrequencies::printFrequencies(bool ascending) {

  std::vector<std::pair<std::string,int>> items(freq.begin(), freq.end());

  // sort in order
  //
  if (ascending) {
    std::sort(items.begin(), items.end(), compareAsc);
  } else {
    std::sort(items.begin(), items.end(),
	      [](const auto &a, const auto &b){ return a.second > b.second; });
  }
  
  for (const auto &p : items) {
    std::cout << p.first << ": " << p.second << std::endl;
  }
}
