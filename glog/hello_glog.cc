#include <glog/logging.h>

int main() {
  // 使用glog之前必须先初始化库，仅需执行一次，括号内为程序名

  FLAGS_log_dir = "/home/zyn/Desktop/bazel_demo/glog/logs";  // 日志输出位置
  FLAGS_alsologtostderr = true;   // 是否将日志输出到文件和stderr
  FLAGS_colorlogtostderr = true;  // 是否启用不同颜色显示
  FLAGS_v = 2;
  google::InitGoogleLogging("test");

  // 1:有条件地记录日志信息

  LOG_IF(INFO, true) << "Got lots of cookies";
  // google::COUNTER，记录该语句被执行次数
  for (int i = 0; i < 100; i++) {
    // 从1开始，在第一次运行输出日志之后，每隔10次再输出一次日志信息
    LOG_EVERY_N(INFO, 10) << "Got the " << google::COUNTER << "th cookie";

    // 从1开始，每隔10次去判断条件是否满足，如果满足则输出日志
    LOG_IF_EVERY_N(INFO, false, 10)
        << "Got the " << google::COUNTER << "th big cookie";

    // 此语句执行的前 20 次都输出日志，然后不再输出
    LOG_FIRST_N(INFO, 20) << "Got the " << google::COUNTER << "th cookie";
  }

  // 2: 有条件地中止程序
  //  CHECK_EQ, CHECK_NE, CHECK_LE, CHECK_LT, CHECK_GE, CHECK_GT
  //  CHECK_DOUBLE_EQ，CHECK_NEAR CHECK_NOTNULL CHECK_STREQ, CHECK_STRNE,
  //  CHECK_STRCASEEQ, CHECK_STRCASENE
  //  不满足条件直接退出
  CHECK(true) << "Write failed!";

  // 3:严重性分级记录信息
  LOG(INFO) << "info test";        // 输出一个Info日志
  LOG(WARNING) << "warning test";  // 输出一个Warning日志
  LOG(ERROR) << "error test";      // 输出一个Error日志
  LOG(FATAL) << "fatal test";  // 输出一个Fatal日志，输出之后会中止程序

  google::ShutdownGoogleLogging();  // 当要结束glog时必须关闭库，否则会内存溢出
  return 0;
}
