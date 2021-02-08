#include<iostream>
#include<math.h>
#include <vector>
#include <stack>
#include <map>
#include<math.h>
#include<algorithm>
using namespace std;
int number = 1000000;
int a[1000001];
void primeNumberSieve() {

    // 1. 배열을 생성하여 초기화한다.
    for (int i = 2; i <= number; i++) {
        a[i] = i;
    }

    // 2. 2부터 시작해서 특정 수의 배수에 해당하는 수를 모두 지운다.
    // (지울 때 자기자신은 지우지 않고, 이미 지워진 수는 건너뛴다.)
    for (int i = 2; i <= number; i++) {
        if (a[i] == 0) continue; // 이미 지워진 수라면 건너뛰기

        // 이미 지워진 숫자가 아니라면, 그 배수부터 출발하여, 가능한 모든 숫자 지우기
        for (int j = 2 * i; j <= number; j += i) {
            a[j] = 0;
        }
    }

    // 3. 2부터 시작하여 남아있는 수를 모두 출력한다.


}
int main()
{
        primeNumberSieve();
        int N;
        cin >> N;

        for (int i = 0; i < N; i++)
        {
            int num;
            cin >> num;
            int answer = 0;
            for (int j = 2; j <= num / 2; j++)
            {
                if (a[j] * a[num - j] != 0)answer++;
            }
            cout << answer << endl;
        }
        return 0;
}