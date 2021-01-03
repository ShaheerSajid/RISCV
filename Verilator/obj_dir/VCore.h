// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VCORE_H_
#define _VCORE_H_  // guard

#include "verilated.h"

//==========

class VCore__Syms;

//----------

VL_MODULE(VCore) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(clk,0,0);
    VL_IN8(reset,0,0);
    VL_OUT8(inst_stall,0,0);
    VL_IN8(avl_waitrequest,0,0);
    VL_OUT8(avl_byteenable,3,0);
    VL_OUT8(avl_read,0,0);
    VL_OUT8(avl_write,0,0);
    VL_IN(inst_data,31,0);
    VL_OUT(inst_addr,31,0);
    VL_IN(avl_readdata,31,0);
    VL_OUT(avl_address,31,0);
    VL_OUT(avl_writedata,31,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        CData/*0:0*/ Core__DOT__clk1;
        CData/*0:0*/ Core__DOT__pc_sel;
        CData/*0:0*/ Core__DOT__RegWEn;
        CData/*2:0*/ Core__DOT__immsel;
        CData/*0:0*/ Core__DOT__Bsel;
        CData/*4:0*/ Core__DOT__ALUsel;
        CData/*1:0*/ Core__DOT__wbSel;
        CData/*0:0*/ Core__DOT__BrUn;
        CData/*0:0*/ Core__DOT__BrEq;
        CData/*0:0*/ Core__DOT__BrLT;
        CData/*1:0*/ Core__DOT__memWrite_pipe_ie;
        CData/*2:0*/ Core__DOT__wbsel_pipe_ie;
        CData/*6:0*/ Core__DOT__aluop_pipe_ie;
        CData/*4:0*/ Core__DOT__rdadd_pipe_ie;
        CData/*4:0*/ Core__DOT__rs1add_pipe_ie;
        CData/*4:0*/ Core__DOT__rs2add_pipe_ie;
        CData/*1:0*/ Core__DOT__memWrite_pipe_imem;
        CData/*2:0*/ Core__DOT__wbsel_pipe_imem;
        CData/*4:0*/ Core__DOT__rdadd_pipe_imem;
        CData/*2:0*/ Core__DOT__mode_ie;
        CData/*2:0*/ Core__DOT__mode_imem;
        CData/*0:0*/ Core__DOT__float_write;
        CData/*0:0*/ Core__DOT__fpu_imem;
        CData/*1:0*/ Core__DOT__float_read;
        CData/*3:0*/ Core__DOT__fpu_ie;
        CData/*0:0*/ Core__DOT__stall_core;
        CData/*0:0*/ Core__DOT__reset_ie;
        CData/*0:0*/ Core__DOT__br_stall;
        CData/*0:0*/ Core__DOT__enable;
        CData/*1:0*/ Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__res3;
        CData/*0:0*/ Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__add_sub;
        CData/*7:0*/ Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__a_exp;
        CData/*7:0*/ Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__b_exp;
        CData/*7:0*/ Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__r_exp;
        CData/*1:0*/ Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__mag;
        CData/*0:0*/ Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__state;
        CData/*0:0*/ Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__int2fp_inst__DOT__sign;
        CData/*7:0*/ Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__int2fp_inst__DOT__eout;
        CData/*7:0*/ Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__int2fp_inst__DOT__num_zeros;
        CData/*1:0*/ Core__DOT__core2avl_inst__DOT__byt;
        CData/*3:0*/ Core__DOT__core2avl_inst__DOT__be;
        SData/*8:0*/ Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__multiply_inst__DOT__pre_prod_exp;
        IData/*31:0*/ Core__DOT__pc_in;
        IData/*31:0*/ Core__DOT__pc_out;
        IData/*31:0*/ Core__DOT__rd;
        IData/*31:0*/ Core__DOT__rs1_br;
        IData/*31:0*/ Core__DOT__rs2_br;
        IData/*31:0*/ Core__DOT__fb_out;
        IData/*31:0*/ Core__DOT__A;
        IData/*31:0*/ Core__DOT__B;
        IData/*31:0*/ Core__DOT__imm;
        IData/*31:0*/ Core__DOT__A_out;
        IData/*31:0*/ Core__DOT__instruction_pipe_id;
        IData/*31:0*/ Core__DOT__pc_out_pipe_id;
        IData/*31:0*/ Core__DOT__pc_out_pipe_ie;
        IData/*31:0*/ Core__DOT__rs1_pipe_ie;
        IData/*31:0*/ Core__DOT__rs2_pipe_ie;
        IData/*31:0*/ Core__DOT__imm_pipe_ie;
        IData/*31:0*/ Core__DOT__rs2_pipe_imem;
        IData/*31:0*/ Core__DOT__aluout_pipe_imem;
        IData/*31:0*/ Core__DOT__pc_out_pipe_imem;
        IData/*31:0*/ Core__DOT__pcALU_inst__DOT__alu;
        IData/*31:0*/ Core__DOT__alu__DOT__fpuout;
        IData/*31:0*/ Core__DOT__alu__DOT__ALUout;
    };
    struct {
        IData/*31:0*/ Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__res1;
        IData/*31:0*/ Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__res4;
        IData/*31:0*/ Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__a_m;
        IData/*31:0*/ Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__b_m;
        IData/*31:0*/ Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__r_m;
        IData/*31:0*/ Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__prm;
        IData/*31:0*/ Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__i;
        IData/*31:0*/ Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__fp2int_inst__DOT__abs_int;
        IData/*31:0*/ Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__int2fp_inst__DOT__abs;
        IData/*22:0*/ Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__int2fp_inst__DOT__mout;
        IData/*31:0*/ Core__DOT__core2avl_inst__DOT__q1;
        QData/*45:0*/ Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__multiply_inst__DOT__pre_prod_frac;
        IData/*31:0*/ Core__DOT__regfile__DOT__regfile[32];
        IData/*31:0*/ Core__DOT__genblk1__DOT__regfile_float__DOT__regfile[32];
    };
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    CData/*4:0*/ __Vtableidx1;
    CData/*0:0*/ __Vclklast__TOP__clk;
    CData/*0:0*/ __Vclklast__TOP__Core__DOT__clk1;
    static CData/*3:0*/ __Vtable1_Core__DOT__core2avl_inst__DOT__be[32];
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    VCore__Syms* __VlSymsp;  // Symbol table
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(VCore);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    VCore(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~VCore();
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval();
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(VCore__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(VCore__Syms* symsp, bool first);
  private:
    static QData _change_request(VCore__Syms* __restrict vlSymsp);
  public:
    static void _combo__TOP__4(VCore__Syms* __restrict vlSymsp);
    static void _combo__TOP__6(VCore__Syms* __restrict vlSymsp);
  private:
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(VCore__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif  // VL_DEBUG
  public:
    static void _eval_initial(VCore__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(VCore__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _initial__TOP__1(VCore__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _sequent__TOP__2(VCore__Syms* __restrict vlSymsp);
    static void _sequent__TOP__5(VCore__Syms* __restrict vlSymsp);
    static void _settle__TOP__3(VCore__Syms* __restrict vlSymsp) VL_ATTR_COLD;
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
