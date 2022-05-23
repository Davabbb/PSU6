//https://contest.yandex.ru/contest/37787/run-report/68551666/

#include <iostream>
#include <vector>
#include <string>


std::string Answer(const std::vector<int>& data) {
    std::string ans = "a";
    for (int i = 1; i < data.size(); ++i) {
        if (data[i] != 0) {
            ans += ans[data[i] - 1];
        } else {
            std::vector<bool> chars(26);
            int last_char = data[i - 1];
            while (last_char > 0) {
                chars[ans[last_char] - 'a'] = true;
                last_char = data[last_char - 1];
            }
            char symbol = 'b';
            while (chars[symbol - 'a']) {
                ++symbol;
            }
            ans += symbol;
        }
    }
    return ans;
}



int main() {
    std::vector<int> data;
    int n;
    while (std::cin >> n) {
        data.push_back(n);
    }
    std::cout << Answer(data) << std::endl;
    return 0;
}
