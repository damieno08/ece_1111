// file: /data/courses/ece_1111/2025_01_fall/homework/hw_12/ortiz_damien/p02/p02.h

// define header if not defined
//
#ifndef P02_H
#define P02_H

// include files
//
#include <cstdio>
#include <cctype>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

// define the class
//
class ComputeWordFrequencies {

  // define all public functions
  //
public:
    ComputeWordFrequencies(const std::string &filename);
    void parseFile();
    void printFrequencies(bool ascending = true);
  // define all private data
  //
private:
    std::string filename;
    std::unordered_map<std::string, int> freq;

    static bool compareAsc(const std::pair<std::string,int> &a,
                           const std::pair<std::string,int> &b);
};

#endif
