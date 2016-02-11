#include <stdlib.h>
#include <nan.h>
#include <node.h>
#include <cstdlib>

void Random(const Nan::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Number> num = Nan::New(rand()/((double)RAND_MAX + 1));
  info.GetReturnValue().Set(num);
}

void Rand(const Nan::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Integer> num = Nan::New(rand());
  info.GetReturnValue().Set(num);
}

void SRand(const Nan::FunctionCallbackInfo<v8::Value>& info) {
  if (info.Length() == 0) {
    Nan::ThrowError("Usage: srand(n)");
  }
  srand(info[0]->Uint32Value());
  info.GetReturnValue().SetUndefined();
}

void Init(v8::Local<v8::Object> exports) {
  exports->Set(Nan::New("random").ToLocalChecked(), Nan::New<v8::FunctionTemplate>(Random)->GetFunction());
  exports->Set(Nan::New("rand").ToLocalChecked(), Nan::New<v8::FunctionTemplate>(Rand)->GetFunction());
  exports->Set(Nan::New("srand").ToLocalChecked(), Nan::New<v8::FunctionTemplate>(SRand)->GetFunction());
  exports->Set(Nan::New("seed").ToLocalChecked(), Nan::New<v8::FunctionTemplate>(SRand)->GetFunction());
  exports->Set(Nan::New("RAND_MAX").ToLocalChecked(), Nan::New<v8::Integer>(RAND_MAX));
}

NODE_MODULE(srand, Init)
