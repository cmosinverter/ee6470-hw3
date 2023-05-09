#ifndef SYSTEM_H_
#define SYSTEM_H_
#include <systemc>
using namespace sc_core;

#include "Testbench.h"
#ifndef NATIVE_SYSTEMC
#include "DoubleFilter_wrap.h"
#else
#include "DoubleFilter.h"
#endif

#include "filter_def.h"

class System: public sc_module
{
public:
	SC_HAS_PROCESS( System );
	System( sc_module_name n, std::string input_bmp, std::string output_bmp );
	~System();
private:
  Testbench tb;
#ifndef NATIVE_SYSTEMC
	DoubleFilter_wrapper double_filter;
#else
	DoubleFilter double_filter;
#endif
	sc_clock clk;
	sc_signal<bool> rst;
#ifndef NATIVE_SYSTEMC
	cynw_p2p< input_t > rgb;
	cynw_p2p< output_t > result;
#else
	sc_fifo< input_t > rgb;
	sc_fifo< output_t > result;
#endif

	std::string _output_bmp;
};
#endif
