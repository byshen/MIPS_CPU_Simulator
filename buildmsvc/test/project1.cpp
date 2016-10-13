#include "gtest/gtest.h"
#include "cpu.hpp"
#include "env.hpp"
#include <stdio.h>
#include <Windows.h>
using namespace MIPS;
using namespace Env;
using std::string;
using namespace std;

TEST(cpu,project1)
{
    CPU cpu;

	//The input is 5!
	// You can change the value by changing the hex number.

    // <input:0> addi $v4, $v4, 5
    cpu.instMem.loadMemory(0x00000000, 0x20c60005);
    // <input:1> addi $v0, $v0, 0
    cpu.instMem.loadMemory(0x00000004, 0x20420000);
	// <input:2> addi $v1, $v1, 1
	cpu.instMem.loadMemory(0x00000008, 0x20630001);
	// <input:3> addi $v2, $v2, 2
	cpu.instMem.loadMemory(0x0000000c, 0x20840002);
	// <input:4> beq $v0, $v4, EXIT0
	cpu.instMem.loadMemory(0x00000010, 0x1046000e);
	// <input:5> beq $v1, $v4, EXIT1
	cpu.instMem.loadMemory(0x00000014, 0x1066000f);
	// <input:6> beq $v2, $v4, EXIT2
	cpu.instMem.loadMemory(0x00000018, 0x10860010);
	// <input:7> addi $v4, $v4, -2
	cpu.instMem.loadMemory(0x0000001c, 0x20c6fffe);
	//function
	// <input:8> add $v3, $v2, $v1
	cpu.instMem.loadMemory(0x00000020, 0x00832820);
	// <input:9> add $v3, $v3, $v1
	cpu.instMem.loadMemory(0x00000024, 0x00a32820);
	// <input:10> add $v3, $v3, $v0
	cpu.instMem.loadMemory(0x00000028, 0x00a22820);
	// <input:11> add $v3, $v3, $v0
	cpu.instMem.loadMemory(0x0000002c, 0x00a22820);
	// <input:12> add $v3, $v3, $v0
	cpu.instMem.loadMemory(0x00000030, 0x00a22820);
    // <input:13> addi $v4, $v4, -1
	cpu.instMem.loadMemory(0x00000034, 0x20c6ffff);
	// <input:14> beq $v4, $zero, EXIT
	cpu.instMem.loadMemory(0x00000038, 0x10c0000a);
	// <input:15> addi $v0, $v1, 0
	cpu.instMem.loadMemory(0x0000003c, 0x20620000);
	// <input:16> addi $v1, $v2, 0
	cpu.instMem.loadMemory(0x00000040, 0x20830000);
	// <input:17> addi $v2, $v3, 0
	cpu.instMem.loadMemory(0x00000044, 0x20a40000);
	// <input:18> beq $v0, $v0, function
	cpu.instMem.loadMemory(0x00000048, 0x1042fff5);
	// EXIT0
	// <input:19> addi $v3, $v0, 0
	cpu.instMem.loadMemory(0x0000004c, 0x20450000);
	// <input:20> beq $v0, $v0, EXIT
	cpu.instMem.loadMemory(0x00000050, 0x10420004);
	// EXIT1
	// <input:21> addi $v3, $v1, 0
	cpu.instMem.loadMemory(0x00000054, 0x20650000);
	// <input:22> beq $v0, $v0, EXIT
	cpu.instMem.loadMemory(0x00000058, 0x10420002);
	// EXIT2
	// <input:23> addi $v3, $v2, 0
	cpu.instMem.loadMemory(0x0000005c, 0x20850000);
	// <input:24> beq $v0, $v0, EXIT
	cpu.instMem.loadMemory(0x00000060, 0x10420000);
	// EXIT
	// <input:25> addi $v0, $v3, 0
	cpu.instMem.loadMemory(0x00000064, 0x20a20000);
	// End of the program
	cpu.instMem.loadMemory(0x00000068, 0xFFFFFFFF);	
	EXPECT_EQ(25, cpu.run());
}