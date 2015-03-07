#include "tester.h"

TEST(ShoudPass) {
    ASSERT(1 == 1);
    ASSERT(2 == 2);
};

TEST(ShouldFail) {
    ASSERT(1 == 1);
    ASSERT(3 == 3);
};

int main()
{
    /* code */
    return 0;
}