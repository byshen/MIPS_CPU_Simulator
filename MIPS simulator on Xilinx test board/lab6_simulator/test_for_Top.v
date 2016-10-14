`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   08:32:22 03/20/2014
// Design Name:   Top
// Module Name:   E:/codsjtu_design/genesys/lab6/test_for_Top.v
// Project Name:  lab6
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: Top
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module test_for_Top;

	// Inputs
	reg CLOCK_IN;
	reg RESET;

	// Outputs

	// Instantiate the Unit Under Test (UUT)
	Top uut (
		.CLOCK_IN(CLOCK_IN), 
		.RESET(RESET)
	);

	initial begin
		// Initialize Inputs
		CLOCK_IN = 0;
		RESET = 1;

		// Wait 100 ns for global reset to finish
		#100;
        RESET=0;
		// Add stimulus here

	end
	always 
	#2 CLOCK_IN=!CLOCK_IN;
      
endmodule

