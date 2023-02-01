#include "gtest/gtest.h"

int32_t Add(int32_t a, int32_t b) { return a + b; }
int32_t Sub(int32_t a, int32_t b) { return a - b; }

TEST(AssertTest, EXPECT_VERIFY) {
  EXPECT_EQ(Add(1, 2), 3) << "result of Add function is " << Add(1, 2);
  EXPECT_NE(Add(1, 2), 2) << "result of Add function is " << Add(1, 2);
  // less than
  // EXPECT_LT(Add(1,2), 3);
  // less than & equal
  EXPECT_LE(Add(1, 2), 3);
  // greater than
  EXPECT_GE(Add(1, 2), 3);
  // greater than & equal
  // EXPECT_GT(Add(1,2), 3);
}

// ASSERT 在出错之后会立刻停止执行
TEST(AssertTest, ASSERT_VERIFY) {
  ASSERT_EQ(Add(1, 2), 3) << "result of Add function is " << Add(1, 2);
  ASSERT_NE(Add(1, 2), 2) << "result of Add function is " << Add(1, 2);
  // less than & equal
  ASSERT_LE(Add(1, 2), 3);
  // greater than
  // ASSERT_GE(Add(1,2), 3);

  // greater than & equal
  // ASSERT_GT(Add(1,2), 3);
  bool val = true;
  ASSERT_TRUE(val == true);
  ASSERT_FALSE(val == false);
}

// 判断字符串是否相等
TEST(AssertTest, ASSERT_STRINGVERIFY) {
  ASSERT_STREQ("hello", "hello");
  ASSERT_STRNE("hello", "hellorr");
  ASSERT_STRCASEEQ("hello", "HeLLO");
  // ASSERT_STRCASENE("hello", "HeLLO");
}

TEST(AssertTest, FAIL) {
  // 会继续向下执行
  // ADD_FAILURE() << "sorry this case failure";
  // FAIL();
}

TEST(AssertTest, Success) { SUCCEED(); }

int32_t AddThrow(int32_t a, int32_t b) {
  if (a == 0 && b == 0) throw("a== 0 && b ==0");
  return a - b;
}

TEST(AssertTest, ASSERT_THROW) {
  // 需要 throw 一个特定类型的 exception,否则会 Assert
  // ASSERT_THROW(AddThrow(0,0), char*);

  // 必须由 throw 才会 pass ，否会fail
  // ASSERT_ANY_THROW(AddThrow(1,0));

  // 必须是 NO_THROW 才会 pass ，否则会 assert 掉
  // ASSERT_NO_THROW(AddThrow(0,0));
}

uint32_t a = 10;
uint32_t b = 10;
TEST(AssertTest, ASSERT_BOOL) {
  // 必须是 true 才能 pass 否则 Assert
  ASSERT_TRUE(a == b);
  // 必须是 false 才能 pass 否则 Assert
  ASSERT_FALSE(a != b);
  // 必须是 true 才能 pass 否则报错
  EXPECT_TRUE(a == b);
  // 必须是 FALSE 才能 pass 否则报错
  // EXPECT_FALSE(a == b);
}

float a_f = 1.23;
float b_f = 1.23;

double c_d = 1.34;
double d_d = 1.34;

double e_d = 1.234;
double f_d = 1.256;

TEST(AssertTest, ASSERT_FLOAT) {
  ASSERT_FLOAT_EQ(a_f, b_f);
  ASSERT_DOUBLE_EQ(c_d, d_d);

  EXPECT_FLOAT_EQ(a_f, b_f);
  EXPECT_DOUBLE_EQ(c_d, d_d);

  // para1 para2 的误差不超过 para3的范围，否则报错
  ASSERT_NEAR(e_d, f_d, 0.1);
  ASSERT_NEAR(e_d, f_d, 0.1);
}