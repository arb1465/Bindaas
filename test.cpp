#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isLucky(int n)
{
    string s = to_string(n);
    int len = s.length();
    vector<int> digits(len + 1);

    // Convert to 1-based indexing for easier condition checking
    for (int i = 0; i < len; i++)
    {
        digits[i + 1] = s[i] - '0';
    }

    for (int i = 1; i <= len; i++)
    {
        // Condition 1: Even indices (2, 4, 6...) are non-decreasing
        if (i % 2 == 0 && i + 2 <= len)
        {
            if (digits[i] > digits[i + 2])
                return false;
        }
        // Condition 2: Odd indices (1, 3, 5...) are non-decreasing
        if (i % 2 != 0 && i + 2 <= len)
        {
            if (digits[i] > digits[i + 2])
                return false;
        }
        // Condition 3: Odd index digit <= next even index digit
        if (i % 2 != 0 && i + 1 <= len)
        {
            if (digits[i] > digits[i + 1])
                return false;
        }
    }
    return true;
}

int main()
{
    int L, R;
    if (!(cin >> L >> R))
        return 0;

    int luckyCount = 0;
    for (int i = L; i <= R; i++)
    {
        if (isLucky(i))
        {
            luckyCount++;
        }
    }

    cout << luckyCount << endl;

    return 0;
}