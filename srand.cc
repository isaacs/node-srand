
#include <stdlib.h>
#include <v8.h>
#include <node.h>

using namespace node;
using namespace v8;

static Handle<Value> Random (const Arguments&);
static Handle<Value> Rand (const Arguments&);
static Handle<Value> SRand (const Arguments&);
extern "C" void init (Handle<Object>);

static Handle<Value> Random (const Arguments& args) {
  return Number::New(rand()/((double)RAND_MAX + 1));
}

static Handle<Value> Rand (const Arguments& args) {
  return Integer::New(rand());
}

static Handle<Value> SRand (const Arguments& args) {
  if (args.Length() == 0) {
    return ThrowException(Exception::Error(String::New("Usage: srand(n)")));
  }
  srand(args[0]->Int32Value());
  return Undefined();
}

extern "C" void init (Handle<Object> target) {
  HandleScope scope;
  NODE_SET_METHOD(target, "random", Random);
  NODE_SET_METHOD(target, "rand", Rand);
  NODE_SET_METHOD(target, "srand", SRand);
  NODE_SET_METHOD(target, "seed", SRand);
  NODE_DEFINE_CONSTANT(target, RAND_MAX);
}
