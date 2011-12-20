#include <node.h>
#include <stdio.h>
#include <v8.h>

using namespace v8;

Handle<Value> FlushAll(const Arguments& args) {
  fflush(NULL);
  return True();
}

Handle<Value> FlushStderr(const Arguments& args) {
  fflush(stderr);
  return True();
}

Handle<Value> FlushStdout(const Arguments& args) {
  fflush(stdout);
  return True();
}

void RegisterModule(Handle<Object> target) {
  NODE_SET_METHOD(target, "flushStdout", FlushStdout);
  NODE_SET_METHOD(target, "flushStderr", FlushStderr);
  NODE_SET_METHOD(target, "flushAll",    FlushAll);
}

NODE_MODULE(fflush, RegisterModule);
