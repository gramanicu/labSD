#include <iostream>
#include <algorithm>

bool compFuncFirst(std::pair<int, char> a, std::pair<int, char> b) {
    return (a.first > b.first);
}

bool compFuncSecond(std::pair<int, char> a, std::pair<int, char> b) {
    return (a.second > b.second);
}

int main() {
    std::pair<int, char> vec[7];
    vec[0] = std::make_pair(1, 'l');
    vec[1] = std::make_pair(2, 'm');
    vec[2] = std::make_pair(3, 'M');
    vec[3] = std::make_pair(4, 'j');
    vec[4] = std::make_pair(5, 'v');
    vec[5] = std::make_pair(6, 's');
    vec[6] = std::make_pair(7, 'd');

    std::sort(std::begin(vec), std::end(vec), compFuncSecond);

    for(auto v: vec) {
        std::cout << v.first << " " << v.second << "\n";
    }



    return 0;
}