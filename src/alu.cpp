#include "alu.hpp"
#include "env.hpp"
using namespace Env;

namespace MIPS {
void ALU::onChange()
{
	// Add your code here
	LineData result = 0;
	switch(in[aluCtr]){
	case 0://and
		result = in[input1]&in[input2];
		setOutput(zero, (result == 0) ? 1 : 0);
		break;
	case 1://or
		result = in[input1]|in[input2];
		setOutput(zero, (result == 0) ? 1 : 0);
		break;
	case 2:
		result = in[input1]+in[input2];
		setOutput(zero, (result == 0) ? 1 : 0);
		break;
	case 6:
		result = in[input1]-in[input2];
		setOutput(zero, (result == 0) ? 1 : 0);
		break;
	case 7:// set on if less than
		if(in[input1]<in[input2])
			result = 1;
		else 
			result =0;
		setOutput(zero, (result == 0) ? 1 : 0);
		break;
	case 12:
		result = ~(in[input1]|in[input2]);
		setOutput(zero, (result == 0) ? 1 : 0);
		break;
	}
	setOutput(aluRes,result);
}
}