
#include <stdlib.h>
#include <v8.h>
#include <nan.h>
#include <node.h>

using namespace node;
using namespace v8;

extern "C" void init (Handle<Object>);

NAN_METHOD(Random) {
  NanScope();
  NanReturnValue(NanNew<Number>(rand()/((double)RAND_MAX + 1)));
}

NAN_METHOD(Rand) {
  NanScope();
  NanReturnValue(NanNew<Integer>(rand()));
}

NAN_METHOD(SRand) {
  NanScope();
  if (args.Length() == 0) {
    NanThrowError(Exception::Error(NanNew<String>("Usage: srand(n)")));
  }
  srand(args[0]->Uint32Value());
  NanReturnValue(NanUndefined());
}

extern "C" void init (Handle<Object> target) {
  NODE_SET_METHOD(target, "random", Random);
  NODE_SET_METHOD(target, "rand", Rand);
  NODE_SET_METHOD(target, "srand", SRand);
  NODE_SET_METHOD(target, "seed", SRand);
  NODE_DEFINE_CONSTANT(target, RAND_MAX);
}

NODE_MODULE(srand, init)
