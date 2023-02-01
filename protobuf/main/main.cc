#include "iostream"
#include "protobuf/proto/msg.pb.h"

using namespace std;

int main(int argc, char const *argv[])

{
  proto_demo::Content content;
  content.set_id(1);
  content.set_opt(1);
  content.add_str("zyn");
  content.add_str("lp");

  cout << content.ShortDebugString() << endl;
  return 0;
}