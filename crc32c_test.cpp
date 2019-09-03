//
// Created by 安博 on 2019/9/3.
//

#include <cstring>
#include <iostream>


#include "crc32c.h"
#include "test/testharness.h"

using namespace std;

namespace crc32c {
    class CRC {};

    void test(){
        char buf[32];

        memset(buf, 0, sizeof(buf));
        for (int i = 0; i < 32; i++) {
            buf[i] = i;
        }
        cout << hex << Value(buf, sizeof(buf)) << endl;
        uint32_t crc = Value("foo", 3);
        cout << hex << crc << endl;
    }

    TEST(CRC, Values) { ASSERT_NE(Value("a", 1), Value("foo", 3)); }

    TEST(CRC, Extend) {
        ASSERT_EQ(Value("hello world", 11), Extend(Value("hello ", 6), "world", 5));
    }
}
int main() {
    ::test::RunAllTests();
}
