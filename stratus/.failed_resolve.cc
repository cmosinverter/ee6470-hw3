/********************/
state0:;
/*HLS_SET_OUTPUT_OPTIONS(i_rgb_m_use_stall_reg_ip, 4ULL);*//* 93ULL */
/*HLS_SET_OUTPUT_OPTIONS(o_result_m_req_m_trig_req, 0ULL);*//* 116ULL */
/*HLS_SET_OUTPUT_OPTIONS(i_rgb_m_stalling, 11ULL);*//* 36ULL */
/*HLS_SET_OUTPUT_OPTIONS(i_rgb_m_busy_req_0, 0ULL);*//* 88ULL */
/*HLS_SET_INPUT_DELAY(i_rgb_data, -1.000000);*//* 101ULL */
/*HLS_SET_OUTPUT_OPTIONS(o_result_data, 2ULL);*//* 117ULL */
center_b = 0ULL;
center_g = 0ULL;
center_r = 0ULL;
goto state1;
/********************/
state1:;
goto state2;
/********************/
state2:;
/*HLS_DEFINE_PROTOCOL("main_reset");*//* 33ULL */
i_rgb_m_busy_req_0 = 1ULL;
i_rgb_m_stalling = 0ULL;
o_result_m_req_m_trig_req = 0ULL;
goto state3;
/********************/
state3:;
/*HLS_DEFINE_PROTOCOL("main_reset");*//* 33ULL */
wait( 1LL ); // cycle_id 1
goto state4;
/********************/
state4:;
/*HLS_LOOP_NAME("while_1");*//* 44ULL */
v = 0ULL;
goto state5;
/********************/
state5:;
/*CYN_ITERATIONS(3ULL, "<generated>");*//* 302ULL */
/*HLS_LOOP_NAME("feed_loop");*//* 47ULL */
goto state6;
/********************/
state6:;
/*HLS_DEFINE_PROTOCOL("input");*//* 49ULL */
i_rgb_m_busy_req_0 = 0ULL;
goto state7;
/********************/
state7:;
/*HLS_DEFINE_STALL_LOOP(ALL,4096ULL, "get", (long long)0x0ULL);*//* 60ULL */
/*HLS_DEFINE_PROTOCOL("input");*//* 49ULL */
goto state8;
/********************/
state8:;
/*HLS_DEFINE_STALL_LOOP(ALL,4096ULL, "get", (long long)0x0ULL);*//* 60ULL */
/*HLS_DEFINE_PROTOCOL("input");*//* 49ULL */
wait( 1LL ); // cycle_id 2
stall0 = i_rgb_m_data_is_invalid;
goto state9;
/********************/
state9:;
/*HLS_DEFINE_PROTOCOL("input");*//* 49ULL */
/*HLS_SET_STALL_LOCAL(i_rgb_m_stalling, 1ULL, 0ULL, (long long)0x0ULL, 
(long long)0x0ULL);*//* 63ULL */
i_rgb_m_busy_req_0 = 1ULL;
u_g_n_686 = i_rgb_data;
goto state10;
/********************/
state10:;
/*HLS_DEFINE_PROTOCOL("input");*//* 49ULL */
wait( 1LL ); // cycle_id 3
goto state11;
/********************/
state11:;
column = u_g_n_686.range(31,24);
logic_in_001 = ((sc_uint<8>)column).or_reduce();
guard_001 = !logic_in_001;
if /*guard*/( guard_001 ) /*Enable*/if (guard_001) (reds)[(sc_uint<4> )(( 
(/*cliff*/sc_uint<32>)((sc_uint<2> )v + ( (sc_uint<3> )(sc_bv<3>)((sc_bv<2>)((
sc_uint<2> )v), 
(sc_bv<1>)(0ULL)) )) ))] = (sc_uint<8> )(((sc_uint<8> )u_g_n_686).range(7,0));
guard_002 = !logic_in_001;
if /*guard*/( guard_001 ) /*Enable*/if (guard_002) (greens)[(sc_uint<4> )(( 
(/*cliff*/sc_uint<32>)((sc_uint<2> )v + ( (sc_uint<3> )(sc_bv<3>)((sc_bv<2>)((
sc_uint<2> )v), 
(sc_bv<1>)(0ULL)) )) ))] = (sc_uint<8> )(((sc_uint<16> )u_g_n_686).range(15,8));
guard_003 = !logic_in_001;
if /*guard*/( guard_001 ) /*Enable*/if (guard_003) (blues)[(sc_uint<4> )(( 
(/*cliff*/sc_uint<32>)((sc_uint<2> )v + ( (sc_uint<3> )(sc_bv<3>)((sc_bv<2>)((
sc_uint<2> )v), 
(sc_bv<1>)(0ULL)) )) ))] = (sc_uint<8> )(((sc_uint<24> )u_g_n_686).range(23,16))
;
guard_004 = ((sc_uint<8>)column).or_reduce();
if /*guard*/( logic_in_001 ) /*Enable*/if (guard_004) (reds)[(sc_uint<4> )(( (
(/*cliff*/sc_uint<32>)((sc_uint<2> )v + ( (sc_uint<3> )(sc_bv<3>)((sc_bv<2>)((
sc_uint<2> )v), 
(sc_bv<1>)(0ULL)) )) + ((/*imp*/sc_uint<2> ) ((/*imp*/sc_int<2> ) (
(/*cliff*/sc_int<32>)(sc_uint<2> )column - 1ULL)).range(1,0))) ))] = (
                                                                     sc_uint<8> 
                                                                     )(((
                                                                     sc_uint<8> 
                                                                     )u_g_n_686)
                                                                     .range(7,0)
                                                                     );
guard_005 = ((sc_uint<8>)column).or_reduce();
if /*guard*/( logic_in_001 ) /*Enable*/if (guard_005) (greens)[(sc_uint<4> )(( (
(/*cliff*/sc_uint<32>)((sc_uint<2> )v + ( (sc_uint<3> )(sc_bv<3>)((sc_bv<2>)((
sc_uint<2> )v), 
(sc_bv<1>)(0ULL)) )) + ((/*imp*/sc_uint<2> ) ((/*imp*/sc_int<2> ) (
(/*cliff*/sc_int<32>)(sc_uint<2> )column - 1ULL)).range(1,0))) ))] = (
                                                                     sc_uint<8> 
                                                                     )(((sc_uint<16> 
                                                                     )u_g_n_686)
                                                                     .range(15,8
                                                                     ));
guard_006 = ((sc_uint<8>)column).or_reduce();
if /*guard*/( logic_in_001 ) /*Enable*/if (guard_006) (blues)[(sc_uint<4> )(( (
(/*cliff*/sc_uint<32>)((sc_uint<2> )v + ( (sc_uint<3> )(sc_bv<3>)((sc_bv<2>)((
sc_uint<2> )v), 
(sc_bv<1>)(0ULL)) )) + ((/*imp*/sc_uint<2> ) ((/*imp*/sc_int<2> ) (
(/*cliff*/sc_int<32>)(sc_uint<2> )column - 1ULL)).range(1,0))) ))] = (
                                                                     sc_uint<8> 
                                                                     )(((sc_uint<24> 
                                                                     )u_g_n_686)
                                                                     .range(23,
                                                                     16));
switch( (sc_uint<8>)(column) ) {
case 0ULL: 
  goto state12;
default:
  goto state22;
}
/********************/
state12:;
/*HLS_DEFINE_PROTOCOL("cynw_p2p_in_get");*//* 68ULL */
i_rgb_m_busy_req_0 = 0ULL;
goto state13;
/********************/
state13:;
/*HLS_DEFINE_STALL_LOOP(ALL,4096ULL, "get", (long long)0x0ULL);*//* 78ULL */
/*HLS_DEFINE_PROTOCOL("cynw_p2p_in_get");*//* 68ULL */
goto state14;
/********************/
state14:;
/*HLS_DEFINE_STALL_LOOP(ALL,4096ULL, "get", (long long)0x0ULL);*//* 78ULL */
/*HLS_DEFINE_PROTOCOL("cynw_p2p_in_get");*//* 68ULL */
wait( 1LL ); // cycle_id 4
stall0 = i_rgb_m_data_is_invalid;
goto state15;
/********************/
state15:;
/*HLS_DEFINE_PROTOCOL("cynw_p2p_in_get");*//* 68ULL */
/*HLS_SET_STALL_LOCAL(i_rgb_m_stalling, 1ULL, 0ULL, (long long)0x0ULL, 
(long long)0x0ULL);*//* 81ULL */
i_rgb_m_busy_req_0 = 1ULL;
u_g_n_686_i0 = i_rgb_data;
goto state16;
/********************/
state16:;
(reds)[(sc_uint<4> )(( (/*cliff*/sc_uint<32>)((/*cliff*/sc_uint<32>)((
sc_uint<2> )v + ( (sc_uint<3> )(sc_bv<3>)((sc_bv<2>)((sc_uint<2> )v), 
(sc_bv<1>)(0ULL)) )) + 1ULL) ))] = (sc_uint<8> )(((sc_uint<8> )u_g_n_686_i0)
                                   .range(7,0));
(greens)[(sc_uint<4> )(( (/*cliff*/sc_uint<32>)((/*cliff*/sc_uint<32>)((
sc_uint<2> )v + ( (sc_uint<3> )(sc_bv<3>)((sc_bv<2>)((sc_uint<2> )v), 
(sc_bv<1>)(0ULL)) )) + 1ULL) ))] = (sc_uint<8> )(((sc_uint<16> )u_g_n_686_i0)
                                   .range(15,8));
(blues)[(sc_uint<4> )(( (/*cliff*/sc_uint<32>)((/*cliff*/sc_uint<32>)((
sc_uint<2> )v + ( (sc_uint<3> )(sc_bv<3>)((sc_bv<2>)((sc_uint<2> )v), 
(sc_bv<1>)(0ULL)) )) + 1ULL) ))] = (sc_uint<8> )(u_g_n_686_i0.range(23,16));
goto state17;
/********************/
state17:;
/*HLS_DEFINE_PROTOCOL("cynw_p2p_in_get");*//* 86ULL */
i_rgb_m_busy_req_0 = 0ULL;
goto state18;
/********************/
state18:;
/*HLS_DEFINE_STALL_LOOP(ALL,4096ULL, "get", (long long)0x0ULL);*//* 96ULL */
/*HLS_DEFINE_PROTOCOL("cynw_p2p_in_get");*//* 86ULL */
goto state19;
/********************/
state19:;
/*HLS_DEFINE_STALL_LOOP(ALL,4096ULL, "get", (long long)0x0ULL);*//* 96ULL */
/*HLS_DEFINE_PROTOCOL("cynw_p2p_in_get");*//* 86ULL */
wait( 1LL ); // cycle_id 5
stall0 = i_rgb_m_data_is_invalid;
goto state20;
/********************/
state20:;
/*HLS_DEFINE_PROTOCOL("cynw_p2p_in_get");*//* 86ULL */
/*HLS_SET_STALL_LOCAL(i_rgb_m_stalling, 1ULL, 0ULL, (long long)0x0ULL, 
(long long)0x0ULL);*//* 99ULL */
i_rgb_m_busy_req_0 = 1ULL;
u_g_n_686_i1 = i_rgb_data;
goto state21;
/********************/
state21:;
(reds)[(sc_uint<4> )(( (/*cliff*/sc_uint<32>)((/*cliff*/sc_uint<32>)((
sc_uint<2> )v + ( (sc_uint<3> )(sc_bv<3>)((sc_bv<2>)((sc_uint<2> )v), 
(sc_bv<1>)(0ULL)) )) + 2ULL) ))] = (sc_uint<8> )(((sc_uint<8> )u_g_n_686_i1)
                                   .range(7,0));
(greens)[(sc_uint<4> )(( (/*cliff*/sc_uint<32>)((/*cliff*/sc_uint<32>)((
sc_uint<2> )v + ( (sc_uint<3> )(sc_bv<3>)((sc_bv<2>)((sc_uint<2> )v), 
(sc_bv<1>)(0ULL)) )) + 2ULL) ))] = (sc_uint<8> )(((sc_uint<16> )u_g_n_686_i1)
                                   .range(15,8));
(blues)[(sc_uint<4> )(( (/*cliff*/sc_uint<32>)((/*cliff*/sc_uint<32>)((
sc_uint<2> )v + ( (sc_uint<3> )(sc_bv<3>)((sc_bv<2>)((sc_uint<2> )v), 
(sc_bv<1>)(0ULL)) )) + 2ULL) ))] = (sc_uint<8> )(u_g_n_686_i1.range(23,16));
goto state22;
/********************/
state22:;
v = (/*cliff*/sc_uint<32>)((sc_uint<2> )v + 1ULL);
condvar_001 = (/*imp*/sc_uint<1>)(v < ((/*imp*/sc_uint<2> )(3ULL)));
switch( (sc_uint<1>)(condvar_001) ) {
case 0ULL: 
  goto state23;
case 1ULL: 
  goto state5;
}
/********************/
state23:;
amtmp001 = ((sc_uint<2> )column).range(1,0);
logic_in_004 = ((sc_uint<2>)amtmp001).or_reduce();
guard_007 = !logic_in_004;
guard_008 = (amtmp001 == 1ULL);
guard_009 = (amtmp001 == 2ULL);
center_r = ( 2LL== (amtmp001) ? (sc_uint<8> )
               (/*Enable*/(guard_009?(sc_uint<8> )(reds)[((/*imp*/sc_uint<2> )(
             3ULL))]:(sc_uint<8> )0ULL)) : 
             1LL== (amtmp001) ? (sc_uint<8> )
               (/*Enable*/(guard_008?(sc_uint<8> )(reds)[((/*imp*/sc_uint<3> )(
             5ULL))]:(sc_uint<8> )0ULL)) : 
             0LL== (amtmp001) ? (sc_uint<8> )
               (/*Enable*/(guard_007?(sc_uint<8> )(reds)[((/*imp*/sc_uint<3> )(
             4ULL))]:(sc_uint<8> )0ULL)) : 
             /*DEFAULT*/ (sc_uint<8> )
               (center_r) );
guard_011 = (amtmp001 == 1ULL);
guard_012 = (amtmp001 == 2ULL);
center_g = ( 2LL== (amtmp001) ? (sc_uint<8> )
               (/*Enable*/(guard_012?(sc_uint<8> )(greens)[((/*imp*/sc_uint<2> 
             )(3ULL))]:(sc_uint<8> )0ULL)) : 
             1LL== (amtmp001) ? (sc_uint<8> )
               (/*Enable*/(guard_011?(sc_uint<8> )(greens)[((/*imp*/sc_uint<3> 
             )(5ULL))]:(sc_uint<8> )0ULL)) : 
             0LL== (amtmp001) ? (sc_uint<8> )
               (/*Enable*/(guard_007?(sc_uint<8> )(greens)[((/*imp*/sc_uint<3> 
             )(4ULL))]:(sc_uint<8> )0ULL)) : 
             /*DEFAULT*/ (sc_uint<8> )
               (center_g) );
guard_014 = (amtmp001 == 1ULL);
guard_015 = (amtmp001 == 2ULL);
center_b = ( 2LL== (amtmp001) ? (sc_uint<8> )
               (/*Enable*/(guard_015?(sc_uint<8> )(blues)[((/*imp*/sc_uint<2> )(
             3ULL))]:(sc_uint<8> )0ULL)) : 
             1LL== (amtmp001) ? (sc_uint<8> )
               (/*Enable*/(guard_014?(sc_uint<8> )(blues)[((/*imp*/sc_uint<3> )(
             5ULL))]:(sc_uint<8> )0ULL)) : 
             0LL== (amtmp001) ? (sc_uint<8> )
               (/*Enable*/(guard_007?(sc_uint<8> )(blues)[((/*imp*/sc_uint<3> )(
             4ULL))]:(sc_uint<8> )0ULL)) : 
             /*DEFAULT*/ (sc_uint<8> )
               (center_b) );
sort_reds_0_002 = (reds)[((/*imp*/sc_uint<1> )(0ULL))];
sort_reds_1_002 = (reds)[((/*imp*/sc_uint<1> )(1ULL))];
sort_reds_2_002 = (reds)[((/*imp*/sc_uint<2> )(2ULL))];
sort_reds_3_002 = (reds)[((/*imp*/sc_uint<2> )(3ULL))];
sort_reds_4_002 = (reds)[((/*imp*/sc_uint<3> )(4ULL))];
sort_reds_5_002 = (reds)[((/*imp*/sc_uint<3> )(5ULL))];
sort_reds_6_002 = (reds)[((/*imp*/sc_uint<3> )(6ULL))];
sort_reds_7_002 = (reds)[((/*imp*/sc_uint<3> )(7ULL))];
sort_reds_8_002 = (reds)[((/*imp*/sc_uint<4> )(8ULL))];
lt001 = (/*imp*/sc_uint<1>)(sort_reds_0_002 < sort_reds_1_002);
sort_reds_0_004 = ( lt001 ? (sc_uint<8> )
                  (sort_reds_0_002) : (sc_uint<8> )
                  (sort_reds_1_002));
sort_reds_1_004 = ( lt001 ? (sc_uint<8> )
                  (sort_reds_1_002) : (sc_uint<8> )
                  (sort_reds_0_002));
lt002 = (/*imp*/sc_uint<1>)(sort_reds_2_002 < sort_reds_3_002);
sort_reds_2_004 = ( lt002 ? (sc_uint<8> )
                  (sort_reds_2_002) : (sc_uint<8> )
                  (sort_reds_3_002));
sort_reds_3_004 = ( lt002 ? (sc_uint<8> )
                  (sort_reds_3_002) : (sc_uint<8> )
                  (sort_reds_2_002));
lt003 = (/*imp*/sc_uint<1>)(sort_reds_0_004 < sort_reds_2_004);
sort_reds_0_006 = ( lt003 ? (sc_uint<8> )
                  (sort_reds_0_004) : (sc_uint<8> )
                  (sort_reds_2_004));
sort_reds_2_006 = ( lt003 ? (sc_uint<8> )
                  (sort_reds_2_004) : (sc_uint<8> )
                  (sort_reds_0_004));
lt004 = (/*imp*/sc_uint<1>)(sort_reds_1_004 < sort_reds_3_004);
sort_reds_1_006 = ( lt004 ? (sc_uint<8> )
                  (sort_reds_1_004) : (sc_uint<8> )
                  (sort_reds_3_004));
sort_reds_3_006 = ( lt004 ? (sc_uint<8> )
                  (sort_reds_3_004) : (sc_uint<8> )
                  (sort_reds_1_004));
lt005 = (/*imp*/sc_uint<1>)(sort_reds_1_006 < sort_reds_2_006);
sort_reds_1_008 = ( lt005 ? (sc_uint<8> )
                  (sort_reds_1_006) : (sc_uint<8> )
                  (sort_reds_2_006));
sort_reds_2_008 = ( lt005 ? (sc_uint<8> )
                  (sort_reds_2_006) : (sc_uint<8> )
                  (sort_reds_1_006));
lt006 = (/*imp*/sc_uint<1>)(sort_reds_4_002 < sort_reds_5_002);
sort_reds_4_004 = ( lt006 ? (sc_uint<8> )
                  (sort_reds_4_002) : (sc_uint<8> )
                  (sort_reds_5_002));
sort_reds_5_004 = ( lt006 ? (sc_uint<8> )
                  (sort_reds_5_002) : (sc_uint<8> )
                  (sort_reds_4_002));
lt007 = (/*imp*/sc_uint<1>)(sort_reds_6_002 < sort_reds_7_002);
sort_reds_6_004 = ( lt007 ? (sc_uint<8> )
                  (sort_reds_6_002) : (sc_uint<8> )
                  (sort_reds_7_002));
sort_reds_7_004 = ( lt007 ? (sc_uint<8> )
                  (sort_reds_7_002) : (sc_uint<8> )
                  (sort_reds_6_002));
lt008 = (/*imp*/sc_uint<1>)(sort_reds_4_004 < sort_reds_6_004);
sort_reds_4_006 = ( lt008 ? (sc_uint<8> )
                  (sort_reds_4_004) : (sc_uint<8> )
                  (sort_reds_6_004));
sort_reds_6_006 = ( lt008 ? (sc_uint<8> )
                  (sort_reds_6_004) : (sc_uint<8> )
                  (sort_reds_4_004));
lt009 = (/*imp*/sc_uint<1>)(sort_reds_5_004 < sort_reds_7_004);
sort_reds_5_006 = ( lt009 ? (sc_uint<8> )
                  (sort_reds_5_004) : (sc_uint<8> )
                  (sort_reds_7_004));
sort_reds_7_006 = ( lt009 ? (sc_uint<8> )
                  (sort_reds_7_004) : (sc_uint<8> )
                  (sort_reds_5_004));
lt010 = (/*imp*/sc_uint<1>)(sort_reds_5_006 < sort_reds_6_006);
sort_reds_5_008 = ( lt010 ? (sc_uint<8> )
                  (sort_reds_5_006) : (sc_uint<8> )
                  (sort_reds_6_006));
sort_reds_6_008 = ( lt010 ? (sc_uint<8> )
                  (sort_reds_6_006) : (sc_uint<8> )
                  (sort_reds_5_006));
lt011 = (/*imp*/sc_uint<1>)(sort_reds_0_006 < sort_reds_4_006);
sort_reds_0_008 = ( lt011 ? (sc_uint<8> )
                  (sort_reds_0_006) : (sc_uint<8> )
                  (sort_reds_4_006));
sort_reds_4_008 = ( lt011 ? (sc_uint<8> )
                  (sort_reds_4_006) : (sc_uint<8> )
                  (sort_reds_0_006));
lt012 = (/*imp*/sc_uint<1>)(sort_reds_2_008 < sort_reds_6_008);
sort_reds_2_010 = ( lt012 ? (sc_uint<8> )
                  (sort_reds_2_008) : (sc_uint<8> )
                  (sort_reds_6_008));
sort_reds_6_010 = ( lt012 ? (sc_uint<8> )
                  (sort_reds_6_008) : (sc_uint<8> )
                  (sort_reds_2_008));
lt013 = (/*imp*/sc_uint<1>)(sort_reds_2_010 < sort_reds_4_008);
sort_reds_2_012 = ( lt013 ? (sc_uint<8> )
                  (sort_reds_2_010) : (sc_uint<8> )
                  (sort_reds_4_008));
sort_reds_4_010 = ( lt013 ? (sc_uint<8> )
                  (sort_reds_4_008) : (sc_uint<8> )
                  (sort_reds_2_010));
lt014 = (/*imp*/sc_uint<1>)(sort_reds_1_008 < sort_reds_5_008);
sort_reds_1_010 = ( lt014 ? (sc_uint<8> )
                  (sort_reds_1_008) : (sc_uint<8> )
                  (sort_reds_5_008));
sort_reds_5_010 = ( lt014 ? (sc_uint<8> )
                  (sort_reds_5_008) : (sc_uint<8> )
                  (sort_reds_1_008));
lt015 = (/*imp*/sc_uint<1>)(sort_reds_3_006 < sort_reds_7_006);
sort_reds_3_008 = ( lt015 ? (sc_uint<8> )
                  (sort_reds_3_006) : (sc_uint<8> )
                  (sort_reds_7_006));
sort_reds_7_008 = ( lt015 ? (sc_uint<8> )
                  (sort_reds_7_006) : (sc_uint<8> )
                  (sort_reds_3_006));
lt016 = (/*imp*/sc_uint<1>)(sort_reds_3_008 < sort_reds_5_010);
sort_reds_3_010 = ( lt016 ? (sc_uint<8> )
                  (sort_reds_3_008) : (sc_uint<8> )
                  (sort_reds_5_010));
sort_reds_5_012 = ( lt016 ? (sc_uint<8> )
                  (sort_reds_5_010) : (sc_uint<8> )
                  (sort_reds_3_008));
lt017 = (/*imp*/sc_uint<1>)(sort_reds_1_010 < sort_reds_2_012);
sort_reds_1_012 = ( lt017 ? (sc_uint<8> )
                  (sort_reds_1_010) : (sc_uint<8> )
                  (sort_reds_2_012));
sort_reds_2_014 = ( lt017 ? (sc_uint<8> )
                  (sort_reds_2_012) : (sc_uint<8> )
                  (sort_reds_1_010));
lt018 = (/*imp*/sc_uint<1>)(sort_reds_3_010 < sort_reds_4_010);
sort_reds_3_012 = ( lt018 ? (sc_uint<8> )
                  (sort_reds_3_010) : (sc_uint<8> )
                  (sort_reds_4_010));
sort_reds_4_012 = ( lt018 ? (sc_uint<8> )
                  (sort_reds_4_010) : (sc_uint<8> )
                  (sort_reds_3_010));
lt019 = (/*imp*/sc_uint<1>)(sort_reds_5_012 < sort_reds_6_010);
sort_reds_5_014 = ( lt019 ? (sc_uint<8> )
                  (sort_reds_5_012) : (sc_uint<8> )
                  (sort_reds_6_010));
sort_reds_6_012 = ( lt019 ? (sc_uint<8> )
                  (sort_reds_6_010) : (sc_uint<8> )
                  (sort_reds_5_012));
lt020 = (/*imp*/sc_uint<1>)(sort_reds_0_008 < sort_reds_8_002);
sort_reds_8_004 = ( lt020 ? (sc_uint<8> )
                  (sort_reds_8_002) : (sc_uint<8> )
                  (sort_reds_0_008));
lt021 = (/*imp*/sc_uint<1>)(sort_reds_4_012 < sort_reds_8_004);
sort_reds_4_014 = ( lt021 ? (sc_uint<8> )
                  (sort_reds_4_012) : (sc_uint<8> )
                  (sort_reds_8_004));
sort_reds_8_006 = ( lt021 ? (sc_uint<8> )
                  (sort_reds_8_004) : (sc_uint<8> )
                  (sort_reds_4_012));
lt022 = (/*imp*/sc_uint<1>)(sort_reds_2_014 < sort_reds_4_014);
sort_reds_2_016 = ( lt022 ? (sc_uint<8> )
                  (sort_reds_2_014) : (sc_uint<8> )
                  (sort_reds_4_014));
sort_reds_4_016 = ( lt022 ? (sc_uint<8> )
                  (sort_reds_4_014) : (sc_uint<8> )
                  (sort_reds_2_014));
lt023 = (/*imp*/sc_uint<1>)(sort_reds_6_012 < sort_reds_8_006);
sort_reds_6_014 = ( lt023 ? (sc_uint<8> )
                  (sort_reds_6_012) : (sc_uint<8> )
                  (sort_reds_8_006));
sort_reds_8_008 = ( lt023 ? (sc_uint<8> )
                  (sort_reds_8_006) : (sc_uint<8> )
                  (sort_reds_6_012));
lt024 = (/*imp*/sc_uint<1>)(sort_reds_3_012 < sort_reds_5_014);
sort_reds_3_014 = ( lt024 ? (sc_uint<8> )
                  (sort_reds_3_012) : (sc_uint<8> )
                  (sort_reds_5_014));
sort_reds_5_016 = ( lt024 ? (sc_uint<8> )
                  (sort_reds_5_014) : (sc_uint<8> )
                  (sort_reds_3_012));
lt025 = (/*imp*/sc_uint<1>)(sort_reds_1_012 < sort_reds_2_016);
lt026 = (/*imp*/sc_uint<1>)(sort_reds_3_014 < sort_reds_4_016);
lt027 = (/*imp*/sc_uint<1>)(sort_reds_5_016 < sort_reds_6_014);
lt028 = (/*imp*/sc_uint<1>)(sort_reds_7_008 < sort_reds_8_008);
(reds)[((/*imp*/sc_uint<1> )(0ULL))] = (sc_uint<8> )(( lt020 ? (sc_uint<8> )
                                       (sort_reds_0_008) : (sc_uint<8> )
                                       (sort_reds_8_002)));
(reds)[((/*imp*/sc_uint<1> )(1ULL))] = (sc_uint<8> )(( lt025 ? (sc_uint<8> )
                                       (sort_reds_1_012) : (sc_uint<8> )
                                       (sort_reds_2_016)));
(reds)[((/*imp*/sc_uint<2> )(2ULL))] = (sc_uint<8> )(( lt025 ? (sc_uint<8> )
                                       (sort_reds_2_016) : (sc_uint<8> )
                                       (sort_reds_1_012)));
(reds)[((/*imp*/sc_uint<2> )(3ULL))] = (sc_uint<8> )(( lt026 ? (sc_uint<8> )
                                       (sort_reds_3_014) : (sc_uint<8> )
                                       (sort_reds_4_016)));
(reds)[((/*imp*/sc_uint<3> )(4ULL))] = (sc_uint<8> )(( lt026 ? (sc_uint<8> )
                                       (sort_reds_4_016) : (sc_uint<8> )
                                       (sort_reds_3_014)));
(reds)[((/*imp*/sc_uint<3> )(5ULL))] = (sc_uint<8> )(( lt027 ? (sc_uint<8> )
                                       (sort_reds_5_016) : (sc_uint<8> )
                                       (sort_reds_6_014)));
(reds)[((/*imp*/sc_uint<3> )(6ULL))] = (sc_uint<8> )(( lt027 ? (sc_uint<8> )
                                       (sort_reds_6_014) : (sc_uint<8> )
                                       (sort_reds_5_016)));
(reds)[((/*imp*/sc_uint<3> )(7ULL))] = (sc_uint<8> )(( lt028 ? (sc_uint<8> )
                                       (sort_reds_7_008) : (sc_uint<8> )
                                       (sort_reds_8_008)));
(reds)[((/*imp*/sc_uint<4> )(8ULL))] = (sc_uint<8> )(( lt028 ? (sc_uint<8> )
                                       (sort_reds_8_008) : (sc_uint<8> )
                                       (sort_reds_7_008)));
sort_greens_0_002 = (greens)[((/*imp*/sc_uint<1> )(0ULL))];
sort_greens_1_002 = (greens)[((/*imp*/sc_uint<1> )(1ULL))];
sort_greens_2_002 = (greens)[((/*imp*/sc_uint<2> )(2ULL))];
sort_greens_3_002 = (greens)[((/*imp*/sc_uint<2> )(3ULL))];
sort_greens_4_002 = (greens)[((/*imp*/sc_uint<3> )(4ULL))];
sort_greens_5_002 = (greens)[((/*imp*/sc_uint<3> )(5ULL))];
sort_greens_6_002 = (greens)[((/*imp*/sc_uint<3> )(6ULL))];
sort_greens_7_002 = (greens)[((/*imp*/sc_uint<3> )(7ULL))];
sort_greens_8_002 = (greens)[((/*imp*/sc_uint<4> )(8ULL))];
lt029 = (/*imp*/sc_uint<1>)(sort_greens_0_002 < sort_greens_1_002);
sort_greens_0_004 = ( lt029 ? (sc_uint<8> )
                    (sort_greens_0_002) : (sc_uint<8> )
                    (sort_greens_1_002));
sort_greens_1_004 = ( lt029 ? (sc_uint<8> )
                    (sort_greens_1_002) : (sc_uint<8> )
                    (sort_greens_0_002));
lt030 = (/*imp*/sc_uint<1>)(sort_greens_2_002 < sort_greens_3_002);
sort_greens_2_004 = ( lt030 ? (sc_uint<8> )
                    (sort_greens_2_002) : (sc_uint<8> )
                    (sort_greens_3_002));
sort_greens_3_004 = ( lt030 ? (sc_uint<8> )
                    (sort_greens_3_002) : (sc_uint<8> )
                    (sort_greens_2_002));
lt031 = (/*imp*/sc_uint<1>)(sort_greens_0_004 < sort_greens_2_004);
sort_greens_0_006 = ( lt031 ? (sc_uint<8> )
                    (sort_greens_0_004) : (sc_uint<8> )
                    (sort_greens_2_004));
sort_greens_2_006 = ( lt031 ? (sc_uint<8> )
                    (sort_greens_2_004) : (sc_uint<8> )
                    (sort_greens_0_004));
lt032 = (/*imp*/sc_uint<1>)(sort_greens_1_004 < sort_greens_3_004);
sort_greens_1_006 = ( lt032 ? (sc_uint<8> )
                    (sort_greens_1_004) : (sc_uint<8> )
                    (sort_greens_3_004));
sort_greens_3_006 = ( lt032 ? (sc_uint<8> )
                    (sort_greens_3_004) : (sc_uint<8> )
                    (sort_greens_1_004));
lt033 = (/*imp*/sc_uint<1>)(sort_greens_1_006 < sort_greens_2_006);
sort_greens_1_008 = ( lt033 ? (sc_uint<8> )
                    (sort_greens_1_006) : (sc_uint<8> )
                    (sort_greens_2_006));
sort_greens_2_008 = ( lt033 ? (sc_uint<8> )
                    (sort_greens_2_006) : (sc_uint<8> )
                    (sort_greens_1_006));
lt034 = (/*imp*/sc_uint<1>)(sort_greens_4_002 < sort_greens_5_002);
sort_greens_4_004 = ( lt034 ? (sc_uint<8> )
                    (sort_greens_4_002) : (sc_uint<8> )
                    (sort_greens_5_002));
sort_greens_5_004 = ( lt034 ? (sc_uint<8> )
                    (sort_greens_5_002) : (sc_uint<8> )
                    (sort_greens_4_002));
lt035 = (/*imp*/sc_uint<1>)(sort_greens_6_002 < sort_greens_7_002);
sort_greens_6_004 = ( lt035 ? (sc_uint<8> )
                    (sort_greens_6_002) : (sc_uint<8> )
                    (sort_greens_7_002));
sort_greens_7_004 = ( lt035 ? (sc_uint<8> )
                    (sort_greens_7_002) : (sc_uint<8> )
                    (sort_greens_6_002));
lt036 = (/*imp*/sc_uint<1>)(sort_greens_4_004 < sort_greens_6_004);
sort_greens_4_006 = ( lt036 ? (sc_uint<8> )
                    (sort_greens_4_004) : (sc_uint<8> )
                    (sort_greens_6_004));
sort_greens_6_006 = ( lt036 ? (sc_uint<8> )
                    (sort_greens_6_004) : (sc_uint<8> )
                    (sort_greens_4_004));
lt037 = (/*imp*/sc_uint<1>)(sort_greens_5_004 < sort_greens_7_004);
sort_greens_5_006 = ( lt037 ? (sc_uint<8> )
                    (sort_greens_5_004) : (sc_uint<8> )
                    (sort_greens_7_004));
sort_greens_7_006 = ( lt037 ? (sc_uint<8> )
                    (sort_greens_7_004) : (sc_uint<8> )
                    (sort_greens_5_004));
lt038 = (/*imp*/sc_uint<1>)(sort_greens_5_006 < sort_greens_6_006);
sort_greens_5_008 = ( lt038 ? (sc_uint<8> )
                    (sort_greens_5_006) : (sc_uint<8> )
                    (sort_greens_6_006));
sort_greens_6_008 = ( lt038 ? (sc_uint<8> )
                    (sort_greens_6_006) : (sc_uint<8> )
                    (sort_greens_5_006));
lt039 = (/*imp*/sc_uint<1>)(sort_greens_0_006 < sort_greens_4_006);
sort_greens_0_008 = ( lt039 ? (sc_uint<8> )
                    (sort_greens_0_006) : (sc_uint<8> )
                    (sort_greens_4_006));
sort_greens_4_008 = ( lt039 ? (sc_uint<8> )
                    (sort_greens_4_006) : (sc_uint<8> )
                    (sort_greens_0_006));
lt040 = (/*imp*/sc_uint<1>)(sort_greens_2_008 < sort_greens_6_008);
sort_greens_2_010 = ( lt040 ? (sc_uint<8> )
                    (sort_greens_2_008) : (sc_uint<8> )
                    (sort_greens_6_008));
sort_greens_6_010 = ( lt040 ? (sc_uint<8> )
                    (sort_greens_6_008) : (sc_uint<8> )
                    (sort_greens_2_008));
lt041 = (/*imp*/sc_uint<1>)(sort_greens_2_010 < sort_greens_4_008);
sort_greens_2_012 = ( lt041 ? (sc_uint<8> )
                    (sort_greens_2_010) : (sc_uint<8> )
                    (sort_greens_4_008));
sort_greens_4_010 = ( lt041 ? (sc_uint<8> )
                    (sort_greens_4_008) : (sc_uint<8> )
                    (sort_greens_2_010));
lt042 = (/*imp*/sc_uint<1>)(sort_greens_1_008 < sort_greens_5_008);
sort_greens_1_010 = ( lt042 ? (sc_uint<8> )
                    (sort_greens_1_008) : (sc_uint<8> )
                    (sort_greens_5_008));
sort_greens_5_010 = ( lt042 ? (sc_uint<8> )
                    (sort_greens_5_008) : (sc_uint<8> )
                    (sort_greens_1_008));
lt043 = (/*imp*/sc_uint<1>)(sort_greens_3_006 < sort_greens_7_006);
sort_greens_3_008 = ( lt043 ? (sc_uint<8> )
                    (sort_greens_3_006) : (sc_uint<8> )
                    (sort_greens_7_006));
sort_greens_7_008 = ( lt043 ? (sc_uint<8> )
                    (sort_greens_7_006) : (sc_uint<8> )
                    (sort_greens_3_006));
lt044 = (/*imp*/sc_uint<1>)(sort_greens_3_008 < sort_greens_5_010);
sort_greens_3_010 = ( lt044 ? (sc_uint<8> )
                    (sort_greens_3_008) : (sc_uint<8> )
                    (sort_greens_5_010));
sort_greens_5_012 = ( lt044 ? (sc_uint<8> )
                    (sort_greens_5_010) : (sc_uint<8> )
                    (sort_greens_3_008));
lt045 = (/*imp*/sc_uint<1>)(sort_greens_1_010 < sort_greens_2_012);
sort_greens_1_012 = ( lt045 ? (sc_uint<8> )
                    (sort_greens_1_010) : (sc_uint<8> )
                    (sort_greens_2_012));
sort_greens_2_014 = ( lt045 ? (sc_uint<8> )
                    (sort_greens_2_012) : (sc_uint<8> )
                    (sort_greens_1_010));
lt046 = (/*imp*/sc_uint<1>)(sort_greens_3_010 < sort_greens_4_010);
sort_greens_3_012 = ( lt046 ? (sc_uint<8> )
                    (sort_greens_3_010) : (sc_uint<8> )
                    (sort_greens_4_010));
sort_greens_4_012 = ( lt046 ? (sc_uint<8> )
                    (sort_greens_4_010) : (sc_uint<8> )
                    (sort_greens_3_010));
lt047 = (/*imp*/sc_uint<1>)(sort_greens_5_012 < sort_greens_6_010);
sort_greens_5_014 = ( lt047 ? (sc_uint<8> )
                    (sort_greens_5_012) : (sc_uint<8> )
                    (sort_greens_6_010));
sort_greens_6_012 = ( lt047 ? (sc_uint<8> )
                    (sort_greens_6_010) : (sc_uint<8> )
                    (sort_greens_5_012));
lt048 = (/*imp*/sc_uint<1>)(sort_greens_0_008 < sort_greens_8_002);
sort_greens_8_004 = ( lt048 ? (sc_uint<8> )
                    (sort_greens_8_002) : (sc_uint<8> )
                    (sort_greens_0_008));
lt049 = (/*imp*/sc_uint<1>)(sort_greens_4_012 < sort_greens_8_004);
sort_greens_4_014 = ( lt049 ? (sc_uint<8> )
                    (sort_greens_4_012) : (sc_uint<8> )
                    (sort_greens_8_004));
sort_greens_8_006 = ( lt049 ? (sc_uint<8> )
                    (sort_greens_8_004) : (sc_uint<8> )
                    (sort_greens_4_012));
lt050 = (/*imp*/sc_uint<1>)(sort_greens_2_014 < sort_greens_4_014);
sort_greens_2_016 = ( lt050 ? (sc_uint<8> )
                    (sort_greens_2_014) : (sc_uint<8> )
                    (sort_greens_4_014));
sort_greens_4_016 = ( lt050 ? (sc_uint<8> )
                    (sort_greens_4_014) : (sc_uint<8> )
                    (sort_greens_2_014));
lt051 = (/*imp*/sc_uint<1>)(sort_greens_6_012 < sort_greens_8_006);
sort_greens_6_014 = ( lt051 ? (sc_uint<8> )
                    (sort_greens_6_012) : (sc_uint<8> )
                    (sort_greens_8_006));
sort_greens_8_008 = ( lt051 ? (sc_uint<8> )
                    (sort_greens_8_006) : (sc_uint<8> )
                    (sort_greens_6_012));
lt052 = (/*imp*/sc_uint<1>)(sort_greens_3_012 < sort_greens_5_014);
sort_greens_3_014 = ( lt052 ? (sc_uint<8> )
                    (sort_greens_3_012) : (sc_uint<8> )
                    (sort_greens_5_014));
sort_greens_5_016 = ( lt052 ? (sc_uint<8> )
                    (sort_greens_5_014) : (sc_uint<8> )
                    (sort_greens_3_012));
lt053 = (/*imp*/sc_uint<1>)(sort_greens_1_012 < sort_greens_2_016);
lt054 = (/*imp*/sc_uint<1>)(sort_greens_3_014 < sort_greens_4_016);
lt055 = (/*imp*/sc_uint<1>)(sort_greens_5_016 < sort_greens_6_014);
lt056 = (/*imp*/sc_uint<1>)(sort_greens_7_008 < sort_greens_8_008);
(greens)[((/*imp*/sc_uint<1> )(0ULL))] = (sc_uint<8> )(( lt048 ? (sc_uint<8> )
                                         (sort_greens_0_008) : (sc_uint<8> )
                                         (sort_greens_8_002)));
(greens)[((/*imp*/sc_uint<1> )(1ULL))] = (sc_uint<8> )(( lt053 ? (sc_uint<8> )
                                         (sort_greens_1_012) : (sc_uint<8> )
                                         (sort_greens_2_016)));
(greens)[((/*imp*/sc_uint<2> )(2ULL))] = (sc_uint<8> )(( lt053 ? (sc_uint<8> )
                                         (sort_greens_2_016) : (sc_uint<8> )
                                         (sort_greens_1_012)));
(greens)[((/*imp*/sc_uint<2> )(3ULL))] = (sc_uint<8> )(( lt054 ? (sc_uint<8> )
                                         (sort_greens_3_014) : (sc_uint<8> )
                                         (sort_greens_4_016)));
(greens)[((/*imp*/sc_uint<3> )(4ULL))] = (sc_uint<8> )(( lt054 ? (sc_uint<8> )
                                         (sort_greens_4_016) : (sc_uint<8> )
                                         (sort_greens_3_014)));
(greens)[((/*imp*/sc_uint<3> )(5ULL))] = (sc_uint<8> )(( lt055 ? (sc_uint<8> )
                                         (sort_greens_5_016) : (sc_uint<8> )
                                         (sort_greens_6_014)));
(greens)[((/*imp*/sc_uint<3> )(6ULL))] = (sc_uint<8> )(( lt055 ? (sc_uint<8> )
                                         (sort_greens_6_014) : (sc_uint<8> )
                                         (sort_greens_5_016)));
(greens)[((/*imp*/sc_uint<3> )(7ULL))] = (sc_uint<8> )(( lt056 ? (sc_uint<8> )
                                         (sort_greens_7_008) : (sc_uint<8> )
                                         (sort_greens_8_008)));
(greens)[((/*imp*/sc_uint<4> )(8ULL))] = (sc_uint<8> )(( lt056 ? (sc_uint<8> )
                                         (sort_greens_8_008) : (sc_uint<8> )
                                         (sort_greens_7_008)));
sort_blues_0_002 = (blues)[((/*imp*/sc_uint<1> )(0ULL))];
sort_blues_1_002 = (blues)[((/*imp*/sc_uint<1> )(1ULL))];
sort_blues_2_002 = (blues)[((/*imp*/sc_uint<2> )(2ULL))];
sort_blues_3_002 = (blues)[((/*imp*/sc_uint<2> )(3ULL))];
sort_blues_4_002 = (blues)[((/*imp*/sc_uint<3> )(4ULL))];
sort_blues_5_002 = (blues)[((/*imp*/sc_uint<3> )(5ULL))];
sort_blues_6_002 = (blues)[((/*imp*/sc_uint<3> )(6ULL))];
sort_blues_7_002 = (blues)[((/*imp*/sc_uint<3> )(7ULL))];
sort_blues_8_002 = (blues)[((/*imp*/sc_uint<4> )(8ULL))];
lt057 = (/*imp*/sc_uint<1>)(sort_blues_0_002 < sort_blues_1_002);
sort_blues_0_004 = ( lt057 ? (sc_uint<8> )
                   (sort_blues_0_002) : (sc_uint<8> )
                   (sort_blues_1_002));
sort_blues_1_004 = ( lt057 ? (sc_uint<8> )
                   (sort_blues_1_002) : (sc_uint<8> )
                   (sort_blues_0_002));
lt058 = (/*imp*/sc_uint<1>)(sort_blues_2_002 < sort_blues_3_002);
sort_blues_2_004 = ( lt058 ? (sc_uint<8> )
                   (sort_blues_2_002) : (sc_uint<8> )
                   (sort_blues_3_002));
sort_blues_3_004 = ( lt058 ? (sc_uint<8> )
                   (sort_blues_3_002) : (sc_uint<8> )
                   (sort_blues_2_002));
lt059 = (/*imp*/sc_uint<1>)(sort_blues_0_004 < sort_blues_2_004);
sort_blues_0_006 = ( lt059 ? (sc_uint<8> )
                   (sort_blues_0_004) : (sc_uint<8> )
                   (sort_blues_2_004));
sort_blues_2_006 = ( lt059 ? (sc_uint<8> )
                   (sort_blues_2_004) : (sc_uint<8> )
                   (sort_blues_0_004));
lt060 = (/*imp*/sc_uint<1>)(sort_blues_1_004 < sort_blues_3_004);
sort_blues_1_006 = ( lt060 ? (sc_uint<8> )
                   (sort_blues_1_004) : (sc_uint<8> )
                   (sort_blues_3_004));
sort_blues_3_006 = ( lt060 ? (sc_uint<8> )
                   (sort_blues_3_004) : (sc_uint<8> )
                   (sort_blues_1_004));
lt061 = (/*imp*/sc_uint<1>)(sort_blues_1_006 < sort_blues_2_006);
sort_blues_1_008 = ( lt061 ? (sc_uint<8> )
                   (sort_blues_1_006) : (sc_uint<8> )
                   (sort_blues_2_006));
sort_blues_2_008 = ( lt061 ? (sc_uint<8> )
                   (sort_blues_2_006) : (sc_uint<8> )
                   (sort_blues_1_006));
lt062 = (/*imp*/sc_uint<1>)(sort_blues_4_002 < sort_blues_5_002);
sort_blues_4_004 = ( lt062 ? (sc_uint<8> )
                   (sort_blues_4_002) : (sc_uint<8> )
                   (sort_blues_5_002));
sort_blues_5_004 = ( lt062 ? (sc_uint<8> )
                   (sort_blues_5_002) : (sc_uint<8> )
                   (sort_blues_4_002));
lt063 = (/*imp*/sc_uint<1>)(sort_blues_6_002 < sort_blues_7_002);
sort_blues_6_004 = ( lt063 ? (sc_uint<8> )
                   (sort_blues_6_002) : (sc_uint<8> )
                   (sort_blues_7_002));
sort_blues_7_004 = ( lt063 ? (sc_uint<8> )
                   (sort_blues_7_002) : (sc_uint<8> )
                   (sort_blues_6_002));
lt064 = (/*imp*/sc_uint<1>)(sort_blues_4_004 < sort_blues_6_004);
sort_blues_4_006 = ( lt064 ? (sc_uint<8> )
                   (sort_blues_4_004) : (sc_uint<8> )
                   (sort_blues_6_004));
sort_blues_6_006 = ( lt064 ? (sc_uint<8> )
                   (sort_blues_6_004) : (sc_uint<8> )
                   (sort_blues_4_004));
lt065 = (/*imp*/sc_uint<1>)(sort_blues_5_004 < sort_blues_7_004);
sort_blues_5_006 = ( lt065 ? (sc_uint<8> )
                   (sort_blues_5_004) : (sc_uint<8> )
                   (sort_blues_7_004));
sort_blues_7_006 = ( lt065 ? (sc_uint<8> )
                   (sort_blues_7_004) : (sc_uint<8> )
                   (sort_blues_5_004));
lt066 = (/*imp*/sc_uint<1>)(sort_blues_5_006 < sort_blues_6_006);
sort_blues_5_008 = ( lt066 ? (sc_uint<8> )
                   (sort_blues_5_006) : (sc_uint<8> )
                   (sort_blues_6_006));
sort_blues_6_008 = ( lt066 ? (sc_uint<8> )
                   (sort_blues_6_006) : (sc_uint<8> )
                   (sort_blues_5_006));
lt067 = (/*imp*/sc_uint<1>)(sort_blues_0_006 < sort_blues_4_006);
sort_blues_0_008 = ( lt067 ? (sc_uint<8> )
                   (sort_blues_0_006) : (sc_uint<8> )
                   (sort_blues_4_006));
sort_blues_4_008 = ( lt067 ? (sc_uint<8> )
                   (sort_blues_4_006) : (sc_uint<8> )
                   (sort_blues_0_006));
lt068 = (/*imp*/sc_uint<1>)(sort_blues_2_008 < sort_blues_6_008);
sort_blues_2_010 = ( lt068 ? (sc_uint<8> )
                   (sort_blues_2_008) : (sc_uint<8> )
                   (sort_blues_6_008));
sort_blues_6_010 = ( lt068 ? (sc_uint<8> )
                   (sort_blues_6_008) : (sc_uint<8> )
                   (sort_blues_2_008));
lt069 = (/*imp*/sc_uint<1>)(sort_blues_2_010 < sort_blues_4_008);
sort_blues_2_012 = ( lt069 ? (sc_uint<8> )
                   (sort_blues_2_010) : (sc_uint<8> )
                   (sort_blues_4_008));
sort_blues_4_010 = ( lt069 ? (sc_uint<8> )
                   (sort_blues_4_008) : (sc_uint<8> )
                   (sort_blues_2_010));
lt070 = (/*imp*/sc_uint<1>)(sort_blues_1_008 < sort_blues_5_008);
sort_blues_1_010 = ( lt070 ? (sc_uint<8> )
                   (sort_blues_1_008) : (sc_uint<8> )
                   (sort_blues_5_008));
sort_blues_5_010 = ( lt070 ? (sc_uint<8> )
                   (sort_blues_5_008) : (sc_uint<8> )
                   (sort_blues_1_008));
lt071 = (/*imp*/sc_uint<1>)(sort_blues_3_006 < sort_blues_7_006);
sort_blues_3_008 = ( lt071 ? (sc_uint<8> )
                   (sort_blues_3_006) : (sc_uint<8> )
                   (sort_blues_7_006));
sort_blues_7_008 = ( lt071 ? (sc_uint<8> )
                   (sort_blues_7_006) : (sc_uint<8> )
                   (sort_blues_3_006));
lt072 = (/*imp*/sc_uint<1>)(sort_blues_3_008 < sort_blues_5_010);
sort_blues_3_010 = ( lt072 ? (sc_uint<8> )
                   (sort_blues_3_008) : (sc_uint<8> )
                   (sort_blues_5_010));
sort_blues_5_012 = ( lt072 ? (sc_uint<8> )
                   (sort_blues_5_010) : (sc_uint<8> )
                   (sort_blues_3_008));
lt073 = (/*imp*/sc_uint<1>)(sort_blues_1_010 < sort_blues_2_012);
sort_blues_1_012 = ( lt073 ? (sc_uint<8> )
                   (sort_blues_1_010) : (sc_uint<8> )
                   (sort_blues_2_012));
sort_blues_2_014 = ( lt073 ? (sc_uint<8> )
                   (sort_blues_2_012) : (sc_uint<8> )
                   (sort_blues_1_010));
lt074 = (/*imp*/sc_uint<1>)(sort_blues_3_010 < sort_blues_4_010);
sort_blues_3_012 = ( lt074 ? (sc_uint<8> )
                   (sort_blues_3_010) : (sc_uint<8> )
                   (sort_blues_4_010));
sort_blues_4_012 = ( lt074 ? (sc_uint<8> )
                   (sort_blues_4_010) : (sc_uint<8> )
                   (sort_blues_3_010));
lt075 = (/*imp*/sc_uint<1>)(sort_blues_5_012 < sort_blues_6_010);
sort_blues_5_014 = ( lt075 ? (sc_uint<8> )
                   (sort_blues_5_012) : (sc_uint<8> )
                   (sort_blues_6_010));
sort_blues_6_012 = ( lt075 ? (sc_uint<8> )
                   (sort_blues_6_010) : (sc_uint<8> )
                   (sort_blues_5_012));
lt076 = (/*imp*/sc_uint<1>)(sort_blues_0_008 < sort_blues_8_002);
sort_blues_8_004 = ( lt076 ? (sc_uint<8> )
                   (sort_blues_8_002) : (sc_uint<8> )
                   (sort_blues_0_008));
lt077 = (/*imp*/sc_uint<1>)(sort_blues_4_012 < sort_blues_8_004);
sort_blues_4_014 = ( lt077 ? (sc_uint<8> )
                   (sort_blues_4_012) : (sc_uint<8> )
                   (sort_blues_8_004));
sort_blues_8_006 = ( lt077 ? (sc_uint<8> )
                   (sort_blues_8_004) : (sc_uint<8> )
                   (sort_blues_4_012));
lt078 = (/*imp*/sc_uint<1>)(sort_blues_2_014 < sort_blues_4_014);
sort_blues_2_016 = ( lt078 ? (sc_uint<8> )
                   (sort_blues_2_014) : (sc_uint<8> )
                   (sort_blues_4_014));
sort_blues_4_016 = ( lt078 ? (sc_uint<8> )
                   (sort_blues_4_014) : (sc_uint<8> )
                   (sort_blues_2_014));
lt079 = (/*imp*/sc_uint<1>)(sort_blues_6_012 < sort_blues_8_006);
sort_blues_6_014 = ( lt079 ? (sc_uint<8> )
                   (sort_blues_6_012) : (sc_uint<8> )
                   (sort_blues_8_006));
sort_blues_8_008 = ( lt079 ? (sc_uint<8> )
                   (sort_blues_8_006) : (sc_uint<8> )
                   (sort_blues_6_012));
lt080 = (/*imp*/sc_uint<1>)(sort_blues_3_012 < sort_blues_5_014);
sort_blues_3_014 = ( lt080 ? (sc_uint<8> )
                   (sort_blues_3_012) : (sc_uint<8> )
                   (sort_blues_5_014));
sort_blues_5_016 = ( lt080 ? (sc_uint<8> )
                   (sort_blues_5_014) : (sc_uint<8> )
                   (sort_blues_3_012));
lt081 = (/*imp*/sc_uint<1>)(sort_blues_1_012 < sort_blues_2_016);
lt082 = (/*imp*/sc_uint<1>)(sort_blues_3_014 < sort_blues_4_016);
lt083 = (/*imp*/sc_uint<1>)(sort_blues_5_016 < sort_blues_6_014);
lt084 = (/*imp*/sc_uint<1>)(sort_blues_7_008 < sort_blues_8_008);
(blues)[((/*imp*/sc_uint<1> )(0ULL))] = (sc_uint<8> )(( lt076 ? (sc_uint<8> )
                                        (sort_blues_0_008) : (sc_uint<8> )
                                        (sort_blues_8_002)));
(blues)[((/*imp*/sc_uint<1> )(1ULL))] = (sc_uint<8> )(( lt081 ? (sc_uint<8> )
                                        (sort_blues_1_012) : (sc_uint<8> )
                                        (sort_blues_2_016)));
(blues)[((/*imp*/sc_uint<2> )(2ULL))] = (sc_uint<8> )(( lt081 ? (sc_uint<8> )
                                        (sort_blues_2_016) : (sc_uint<8> )
                                        (sort_blues_1_012)));
(blues)[((/*imp*/sc_uint<2> )(3ULL))] = (sc_uint<8> )(( lt082 ? (sc_uint<8> )
                                        (sort_blues_3_014) : (sc_uint<8> )
                                        (sort_blues_4_016)));
(blues)[((/*imp*/sc_uint<3> )(4ULL))] = (sc_uint<8> )(( lt082 ? (sc_uint<8> )
                                        (sort_blues_4_016) : (sc_uint<8> )
                                        (sort_blues_3_014)));
(blues)[((/*imp*/sc_uint<3> )(5ULL))] = (sc_uint<8> )(( lt083 ? (sc_uint<8> )
                                        (sort_blues_5_016) : (sc_uint<8> )
                                        (sort_blues_6_014)));
(blues)[((/*imp*/sc_uint<3> )(6ULL))] = (sc_uint<8> )(( lt083 ? (sc_uint<8> )
                                        (sort_blues_6_014) : (sc_uint<8> )
                                        (sort_blues_5_016)));
(blues)[((/*imp*/sc_uint<3> )(7ULL))] = (sc_uint<8> )(( lt084 ? (sc_uint<8> )
                                        (sort_blues_7_008) : (sc_uint<8> )
                                        (sort_blues_8_008)));
(blues)[((/*imp*/sc_uint<4> )(8ULL))] = (sc_uint<8> )(( lt084 ? (sc_uint<8> )
                                        (sort_blues_8_008) : (sc_uint<8> )
                                        (sort_blues_7_008)));
sum_r = 0ULL;
sum_g = 0ULL;
sum_b = 0ULL;
i = (sc_int<5> ) (0ULL);
goto state24;
/********************/
state24:;
/*CYN_ITERATIONS(9ULL, "<generated>");*//* 301ULL */
/*HLS_LOOP_NAME("sum_loop");*//* 105ULL */
sum_r = (sum_r + (sc_uint<8> )((reds)[(sc_uint<4> )((sc_uint<4> )i)]));
sum_g = (sum_g + (sc_uint<8> )((greens)[(sc_uint<4> )((sc_uint<4> )i)]));
sum_b = (sum_b + (sc_uint<8> )((blues)[(sc_uint<4> )((sc_uint<4> )i)]));
i = (sc_int<5> ) ((/*cliff*/sc_uint<32>)((sc_uint<4> )i + 1ULL));
condvar_002 = (/*imp*/sc_uint<1>)(i < ((/*imp*/sc_int<5> )(9LL)));
switch( (sc_uint<1>)(condvar_002) ) {
case 0ULL: 
  goto state25;
case 1ULL: 
  goto state24;
}
/********************/
state25:;
total = ( (sc_biguint<24> )(sc_bv<24>)((sc_bv<16>)((sc_bv<8>)((sc_uint<8> )(( ( 
        (( sum_b - (sc_uint<8> )center_b ) + ( (sc_uint<8> )(sc_bv<8>)(
        (sc_bv<7>)((sc_uint<7> )((blues)[((/*imp*/sc_uint<3> )(4ULL))])), 
        (sc_bv<1>)(0ULL)) )) ) * 0.100000 ))), 
        (sc_bv<8>)((sc_uint<8> )(( ( (( sum_g - (sc_uint<8> )center_g ) + ( (
        sc_uint<8> )(sc_bv<8>)((sc_bv<7>)((sc_uint<7> )((greens)[((/*imp*/
        sc_uint<3> )(4ULL))])), 
        (sc_bv<1>)(0ULL)) )) ) * 0.100000 )))), 
        (sc_bv<8>)((sc_uint<8> )(( ( (( sum_r - (sc_uint<8> )center_r ) + ( (
        sc_uint<8> )(sc_bv<8>)((sc_bv<7>)((sc_uint<7> )((reds)[((/*imp*/
        sc_uint<3> )(4ULL))])), 
        (sc_bv<1>)(0ULL)) )) ) * 0.100000 )))) );
goto state26;
/********************/
state26:;
/*HLS_DEFINE_PROTOCOL("output");*//* 107ULL */
o_result_data = total;
o_result_m_req_m_trig_req = o_result_m_req_m_next_trig_req;
goto state27;
/********************/
state27:;
/*HLS_DEFINE_STALL_LOOP(ALL,4096ULL, "put", (long long)0x0ULL);*//* 118ULL */
/*HLS_DEFINE_PROTOCOL("output");*//* 107ULL */
goto state28;
/********************/
state28:;
/*HLS_DEFINE_STALL_LOOP(ALL,4096ULL, "put", (long long)0x0ULL);*//* 118ULL */
/*HLS_DEFINE_PROTOCOL("output");*//* 107ULL */
wait( 1LL ); // cycle_id 6
stall0 = o_result_m_stalling;
goto state29;
/********************/
state29:;
/*HLS_DEFINE_PROTOCOL("output");*//* 107ULL */
goto state30;
/********************/
state30:;
/*HLS_DEFINE_PROTOCOL("output");*//* 107ULL */
wait( 1LL ); // cycle_id 7
goto state4;
