#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dulljson.h"

static int test_count = 0;
static int pass_count = 0;
static int main_ret = 0;

#define EXPECT_EQ_BASE(equality, expect, actual, format) \
    do{\
        test_count++;\
        if(equality)\
            pass_count++;\
        else{\
            fprintf(stderr, "%s:%d: expect" format " actual: " format "\n", __FILE__, __LINE__, expect, actual);\
            main_ret = 1;\
        }\
    } while(0)

#define EXPECT_EQ_INT(expect, actual) EXPECT_EQ_BASE((expect) == (actual), expect, actual, "%d")

static void test_parse_null(){
    dull_value v;
    v.type = DULL_TRUE;

    EXPECT_EQ_INT(DULL_PARSE_OK, dull_parse(&v, "null"));
    EXPECT_EQ_INT(DULL_NULL, dull_get_type(&v));
}

static void test_parse(){
    test_parse_null();
}

int main(){
    test_parse();
    printf("%d/%d (%3.2f%%) passed\n", pass_count, test_count, pass_count * 100.0 / test_count);
    return main_ret;
}
