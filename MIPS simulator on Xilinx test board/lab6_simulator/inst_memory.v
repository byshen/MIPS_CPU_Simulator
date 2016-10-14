`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    08:38:24 03/13/2014 
// Design Name: 
// Module Name:    inst_memory 
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
module inst_memory(
	 input [31:0]address,
	 output reg[31:0] readData
    );
	 
	 reg [31:0] memFile[0:255];
	 
	 initial
	 begin
	     $readmemb("./Src/mem_inst.txt",memFile,8'h0);
	 end
	 
	 always @(address or readData or memFile)
	 begin
		      readData=memFile[address];
	 end


endmodule
