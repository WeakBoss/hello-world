#include <string>
class Chapter2 {
public:
  Chapter2(){}
  Chapter2(std::string &title, int pages):pages(pages),title(title) {}
  void show() const {}
private:
  const string title; //??????????
  const int pages; //??????,????
  //??????????,????
  Chapter2(const Chapter2 &obj) {}
}
