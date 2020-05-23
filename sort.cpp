#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>

int main()
{
    std::vector<std::string> string_s;

    while (std::cin)
    {
        std::string s;
        std::getline(std::cin, s);
        string_s.push_back(s);
    }

    for (int i = 0; i < string_s.size() - 1; ++i)
    {
        std::string s = string_s[i];
        for (int j = i + 1; j < string_s.size(); ++j)
        {
            if (string_s[i] == string_s[j])
                string_s[j] = "";
        }
    }

    std::sort(string_s.begin(), string_s.end(),
                [](const std::string &i, const std::string &j) { return i < j; });

    for (int i = 0; i < string_s.size(); ++i)
        if(string_s[i] != "") std::cout << string_s[i] << '\n';
}