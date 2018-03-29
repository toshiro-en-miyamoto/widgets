#include <iostream>
#include <experimental/filesystem>
namespace fs = std::experimental::filesystem;
using namespace std;

int main() {
  cout << fs::current_path() << endl;
  return 0;
}
