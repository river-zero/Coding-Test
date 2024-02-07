#include <vector>

using namespace std;

int get_target_number(const vector<int> &numbers, int target, int sum, int index) {
    // 타겟 넘버에 도달하면 1, 아니면 0
    if (index == numbers.size()) {
        return (sum == target) ? 1 : 0;
    }
    // 현재 숫자를 더하거나 빼는 두 가지 경우를 각각 재귀적으로 호출
    int cnt1 = get_target_number(numbers, target, sum + numbers[index], index + 1);
    int cnt2 = get_target_number(numbers, target, sum - numbers[index], index + 1);

    // 현재 숫자를 포함하여 타겟 넘버를 만들 수 있는 모든 경우의 수를 반환
    return cnt1 + cnt2;
}

int solution(vector<int> numbers, int target) {
    return get_target_number(numbers, target, 0, 0);
}
