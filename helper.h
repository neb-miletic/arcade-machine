#ifndef HELPER_H
#define HELPER_H
// Helper class
// Any generic functions can go here

namespace fs = std::experimental::filesystem;
using namespace std;
using std::vector;

class Helper{
    public:
        char* string_to_char(string str)
        {
            int n = str.length();
            char* name[n+1];
            strcpy(*name, str.c_str());
            return *name;
        }
};
#endif