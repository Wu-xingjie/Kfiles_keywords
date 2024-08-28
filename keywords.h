#pragma once

#include <fstream>
#include <set>
#include <string>
#include <iostream>

class KEYWORDS {
 public:
  KEYWORDS(const std::set<std::string>& src_files);
  void CatchKeywords();

 private:
  std::set<std::string> _src_Kfiles;
  std::set<std::string> _keywords;
};