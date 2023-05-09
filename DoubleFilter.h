#ifndef DOUBLE_FILTER_H_
#define DOUBLE_FILTER_H_
#include <systemc>
using namespace sc_core;

#ifndef NATIVE_SYSTEMC
#include <cynw_p2p.h>
#endif

#include "filter_def.h"

class DoubleFilter: public sc_module
{
public:
	sc_in_clk i_clk;
	sc_in < bool >  i_rst;
#ifndef NATIVE_SYSTEMC
	cynw_p2p< input_t >::in i_rgb;
	cynw_p2p< output_t >::out o_result;
#else
	sc_fifo_in< input_t > i_rgb;
	sc_fifo_out< output_t > o_result;
#endif

	SC_HAS_PROCESS( DoubleFilter );
	DoubleFilter( sc_module_name n );
	~DoubleFilter();
private:
	void do_filter();
	sc_dt::sc_uint<12> reds[9];
	sc_dt::sc_uint<12> greens[9];
	sc_dt::sc_uint<12> blues[9];
};
#endif
