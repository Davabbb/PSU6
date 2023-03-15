//https://contest.yandex.ru/contest/37787/run-report/68602101/

#include <iostream>
#include <string>
#include <vector>

unsigned long long OddManaker(const std::string& s) {
    unsigned long long ans = 0;
    std::vector<int> data (s.size());
    int left = 0, right = -1;
    for (int i = 0; i < s.size(); ++i) {
        int k = i > right ? 1 : std::min (data[left + right - i], right - i + 1);
        while (i + k < s.size() && i - k >= 0 && s[i + k] == s[i - k]) ++k;
        data[i] = k;
        if (k > 1) ans += k - 1;
        if (i + k - 1 > right)
            left = i - k + 1,  right = i + k - 1;
    }
    return ans;
}

unsigned long long EvenManaker(const std::string& s) {
    unsigned long long ans = 0;
    std::vector<int> data (s.size());
    int left = 0, right = -1;
    for (int i = 0; i < s.size(); ++i) {
        int k = i > right ? 0 : std::min (data[left + right - i + 1], right - i + 1);
        while (i + k < s.size() && i - k - 1 >= 0 && s[i + k] == s[i - k - 1])  ++k;
        data[i] = k;
        if (k > 0) ans += k;
        if (i + k - 1 > right)
            left = i - k,  right = i + k - 1;
    }
    return ans;
}

unsigned long long Palindrom(const std::string& s) {
    return OddManaker(s) + EvenManaker(s);
}


int main() {
    std::string s; std::cin >> s;
    std::cout << Palindrom(s) << std::endl;
    return 0;
}
