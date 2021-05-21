// ببین که پسوند فایل انقدر هم مهم نیست

#include <iostream>

int version = 10;

int main()
{
  std::cout << "version is " << ::version << std::endl;
  return 0;
}
