#include <cmath>
#include <algorithm>
#ifndef NATIVE_SYSTEMC
#include "stratus_hls.h"
#endif

#include "DoubleFilter.h"

DoubleFilter::DoubleFilter( sc_module_name n ): sc_module( n )
{
// #ifndef NATIVE_SYSTEMC
// HLS_FLATTEN_ARRAY(reds);
// HLS_FLATTEN_ARRAY(greens);
// HLS_FLATTEN_ARRAY(blues);
// #endif

	SC_THREAD( do_filter );
	sensitive << i_clk.pos();
	dont_initialize();
	reset_signal_is(i_rst, false);
        
#ifndef NATIVE_SYSTEMC
	i_rgb.clk_rst(i_clk, i_rst);
  	o_result.clk_rst(i_clk, i_rst);
#endif
}

DoubleFilter::~DoubleFilter() {}

void DoubleFilter::do_filter() {
	{
#ifndef NATIVE_SYSTEMC
		HLS_DEFINE_PROTOCOL("main_reset");
		i_rgb.reset();
		o_result.reset();
#endif
		wait();
	}

  	unsigned char column;
	
while_1:
	while (true) {

feed_loop:
		for (unsigned int v = 0; v<MASK_Y; ++v) { //0, 1, 2
				input_t rgb;
#ifndef NATIVE_SYSTEMC
				{
					HLS_DEFINE_PROTOCOL("input");
					rgb = i_rgb.get();
					wait();
				}
#else
				rgb = i_rgb.read();
#endif
					column = rgb.range(31,24);
					if (column == 0) {

						// Improved Coding Style
						reds[(v + (v << 1)) + 0] = rgb.range(7,0);
						greens[(v + (v << 1)) + 0] = rgb.range(15,8);
						blues[(v + (v << 1)) + 0] = rgb.range(23,16);

						// Poor Coding Style
						// reds[(3 * v) + 0] = rgb.range(7,0);
						// greens[(3 * v) + 0] = rgb.range(15,8);
						// blues[(3 * v) + 0] = rgb.range(23,16);
#ifndef NATIVE_SYSTEMC
				{
						HLS_DEFINE_PROTOCOL("input");
						rgb = i_rgb.get();
						wait();
				}
#else
						rgb = i_rgb.read();

#endif					// Improved Coding Style
						reds[(v + (v << 1)) + 1] = rgb.range(7,0);
						greens[(v + (v << 1)) + 1] = rgb.range(15,8);
						blues[(v + (v << 1)) + 1] = rgb.range(23,16);

						// Poor Coding Style
						// reds[(3 * v) + 1] = rgb.range(7,0);
						// greens[(3 * v) + 1] = rgb.range(15,8);
						// blues[(3 * v) + 1] = rgb.range(23,16);
#ifndef NATIVE_SYSTEMC
				{
						HLS_DEFINE_PROTOCOL("input");
						rgb = i_rgb.get();
						wait();
				}
#else
						rgb = i_rgb.read();

#endif					// Improved Coding Style
						reds[(v + (v << 1)) + 2] = rgb.range(7,0);
						greens[(v + (v << 1)) + 2] = rgb.range(15,8);
						blues[(v + (v << 1)) + 2] = rgb.range(23,16);

						// Poor Coding Style
						// reds[(3 * v) + 2] = rgb.range(7,0);
						// greens[(3 * v) + 2] = rgb.range(15,8);
						// blues[(3 * v) + 2] = rgb.range(23,16);
						
					} else {
						// Improved Coding Style
						reds[(v + (v << 1)) + ((column-1) & 0x3)] = rgb.range(7,0);
						greens[(v + (v << 1)) + ((column-1) & 0x3)] = rgb.range(15,8);
						blues[(v + (v << 1)) + ((column-1) & 0x3)] = rgb.range(23,16);

						// Poor Coding Style
						// reds[(3 * v) + ((column-1) % 3)] = rgb.range(7,0);
						// greens[(3 * v) + ((column-1) % 3)] = rgb.range(15,8);
						// blues[(3 * v) + ((column-1) % 3)] = rgb.range(23,16);
					}
				}
		// Improved Coding Style
		unsigned char center_r;
		unsigned char center_g;
		unsigned char center_b;

		// Poor Coding Style
		// int center_r;
		// int center_g;
		// int center_b;

		switch(column % 3) {
			case 0:
				center_r = reds[4];
				center_g = greens[4];
				center_b = blues[4];
				break;
			case 1:
				center_r = reds[5];
				center_g = greens[5];
				center_b = blues[5];
				break;
			case 2:
				center_r = reds[3];
				center_g = greens[3];
				center_b = blues[3];
				break;
		}

		std::sort(reds, reds + 9);
		std::sort(greens, greens + 9);
		std::sort(blues, blues + 9);

		// Improved Coding Style
		sc_dt::sc_uint<12> sum_r;
		sc_dt::sc_uint<12> sum_g;
		sc_dt::sc_uint<12> sum_b;

		// Poor Coding Style
		// int sum_r;
		// int sum_g;
		// int sum_b;

		sum_r = 0;
		sum_g = 0;
		sum_b = 0;

sum_loop:
		for (int i = 0; i < 9; i++) {
			sum_r += reds[i];
			sum_g += greens[i];
			sum_b += blues[i];
		}

		sc_dt::sc_uint<8> o_r;
		sc_dt::sc_uint<8> o_g;
		sc_dt::sc_uint<8> o_b;
		o_r = (sum_r - center_r + (reds[4] * 2)) / 10;
		o_g = (sum_g - center_g + (greens[4] * 2)) / 10;
		o_b = (sum_b - center_b + (blues[4] * 2)) / 10;

		output_t total;
		total = (o_b, o_g, o_r);

#ifndef NATIVE_SYSTEMC
		{
			HLS_DEFINE_PROTOCOL("output");
			o_result.put(total);
			wait();
		}
#else
		o_result.write(total);
#endif
	}
}
