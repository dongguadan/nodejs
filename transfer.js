var test = require('./build/Release/transfer');

//test
test.hello('transfer', function(data) {
  console.log(data);
});
console.log(test.Addons_GTransfer_GetVersion());
console.log(test.Addons_GTransfer_Domain2IP('baidu.com', 80));



//server
console.log(test.Addons_FMFT_Init());
console.log(test.Addons_FMFT_Start_Listen(80));
console.log(test.Addons_FMFT_Accept());
console.log(test.Addons_FMFT_FinishAcccept("json message", 12));
console.log(test.Addons_FMFT_Stop_Listen());


//client
console.log(test.Addons_FMFT_Init());
console.log(test.Addons_FMFT_Connect("10.0.15.59", 36201, 36200, "json message"));
console.log(test.Addons_FMFT_AddNode(1, "json message"));
const opcode = Buffer.from("1");//0:json control message  1: raw video data
const packet = Buffer.from("video data");
console.log(test.Addons_FMFT_Can_Send(1));
console.log(test.Addons_FMFT_Send(1, opcode, packet, packet.length));
console.log(test.Addons_FMFT_Recv(1, opcode, packet, packet.length));
console.log(test.Addons_FMFT_DelNode(1));