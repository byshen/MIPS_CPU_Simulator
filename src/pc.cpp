#include "pc.hpp"
#include "env.hpp"
using namespace Env;

namespace MIPS {
void PC::onClock()
{
	// Add your code here
	if(in[zero] && in[branch])   m_pc = m_pc + 4*in[immData];

	m_pc = m_pc + 4;
	setOutput(newPC,m_pc);
}
}
