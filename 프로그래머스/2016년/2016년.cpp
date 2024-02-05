#include <string>
using namespace std;

string solution(int a, int b) {
    const int daysInMonth[] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    const string daysOfWeek[] = { "THU", "FRI", "SAT", "SUN", "MON", "TUE", "WED" };
    
    int totalDays = b;

    for(int i = 0; i < a - 1; i++) {
        totalDays += daysInMonth[i];
    }

    return daysOfWeek[totalDays % 7];
}
