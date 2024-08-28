#include "keywords.h"

int main() {
  std::fstream kfile;
  kfile.open("/home/wxj/Kfiles_keywords/kfile/Kfile.txt", std::ios_base::in);
  if (kfile.is_open()) {
    std::set<std::string> src_files;
    std::string content;
    while (kfile.good()) {
      getline(kfile, content);
      src_files.insert(content);
    }
    kfile.close();

    KEYWORDS keywords_of_files(src_files);
    keywords_of_files.CatchKeywords();
  } else {
    std::cout << "Kfile.txt open failed!" << std::endl;
  }

  return 0;
}