`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    17:02:04 03/18/2014 
// Design Name: 
// Module Name:    Top 
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
module Top(
    input CLOCK_IN,
	 input RESET
	 );
	 
	 //for io
	 wire CLK;
	 assign CLK=CLOCK_IN;
	 
	 //Regs
	 //PC
	 reg [31:0] PC;
	 
	 //1.0 for stage IF to ID
	 reg [31:0] IF_ID_PcAdd4;
	 reg [31:0] IF_ID_Instruction;
	 
	 //2.0 for stage ID to EX
	 reg [31:0] ID_EX_PcAdd4;
	 reg [31:0] ID_EX_ReadData1;
	 reg [31:0] ID_EX_ReadData2;
	 reg [31:0] ID_EX_SignExt;
	 reg [20:16] ID_EX_InstHigh;
	 reg [15:11] ID_EX_InstLow;
	 //2.1 to EX
	 reg ID_EX_RegDst;
	 reg [1:0] ID_EX_ALUOp;
	 reg ID_EX_ALUSrc;
	 //2.2 to MEM;
	 reg ID_EX_Branch;
    reg ID_EX_MemRead;
    reg ID_EX_MemWrite;
	 //2.3 to WB
	 reg ID_EX_MemToReg;
    reg ID_EX_RegWrite;
	 
	 //3.0 for stage EX to MEM
	 reg [31:0] EX_MEM_PcNew;
	 reg EX_MEM_Zero;
	 reg [31:0] EX_MEM_ALUOut;
    reg [31:0] EX_MEM_ReadData2;
	 reg [4:0] EX_MEM_WriteReg;
	 //3.1 to MEM;
	 reg EX_MEM_Branch;
    reg EX_MEM_MemRead;
    reg EX_MEM_MemWrite;
	 //3.2 to WB
	 reg EX_MEM_MemToReg;
    reg EX_MEM_RegWrite;
	 
	 //4.0 for stage MEM to WB
	 reg [31:0] MEM_WB_ALUOut;
    reg [31:0] MEM_WB_ReadData;
	 reg [4:0] MEM_WB_WriteReg;
	 //4.1 to WB
	 reg MEM_WB_MemToReg;
    reg MEM_WB_RegWrite;
	 
	 //wire
	  wire REG_DST,
	     JUMP,
		  BRANCH,
		  MEM_READ,
		  MEM_TO_REG,
		  MEM_WRITE;
	 wire [1:0] ALU_OP;
	 wire ALU_SRC,
	     REG_WRITE;
	 wire [31:0] REG_READ1,REG_READ2,SGE_OUT;
	 wire ZERO;
	 wire [31:0] ALU_OUT,MEM_DATA,READ_ADD,INST;
	 wire [3:0] ALU_CTR;
	 
	 initial
	 begin
	 PC<=32'b0;
	 end	 
	 
	 Ctr mainCtr(
	         .opCode(IF_ID_Instruction[31:26]),
				.regDst(REG_DST),
				.jump(JUMP),
				.branch(BRANCH),
				.memRead(MEM_READ),
				.memToReg(MEM_TO_REG),
				.aluOp(ALU_OP),
				.memWrite(MEM_WRITE),
				.aluSrc(ALU_SRC),
				.regWrite(REG_WRITE));
	 signext se(
	         .inst(IF_ID_Instruction[15:0]),
				.data(SGE_OUT));
	 AluCtr aluCtr(
	         .aluOp(ID_EX_ALUOp),
				.funct(ID_EX_SignExt[5:0]),
				.aluCtr(ALU_CTR));
	 Alu alu(
	         .input1(ID_EX_ReadData1),
				.input2(ID_EX_ALUSrc? ID_EX_SignExt:ID_EX_ReadData2),
				.zero(ZERO),
				.aluRes(ALU_OUT),
				.aluCtr(ALU_CTR));
	 register regs(
	         .clock_in(CLK),
				.res(RESET),
	         .readReg1(IF_ID_Instruction[25:21]),
	         .readReg2(IF_ID_Instruction[20:16]),
	         .writeReg(MEM_WB_WriteReg),
	         .writeData(MEM_WB_MemToReg? MEM_WB_ReadData:MEM_WB_ALUOut),
	         .regWrite(MEM_WB_RegWrite),
	         .readData1(REG_READ1),
				.readData2(REG_READ2));
	 data_memory dm(
            .clock_in(CLK),
	         .writeData(EX_MEM_ReadData2),
	         .address(EX_MEM_ALUOut),
	         .memRead(EX_MEM_MemRead),
	         .memWrite(EX_MEM_MemWrite),
	         .readData(MEM_DATA));
	 inst_memory im(
	         .address(READ_ADD/4),
	         .readData(INST));
	assign READ_ADD=PC;
	always@(posedge CLK)
	begin
		if (RESET == 1)
		begin
	      PC<=32'b0;
	 
			IF_ID_PcAdd4 <= 0;
			IF_ID_Instruction <= 0;
				
			ID_EX_PcAdd4 <= 0;
			ID_EX_ReadData1 <= 0;
			ID_EX_ReadData2 <= 0;
			ID_EX_SignExt <= 0;
			ID_EX_InstHigh <= 0;
			ID_EX_InstLow <= 0;
			ID_EX_RegDst <= 0;
			ID_EX_ALUOp <= 0;
			ID_EX_ALUSrc <= 0;
			ID_EX_Branch <= 0;
			ID_EX_MemWrite <= 0;
			ID_EX_MemRead <= 0;
			ID_EX_RegWrite <= 0;
			ID_EX_MemToReg <= 0;
				
			EX_MEM_PcNew <= 0;
			EX_MEM_Zero <= 0;
			EX_MEM_ALUOut <= 0;
			EX_MEM_ReadData2 <= 0;
			EX_MEM_WriteReg <= 0;
			EX_MEM_Branch <= 0;
			EX_MEM_MemWrite <= 0;
			EX_MEM_MemRead <= 0;
			EX_MEM_RegWrite <= 0;
			EX_MEM_MemToReg <= 0;
				
			MEM_WB_ALUOut <= 0;
			MEM_WB_ReadData <= 0;
			MEM_WB_WriteReg <= 0;
			MEM_WB_RegWrite <= 0;
			MEM_WB_MemToReg <= 0;
		end
		else
		begin
			IF_ID_PcAdd4 <= READ_ADD+4;
			IF_ID_Instruction <= INST;
			
		   ID_EX_PcAdd4 <= IF_ID_PcAdd4;
			ID_EX_ReadData1 <= REG_READ1;
			ID_EX_ReadData2 <= REG_READ2;
			ID_EX_SignExt <= SGE_OUT;
			ID_EX_InstHigh <= IF_ID_Instruction[20:16];
			ID_EX_InstLow <= IF_ID_Instruction[15:11];
		   ID_EX_RegDst <= REG_DST;
			ID_EX_ALUOp <= ALU_OP;
			ID_EX_ALUSrc <= ALU_SRC;
			ID_EX_Branch <= BRANCH;
			ID_EX_MemWrite <= MEM_WRITE;
			ID_EX_MemRead <= MEM_READ;
			ID_EX_RegWrite <= REG_WRITE;
			ID_EX_MemToReg <= MEM_TO_REG;
			
			EX_MEM_PcNew <= ID_EX_PcAdd4 + (ID_EX_SignExt << 2);
			EX_MEM_Zero <= ZERO;
			EX_MEM_ALUOut <= ALU_OUT;
			EX_MEM_ReadData2 <= ID_EX_ReadData2;
			EX_MEM_WriteReg <= ID_EX_RegDst ? ID_EX_InstLow : ID_EX_InstHigh;
			EX_MEM_Branch <= ID_EX_Branch;
			EX_MEM_MemWrite <= ID_EX_MemWrite;
			EX_MEM_MemRead <= ID_EX_MemRead;
			EX_MEM_RegWrite <= ID_EX_RegWrite;
			EX_MEM_MemToReg <= ID_EX_MemToReg;
			
			MEM_WB_ALUOut <= EX_MEM_ALUOut;
			MEM_WB_ReadData <= MEM_DATA;
			MEM_WB_WriteReg <= EX_MEM_WriteReg;
			MEM_WB_RegWrite <= EX_MEM_RegWrite;
			MEM_WB_MemToReg <= EX_MEM_MemToReg;
			
			PC <= (EX_MEM_Zero & EX_MEM_Branch) ?  EX_MEM_PcNew : (PC+4);
			
			if (EX_MEM_Zero & EX_MEM_Branch)
			begin
			IF_ID_PcAdd4 <= 0;
			IF_ID_Instruction <= 0;
				
			ID_EX_PcAdd4 <= 0;
			ID_EX_ReadData1 <= 0;
			ID_EX_ReadData2 <= 0;
			ID_EX_SignExt <= 0;
			ID_EX_InstHigh <= 0;
			ID_EX_InstLow <= 0;
			ID_EX_RegDst <= 0;
			ID_EX_ALUOp <= 0;
			ID_EX_ALUSrc <= 0;
			ID_EX_Branch <= 0;
			ID_EX_MemWrite <= 0;
			ID_EX_MemRead <= 0;
			ID_EX_RegWrite <= 0;
			ID_EX_MemToReg <= 0;
				
			EX_MEM_PcNew <= 0;
			EX_MEM_Zero <= 0;
			EX_MEM_ALUOut <= 0;
			EX_MEM_ReadData2 <= 0;
			EX_MEM_WriteReg <= 0;
			EX_MEM_Branch <= 0;
			EX_MEM_MemWrite <= 0;
			EX_MEM_MemRead <= 0;
			EX_MEM_RegWrite <= 0;
			EX_MEM_MemToReg <= 0;			end
		end	
	end

endmodule
