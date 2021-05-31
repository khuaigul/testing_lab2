#ifndef TEST_M_H
#define TEST_M_H
#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <string.h>
//#include "text.h"
//#include "_text.h"

using namespace std;

extern "C" {
#include "common.h"
}

TEST(m, test1)
{
    testing::internal::CaptureStdout();
    //string output = testing::internal::GetCapturedStdout();
    string output = "";
    string ex = "";

    text cur = create_text();

    char* tm[5];
    tm[0] = "aaa a a aa\0";
    tm[1] = "bbb b b bb\0";
    tm[2] = "ccc c c cc\0";
    tm[3] = "ddd d d dd\0";
    tm[4] = "eee e e ee\0";
    for (int i = 0; i < 5; i++)
    {
        append_line(cur, tm[i]);
        if (i == 0)
        {
            ex += "|" + (string)tm[i] + "\n";
            continue;
        }
        ex += (string)tm[i] + "\n";
    }
    m(cur, 0, 0);
    show(cur);
    output = testing::internal::GetCapturedStdout();
    ASSERT_EQ(output, ex);
}
TEST(m, test2)
{
    testing::internal::CaptureStdout();
    //string output = testing::internal::GetCapturedStdout();
    string output = "";
    string ex = "";

    text cur = create_text();

    char* tm[5];
    tm[0] = "aaa a a aa";
    tm[1] = "bbb b b bb";
    tm[2] = "ccc c c cc";
    tm[3] = "ddd d d dd";
    tm[4] = "eee e e ee";
    for (int i = 0; i < 5; i++)
    {
        append_line(cur, tm[i]);
        if (i == 2)
        {
            ex += "ccc |c c cc\n";
            continue;
        }
        ex += (string)tm[i] + "\n";
    }
    m(cur, 2, 4);
    show(cur);
    output = testing::internal::GetCapturedStdout();
    ASSERT_EQ(output, ex);
}
TEST(m, test3)
{
    testing::internal::CaptureStdout();
    //string output = testing::internal::GetCapturedStdout();
    string output = "";
    string ex = "";

    text cur = create_text();

    char* tm[5];
    tm[0] = "aaa a a aa\0";
    tm[1] = "bbb b b bb\0";
    tm[2] = "ccc c c cc\0";
    tm[3] = "ddd d d dd\0";
    tm[4] = "eee e e ee\0";
    for (int i = 0; i < 5; i++)
    {
        append_line(cur, tm[i]);
        if (i == 2)
        {
            ex += (string)tm[i] + "|" + "\n";
            continue;
        }
        ex += (string)tm[i] + "\n";
    }
    m(cur, 2, 12);
    show(cur);
    output = testing::internal::GetCapturedStdout();
    ASSERT_EQ(output, ex);
}
TEST(m, test4)
{
    testing::internal::CaptureStdout();
    //string output = testing::internal::GetCapturedStdout();
    string output = "";
    string ex = "";

    text cur = create_text();

    char* tm[5];
    tm[0] = "aaa a a aa";
    tm[1] = "bbb b b bb";
    tm[2] = "ccc c c cc";
    tm[3] = "ddd d d dd";
    tm[4] = "eee e e ee";
    for (int i = 0; i < 5; i++)
    {
        append_line(cur, tm[i]);
        if (i == 4)
        {
            ex += (string)tm[i] + "|\n";
            continue;
        }
        ex += (string)tm[i] + "\n";
    }
    m(cur, 6, 2);
    show(cur);
    output = testing::internal::GetCapturedStdout();
    ASSERT_EQ(output, ex);
}

TEST (save, test1)
{
    string ex = "";
    text cur = create_text();
    char* tm[5];
    int p = 0;
    tm[0] = "aaa a a aa\0";
    tm[1] = "bbb b b bb\0";
    tm[2] = "ccc c c cc\0";
    tm[3] = "ddd d d dd\0";
    tm[4] = "eee e e ee\0";
    for (int i = 0; i < 5; i++)
    {
        append_line(cur, tm[i]);
        ex += (string)tm[i] + "\n";
    }

    save(cur, "file");

    FILE *f = fopen("file", "r");
    char* out;
    p = 0;
    while(1)
    {
        char c = getc(f);
        if (c == 0)
            break;
        if (c != ex[p])
            break;
        p++;
    }
//    while (fgets(out, 1025, f) != 0)
//    {
//        if (out != tm[p])
//            break;
//        p++;
//    }
    fclose(f);
    ASSERT_EQ(p, (int)ex.size());
}

TEST (cn, test1)
{
    testing::internal::CaptureStdout();
    //string output = testing::internal::GetCapturedStdout();
    text cur = create_text();
    string ex = "";

    char* tm[5];
    tm[0] = "aaa a a aa";
    tm[1] = "bbb b b bb";
    tm[2] = "ccc c c cc";
    tm[3] = "ddd d d dd";
    tm[4] = "eee e e ee";
    for (int i = 0; i < 5; i++)
    {
        append_line(cur, tm[i]);
        if (i == 0)
            ex += (string)tm[1] + "\n";
        else if (i == 1)
            ex += "|" + (string)tm[0] + "\n";
        else
            ex += (string)tm[i] + "\n";
    }
    m(cur, 0, 0);
    cn(cur);
    show(cur);
    string output = testing::internal::GetCapturedStdout();
    ASSERT_EQ(output, ex);
}
TEST (cn, test2)
{
    testing::internal::CaptureStdout();
    //string output = testing::internal::GetCapturedStdout();
    text cur = create_text();
    string ex = "";
    string output = "";

    char* tm[5];
    tm[0] = "aaa a a aa";
    tm[1] = "bbb b b bb";
    tm[2] = "ccc c c cc";
    tm[3] = "ddd d d dd";
    tm[4] = "eee e e ee";
    ex += "Uncorrect data\n";
    for (int i = 0; i < 5; i++)
    {
        append_line(cur, tm[i]);
        if (i == 4)
            ex += "|";
        ex += (string)tm[i] + "\n";
    }
    m(cur, 4, 0);
    cn(cur);
    show(cur);
    output = testing::internal::GetCapturedStdout();
    ASSERT_EQ(output, ex);
}

TEST (rch, test1)
{
    testing::internal::CaptureStdout();
    //string output = testing::internal::GetCapturedStdout();

    text cur = create_text();
    string ex = "";
    string output = "";

    char* tm[5];
    tm[0] = "aaa a a aa";
    tm[1] = "bbb b b bb";
    tm[2] = "ccc c c cc";
    tm[3] = "ddd d d dd";
    tm[4] = "eee e e ee";

    for (int i = 0; i < 5; i++)
    {
        append_line(cur, tm[i]);
        if (i == 0)
            ex += "|aa a a aa\n";
        else
            ex += (string)tm[i] + "\n";
    }
    m(cur, 0, 0);
    rch(cur);
    show(cur);
    output = testing::internal::GetCapturedStdout();

    ASSERT_EQ(output, ex);
}
TEST (rch, test2)
{
    testing::internal::CaptureStdout();
    //string output = testing::internal::GetCapturedStdout();

    text cur = create_text();
    string ex = "";
    string output = "";

    char* tm[5];
    tm[0] = "aaa a a aa";
    tm[1] = "bbb b b bb";
    tm[2] = "ccc c c cc";
    tm[3] = "ddd d d dd";
    tm[4] = "eee e e ee";

    for (int i = 0; i < 5; i++)
    {
        append_line(cur, tm[i]);
        if (i == 1)
            ex += (string)tm[i] + "|\n";
        else
            ex += (string)tm[i] + "\n";
    }
    m(cur, 1, 12);
    rch(cur);
    show(cur);
    output = testing::internal::GetCapturedStdout();

    ASSERT_EQ(output, ex);
}

TEST (shownumspaces, test1)
{
    testing::internal::CaptureStdout();
    //string output = testing::internal::GetCapturedStdout();

    text cur = create_text();
    string ex = "";
    string output = "";

    char* tm[5];
    tm[0] = "aaa a a a n a";
    tm[1] = "bbb";
    tm[2] = "    ";
    tm[3] = "";
    tm[4] = "eee e e ee";

    for (int i = 0; i < 5; i++)
        append_line(cur, tm[i]);
    ex = "5\n0\n4\n0\n3\n";
    shownumspaces(cur);

    output = testing::internal::GetCapturedStdout();

    ASSERT_EQ(output, ex);
}

#endif // TEST_M_H
