//https://contest.yandex.ru/contest/37787/run-report/68180664/

#include <iostream>
#include <string>
#include <vector>

std::vector<int> ZFunction(const std::string& s) {
    int n = s.size();
    std::vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r) {
            z[i] = std::min(r - i + 1, z[i - l]);
        }
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            ++z[i];
        }
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
    return z;
}

int main() {
    std::string substring, string;
    std::cin >> substring >> string;
    std::string new_s = substring + "#" + string;
    std::vector<int> z = ZFunction(new_s);
    int n = substring.size();
    for (int i = n; i < z.size(); ++i) {
        if (z[i] == n) {
            std::cout << i - n - 1 << " ";
        }
    }
    return 0;
}
