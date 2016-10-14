`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    10:19:00 02/27/2014 
// Design Name: 
// Module Name:    AluCtr 
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
module AluCtr(
    input [1:0] aluOp,
    input [5:0] funct,
    output [3:0] aluCtr
    );
	 
	 reg [3:0] aluCtr;
	 
	 always @(aluOp or funct)
	 casex({aluOp, funct})
	     8'b00xxxxxx: aluCtr = 4'b0010;
		  8'b01xxxxxx: aluCtr = 4'b0110;
		  8'b10100000: aluCtr = 4'b0010;
		  8'b10100010: aluCtr = 4'b0110;
		  8'b10100100: aluCtr = 4'b0000;
		  8'b10100101: aluCtr = 4'b0001;
		  8'b10101010: aluCtr = 4'b0111;
		  default: aluCtr = 4'b0000;
	 endcase

endmodule
