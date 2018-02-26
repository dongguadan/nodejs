#include <node.h>
#include <v8.h>
#include <nan.h>
#include <iostream>

using namespace v8;
using namespace std;

void hello(const FunctionCallbackInfo<Value>& args)
{
    Isolate* isolate = Isolate::GetCurrent();
    HandleScope scope(isolate);

    if (args.Length() < 2 || !args[0]->IsString())
    {
        isolate->ThrowException(Exception::TypeError(
        String::NewFromUtf8(isolate, "Wrong arguments")));
        return;
    }

    Local<Function> callback = Local<Function>::Cast(args[1]);
    Local<Value> argv[1] = {
        String::Concat(Local<String>::Cast(args[0]), String::NewFromUtf8(isolate, " hello world"))
    };

    callback->Call(isolate->GetCurrentContext()->Global(), 1, argv);
    return;
}

void Node_GTransfer_GetVersion(const FunctionCallbackInfo<Value>& args)
{
    Isolate* isolate = Isolate::GetCurrent();
    HandleScope scope(isolate);

    Local<String> strVersion = String::NewFromUtf8(isolate, "3.0.0.1");
    Local<Number> numRet = Number::New(isolate, 0);

    Local<Object> obj = Object::New(isolate);
    obj->Set(v8::String::NewFromUtf8(isolate, "Version"), strVersion);
    obj->Set(v8::String::NewFromUtf8(isolate, "Result"), numRet);
    args.GetReturnValue().Set(obj);
    return;
}

void Node_GTransfer_Domain2IP(const FunctionCallbackInfo<Value>& args)
{
    Isolate* isolate = Isolate::GetCurrent();
    HandleScope scope(isolate);

    if (args.Length() < 2)
    {
        isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "Wrong number of arguments")));
        return;
    }

    if (!args[0]->IsString() || !args[1]->IsNumber())
    {
        isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "argumnets must be String-Number")));
        return;
    }

    Local<String> strDomain = Local<String>::Cast(args[0]);
    Local<Number> numPort = Local<Number>::Cast(args[1]);

    String::Utf8Value v8Domain(strDomain);
    int v8Port = numPort->NumberValue();

    cout << "Node_GTransfer_Domain2IP domain : " << string(*v8Domain) << " port : " << v8Port << endl;

    Local<Number> numRet = Number::New(isolate, 0);
    Local<String> strIp = String::NewFromUtf8(isolate, "10.0.15.59");
    Local<Object> obj = Object::New(isolate);
    obj->Set(v8::String::NewFromUtf8(isolate, "Ip"), strIp);
    obj->Set(v8::String::NewFromUtf8(isolate, "Result"), numRet);
    args.GetReturnValue().Set(obj);
    return;
}

void Node_FMFT_Init(const FunctionCallbackInfo<Value>& args)
{
    Isolate* isolate = Isolate::GetCurrent();
    HandleScope scope(isolate);

    Local<Number> numRet = Number::New(isolate, 0);
    Local<Object> obj = Object::New(isolate);
    obj->Set(v8::String::NewFromUtf8(isolate, "Result"), numRet);
    args.GetReturnValue().Set(obj);
    return;
}

void Node_FMFT_Start_Listen(const FunctionCallbackInfo<Value>& args)
{
    Isolate* isolate = Isolate::GetCurrent();
    HandleScope scope(isolate);

    if (args.Length() < 1)
    {
        isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "Wrong number of arguments")));
        return;
    }

    if (!args[0]->IsNumber())
    {
        isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "argumnets must be String-Number")));
        return;
    }

    Local<Number> numPort = Local<Number>::Cast(args[0]);
    int v8Port = numPort->NumberValue();

    cout << "Node_FMFT_Init port : " << v8Port << endl;

    Local<Number> numRet = Number::New(isolate, 0);
    Local<Object> obj = Object::New(isolate);
    obj->Set(v8::String::NewFromUtf8(isolate, "Result"), numRet);
    args.GetReturnValue().Set(obj);
    return;
}

void Node_FMFT_Stop_Listen(const FunctionCallbackInfo<Value>& args)
{
    Isolate* isolate = Isolate::GetCurrent();
    HandleScope scope(isolate);

    Local<Number> numRet = Number::New(isolate, 0);
    Local<Object> obj = Object::New(isolate);
    obj->Set(v8::String::NewFromUtf8(isolate, "Result"), numRet);
    args.GetReturnValue().Set(obj);
    return;
}

void Node_FMFT_Accept(const FunctionCallbackInfo<Value>& args)
{
    Isolate* isolate = Isolate::GetCurrent();
    HandleScope scope(isolate);

    string message = "phoenixtv";
    Local<Number> numLen = v8::Number::New(isolate, message.length());
    Local<String> strPacket = v8::String::NewFromUtf8(isolate, "phoenixtv");

    String::Utf8Value v8Packet(strPacket);
    int v8Len = numLen->NumberValue();

    cout << "Node_FMFT_Accept packet : " << string(*v8Packet) << " Len : " << v8Len << endl;

    Local<Number> numRet = Number::New(isolate, v8Len);
    Local<String> strPacket_2 = String::NewFromUtf8(isolate, *v8Packet);
    Local<Object> obj = Object::New(isolate);
    obj->Set(v8::String::NewFromUtf8(isolate, "Packet"), strPacket_2);
    obj->Set(v8::String::NewFromUtf8(isolate, "Result"), numRet);
    args.GetReturnValue().Set(obj);
    return;
}

void Node_FMFT_FinishAcccept(const FunctionCallbackInfo<Value>& args)
{
    Isolate* isolate = Isolate::GetCurrent();
    HandleScope scope(isolate);

    if (args.Length() < 2)
    {
        isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "Wrong number of arguments")));
        return;
    }

    if (!args[0]->IsString() || !args[1]->IsNumber())
    {
        isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "argumnets must be String-Number")));
        return;
    }

    Local<String> strPacket = Local<String>::Cast(args[0]);
    Local<Number> numLen = Local<Number>::Cast(args[1]);

    String::Utf8Value v8Packet(strPacket);
    int v8Len = numLen->NumberValue();

    cout << "Node_FMFT_FinishAcccept packet : " << string(*v8Packet) << " Len : " << v8Len << endl;

    Local<Number> numRet = Number::New(isolate, v8Len);
    Local<String> strPacket_2 = String::NewFromUtf8(isolate, *v8Packet);
    Local<Object> obj = Object::New(isolate);
    obj->Set(v8::String::NewFromUtf8(isolate, "Packet"), strPacket_2);
    obj->Set(v8::String::NewFromUtf8(isolate, "Result"), numRet);
    args.GetReturnValue().Set(obj);
    return;
}

void Node_FMFT_Connect(const FunctionCallbackInfo<Value>& args)
{
    Isolate* isolate = Isolate::GetCurrent();
    HandleScope scope(isolate);

    if (args.Length() < 4)
    {
        isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "Wrong number of arguments")));
        return;
    }

    if (!args[0]->IsString() || !args[1]->IsNumber() || !args[2]->IsNumber() || !args[3]->IsString())
    {
        isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "argumnets must be String-Number")));
        return;
    }

    Local<String> strIp = Local<String>::Cast(args[0]);
    Local<Number> numRemotePort = Local<Number>::Cast(args[1]);
    Local<Number> numLocalPort = Local<Number>::Cast(args[2]);
    Local<String> strPacket = Local<String>::Cast(args[3]);

    String::Utf8Value v8Ip(strIp);
    int v8RemotePort = numRemotePort->NumberValue();
    int v8LocalPort = numLocalPort->NumberValue();
    String::Utf8Value v8Packet(strPacket);

    cout << "Node_FMFT_Connect packet : " << string(*v8Ip) << " RemotePort : " << v8RemotePort << " LocalPort : " << v8LocalPort << " packet : " << string(*v8Packet) << endl;

    Local<Number> numRet = Number::New(isolate, 0);
    Local<String> strPacket_2 = String::NewFromUtf8(isolate, *v8Packet);
    Local<Object> obj = Object::New(isolate);
    obj->Set(v8::String::NewFromUtf8(isolate, "Packet"), strPacket_2);
    obj->Set(v8::String::NewFromUtf8(isolate, "Result"), numRet);
    args.GetReturnValue().Set(obj);
    return;   
}

void Node_FMFT_Recv(const FunctionCallbackInfo<Value>& args)
{
    Isolate* isolate = Isolate::GetCurrent();
    HandleScope scope(isolate);

    if (args.Length() < 4)
    {
        isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "Wrong number of arguments")));
        return;
    }

    Local<Number> numId = Local<Number>::Cast(args[0]);
    Local<Number> numLen = Local<Number>::Cast(args[3]);

    int v8Id = numId->NumberValue();
    int v8Len = numLen->NumberValue();

    cout << "Node_FMFT_Recv id : " << v8Id << " Len : " << v8Len << endl;

    char* opcode = (char*) node::Buffer::Data(args[1]->ToObject());
    char* packet = (char*) node::Buffer::Data(args[2]->ToObject());

    for (int index = 0; index < v8Len; index++)
    {
        packet[index] = 'A';
    }

    opcode[0] = '1';


    Local<Number> numRet = Number::New(isolate, v8Len);
    Local<Object> obj = Object::New(isolate);
    obj->Set(v8::String::NewFromUtf8(isolate, "Result"), numRet);
    args.GetReturnValue().Set(obj);
    return;
}

void Node_FMFT_Send(const FunctionCallbackInfo<Value>& args)
{
    Isolate* isolate = Isolate::GetCurrent();
    HandleScope scope(isolate);

    if (args.Length() < 4)
    {
        isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "Wrong number of arguments")));
        return;
    }

    Local<Number> numId = Local<Number>::Cast(args[0]);
    Local<Number> numLen = Local<Number>::Cast(args[3]);

    int v8Id = numId->NumberValue();
    int v8Len = numLen->NumberValue();

    char* opcode = (char*) node::Buffer::Data(args[1]->ToObject());
    char* packet = (char*) node::Buffer::Data(args[2]->ToObject());


    cout << "Node_FMFT_Send id : " << v8Id << " Len : " << v8Len << " opcode : " << opcode << endl;

    Local<Number> numRet = Number::New(isolate, v8Len);
    Local<Object> obj = Object::New(isolate);
    obj->Set(v8::String::NewFromUtf8(isolate, "Result"), numRet);
    args.GetReturnValue().Set(obj);
    return;
}

void Node_FMFT_Can_Send(const FunctionCallbackInfo<Value>& args)
{
    Isolate* isolate = Isolate::GetCurrent();
    HandleScope scope(isolate);

    if (args.Length() < 1)
    {
        isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "Wrong number of arguments")));
        return;
    }

    if (!args[0]->IsNumber())
    {
        isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "argumnets must be String-Number")));
        return;
    }

    Local<Number> numId = Local<Number>::Cast(args[0]);
    int v8Id = numId->NumberValue();

    cout << "Node_FMFT_Can_Send id : " << v8Id << endl;

    Local<Number> numRet = Number::New(isolate, 1);
    Local<Object> obj = Object::New(isolate);
    obj->Set(v8::String::NewFromUtf8(isolate, "Result"), numRet);
    args.GetReturnValue().Set(obj);
}

void Node_FMFT_AddNode(const FunctionCallbackInfo<Value>& args)
{
    Isolate* isolate = Isolate::GetCurrent();
    HandleScope scope(isolate);

    if (args.Length() < 2)
    {
        isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "Wrong number of arguments")));
        return;
    }

    if (!args[0]->IsNumber() || !args[1]->IsString())
    {
        isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "argumnets must be String-Number")));
        return;
    }

    Local<String> strPacket = Local<String>::Cast(args[1]);
    Local<Number> numId = Local<Number>::Cast(args[0]);

    String::Utf8Value v8Packet(strPacket);
    int v8Id = numId->NumberValue();

    cout << "Node_FMFT_AddNode packet : " << string(*v8Packet) << " id : " << v8Id << endl;

    Local<Number> numRet = Number::New(isolate, 0);
    Local<Object> obj = Object::New(isolate);
    obj->Set(v8::String::NewFromUtf8(isolate, "Result"), numRet);
    args.GetReturnValue().Set(obj);
    return;
}

void Node_FMFT_DelNode(const FunctionCallbackInfo<Value>& args)
{
    Isolate* isolate = Isolate::GetCurrent();
    HandleScope scope(isolate);

    if (args.Length() < 1)
    {
        isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "Wrong number of arguments")));
        return;
    }

    if (!args[0]->IsNumber())
    {
        isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "argumnets must be String-Number")));
        return;
    }

    Local<Number> numId = Local<Number>::Cast(args[0]);
    int v8Id = numId->NumberValue();

    cout << "Node_FMFT_DelNode id : " << v8Id << endl;

    Local<Number> numRet = Number::New(isolate, 0);
    Local<Object> obj = Object::New(isolate);
    obj->Set(v8::String::NewFromUtf8(isolate, "Result"), numRet);
    args.GetReturnValue().Set(obj);
    return;
}

void init(Handle<Object> exports) {
    NODE_SET_METHOD(exports, "hello", hello);
    NODE_SET_METHOD(exports, "Addons_GTransfer_GetVersion", Node_GTransfer_GetVersion);
    NODE_SET_METHOD(exports, "Addons_GTransfer_Domain2IP" , Node_GTransfer_Domain2IP);
    NODE_SET_METHOD(exports, "Addons_FMFT_Init"           , Node_FMFT_Init);
    NODE_SET_METHOD(exports, "Addons_FMFT_Start_Listen"   , Node_FMFT_Start_Listen);
    NODE_SET_METHOD(exports, "Addons_FMFT_Stop_Listen"    , Node_FMFT_Stop_Listen);
    NODE_SET_METHOD(exports, "Addons_FMFT_Accept"         , Node_FMFT_Accept);
    NODE_SET_METHOD(exports, "Addons_FMFT_FinishAcccept"  , Node_FMFT_FinishAcccept);
    NODE_SET_METHOD(exports, "Addons_FMFT_Connect"        , Node_FMFT_Connect);
    NODE_SET_METHOD(exports, "Addons_FMFT_Recv"           , Node_FMFT_Recv);
    NODE_SET_METHOD(exports, "Addons_FMFT_Send"           , Node_FMFT_Send);
    NODE_SET_METHOD(exports, "Addons_FMFT_Can_Send"       , Node_FMFT_Can_Send);
    NODE_SET_METHOD(exports, "Addons_FMFT_AddNode"        , Node_FMFT_AddNode);
    NODE_SET_METHOD(exports, "Addons_FMFT_DelNode"        , Node_FMFT_DelNode);
}

NODE_MODULE(test, init);
