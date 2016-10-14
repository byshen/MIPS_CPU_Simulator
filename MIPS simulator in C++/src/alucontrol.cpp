#include "alucontrol.hpp"
#include "env.hpp"
using namespace Env;

namespace MIPS {
void ALUControl::onChange()
{
	// Add your code here
	if(in[aluOp] == 0){
		setOutput(aluCtr,B("0010"));
		return;
	}
	if(in[aluOp] == 1){
		setOutput(aluCtr,B("0110"));
		return;
	}
	if(in[aluOp] == 2){
		if(in[funct] == 0){
			setOutput(aluCtr,B("0010"));
			return;
		}
		if(in[funct] == 2){
			setOutput(aluCtr,B("0110"));
			return;
		}if(in[funct] == 4){
			setOutput(aluCtr,B("0000"));
			return;
		}if(in[funct] == 5){
			setOutput(aluCtr,B("0001"));
			return;
		}
		if(in[funct] == 10){
			setOutput(aluCtr,B("0111"));
			return;
		}

	}


}
}
