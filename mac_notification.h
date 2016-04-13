#ifndef NATIVE_EXTENSION_GRAB_H
#define NATIVE_EXTENSION_GRAB_H

#include <nan.h>

using namespace v8;

class MacNotification : public Nan::ObjectWrap {
  public:
    static NAN_MODULE_INIT(Init);

  private:
    explicit MacNotification(Nan::Utf8String *id, Nan::Utf8String *title, Nan::Utf8String *body, bool canReply);
    ~MacNotification();
    
    static void RegisterDelegate(Nan::Callback *activated);
    static void UnregisterDelegate();

    static NAN_METHOD(New);
    static NAN_GETTER(GetId);
    static NAN_GETTER(GetTitle);
    static NAN_GETTER(GetBody);
    static NAN_GETTER(GetCanReply);
    
    static Nan::Persistent<Function> constructor;

    Nan::Utf8String *_id;
    Nan::Utf8String *_title;
    Nan::Utf8String *_body;
    bool _canReply;
};

#endif
