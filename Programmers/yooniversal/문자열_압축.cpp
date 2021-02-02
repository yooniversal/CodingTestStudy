#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s) {
    int answer = s.size();

    for (int size = s.size(); size >= 1; --size) {
        int tmp = 0; //압축 문자열 길이
        for (int i = 0; i < s.size(); ) {
            //길이가 넘어가면 탐색 중지
            if (i + size - 1 >= s.size()) {
                tmp += s.size() - i;
                break;
            }

            int cnt = 0; //size 충족 횟수
            string cur = s.substr(i, size); //기준
            for (int j = i + size; j + size - 1 < s.size(); j += size) {
                if (cur == s.substr(j, size)) ++cnt;
                else break;
            }

            tmp += size;
            if (cnt) tmp += to_string(cnt + 1).size();
            i += size * (cnt + 1);
        }
        answer = min(answer, tmp);
    }
    return answer;
}