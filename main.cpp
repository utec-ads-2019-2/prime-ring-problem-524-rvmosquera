#include <string>

const int MAX_NUM=20;

using namespace std;

int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41};
int result[MAX_NUM];

bool isPrime(int a)
{
    for (int n : primes)
        if (n == a)
            return true;

    return false;
}
void test_n_set(int num, int n, bool *visit)
{
    if (num == n) {
        if (!isPrime(result[n - 1] + 1)) // end of ring
            return;
        printf("1");
        for (int i = 1; i < n; ++i)
            printf(" %d", result[i]);
        printf("\n");
        return;
    }
    for (int i = 2; i <= n; ++i) {
        if (visit[i])
            continue;

        if (isPrime(i + result[num - 1])) {
            visit[i] = 1;
            result[num] = i;

            test_n_set(num + 1, n, visit);

            visit[i] = 0;
        }
    }
}
int main()
{
    int n, case_num = 0;

    result[0] = 1;
    while (scanf("%d", &n) != EOF) {
        if (case_num++)
            putchar('\n');
        printf("Case %d:\n", case_num);
        bool visit[MAX_NUM] = {0};
        test_n_set(1, n, visit);
    }
}