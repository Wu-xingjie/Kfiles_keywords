#include "keywords.h"

KEYWORDS::KEYWORDS(const std::set<std::string>& src_files) {
  if (!src_files.empty()) {
    for (auto elme : src_files) {
      _src_Kfiles.insert(elme);
    }
  } else {
    std::cout << "source file is empty!" << std::endl;
  }
}

void KEYWORDS::CatchKeywords() {
  // catch keywords
  for (auto kfile : _src_Kfiles) {
    std::fstream thisfile;
    std::string addr = "kfile/lib_kfile/" + kfile;
    thisfile.open(addr, std::ios_base::in);
    if (thisfile.is_open()) {
      std::string content;
      while (thisfile.good()) {
        getline(thisfile, content);
        if (content.size() && content.front() == '*') {
          _keywords.insert(content);
        }
      }
      thisfile.close();
    } else {
      std::cout << "this file open failed ->" << kfile << std::endl;
    }
  }
  // print keywords into target file named keywords.txt
  std::fstream tar_file;
  tar_file.open("keywords.txt", std::ios_base::out);
  if (tar_file.is_open()) {
    for (auto keyword : _keywords) {
      tar_file << keyword << std::endl;
    }
    tar_file.close();
  } else {
    std::cout << "keywords.txt open failed!" << std::endl;
  }
}