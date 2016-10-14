`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    08:18:22 03/06/2014 
// Design Name: 
// Module Name:    register 
// Project Name: 
// Target Devices: 
// Tool versions: 
// Description: 
//
// Dependencies: 
//
// Revision: 
// Revision 0.01 - File Created
// Additional Comments: 
//
//////////////////////////////////////////////////////////////////////////////////
module register(
    input clock_in,
	 input [25:21]readReg1,
	 input [20:16]readReg2,
	 input [4:0]writeReg,
	 input [31:0]writeData,
	 input regWrite,
	 output [31:0]readData1,
	 output [31:0]readData2,
	 input res
    );
	 
	 reg [31:0] regFile[0:31];
	 reg [31:0] readData1;
	 reg [31:0] readData2;
	 integer i;
	 initial
	 begin
	     $readmemh("./Src/regist.txt",regFile,32'h0);
	 end
		  
	 
	 always @ (readReg1 or readReg2 or readData1 or readData2 or regFile)
	 begin
	     readData1 = regFile [ readReg1 ];
		  readData2 = regFile [ readReg2 ];
	 end
	 
	 always @(posedge clock_in)
	 begin
	     if(res==1)
		  			for (i=0;i<32;i=i+1) 
					regFile[i] = 32'b0;		      
	 end
	 
	 always @(negedge clock_in)
	 begin
	     if(regWrite==1)
		      regFile[writeReg] = writeData;		      
	 end


endmodule
