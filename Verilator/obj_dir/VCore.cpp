// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VCore.h for the primary calling header

#include "VCore.h"
#include "VCore__Syms.h"

//==========
CData/*3:0*/ VCore::__Vtable1_Core__DOT__core2avl_inst__DOT__be[32];

VL_CTOR_IMP(VCore) {
    VCore__Syms* __restrict vlSymsp = __VlSymsp = new VCore__Syms(this, name());
    VCore* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void VCore::__Vconfigure(VCore__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

VCore::~VCore() {
    delete __VlSymsp; __VlSymsp=NULL;
}

void VCore::eval() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VCore::eval\n"); );
    VCore__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    VCore* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("../IP/Core/Core.v", 1, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void VCore::_eval_initial_loop(VCore__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        _eval_settle(vlSymsp);
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("../IP/Core/Core.v", 1, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void VCore::_initial__TOP__1(VCore__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCore::_initial__TOP__1\n"); );
    VCore* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->Core__DOT__regfile__DOT__regfile[0U] = 0U;
    vlTOPp->Core__DOT__regfile__DOT__regfile[1U] = 0U;
    vlTOPp->Core__DOT__regfile__DOT__regfile[2U] = 0U;
    vlTOPp->Core__DOT__regfile__DOT__regfile[3U] = 0U;
    vlTOPp->Core__DOT__regfile__DOT__regfile[4U] = 0U;
    vlTOPp->Core__DOT__regfile__DOT__regfile[5U] = 0U;
    vlTOPp->Core__DOT__regfile__DOT__regfile[6U] = 0U;
    vlTOPp->Core__DOT__regfile__DOT__regfile[7U] = 0U;
    vlTOPp->Core__DOT__regfile__DOT__regfile[8U] = 0U;
    vlTOPp->Core__DOT__regfile__DOT__regfile[9U] = 0U;
    vlTOPp->Core__DOT__regfile__DOT__regfile[0xaU] = 0U;
    vlTOPp->Core__DOT__regfile__DOT__regfile[0xbU] = 0U;
    vlTOPp->Core__DOT__regfile__DOT__regfile[0xcU] = 0U;
    vlTOPp->Core__DOT__regfile__DOT__regfile[0xdU] = 0U;
    vlTOPp->Core__DOT__regfile__DOT__regfile[0xeU] = 0U;
    vlTOPp->Core__DOT__regfile__DOT__regfile[0xfU] = 0U;
    vlTOPp->Core__DOT__regfile__DOT__regfile[0x10U] = 0U;
    vlTOPp->Core__DOT__regfile__DOT__regfile[0x11U] = 0U;
    vlTOPp->Core__DOT__regfile__DOT__regfile[0x12U] = 0U;
    vlTOPp->Core__DOT__regfile__DOT__regfile[0x13U] = 0U;
    vlTOPp->Core__DOT__regfile__DOT__regfile[0x14U] = 0U;
    vlTOPp->Core__DOT__regfile__DOT__regfile[0x15U] = 0U;
    vlTOPp->Core__DOT__regfile__DOT__regfile[0x16U] = 0U;
    vlTOPp->Core__DOT__regfile__DOT__regfile[0x17U] = 0U;
    vlTOPp->Core__DOT__regfile__DOT__regfile[0x18U] = 0U;
    vlTOPp->Core__DOT__regfile__DOT__regfile[0x19U] = 0U;
    vlTOPp->Core__DOT__regfile__DOT__regfile[0x1aU] = 0U;
    vlTOPp->Core__DOT__regfile__DOT__regfile[0x1bU] = 0U;
    vlTOPp->Core__DOT__regfile__DOT__regfile[0x1cU] = 0U;
    vlTOPp->Core__DOT__regfile__DOT__regfile[0x1dU] = 0U;
    vlTOPp->Core__DOT__regfile__DOT__regfile[0x1eU] = 0U;
    vlTOPp->Core__DOT__regfile__DOT__regfile[0x1fU] = 0U;
    vlTOPp->Core__DOT__genblk1__DOT__regfile_float__DOT__regfile[0U] = 0U;
    vlTOPp->Core__DOT__genblk1__DOT__regfile_float__DOT__regfile[1U] = 0U;
    vlTOPp->Core__DOT__genblk1__DOT__regfile_float__DOT__regfile[2U] = 0U;
    vlTOPp->Core__DOT__genblk1__DOT__regfile_float__DOT__regfile[3U] = 0U;
    vlTOPp->Core__DOT__genblk1__DOT__regfile_float__DOT__regfile[4U] = 0U;
    vlTOPp->Core__DOT__genblk1__DOT__regfile_float__DOT__regfile[5U] = 0U;
    vlTOPp->Core__DOT__genblk1__DOT__regfile_float__DOT__regfile[6U] = 0U;
    vlTOPp->Core__DOT__genblk1__DOT__regfile_float__DOT__regfile[7U] = 0U;
    vlTOPp->Core__DOT__genblk1__DOT__regfile_float__DOT__regfile[8U] = 0U;
    vlTOPp->Core__DOT__genblk1__DOT__regfile_float__DOT__regfile[9U] = 0U;
    vlTOPp->Core__DOT__genblk1__DOT__regfile_float__DOT__regfile[0xaU] = 0U;
    vlTOPp->Core__DOT__genblk1__DOT__regfile_float__DOT__regfile[0xbU] = 0U;
    vlTOPp->Core__DOT__genblk1__DOT__regfile_float__DOT__regfile[0xcU] = 0U;
    vlTOPp->Core__DOT__genblk1__DOT__regfile_float__DOT__regfile[0xdU] = 0U;
    vlTOPp->Core__DOT__genblk1__DOT__regfile_float__DOT__regfile[0xeU] = 0U;
    vlTOPp->Core__DOT__genblk1__DOT__regfile_float__DOT__regfile[0xfU] = 0U;
    vlTOPp->Core__DOT__genblk1__DOT__regfile_float__DOT__regfile[0x10U] = 0U;
    vlTOPp->Core__DOT__genblk1__DOT__regfile_float__DOT__regfile[0x11U] = 0U;
    vlTOPp->Core__DOT__genblk1__DOT__regfile_float__DOT__regfile[0x12U] = 0U;
    vlTOPp->Core__DOT__genblk1__DOT__regfile_float__DOT__regfile[0x13U] = 0U;
    vlTOPp->Core__DOT__genblk1__DOT__regfile_float__DOT__regfile[0x14U] = 0U;
    vlTOPp->Core__DOT__genblk1__DOT__regfile_float__DOT__regfile[0x15U] = 0U;
    vlTOPp->Core__DOT__genblk1__DOT__regfile_float__DOT__regfile[0x16U] = 0U;
    vlTOPp->Core__DOT__genblk1__DOT__regfile_float__DOT__regfile[0x17U] = 0U;
    vlTOPp->Core__DOT__genblk1__DOT__regfile_float__DOT__regfile[0x18U] = 0U;
    vlTOPp->Core__DOT__genblk1__DOT__regfile_float__DOT__regfile[0x19U] = 0U;
    vlTOPp->Core__DOT__genblk1__DOT__regfile_float__DOT__regfile[0x1aU] = 0U;
    vlTOPp->Core__DOT__genblk1__DOT__regfile_float__DOT__regfile[0x1bU] = 0U;
    vlTOPp->Core__DOT__genblk1__DOT__regfile_float__DOT__regfile[0x1cU] = 0U;
    vlTOPp->Core__DOT__genblk1__DOT__regfile_float__DOT__regfile[0x1dU] = 0U;
    vlTOPp->Core__DOT__genblk1__DOT__regfile_float__DOT__regfile[0x1eU] = 0U;
    vlTOPp->Core__DOT__genblk1__DOT__regfile_float__DOT__regfile[0x1fU] = 0U;
}

VL_INLINE_OPT void VCore::_sequent__TOP__2(VCore__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCore::_sequent__TOP__2\n"); );
    VCore* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->Core__DOT__enable = (1U & (~ (IData)(vlTOPp->Core__DOT__stall_core)));
}

void VCore::_settle__TOP__3(VCore__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCore::_settle__TOP__3\n"); );
    VCore* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->Core__DOT__stall_core = ((IData)(vlTOPp->avl_waitrequest) 
                                     & (~ (IData)(vlTOPp->reset)));
    vlTOPp->Core__DOT__clk1 = ((IData)(vlTOPp->Core__DOT__enable) 
                               & (IData)(vlTOPp->clk));
    vlTOPp->avl_read = (1U & ((IData)(vlTOPp->Core__DOT__memWrite_pipe_imem) 
                              >> 1U));
    vlTOPp->avl_write = (1U & (IData)(vlTOPp->Core__DOT__memWrite_pipe_imem));
    vlTOPp->avl_address = vlTOPp->Core__DOT__aluout_pipe_imem;
    vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__add_sub 
        = (((((((((0U == (0x1fU & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie))) 
                  | (1U == (0x1fU & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie)))) 
                 | (2U == (0x1fU & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie)))) 
                | (3U == (0x1fU & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie)))) 
               | (4U == (0x1fU & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie)))) 
              | (5U == (0x1fU & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie)))) 
             | (6U == (0x1fU & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie)))) 
            | (7U == (0x1fU & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie)))) 
           & ((0U != (0x1fU & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie))) 
              & ((1U != (0x1fU & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie))) 
                 & ((2U != (0x1fU & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie))) 
                    & ((3U != (0x1fU & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie))) 
                       & ((4U != (0x1fU & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie))) 
                          & (5U == (0x1fU & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie)))))))));
    vlTOPp->Core__DOT__core2avl_inst__DOT__byt = (3U 
                                                  & ((0U 
                                                      == 
                                                      (vlTOPp->Core__DOT__aluout_pipe_imem 
                                                       >> 2U))
                                                      ? vlTOPp->Core__DOT__aluout_pipe_imem
                                                      : 
                                                     (vlTOPp->Core__DOT__aluout_pipe_imem 
                                                      - 
                                                      ((0x1fU 
                                                        >= 
                                                        (vlTOPp->Core__DOT__aluout_pipe_imem 
                                                         >> 2U))
                                                        ? 
                                                       ((IData)(2U) 
                                                        << 
                                                        (vlTOPp->Core__DOT__aluout_pipe_imem 
                                                         >> 2U))
                                                        : 0U))));
    vlTOPp->Core__DOT__Bsel = (1U & ((0x40U & vlTOPp->Core__DOT__instruction_pipe_id)
                                      ? ((vlTOPp->Core__DOT__instruction_pipe_id 
                                          >> 5U) & 
                                         ((~ (vlTOPp->Core__DOT__instruction_pipe_id 
                                              >> 4U)) 
                                          & ((8U & vlTOPp->Core__DOT__instruction_pipe_id)
                                              ? ((vlTOPp->Core__DOT__instruction_pipe_id 
                                                  >> 2U) 
                                                 & ((vlTOPp->Core__DOT__instruction_pipe_id 
                                                     >> 1U) 
                                                    & vlTOPp->Core__DOT__instruction_pipe_id))
                                              : ((4U 
                                                  & vlTOPp->Core__DOT__instruction_pipe_id)
                                                  ? 
                                                 ((vlTOPp->Core__DOT__instruction_pipe_id 
                                                   >> 1U) 
                                                  & vlTOPp->Core__DOT__instruction_pipe_id)
                                                  : 
                                                 ((vlTOPp->Core__DOT__instruction_pipe_id 
                                                   >> 1U) 
                                                  & vlTOPp->Core__DOT__instruction_pipe_id)))))
                                      : ((0x20U & vlTOPp->Core__DOT__instruction_pipe_id)
                                          ? ((0x10U 
                                              & vlTOPp->Core__DOT__instruction_pipe_id)
                                              ? ((~ 
                                                  (vlTOPp->Core__DOT__instruction_pipe_id 
                                                   >> 3U)) 
                                                 & ((vlTOPp->Core__DOT__instruction_pipe_id 
                                                     >> 2U) 
                                                    & ((vlTOPp->Core__DOT__instruction_pipe_id 
                                                        >> 1U) 
                                                       & vlTOPp->Core__DOT__instruction_pipe_id)))
                                              : ((~ 
                                                  (vlTOPp->Core__DOT__instruction_pipe_id 
                                                   >> 3U)) 
                                                 & ((4U 
                                                     & vlTOPp->Core__DOT__instruction_pipe_id)
                                                     ? 
                                                    ((vlTOPp->Core__DOT__instruction_pipe_id 
                                                      >> 1U) 
                                                     & vlTOPp->Core__DOT__instruction_pipe_id)
                                                     : 
                                                    ((vlTOPp->Core__DOT__instruction_pipe_id 
                                                      >> 1U) 
                                                     & vlTOPp->Core__DOT__instruction_pipe_id))))
                                          : ((0x10U 
                                              & vlTOPp->Core__DOT__instruction_pipe_id)
                                              ? ((~ 
                                                  (vlTOPp->Core__DOT__instruction_pipe_id 
                                                   >> 3U)) 
                                                 & ((4U 
                                                     & vlTOPp->Core__DOT__instruction_pipe_id)
                                                     ? 
                                                    ((vlTOPp->Core__DOT__instruction_pipe_id 
                                                      >> 1U) 
                                                     & vlTOPp->Core__DOT__instruction_pipe_id)
                                                     : 
                                                    ((vlTOPp->Core__DOT__instruction_pipe_id 
                                                      >> 1U) 
                                                     & vlTOPp->Core__DOT__instruction_pipe_id)))
                                              : ((~ 
                                                  (vlTOPp->Core__DOT__instruction_pipe_id 
                                                   >> 3U)) 
                                                 & ((4U 
                                                     & vlTOPp->Core__DOT__instruction_pipe_id)
                                                     ? 
                                                    ((vlTOPp->Core__DOT__instruction_pipe_id 
                                                      >> 1U) 
                                                     & vlTOPp->Core__DOT__instruction_pipe_id)
                                                     : 
                                                    ((vlTOPp->Core__DOT__instruction_pipe_id 
                                                      >> 1U) 
                                                     & vlTOPp->Core__DOT__instruction_pipe_id)))))));
    vlTOPp->Core__DOT__RegWEn = (1U & ((0x40U & vlTOPp->Core__DOT__instruction_pipe_id)
                                        ? ((0x20U & vlTOPp->Core__DOT__instruction_pipe_id)
                                            ? ((~ (vlTOPp->Core__DOT__instruction_pipe_id 
                                                   >> 4U)) 
                                               & ((8U 
                                                   & vlTOPp->Core__DOT__instruction_pipe_id)
                                                   ? 
                                                  ((vlTOPp->Core__DOT__instruction_pipe_id 
                                                    >> 2U) 
                                                   & ((vlTOPp->Core__DOT__instruction_pipe_id 
                                                       >> 1U) 
                                                      & vlTOPp->Core__DOT__instruction_pipe_id))
                                                   : 
                                                  ((vlTOPp->Core__DOT__instruction_pipe_id 
                                                    >> 2U) 
                                                   & ((vlTOPp->Core__DOT__instruction_pipe_id 
                                                       >> 1U) 
                                                      & vlTOPp->Core__DOT__instruction_pipe_id))))
                                            : ((vlTOPp->Core__DOT__instruction_pipe_id 
                                                >> 4U) 
                                               & ((~ 
                                                   (vlTOPp->Core__DOT__instruction_pipe_id 
                                                    >> 3U)) 
                                                  & ((~ 
                                                      (vlTOPp->Core__DOT__instruction_pipe_id 
                                                       >> 2U)) 
                                                     & ((vlTOPp->Core__DOT__instruction_pipe_id 
                                                         >> 1U) 
                                                        & vlTOPp->Core__DOT__instruction_pipe_id)))))
                                        : ((0x20U & vlTOPp->Core__DOT__instruction_pipe_id)
                                            ? ((vlTOPp->Core__DOT__instruction_pipe_id 
                                                >> 4U) 
                                               & ((~ 
                                                   (vlTOPp->Core__DOT__instruction_pipe_id 
                                                    >> 3U)) 
                                                  & ((4U 
                                                      & vlTOPp->Core__DOT__instruction_pipe_id)
                                                      ? 
                                                     ((vlTOPp->Core__DOT__instruction_pipe_id 
                                                       >> 1U) 
                                                      & vlTOPp->Core__DOT__instruction_pipe_id)
                                                      : 
                                                     ((vlTOPp->Core__DOT__instruction_pipe_id 
                                                       >> 1U) 
                                                      & vlTOPp->Core__DOT__instruction_pipe_id))))
                                            : ((0x10U 
                                                & vlTOPp->Core__DOT__instruction_pipe_id)
                                                ? (
                                                   (~ 
                                                    (vlTOPp->Core__DOT__instruction_pipe_id 
                                                     >> 3U)) 
                                                   & ((4U 
                                                       & vlTOPp->Core__DOT__instruction_pipe_id)
                                                       ? 
                                                      ((vlTOPp->Core__DOT__instruction_pipe_id 
                                                        >> 1U) 
                                                       & vlTOPp->Core__DOT__instruction_pipe_id)
                                                       : 
                                                      ((vlTOPp->Core__DOT__instruction_pipe_id 
                                                        >> 1U) 
                                                       & vlTOPp->Core__DOT__instruction_pipe_id)))
                                                : (
                                                   (~ 
                                                    (vlTOPp->Core__DOT__instruction_pipe_id 
                                                     >> 3U)) 
                                                   & ((4U 
                                                       & vlTOPp->Core__DOT__instruction_pipe_id)
                                                       ? 
                                                      ((vlTOPp->Core__DOT__instruction_pipe_id 
                                                        >> 1U) 
                                                       & vlTOPp->Core__DOT__instruction_pipe_id)
                                                       : 
                                                      ((vlTOPp->Core__DOT__instruction_pipe_id 
                                                        >> 1U) 
                                                       & vlTOPp->Core__DOT__instruction_pipe_id)))))));
    vlTOPp->Core__DOT__ALUsel = ((0x40U & vlTOPp->Core__DOT__instruction_pipe_id)
                                  ? ((0x20U & vlTOPp->Core__DOT__instruction_pipe_id)
                                      ? ((0x10U & vlTOPp->Core__DOT__instruction_pipe_id)
                                          ? 0U : ((8U 
                                                   & vlTOPp->Core__DOT__instruction_pipe_id)
                                                   ? 
                                                  ((4U 
                                                    & vlTOPp->Core__DOT__instruction_pipe_id)
                                                    ? 
                                                   ((2U 
                                                     & vlTOPp->Core__DOT__instruction_pipe_id)
                                                     ? 
                                                    ((1U 
                                                      & vlTOPp->Core__DOT__instruction_pipe_id)
                                                      ? 2U
                                                      : 0U)
                                                     : 0U)
                                                    : 0U)
                                                   : 
                                                  ((4U 
                                                    & vlTOPp->Core__DOT__instruction_pipe_id)
                                                    ? 
                                                   ((2U 
                                                     & vlTOPp->Core__DOT__instruction_pipe_id)
                                                     ? 
                                                    ((1U 
                                                      & vlTOPp->Core__DOT__instruction_pipe_id)
                                                      ? 2U
                                                      : 0U)
                                                     : 0U)
                                                    : 
                                                   ((2U 
                                                     & vlTOPp->Core__DOT__instruction_pipe_id)
                                                     ? 
                                                    ((1U 
                                                      & vlTOPp->Core__DOT__instruction_pipe_id)
                                                      ? 2U
                                                      : 0U)
                                                     : 0U))))
                                      : ((0x10U & vlTOPp->Core__DOT__instruction_pipe_id)
                                          ? ((8U & vlTOPp->Core__DOT__instruction_pipe_id)
                                              ? 0U : 
                                             ((4U & vlTOPp->Core__DOT__instruction_pipe_id)
                                               ? 0U
                                               : ((2U 
                                                   & vlTOPp->Core__DOT__instruction_pipe_id)
                                                   ? 
                                                  ((1U 
                                                    & vlTOPp->Core__DOT__instruction_pipe_id)
                                                    ? 
                                                   ((0x80000000U 
                                                     & vlTOPp->Core__DOT__instruction_pipe_id)
                                                     ? 
                                                    ((0x40000000U 
                                                      & vlTOPp->Core__DOT__instruction_pipe_id)
                                                      ? 
                                                     ((0x20000000U 
                                                       & vlTOPp->Core__DOT__instruction_pipe_id)
                                                       ? 
                                                      ((0x10000000U 
                                                        & vlTOPp->Core__DOT__instruction_pipe_id)
                                                        ? 
                                                       ((0x8000000U 
                                                         & vlTOPp->Core__DOT__instruction_pipe_id)
                                                         ? 0U
                                                         : 0xcU)
                                                        : 
                                                       ((0x8000000U 
                                                         & vlTOPp->Core__DOT__instruction_pipe_id)
                                                         ? 0U
                                                         : 0xdU))
                                                       : 
                                                      ((0x10000000U 
                                                        & vlTOPp->Core__DOT__instruction_pipe_id)
                                                        ? 
                                                       ((0x8000000U 
                                                         & vlTOPp->Core__DOT__instruction_pipe_id)
                                                         ? 0U
                                                         : 0xeU)
                                                        : 
                                                       ((0x8000000U 
                                                         & vlTOPp->Core__DOT__instruction_pipe_id)
                                                         ? 0U
                                                         : 0xfU)))
                                                      : 
                                                     ((0x20000000U 
                                                       & vlTOPp->Core__DOT__instruction_pipe_id)
                                                       ? 
                                                      ((0x10000000U 
                                                        & vlTOPp->Core__DOT__instruction_pipe_id)
                                                        ? 0U
                                                        : 
                                                       ((0x8000000U 
                                                         & vlTOPp->Core__DOT__instruction_pipe_id)
                                                         ? 0U
                                                         : 
                                                        ((0U 
                                                          == 
                                                          (7U 
                                                           & (vlTOPp->Core__DOT__instruction_pipe_id 
                                                              >> 0xcU)))
                                                          ? 0xbU
                                                          : 
                                                         ((1U 
                                                           == 
                                                           (7U 
                                                            & (vlTOPp->Core__DOT__instruction_pipe_id 
                                                               >> 0xcU)))
                                                           ? 0xaU
                                                           : 
                                                          ((2U 
                                                            == 
                                                            (7U 
                                                             & (vlTOPp->Core__DOT__instruction_pipe_id 
                                                                >> 0xcU)))
                                                            ? 9U
                                                            : 0U)))))
                                                       : 0U))
                                                     : 
                                                    ((0x40000000U 
                                                      & vlTOPp->Core__DOT__instruction_pipe_id)
                                                      ? 0U
                                                      : 
                                                     ((0x20000000U 
                                                       & vlTOPp->Core__DOT__instruction_pipe_id)
                                                       ? 
                                                      ((0x10000000U 
                                                        & vlTOPp->Core__DOT__instruction_pipe_id)
                                                        ? 0U
                                                        : 
                                                       ((0x8000000U 
                                                         & vlTOPp->Core__DOT__instruction_pipe_id)
                                                         ? 
                                                        ((0U 
                                                          == 
                                                          (7U 
                                                           & (vlTOPp->Core__DOT__instruction_pipe_id 
                                                              >> 0xcU)))
                                                          ? 7U
                                                          : 8U)
                                                         : 0U))
                                                       : 
                                                      ((0x10000000U 
                                                        & vlTOPp->Core__DOT__instruction_pipe_id)
                                                        ? 
                                                       ((0x8000000U 
                                                         & vlTOPp->Core__DOT__instruction_pipe_id)
                                                         ? 0U
                                                         : 6U)
                                                        : 
                                                       ((0x8000000U 
                                                         & vlTOPp->Core__DOT__instruction_pipe_id)
                                                         ? 5U
                                                         : 4U)))))
                                                    : 0U)
                                                   : 0U)))
                                          : 0U)) : 
                                 ((0x20U & vlTOPp->Core__DOT__instruction_pipe_id)
                                   ? ((0x10U & vlTOPp->Core__DOT__instruction_pipe_id)
                                       ? ((8U & vlTOPp->Core__DOT__instruction_pipe_id)
                                           ? 0U : (
                                                   (4U 
                                                    & vlTOPp->Core__DOT__instruction_pipe_id)
                                                    ? 
                                                   ((2U 
                                                     & vlTOPp->Core__DOT__instruction_pipe_id)
                                                     ? 
                                                    ((1U 
                                                      & vlTOPp->Core__DOT__instruction_pipe_id)
                                                      ? 1U
                                                      : 0U)
                                                     : 0U)
                                                    : 
                                                   ((2U 
                                                     & vlTOPp->Core__DOT__instruction_pipe_id)
                                                     ? 
                                                    ((1U 
                                                      & vlTOPp->Core__DOT__instruction_pipe_id)
                                                      ? 
                                                     ((1U 
                                                       == 
                                                       (0x7fU 
                                                        & (vlTOPp->Core__DOT__instruction_pipe_id 
                                                           >> 0x19U)))
                                                       ? 
                                                      ((0x4000U 
                                                        & vlTOPp->Core__DOT__instruction_pipe_id)
                                                        ? 
                                                       ((0x2000U 
                                                         & vlTOPp->Core__DOT__instruction_pipe_id)
                                                         ? 
                                                        ((0x1000U 
                                                          & vlTOPp->Core__DOT__instruction_pipe_id)
                                                          ? 0x14U
                                                          : 0x13U)
                                                         : 
                                                        ((0x1000U 
                                                          & vlTOPp->Core__DOT__instruction_pipe_id)
                                                          ? 0x12U
                                                          : 0x11U))
                                                        : 
                                                       ((0x2000U 
                                                         & vlTOPp->Core__DOT__instruction_pipe_id)
                                                         ? 
                                                        ((0x1000U 
                                                          & vlTOPp->Core__DOT__instruction_pipe_id)
                                                          ? 0x10U
                                                          : 0U)
                                                         : 
                                                        ((0x1000U 
                                                          & vlTOPp->Core__DOT__instruction_pipe_id)
                                                          ? 0xfU
                                                          : 8U)))
                                                       : 
                                                      ((0x4000U 
                                                        & vlTOPp->Core__DOT__instruction_pipe_id)
                                                        ? 
                                                       ((0x2000U 
                                                         & vlTOPp->Core__DOT__instruction_pipe_id)
                                                         ? 
                                                        ((0x1000U 
                                                          & vlTOPp->Core__DOT__instruction_pipe_id)
                                                          ? 0xaU
                                                          : 0xbU)
                                                         : 
                                                        ((0x1000U 
                                                          & vlTOPp->Core__DOT__instruction_pipe_id)
                                                          ? 
                                                         ((0x40000000U 
                                                           & vlTOPp->Core__DOT__instruction_pipe_id)
                                                           ? 9U
                                                           : 7U)
                                                          : 0xcU))
                                                        : 
                                                       ((0x2000U 
                                                         & vlTOPp->Core__DOT__instruction_pipe_id)
                                                         ? 
                                                        ((0x1000U 
                                                          & vlTOPp->Core__DOT__instruction_pipe_id)
                                                          ? 0xdU
                                                          : 0xeU)
                                                         : 
                                                        ((0x1000U 
                                                          & vlTOPp->Core__DOT__instruction_pipe_id)
                                                          ? 6U
                                                          : 
                                                         ((0x40000000U 
                                                           & vlTOPp->Core__DOT__instruction_pipe_id)
                                                           ? 3U
                                                           : 2U)))))
                                                      : 0U)
                                                     : 0U)))
                                       : ((8U & vlTOPp->Core__DOT__instruction_pipe_id)
                                           ? 0U : (
                                                   (4U 
                                                    & vlTOPp->Core__DOT__instruction_pipe_id)
                                                    ? 
                                                   ((2U 
                                                     & vlTOPp->Core__DOT__instruction_pipe_id)
                                                     ? 
                                                    ((1U 
                                                      & vlTOPp->Core__DOT__instruction_pipe_id)
                                                      ? 2U
                                                      : 0U)
                                                     : 0U)
                                                    : 
                                                   ((2U 
                                                     & vlTOPp->Core__DOT__instruction_pipe_id)
                                                     ? 
                                                    ((1U 
                                                      & vlTOPp->Core__DOT__instruction_pipe_id)
                                                      ? 2U
                                                      : 0U)
                                                     : 0U))))
                                   : ((0x10U & vlTOPp->Core__DOT__instruction_pipe_id)
                                       ? ((8U & vlTOPp->Core__DOT__instruction_pipe_id)
                                           ? 0U : (
                                                   (4U 
                                                    & vlTOPp->Core__DOT__instruction_pipe_id)
                                                    ? 
                                                   ((2U 
                                                     & vlTOPp->Core__DOT__instruction_pipe_id)
                                                     ? 
                                                    ((1U 
                                                      & vlTOPp->Core__DOT__instruction_pipe_id)
                                                      ? 2U
                                                      : 0U)
                                                     : 0U)
                                                    : 
                                                   ((2U 
                                                     & vlTOPp->Core__DOT__instruction_pipe_id)
                                                     ? 
                                                    ((1U 
                                                      & vlTOPp->Core__DOT__instruction_pipe_id)
                                                      ? 
                                                     ((0x4000U 
                                                       & vlTOPp->Core__DOT__instruction_pipe_id)
                                                       ? 
                                                      ((0x2000U 
                                                        & vlTOPp->Core__DOT__instruction_pipe_id)
                                                        ? 
                                                       ((0x1000U 
                                                         & vlTOPp->Core__DOT__instruction_pipe_id)
                                                         ? 0xaU
                                                         : 0xbU)
                                                        : 
                                                       ((0x1000U 
                                                         & vlTOPp->Core__DOT__instruction_pipe_id)
                                                         ? 
                                                        ((0x40000000U 
                                                          & vlTOPp->Core__DOT__instruction_pipe_id)
                                                          ? 9U
                                                          : 7U)
                                                         : 0xcU))
                                                       : 
                                                      ((0x2000U 
                                                        & vlTOPp->Core__DOT__instruction_pipe_id)
                                                        ? 
                                                       ((0x1000U 
                                                         & vlTOPp->Core__DOT__instruction_pipe_id)
                                                         ? 0xdU
                                                         : 0xeU)
                                                        : 
                                                       ((0x1000U 
                                                         & vlTOPp->Core__DOT__instruction_pipe_id)
                                                         ? 6U
                                                         : 2U)))
                                                      : 0U)
                                                     : 0U)))
                                       : ((8U & vlTOPp->Core__DOT__instruction_pipe_id)
                                           ? 0U : (
                                                   (4U 
                                                    & vlTOPp->Core__DOT__instruction_pipe_id)
                                                    ? 
                                                   ((2U 
                                                     & vlTOPp->Core__DOT__instruction_pipe_id)
                                                     ? 
                                                    ((1U 
                                                      & vlTOPp->Core__DOT__instruction_pipe_id)
                                                      ? 2U
                                                      : 0U)
                                                     : 0U)
                                                    : 
                                                   ((2U 
                                                     & vlTOPp->Core__DOT__instruction_pipe_id)
                                                     ? 
                                                    ((1U 
                                                      & vlTOPp->Core__DOT__instruction_pipe_id)
                                                      ? 2U
                                                      : 0U)
                                                     : 0U))))));
    vlTOPp->Core__DOT__wbSel = ((0x40U & vlTOPp->Core__DOT__instruction_pipe_id)
                                 ? ((0x20U & vlTOPp->Core__DOT__instruction_pipe_id)
                                     ? ((0x10U & vlTOPp->Core__DOT__instruction_pipe_id)
                                         ? 0U : ((8U 
                                                  & vlTOPp->Core__DOT__instruction_pipe_id)
                                                  ? 
                                                 ((4U 
                                                   & vlTOPp->Core__DOT__instruction_pipe_id)
                                                   ? 
                                                  ((2U 
                                                    & vlTOPp->Core__DOT__instruction_pipe_id)
                                                    ? 
                                                   ((1U 
                                                     & vlTOPp->Core__DOT__instruction_pipe_id)
                                                     ? 1U
                                                     : 0U)
                                                    : 0U)
                                                   : 0U)
                                                  : 
                                                 ((4U 
                                                   & vlTOPp->Core__DOT__instruction_pipe_id)
                                                   ? 
                                                  ((2U 
                                                    & vlTOPp->Core__DOT__instruction_pipe_id)
                                                    ? 
                                                   ((1U 
                                                     & vlTOPp->Core__DOT__instruction_pipe_id)
                                                     ? 1U
                                                     : 0U)
                                                    : 0U)
                                                   : 0U)))
                                     : 0U) : ((0x20U 
                                               & vlTOPp->Core__DOT__instruction_pipe_id)
                                               ? 0U
                                               : ((0x10U 
                                                   & vlTOPp->Core__DOT__instruction_pipe_id)
                                                   ? 0U
                                                   : 
                                                  ((8U 
                                                    & vlTOPp->Core__DOT__instruction_pipe_id)
                                                    ? 0U
                                                    : 
                                                   ((4U 
                                                     & vlTOPp->Core__DOT__instruction_pipe_id)
                                                     ? 
                                                    ((2U 
                                                      & vlTOPp->Core__DOT__instruction_pipe_id)
                                                      ? 
                                                     ((1U 
                                                       & vlTOPp->Core__DOT__instruction_pipe_id)
                                                       ? 2U
                                                       : 0U)
                                                      : 0U)
                                                     : 
                                                    ((2U 
                                                      & vlTOPp->Core__DOT__instruction_pipe_id)
                                                      ? 
                                                     ((1U 
                                                       & vlTOPp->Core__DOT__instruction_pipe_id)
                                                       ? 2U
                                                       : 0U)
                                                      : 0U))))));
    vlTOPp->Core__DOT__float_write = (1U & ((0x40U 
                                             & vlTOPp->Core__DOT__instruction_pipe_id)
                                             ? ((~ 
                                                 (vlTOPp->Core__DOT__instruction_pipe_id 
                                                  >> 5U)) 
                                                & ((vlTOPp->Core__DOT__instruction_pipe_id 
                                                    >> 4U) 
                                                   & ((~ 
                                                       (vlTOPp->Core__DOT__instruction_pipe_id 
                                                        >> 3U)) 
                                                      & ((~ 
                                                          (vlTOPp->Core__DOT__instruction_pipe_id 
                                                           >> 2U)) 
                                                         & ((vlTOPp->Core__DOT__instruction_pipe_id 
                                                             >> 1U) 
                                                            & (vlTOPp->Core__DOT__instruction_pipe_id 
                                                               & ((0x80000000U 
                                                                   & vlTOPp->Core__DOT__instruction_pipe_id)
                                                                   ? 
                                                                  ((vlTOPp->Core__DOT__instruction_pipe_id 
                                                                    >> 0x1eU) 
                                                                   & ((0x20000000U 
                                                                       & vlTOPp->Core__DOT__instruction_pipe_id)
                                                                       ? 
                                                                      ((vlTOPp->Core__DOT__instruction_pipe_id 
                                                                        >> 0x1cU) 
                                                                       & (~ 
                                                                          (vlTOPp->Core__DOT__instruction_pipe_id 
                                                                           >> 0x1bU)))
                                                                       : 
                                                                      ((vlTOPp->Core__DOT__instruction_pipe_id 
                                                                        >> 0x1cU) 
                                                                       & (~ 
                                                                          (vlTOPp->Core__DOT__instruction_pipe_id 
                                                                           >> 0x1bU)))))
                                                                   : 
                                                                  ((~ 
                                                                    (vlTOPp->Core__DOT__instruction_pipe_id 
                                                                     >> 0x1eU)) 
                                                                   & ((0x20000000U 
                                                                       & vlTOPp->Core__DOT__instruction_pipe_id)
                                                                       ? 
                                                                      ((~ 
                                                                        (vlTOPp->Core__DOT__instruction_pipe_id 
                                                                         >> 0x1cU)) 
                                                                       & (vlTOPp->Core__DOT__instruction_pipe_id 
                                                                          >> 0x1bU))
                                                                       : 
                                                                      ((~ 
                                                                        (vlTOPp->Core__DOT__instruction_pipe_id 
                                                                         >> 0x1cU)) 
                                                                       | (~ 
                                                                          (vlTOPp->Core__DOT__instruction_pipe_id 
                                                                           >> 0x1bU))))))))))))
                                             : ((~ 
                                                 (vlTOPp->Core__DOT__instruction_pipe_id 
                                                  >> 5U)) 
                                                & ((~ 
                                                    (vlTOPp->Core__DOT__instruction_pipe_id 
                                                     >> 4U)) 
                                                   & ((~ 
                                                       (vlTOPp->Core__DOT__instruction_pipe_id 
                                                        >> 3U)) 
                                                      & ((vlTOPp->Core__DOT__instruction_pipe_id 
                                                          >> 2U) 
                                                         & ((vlTOPp->Core__DOT__instruction_pipe_id 
                                                             >> 1U) 
                                                            & vlTOPp->Core__DOT__instruction_pipe_id)))))));
    vlTOPp->Core__DOT__immsel = ((0x40U & vlTOPp->Core__DOT__instruction_pipe_id)
                                  ? ((0x20U & vlTOPp->Core__DOT__instruction_pipe_id)
                                      ? ((0x10U & vlTOPp->Core__DOT__instruction_pipe_id)
                                          ? 0U : ((8U 
                                                   & vlTOPp->Core__DOT__instruction_pipe_id)
                                                   ? 
                                                  ((4U 
                                                    & vlTOPp->Core__DOT__instruction_pipe_id)
                                                    ? 
                                                   ((2U 
                                                     & vlTOPp->Core__DOT__instruction_pipe_id)
                                                     ? 
                                                    ((1U 
                                                      & vlTOPp->Core__DOT__instruction_pipe_id)
                                                      ? 3U
                                                      : 0U)
                                                     : 0U)
                                                    : 0U)
                                                   : 
                                                  ((4U 
                                                    & vlTOPp->Core__DOT__instruction_pipe_id)
                                                    ? 0U
                                                    : 
                                                   ((2U 
                                                     & vlTOPp->Core__DOT__instruction_pipe_id)
                                                     ? 
                                                    ((1U 
                                                      & vlTOPp->Core__DOT__instruction_pipe_id)
                                                      ? 2U
                                                      : 0U)
                                                     : 0U))))
                                      : 0U) : ((0x20U 
                                                & vlTOPp->Core__DOT__instruction_pipe_id)
                                                ? (
                                                   (0x10U 
                                                    & vlTOPp->Core__DOT__instruction_pipe_id)
                                                    ? 
                                                   ((8U 
                                                     & vlTOPp->Core__DOT__instruction_pipe_id)
                                                     ? 0U
                                                     : 
                                                    ((4U 
                                                      & vlTOPp->Core__DOT__instruction_pipe_id)
                                                      ? 
                                                     ((2U 
                                                       & vlTOPp->Core__DOT__instruction_pipe_id)
                                                       ? 
                                                      ((1U 
                                                        & vlTOPp->Core__DOT__instruction_pipe_id)
                                                        ? 4U
                                                        : 0U)
                                                       : 0U)
                                                      : 0U))
                                                    : 
                                                   ((8U 
                                                     & vlTOPp->Core__DOT__instruction_pipe_id)
                                                     ? 0U
                                                     : 
                                                    ((4U 
                                                      & vlTOPp->Core__DOT__instruction_pipe_id)
                                                      ? 
                                                     ((2U 
                                                       & vlTOPp->Core__DOT__instruction_pipe_id)
                                                       ? 
                                                      ((1U 
                                                        & vlTOPp->Core__DOT__instruction_pipe_id)
                                                        ? 1U
                                                        : 0U)
                                                       : 0U)
                                                      : 
                                                     ((2U 
                                                       & vlTOPp->Core__DOT__instruction_pipe_id)
                                                       ? 
                                                      ((1U 
                                                        & vlTOPp->Core__DOT__instruction_pipe_id)
                                                        ? 1U
                                                        : 0U)
                                                       : 0U))))
                                                : (
                                                   (0x10U 
                                                    & vlTOPp->Core__DOT__instruction_pipe_id)
                                                    ? 
                                                   ((8U 
                                                     & vlTOPp->Core__DOT__instruction_pipe_id)
                                                     ? 0U
                                                     : 
                                                    ((4U 
                                                      & vlTOPp->Core__DOT__instruction_pipe_id)
                                                      ? 
                                                     ((2U 
                                                       & vlTOPp->Core__DOT__instruction_pipe_id)
                                                       ? 
                                                      ((1U 
                                                        & vlTOPp->Core__DOT__instruction_pipe_id)
                                                        ? 4U
                                                        : 0U)
                                                       : 0U)
                                                      : 0U))
                                                    : 0U)));
    vlTOPp->Core__DOT__BrUn = (1U & ((vlTOPp->Core__DOT__instruction_pipe_id 
                                      >> 6U) & ((vlTOPp->Core__DOT__instruction_pipe_id 
                                                 >> 5U) 
                                                & ((~ 
                                                    (vlTOPp->Core__DOT__instruction_pipe_id 
                                                     >> 4U)) 
                                                   & ((~ 
                                                       (vlTOPp->Core__DOT__instruction_pipe_id 
                                                        >> 3U)) 
                                                      & ((~ 
                                                          (vlTOPp->Core__DOT__instruction_pipe_id 
                                                           >> 2U)) 
                                                         & ((vlTOPp->Core__DOT__instruction_pipe_id 
                                                             >> 1U) 
                                                            & (vlTOPp->Core__DOT__instruction_pipe_id 
                                                               & ((~ 
                                                                   (vlTOPp->Core__DOT__instruction_pipe_id 
                                                                    >> 0xeU)) 
                                                                  | (vlTOPp->Core__DOT__instruction_pipe_id 
                                                                     >> 0xdU))))))))));
    vlTOPp->Core__DOT__float_read = ((0x40U & vlTOPp->Core__DOT__instruction_pipe_id)
                                      ? ((0x20U & vlTOPp->Core__DOT__instruction_pipe_id)
                                          ? 0U : ((0x10U 
                                                   & vlTOPp->Core__DOT__instruction_pipe_id)
                                                   ? 
                                                  ((8U 
                                                    & vlTOPp->Core__DOT__instruction_pipe_id)
                                                    ? 0U
                                                    : 
                                                   ((4U 
                                                     & vlTOPp->Core__DOT__instruction_pipe_id)
                                                     ? 0U
                                                     : 
                                                    ((2U 
                                                      & vlTOPp->Core__DOT__instruction_pipe_id)
                                                      ? 
                                                     ((1U 
                                                       & vlTOPp->Core__DOT__instruction_pipe_id)
                                                       ? 
                                                      ((0x80000000U 
                                                        & vlTOPp->Core__DOT__instruction_pipe_id)
                                                        ? 
                                                       ((0x40000000U 
                                                         & vlTOPp->Core__DOT__instruction_pipe_id)
                                                         ? 
                                                        ((0x20000000U 
                                                          & vlTOPp->Core__DOT__instruction_pipe_id)
                                                          ? 
                                                         ((0x10000000U 
                                                           & vlTOPp->Core__DOT__instruction_pipe_id)
                                                           ? 0U
                                                           : 
                                                          ((0x8000000U 
                                                            & vlTOPp->Core__DOT__instruction_pipe_id)
                                                            ? 0U
                                                            : 2U))
                                                          : 
                                                         ((0x10000000U 
                                                           & vlTOPp->Core__DOT__instruction_pipe_id)
                                                           ? 0U
                                                           : 
                                                          ((0x8000000U 
                                                            & vlTOPp->Core__DOT__instruction_pipe_id)
                                                            ? 0U
                                                            : 2U)))
                                                         : 
                                                        ((0x20000000U 
                                                          & vlTOPp->Core__DOT__instruction_pipe_id)
                                                          ? 
                                                         ((0x10000000U 
                                                           & vlTOPp->Core__DOT__instruction_pipe_id)
                                                           ? 0U
                                                           : 
                                                          ((0x8000000U 
                                                            & vlTOPp->Core__DOT__instruction_pipe_id)
                                                            ? 0U
                                                            : 3U))
                                                          : 0U))
                                                        : 
                                                       ((0x40000000U 
                                                         & vlTOPp->Core__DOT__instruction_pipe_id)
                                                         ? 0U
                                                         : 
                                                        ((0x20000000U 
                                                          & vlTOPp->Core__DOT__instruction_pipe_id)
                                                          ? 
                                                         ((0x10000000U 
                                                           & vlTOPp->Core__DOT__instruction_pipe_id)
                                                           ? 0U
                                                           : 
                                                          ((0x8000000U 
                                                            & vlTOPp->Core__DOT__instruction_pipe_id)
                                                            ? 3U
                                                            : 0U))
                                                          : 
                                                         ((0x10000000U 
                                                           & vlTOPp->Core__DOT__instruction_pipe_id)
                                                           ? 
                                                          ((0x8000000U 
                                                            & vlTOPp->Core__DOT__instruction_pipe_id)
                                                            ? 0U
                                                            : 3U)
                                                           : 3U))))
                                                       : 0U)
                                                      : 0U)))
                                                   : 0U))
                                      : ((0x20U & vlTOPp->Core__DOT__instruction_pipe_id)
                                          ? ((0x10U 
                                              & vlTOPp->Core__DOT__instruction_pipe_id)
                                              ? 0U : 
                                             ((8U & vlTOPp->Core__DOT__instruction_pipe_id)
                                               ? 0U
                                               : ((4U 
                                                   & vlTOPp->Core__DOT__instruction_pipe_id)
                                                   ? 
                                                  ((2U 
                                                    & vlTOPp->Core__DOT__instruction_pipe_id)
                                                    ? 
                                                   ((1U 
                                                     & vlTOPp->Core__DOT__instruction_pipe_id)
                                                     ? 1U
                                                     : 0U)
                                                    : 0U)
                                                   : 0U)))
                                          : 0U));
    if ((0U == (IData)(vlTOPp->Core__DOT__core2avl_inst__DOT__byt))) {
        vlTOPp->avl_writedata = vlTOPp->Core__DOT__rs2_pipe_imem;
    } else {
        if ((1U == (IData)(vlTOPp->Core__DOT__core2avl_inst__DOT__byt))) {
            vlTOPp->avl_writedata = (vlTOPp->Core__DOT__rs2_pipe_imem 
                                     << 8U);
        } else {
            if ((2U == (IData)(vlTOPp->Core__DOT__core2avl_inst__DOT__byt))) {
                vlTOPp->avl_writedata = (vlTOPp->Core__DOT__rs2_pipe_imem 
                                         << 0x10U);
            } else {
                if ((3U == (IData)(vlTOPp->Core__DOT__core2avl_inst__DOT__byt))) {
                    vlTOPp->avl_writedata = (vlTOPp->Core__DOT__rs2_pipe_imem 
                                             << 0x18U);
                }
            }
        }
    }
    vlTOPp->__Vtableidx1 = (((IData)(vlTOPp->Core__DOT__core2avl_inst__DOT__byt) 
                             << 3U) | (IData)(vlTOPp->Core__DOT__mode_imem));
    vlTOPp->Core__DOT__core2avl_inst__DOT__be = vlTOPp->__Vtable1_Core__DOT__core2avl_inst__DOT__be
        [vlTOPp->__Vtableidx1];
    vlTOPp->Core__DOT__imm = ((4U & (IData)(vlTOPp->Core__DOT__immsel))
                               ? ((2U & (IData)(vlTOPp->Core__DOT__immsel))
                                   ? 0U : ((1U & (IData)(vlTOPp->Core__DOT__immsel))
                                            ? 0U : 
                                           (0xfffff000U 
                                            & vlTOPp->Core__DOT__instruction_pipe_id)))
                               : ((2U & (IData)(vlTOPp->Core__DOT__immsel))
                                   ? ((1U & (IData)(vlTOPp->Core__DOT__immsel))
                                       ? ((0xfff00000U 
                                           & (VL_NEGATE_I((IData)(
                                                                  (1U 
                                                                   & (vlTOPp->Core__DOT__instruction_pipe_id 
                                                                      >> 0x1fU)))) 
                                              << 0x14U)) 
                                          | ((0x80000U 
                                              & (vlTOPp->Core__DOT__instruction_pipe_id 
                                                 >> 0xcU)) 
                                             | ((0x7f800U 
                                                 & (vlTOPp->Core__DOT__instruction_pipe_id 
                                                    >> 1U)) 
                                                | ((0x400U 
                                                    & (vlTOPp->Core__DOT__instruction_pipe_id 
                                                       >> 0xaU)) 
                                                   | (0x3ffU 
                                                      & (vlTOPp->Core__DOT__instruction_pipe_id 
                                                         >> 0x15U))))))
                                       : ((0xfffff000U 
                                           & (VL_NEGATE_I((IData)(
                                                                  (1U 
                                                                   & (vlTOPp->Core__DOT__instruction_pipe_id 
                                                                      >> 0x1fU)))) 
                                              << 0xcU)) 
                                          | ((0x800U 
                                              & (vlTOPp->Core__DOT__instruction_pipe_id 
                                                 >> 0x14U)) 
                                             | ((0x400U 
                                                 & (vlTOPp->Core__DOT__instruction_pipe_id 
                                                    << 3U)) 
                                                | ((0x3f0U 
                                                    & (vlTOPp->Core__DOT__instruction_pipe_id 
                                                       >> 0x15U)) 
                                                   | (0xfU 
                                                      & (vlTOPp->Core__DOT__instruction_pipe_id 
                                                         >> 8U)))))))
                                   : ((1U & (IData)(vlTOPp->Core__DOT__immsel))
                                       ? ((0xfffff000U 
                                           & (VL_NEGATE_I((IData)(
                                                                  (1U 
                                                                   & (vlTOPp->Core__DOT__instruction_pipe_id 
                                                                      >> 0x1fU)))) 
                                              << 0xcU)) 
                                          | ((0xfe0U 
                                              & (vlTOPp->Core__DOT__instruction_pipe_id 
                                                 >> 0x14U)) 
                                             | (0x1fU 
                                                & (vlTOPp->Core__DOT__instruction_pipe_id 
                                                   >> 7U))))
                                       : ((0xfffff000U 
                                           & (VL_NEGATE_I((IData)(
                                                                  (1U 
                                                                   & (vlTOPp->Core__DOT__instruction_pipe_id 
                                                                      >> 0x1fU)))) 
                                              << 0xcU)) 
                                          | (0xfffU 
                                             & (vlTOPp->Core__DOT__instruction_pipe_id 
                                                >> 0x14U))))));
    vlTOPp->Core__DOT__br_stall = (((((vlTOPp->Core__DOT__instruction_pipe_id 
                                       >> 6U) & ((vlTOPp->Core__DOT__instruction_pipe_id 
                                                  >> 5U) 
                                                 & ((~ 
                                                     (vlTOPp->Core__DOT__instruction_pipe_id 
                                                      >> 4U)) 
                                                    & ((~ 
                                                        (vlTOPp->Core__DOT__instruction_pipe_id 
                                                         >> 3U)) 
                                                       & ((4U 
                                                           & vlTOPp->Core__DOT__instruction_pipe_id)
                                                           ? 
                                                          ((vlTOPp->Core__DOT__instruction_pipe_id 
                                                            >> 1U) 
                                                           & vlTOPp->Core__DOT__instruction_pipe_id)
                                                           : 
                                                          ((vlTOPp->Core__DOT__instruction_pipe_id 
                                                            >> 1U) 
                                                           & vlTOPp->Core__DOT__instruction_pipe_id)))))) 
                                     & (IData)(vlTOPp->Core__DOT__wbsel_pipe_ie)) 
                                    & (0U != (IData)(vlTOPp->Core__DOT__rdadd_pipe_ie))) 
                                   & ((((IData)(vlTOPp->Core__DOT__rdadd_pipe_ie) 
                                        == (0x1fU & 
                                            (vlTOPp->Core__DOT__instruction_pipe_id 
                                             >> 0xfU))) 
                                       & ((1U & ((IData)(vlTOPp->Core__DOT__float_read) 
                                                 >> 1U)) 
                                          == (1U & 
                                              ((IData)(vlTOPp->Core__DOT__fpu_ie) 
                                               >> 2U)))) 
                                      | (((IData)(vlTOPp->Core__DOT__rdadd_pipe_ie) 
                                          == (0x1fU 
                                              & (vlTOPp->Core__DOT__instruction_pipe_id 
                                                 >> 0x14U))) 
                                         & ((1U & (IData)(vlTOPp->Core__DOT__float_read)) 
                                            == (1U 
                                                & ((IData)(vlTOPp->Core__DOT__fpu_ie) 
                                                   >> 2U))))));
    vlTOPp->avl_byteenable = vlTOPp->Core__DOT__core2avl_inst__DOT__be;
    vlTOPp->Core__DOT__core2avl_inst__DOT__q1 = ((8U 
                                                  & (IData)(vlTOPp->Core__DOT__core2avl_inst__DOT__be))
                                                  ? 
                                                 ((4U 
                                                   & (IData)(vlTOPp->Core__DOT__core2avl_inst__DOT__be))
                                                   ? 
                                                  ((2U 
                                                    & (IData)(vlTOPp->Core__DOT__core2avl_inst__DOT__be))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(vlTOPp->Core__DOT__core2avl_inst__DOT__be))
                                                     ? vlTOPp->avl_readdata
                                                     : 0U)
                                                    : 
                                                   ((1U 
                                                     & (IData)(vlTOPp->Core__DOT__core2avl_inst__DOT__be))
                                                     ? 0U
                                                     : 
                                                    (0xffffU 
                                                     & (vlTOPp->avl_readdata 
                                                        >> 0x10U))))
                                                   : 
                                                  ((2U 
                                                    & (IData)(vlTOPp->Core__DOT__core2avl_inst__DOT__be))
                                                    ? 0U
                                                    : 
                                                   ((1U 
                                                     & (IData)(vlTOPp->Core__DOT__core2avl_inst__DOT__be))
                                                     ? 0U
                                                     : 
                                                    (0xffU 
                                                     & (vlTOPp->avl_readdata 
                                                        >> 0x18U)))))
                                                  : 
                                                 ((4U 
                                                   & (IData)(vlTOPp->Core__DOT__core2avl_inst__DOT__be))
                                                   ? 
                                                  ((2U 
                                                    & (IData)(vlTOPp->Core__DOT__core2avl_inst__DOT__be))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(vlTOPp->Core__DOT__core2avl_inst__DOT__be))
                                                     ? 0U
                                                     : 
                                                    (0xffffU 
                                                     & (vlTOPp->avl_readdata 
                                                        >> 8U)))
                                                    : 
                                                   ((1U 
                                                     & (IData)(vlTOPp->Core__DOT__core2avl_inst__DOT__be))
                                                     ? 0U
                                                     : 
                                                    (0xffU 
                                                     & (vlTOPp->avl_readdata 
                                                        >> 0x10U))))
                                                   : 
                                                  ((2U 
                                                    & (IData)(vlTOPp->Core__DOT__core2avl_inst__DOT__be))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(vlTOPp->Core__DOT__core2avl_inst__DOT__be))
                                                     ? 
                                                    (0xffffU 
                                                     & vlTOPp->avl_readdata)
                                                     : 
                                                    (0xffU 
                                                     & (vlTOPp->avl_readdata 
                                                        >> 8U)))
                                                    : 
                                                   ((1U 
                                                     & (IData)(vlTOPp->Core__DOT__core2avl_inst__DOT__be))
                                                     ? 
                                                    (0xffU 
                                                     & vlTOPp->avl_readdata)
                                                     : 0U))));
    vlTOPp->inst_stall = ((IData)(vlTOPp->Core__DOT__br_stall) 
                          | (IData)(vlTOPp->Core__DOT__stall_core));
    vlTOPp->Core__DOT__reset_ie = ((IData)(vlTOPp->Core__DOT__br_stall) 
                                   | (IData)(vlTOPp->reset));
    vlTOPp->Core__DOT__rd = ((2U & (IData)(vlTOPp->Core__DOT__wbsel_pipe_imem))
                              ? vlTOPp->Core__DOT__pc_out_pipe_imem
                              : ((4U & (IData)(vlTOPp->Core__DOT__wbsel_pipe_imem))
                                  ? ((4U & (IData)(vlTOPp->Core__DOT__mode_imem))
                                      ? ((2U & (IData)(vlTOPp->Core__DOT__mode_imem))
                                          ? 0U : ((1U 
                                                   & (IData)(vlTOPp->Core__DOT__mode_imem))
                                                   ? 
                                                  (0xffffU 
                                                   & vlTOPp->Core__DOT__core2avl_inst__DOT__q1)
                                                   : 
                                                  (0xffU 
                                                   & vlTOPp->Core__DOT__core2avl_inst__DOT__q1)))
                                      : ((2U & (IData)(vlTOPp->Core__DOT__mode_imem))
                                          ? ((1U & (IData)(vlTOPp->Core__DOT__mode_imem))
                                              ? 0U : vlTOPp->Core__DOT__core2avl_inst__DOT__q1)
                                          : ((1U & (IData)(vlTOPp->Core__DOT__mode_imem))
                                              ? ((0xffff0000U 
                                                  & (VL_NEGATE_I((IData)(
                                                                         (1U 
                                                                          & (vlTOPp->Core__DOT__core2avl_inst__DOT__q1 
                                                                             >> 0xfU)))) 
                                                     << 0x10U)) 
                                                 | (0xffffU 
                                                    & vlTOPp->Core__DOT__core2avl_inst__DOT__q1))
                                              : ((0xffffff00U 
                                                  & (VL_NEGATE_I((IData)(
                                                                         (1U 
                                                                          & (vlTOPp->Core__DOT__core2avl_inst__DOT__q1 
                                                                             >> 7U)))) 
                                                     << 8U)) 
                                                 | (0xffU 
                                                    & vlTOPp->Core__DOT__core2avl_inst__DOT__q1)))))
                                  : vlTOPp->Core__DOT__aluout_pipe_imem));
    vlTOPp->Core__DOT__A = ((0x40U & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie))
                             ? vlTOPp->Core__DOT__pc_out_pipe_ie
                             : (((((IData)(vlTOPp->Core__DOT__wbsel_pipe_imem) 
                                   & (0U != (IData)(vlTOPp->Core__DOT__rdadd_pipe_imem))) 
                                  & ((IData)(vlTOPp->Core__DOT__rdadd_pipe_imem) 
                                     == (IData)(vlTOPp->Core__DOT__rs1add_pipe_ie))) 
                                 & ((1U & ((IData)(vlTOPp->Core__DOT__fpu_ie) 
                                           >> 1U)) 
                                    == (IData)(vlTOPp->Core__DOT__fpu_imem)))
                                 ? vlTOPp->Core__DOT__rd
                                 : vlTOPp->Core__DOT__rs1_pipe_ie));
    vlTOPp->Core__DOT__fb_out = (((((IData)(vlTOPp->Core__DOT__wbsel_pipe_imem) 
                                    & (0U != (IData)(vlTOPp->Core__DOT__rdadd_pipe_imem))) 
                                   & ((IData)(vlTOPp->Core__DOT__rdadd_pipe_imem) 
                                      == (IData)(vlTOPp->Core__DOT__rs2add_pipe_ie))) 
                                  & ((1U & (IData)(vlTOPp->Core__DOT__fpu_ie)) 
                                     == (IData)(vlTOPp->Core__DOT__fpu_imem)))
                                  ? vlTOPp->Core__DOT__rd
                                  : vlTOPp->Core__DOT__rs2_pipe_ie);
    vlTOPp->Core__DOT__rs2_br = (((((IData)(vlTOPp->Core__DOT__wbsel_pipe_imem) 
                                    & (0U != (IData)(vlTOPp->Core__DOT__rdadd_pipe_imem))) 
                                   & ((IData)(vlTOPp->Core__DOT__rdadd_pipe_imem) 
                                      == (0x1fU & (vlTOPp->Core__DOT__instruction_pipe_id 
                                                   >> 0x14U)))) 
                                  & ((1U & (IData)(vlTOPp->Core__DOT__float_read)) 
                                     == (IData)(vlTOPp->Core__DOT__fpu_imem)))
                                  ? vlTOPp->Core__DOT__rd
                                  : ((1U & (IData)(vlTOPp->Core__DOT__float_read))
                                      ? vlTOPp->Core__DOT__genblk1__DOT__regfile_float__DOT__regfile
                                     [(0x1fU & (vlTOPp->Core__DOT__instruction_pipe_id 
                                                >> 0x14U))]
                                      : vlTOPp->Core__DOT__regfile__DOT__regfile
                                     [(0x1fU & (vlTOPp->Core__DOT__instruction_pipe_id 
                                                >> 0x14U))]));
    vlTOPp->Core__DOT__rs1_br = (((((IData)(vlTOPp->Core__DOT__wbsel_pipe_imem) 
                                    & (0U != (IData)(vlTOPp->Core__DOT__rdadd_pipe_imem))) 
                                   & ((IData)(vlTOPp->Core__DOT__rdadd_pipe_imem) 
                                      == (0x1fU & (vlTOPp->Core__DOT__instruction_pipe_id 
                                                   >> 0xfU)))) 
                                  & ((1U & ((IData)(vlTOPp->Core__DOT__float_read) 
                                            >> 1U)) 
                                     == (IData)(vlTOPp->Core__DOT__fpu_imem)))
                                  ? vlTOPp->Core__DOT__rd
                                  : ((2U & (IData)(vlTOPp->Core__DOT__float_read))
                                      ? vlTOPp->Core__DOT__genblk1__DOT__regfile_float__DOT__regfile
                                     [(0x1fU & (vlTOPp->Core__DOT__instruction_pipe_id 
                                                >> 0xfU))]
                                      : vlTOPp->Core__DOT__regfile__DOT__regfile
                                     [(0x1fU & (vlTOPp->Core__DOT__instruction_pipe_id 
                                                >> 0xfU))]));
    vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__fp2int_inst__DOT__abs_int 
        = ((0x7fU <= (0xffU & (vlTOPp->Core__DOT__A 
                               >> 0x17U))) ? ((0x1fU 
                                               >= ((IData)(0x9dU) 
                                                   - 
                                                   (0xffU 
                                                    & (vlTOPp->Core__DOT__A 
                                                       >> 0x17U))))
                                               ? ((0x40000000U 
                                                   | (0x3fffff80U 
                                                      & (vlTOPp->Core__DOT__A 
                                                         << 7U))) 
                                                  >> 
                                                  ((IData)(0x9dU) 
                                                   - 
                                                   (0xffU 
                                                    & (vlTOPp->Core__DOT__A 
                                                       >> 0x17U))))
                                               : 0U)
            : 0U);
    vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__int2fp_inst__DOT__abs 
        = ((0x80000000U & vlTOPp->Core__DOT__A) ? ((IData)(1U) 
                                                   + 
                                                   (~ vlTOPp->Core__DOT__A))
            : vlTOPp->Core__DOT__A);
    if ((0U == (0x7fffffffU & vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__int2fp_inst__DOT__abs))) {
        vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__int2fp_inst__DOT__eout = 0U;
        vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__int2fp_inst__DOT__mout = 0U;
        vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__int2fp_inst__DOT__sign = 0U;
        vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__int2fp_inst__DOT__num_zeros = 0U;
    } else {
        vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__int2fp_inst__DOT__num_zeros 
            = (((((((((0x40000000U == (0x40000000U 
                                       & vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__int2fp_inst__DOT__abs)) 
                      | (0x20000000U == (0x60000000U 
                                         & vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__int2fp_inst__DOT__abs))) 
                     | (0x10000000U == (0x70000000U 
                                        & vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__int2fp_inst__DOT__abs))) 
                    | (0x8000000U == (0x78000000U & vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__int2fp_inst__DOT__abs))) 
                   | (0x4000000U == (0x7c000000U & vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__int2fp_inst__DOT__abs))) 
                  | (0x2000000U == (0x7e000000U & vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__int2fp_inst__DOT__abs))) 
                 | (0x1000000U == (0x7f000000U & vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__int2fp_inst__DOT__abs))) 
                | (0x800000U == (0x7f800000U & vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__int2fp_inst__DOT__abs)))
                ? ((0x40000000U == (0x40000000U & vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__int2fp_inst__DOT__abs))
                    ? 0U : ((0x20000000U == (0x60000000U 
                                             & vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__int2fp_inst__DOT__abs))
                             ? 1U : ((0x10000000U == 
                                      (0x70000000U 
                                       & vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__int2fp_inst__DOT__abs))
                                      ? 2U : ((0x8000000U 
                                               == (0x78000000U 
                                                   & vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__int2fp_inst__DOT__abs))
                                               ? 3U
                                               : ((0x4000000U 
                                                   == 
                                                   (0x7c000000U 
                                                    & vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__int2fp_inst__DOT__abs))
                                                   ? 4U
                                                   : 
                                                  ((0x2000000U 
                                                    == 
                                                    (0x7e000000U 
                                                     & vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__int2fp_inst__DOT__abs))
                                                    ? 5U
                                                    : 
                                                   ((0x1000000U 
                                                     == 
                                                     (0x7f000000U 
                                                      & vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__int2fp_inst__DOT__abs))
                                                     ? 6U
                                                     : 7U)))))))
                : (((((((((0x400000U == (0x7fc00000U 
                                         & vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__int2fp_inst__DOT__abs)) 
                          | (0x200000U == (0x7fe00000U 
                                           & vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__int2fp_inst__DOT__abs))) 
                         | (0x100000U == (0x7ff00000U 
                                          & vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__int2fp_inst__DOT__abs))) 
                        | (0x80000U == (0x7ff80000U 
                                        & vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__int2fp_inst__DOT__abs))) 
                       | (0x40000U == (0x7ffc0000U 
                                       & vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__int2fp_inst__DOT__abs))) 
                      | (0x20000U == (0x7ffe0000U & vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__int2fp_inst__DOT__abs))) 
                     | (0x10000U == (0x7fff0000U & vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__int2fp_inst__DOT__abs))) 
                    | (0x8000U == (0x7fff8000U & vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__int2fp_inst__DOT__abs)))
                    ? ((0x400000U == (0x7fc00000U & vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__int2fp_inst__DOT__abs))
                        ? 8U : ((0x200000U == (0x7fe00000U 
                                               & vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__int2fp_inst__DOT__abs))
                                 ? 9U : ((0x100000U 
                                          == (0x7ff00000U 
                                              & vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__int2fp_inst__DOT__abs))
                                          ? 0xaU : 
                                         ((0x80000U 
                                           == (0x7ff80000U 
                                               & vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__int2fp_inst__DOT__abs))
                                           ? 0xbU : 
                                          ((0x40000U 
                                            == (0x7ffc0000U 
                                                & vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__int2fp_inst__DOT__abs))
                                            ? 0xcU : 
                                           ((0x20000U 
                                             == (0x7ffe0000U 
                                                 & vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__int2fp_inst__DOT__abs))
                                             ? 0xdU
                                             : ((0x10000U 
                                                 == 
                                                 (0x7fff0000U 
                                                  & vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__int2fp_inst__DOT__abs))
                                                 ? 0xeU
                                                 : 0xfU)))))))
                    : (((((((((0x4000U == (0x7fffc000U 
                                           & vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__int2fp_inst__DOT__abs)) 
                              | (0x2000U == (0x7fffe000U 
                                             & vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__int2fp_inst__DOT__abs))) 
                             | (0x1000U == (0x7ffff000U 
                                            & vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__int2fp_inst__DOT__abs))) 
                            | (0x800U == (0x7ffff800U 
                                          & vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__int2fp_inst__DOT__abs))) 
                           | (0x400U == (0x7ffffc00U 
                                         & vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__int2fp_inst__DOT__abs))) 
                          | (0x200U == (0x7ffffe00U 
                                        & vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__int2fp_inst__DOT__abs))) 
                         | (0x100U == (0x7fffff00U 
                                       & vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__int2fp_inst__DOT__abs))) 
                        | (0x80U == (0x7fffff80U & vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__int2fp_inst__DOT__abs)))
                        ? ((0x4000U == (0x7fffc000U 
                                        & vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__int2fp_inst__DOT__abs))
                            ? 0x10U : ((0x2000U == 
                                        (0x7fffe000U 
                                         & vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__int2fp_inst__DOT__abs))
                                        ? 0x11U : (
                                                   (0x1000U 
                                                    == 
                                                    (0x7ffff000U 
                                                     & vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__int2fp_inst__DOT__abs))
                                                    ? 0x12U
                                                    : 
                                                   ((0x800U 
                                                     == 
                                                     (0x7ffff800U 
                                                      & vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__int2fp_inst__DOT__abs))
                                                     ? 0x13U
                                                     : 
                                                    ((0x400U 
                                                      == 
                                                      (0x7ffffc00U 
                                                       & vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__int2fp_inst__DOT__abs))
                                                      ? 0x14U
                                                      : 
                                                     ((0x200U 
                                                       == 
                                                       (0x7ffffe00U 
                                                        & vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__int2fp_inst__DOT__abs))
                                                       ? 0x15U
                                                       : 
                                                      ((0x100U 
                                                        == 
                                                        (0x7fffff00U 
                                                         & vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__int2fp_inst__DOT__abs))
                                                        ? 0x16U
                                                        : 0x17U)))))))
                        : ((0x40U == (0x7fffffc0U & vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__int2fp_inst__DOT__abs))
                            ? 0x18U : ((0x20U == (0x7fffffe0U 
                                                  & vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__int2fp_inst__DOT__abs))
                                        ? 0x19U : (
                                                   (0x10U 
                                                    == 
                                                    (0x7ffffff0U 
                                                     & vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__int2fp_inst__DOT__abs))
                                                    ? 0x1aU
                                                    : 
                                                   ((8U 
                                                     == 
                                                     (0x7ffffff8U 
                                                      & vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__int2fp_inst__DOT__abs))
                                                     ? 0x1bU
                                                     : 
                                                    ((4U 
                                                      == 
                                                      (0x7ffffffcU 
                                                       & vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__int2fp_inst__DOT__abs))
                                                      ? 0x1cU
                                                      : 
                                                     ((2U 
                                                       == 
                                                       (0x7ffffffeU 
                                                        & vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__int2fp_inst__DOT__abs))
                                                       ? 0x1dU
                                                       : 
                                                      ((1U 
                                                        == 
                                                        (0x7fffffffU 
                                                         & vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__int2fp_inst__DOT__abs))
                                                        ? 0x1eU
                                                        : 0x1fU))))))))));
        vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__int2fp_inst__DOT__mout 
            = (0x7fffffU & (((0x1eU >= (IData)(vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__int2fp_inst__DOT__num_zeros))
                              ? (0x7fffffffU & (vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__int2fp_inst__DOT__abs 
                                                << (IData)(vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__int2fp_inst__DOT__num_zeros)))
                              : 0U) >> 7U));
        vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__int2fp_inst__DOT__sign 
            = (1U & (vlTOPp->Core__DOT__A >> 0x1fU));
        vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__int2fp_inst__DOT__eout 
            = (0xffU & ((IData)(0x9dU) - (IData)(vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__int2fp_inst__DOT__num_zeros)));
    }
    vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__res4 
        = (((IData)(vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__int2fp_inst__DOT__sign) 
            << 0x1fU) | (((IData)(vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__int2fp_inst__DOT__eout) 
                          << 0x17U) | vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__int2fp_inst__DOT__mout));
    vlTOPp->Core__DOT__B = ((0x20U & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie))
                             ? vlTOPp->Core__DOT__imm_pipe_ie
                             : vlTOPp->Core__DOT__fb_out);
    vlTOPp->Core__DOT__A_out = ((1U & ((vlTOPp->Core__DOT__instruction_pipe_id 
                                        >> 6U) & ((vlTOPp->Core__DOT__instruction_pipe_id 
                                                   >> 5U) 
                                                  & ((~ 
                                                      (vlTOPp->Core__DOT__instruction_pipe_id 
                                                       >> 4U)) 
                                                     & ((~ 
                                                         (vlTOPp->Core__DOT__instruction_pipe_id 
                                                          >> 3U)) 
                                                        & ((vlTOPp->Core__DOT__instruction_pipe_id 
                                                            >> 2U) 
                                                           & ((vlTOPp->Core__DOT__instruction_pipe_id 
                                                               >> 1U) 
                                                              & vlTOPp->Core__DOT__instruction_pipe_id)))))))
                                 ? vlTOPp->Core__DOT__rs1_br
                                 : vlTOPp->Core__DOT__pc_out_pipe_id);
    vlTOPp->Core__DOT__BrLT = ((IData)(vlTOPp->Core__DOT__BrUn)
                                ? (vlTOPp->Core__DOT__rs1_br 
                                   < vlTOPp->Core__DOT__rs2_br)
                                : VL_LTS_III(1,32,32, vlTOPp->Core__DOT__rs1_br, vlTOPp->Core__DOT__rs2_br));
    vlTOPp->Core__DOT__BrEq = ((IData)(vlTOPp->Core__DOT__BrUn)
                                ? (vlTOPp->Core__DOT__rs1_br 
                                   == vlTOPp->Core__DOT__rs2_br)
                                : (vlTOPp->Core__DOT__rs1_br 
                                   == vlTOPp->Core__DOT__rs2_br));
    vlTOPp->Core__DOT__alu__DOT__ALUout = (((((((((0U 
                                                   == 
                                                   (0x1fU 
                                                    & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie))) 
                                                  | (1U 
                                                     == 
                                                     (0x1fU 
                                                      & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie)))) 
                                                 | (2U 
                                                    == 
                                                    (0x1fU 
                                                     & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie)))) 
                                                | (3U 
                                                   == 
                                                   (0x1fU 
                                                    & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie)))) 
                                               | (4U 
                                                  == 
                                                  (0x1fU 
                                                   & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie)))) 
                                              | (5U 
                                                 == 
                                                 (0x1fU 
                                                  & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie)))) 
                                             | (6U 
                                                == 
                                                (0x1fU 
                                                 & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie)))) 
                                            | (7U == 
                                               (0x1fU 
                                                & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie))))
                                            ? ((0U 
                                                == 
                                                (0x1fU 
                                                 & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie)))
                                                ? vlTOPp->Core__DOT__A
                                                : (
                                                   (1U 
                                                    == 
                                                    (0x1fU 
                                                     & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie)))
                                                    ? vlTOPp->Core__DOT__B
                                                    : 
                                                   ((2U 
                                                     == 
                                                     (0x1fU 
                                                      & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie)))
                                                     ? 
                                                    (vlTOPp->Core__DOT__A 
                                                     + vlTOPp->Core__DOT__B)
                                                     : 
                                                    ((3U 
                                                      == 
                                                      (0x1fU 
                                                       & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie)))
                                                      ? 
                                                     (vlTOPp->Core__DOT__A 
                                                      - vlTOPp->Core__DOT__B)
                                                      : 
                                                     ((4U 
                                                       == 
                                                       (0x1fU 
                                                        & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie)))
                                                       ? 
                                                      (~ vlTOPp->Core__DOT__A)
                                                       : 
                                                      ((5U 
                                                        == 
                                                        (0x1fU 
                                                         & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie)))
                                                        ? 
                                                       (~ vlTOPp->Core__DOT__B)
                                                        : 
                                                       ((6U 
                                                         == 
                                                         (0x1fU 
                                                          & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie)))
                                                         ? 
                                                        (vlTOPp->Core__DOT__A 
                                                         << 
                                                         (0x1fU 
                                                          & vlTOPp->Core__DOT__B))
                                                         : 
                                                        (vlTOPp->Core__DOT__A 
                                                         >> 
                                                         (0x1fU 
                                                          & vlTOPp->Core__DOT__B)))))))))
                                            : (((((
                                                   ((((8U 
                                                       == 
                                                       (0x1fU 
                                                        & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie))) 
                                                      | (9U 
                                                         == 
                                                         (0x1fU 
                                                          & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie)))) 
                                                     | (0xaU 
                                                        == 
                                                        (0x1fU 
                                                         & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie)))) 
                                                    | (0xbU 
                                                       == 
                                                       (0x1fU 
                                                        & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie)))) 
                                                   | (0xcU 
                                                      == 
                                                      (0x1fU 
                                                       & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie)))) 
                                                  | (0xdU 
                                                     == 
                                                     (0x1fU 
                                                      & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie)))) 
                                                 | (0xeU 
                                                    == 
                                                    (0x1fU 
                                                     & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie)))) 
                                                | (0xfU 
                                                   == 
                                                   (0x1fU 
                                                    & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie))))
                                                ? (
                                                   (8U 
                                                    == 
                                                    (0x1fU 
                                                     & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie)))
                                                    ? 
                                                   (vlTOPp->Core__DOT__A 
                                                    * vlTOPp->Core__DOT__B)
                                                    : 
                                                   ((9U 
                                                     == 
                                                     (0x1fU 
                                                      & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie)))
                                                     ? 
                                                    VL_SHIFTRS_III(32,32,5, vlTOPp->Core__DOT__A, 
                                                                   (0x1fU 
                                                                    & vlTOPp->Core__DOT__B))
                                                     : 
                                                    ((0xaU 
                                                      == 
                                                      (0x1fU 
                                                       & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie)))
                                                      ? 
                                                     (vlTOPp->Core__DOT__A 
                                                      & vlTOPp->Core__DOT__B)
                                                      : 
                                                     ((0xbU 
                                                       == 
                                                       (0x1fU 
                                                        & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie)))
                                                       ? 
                                                      (vlTOPp->Core__DOT__A 
                                                       | vlTOPp->Core__DOT__B)
                                                       : 
                                                      ((0xcU 
                                                        == 
                                                        (0x1fU 
                                                         & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie)))
                                                        ? 
                                                       (vlTOPp->Core__DOT__A 
                                                        ^ vlTOPp->Core__DOT__B)
                                                        : 
                                                       ((0xdU 
                                                         == 
                                                         (0x1fU 
                                                          & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie)))
                                                         ? 
                                                        ((vlTOPp->Core__DOT__A 
                                                          < vlTOPp->Core__DOT__B)
                                                          ? 1U
                                                          : 0U)
                                                         : 
                                                        ((0xeU 
                                                          == 
                                                          (0x1fU 
                                                           & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie)))
                                                          ? 
                                                         (VL_LTS_III(1,32,32, vlTOPp->Core__DOT__A, vlTOPp->Core__DOT__B)
                                                           ? 1U
                                                           : 0U)
                                                          : (IData)(
                                                                    (((((QData)((IData)(
                                                                                VL_NEGATE_I((IData)(
                                                                                (1U 
                                                                                & (vlTOPp->Core__DOT__A 
                                                                                >> 0x1fU)))))) 
                                                                        << 0x20U) 
                                                                       | (QData)((IData)(vlTOPp->Core__DOT__A))) 
                                                                      * 
                                                                      (((QData)((IData)(
                                                                                VL_NEGATE_I((IData)(
                                                                                (1U 
                                                                                & (vlTOPp->Core__DOT__B 
                                                                                >> 0x1fU)))))) 
                                                                        << 0x20U) 
                                                                       | (QData)((IData)(vlTOPp->Core__DOT__B)))) 
                                                                     >> 0x20U)))))))))
                                                : (
                                                   (0x10U 
                                                    == 
                                                    (0x1fU 
                                                     & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie)))
                                                    ? (IData)(
                                                              (((QData)((IData)(vlTOPp->Core__DOT__A)) 
                                                                * (QData)((IData)(vlTOPp->Core__DOT__B))) 
                                                               >> 0x20U))
                                                    : 
                                                   ((0x11U 
                                                     == 
                                                     (0x1fU 
                                                      & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie)))
                                                     ? 
                                                    VL_DIVS_III(32, vlTOPp->Core__DOT__A, vlTOPp->Core__DOT__B)
                                                     : 
                                                    ((0x12U 
                                                      == 
                                                      (0x1fU 
                                                       & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie)))
                                                      ? 
                                                     VL_DIV_III(32, vlTOPp->Core__DOT__A, vlTOPp->Core__DOT__B)
                                                      : 
                                                     ((0x13U 
                                                       == 
                                                       (0x1fU 
                                                        & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie)))
                                                       ? 
                                                      VL_MODDIVS_III(32, vlTOPp->Core__DOT__A, vlTOPp->Core__DOT__B)
                                                       : 
                                                      ((0x14U 
                                                        == 
                                                        (0x1fU 
                                                         & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie)))
                                                        ? 
                                                       VL_MODDIV_III(32, vlTOPp->Core__DOT__A, vlTOPp->Core__DOT__B)
                                                        : 0U)))))));
    vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__multiply_inst__DOT__pre_prod_frac 
        = (VL_ULL(0x3fffffffffff) & ((QData)((IData)(
                                                     (0x400000U 
                                                      | (0x3fffffU 
                                                         & (vlTOPp->Core__DOT__A 
                                                            >> 1U))))) 
                                     * (QData)((IData)(
                                                       (0x400000U 
                                                        | (0x3fffffU 
                                                           & (vlTOPp->Core__DOT__B 
                                                              >> 1U)))))));
    vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__multiply_inst__DOT__pre_prod_exp 
        = (0x1ffU & ((0xffU & (vlTOPp->Core__DOT__A 
                               >> 0x17U)) + (0xffU 
                                             & (vlTOPp->Core__DOT__B 
                                                >> 0x17U))));
    vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__a_exp 
        = (0xffU & (vlTOPp->Core__DOT__A >> 0x17U));
    vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__a_m 
        = (0x800000U | (0x7fffffU & vlTOPp->Core__DOT__A));
    vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__b_exp 
        = (0xffU & (vlTOPp->Core__DOT__B >> 0x17U));
    vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__b_m 
        = (0x800000U | (0x7fffffU & vlTOPp->Core__DOT__B));
    if (((IData)(vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__a_exp) 
         > (IData)(vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__b_exp))) {
        vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__b_m 
            = ((0x1fU >= (0xffU & ((IData)(vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__a_exp) 
                                   - (IData)(vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__b_exp))))
                ? (vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__b_m 
                   >> (0xffU & ((IData)(vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__a_exp) 
                                - (IData)(vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__b_exp))))
                : 0U);
        vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__mag = 0U;
        vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__res3 = 0U;
        vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__b_exp 
            = (0xffU & ((IData)(vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__b_exp) 
                        + ((IData)(vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__a_exp) 
                           - (IData)(vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__b_exp))));
    } else {
        if (((IData)(vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__a_exp) 
             < (IData)(vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__b_exp))) {
            vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__a_m 
                = ((0x1fU >= (0xffU & ((IData)(vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__b_exp) 
                                       - (IData)(vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__a_exp))))
                    ? (vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__a_m 
                       >> (0xffU & ((IData)(vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__b_exp) 
                                    - (IData)(vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__a_exp))))
                    : 0U);
            vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__mag = 1U;
            vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__res3 = 1U;
            vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__a_exp 
                = (0xffU & ((IData)(vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__a_exp) 
                            + ((IData)(vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__b_exp) 
                               - (IData)(vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__a_exp))));
        } else {
            vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__mag = 2U;
            vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__res3 
                = ((vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__a_m 
                    > vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__b_m)
                    ? 0U : ((vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__a_m 
                             < vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__b_m)
                             ? 1U : 2U));
        }
    }
    if (((((1U & (vlTOPp->Core__DOT__A >> 0x1fU)) == 
           (1U & (vlTOPp->Core__DOT__B >> 0x1fU))) 
          & (~ (IData)(vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__add_sub))) 
         | (((1U & (vlTOPp->Core__DOT__A >> 0x1fU)) 
             != (1U & (vlTOPp->Core__DOT__B >> 0x1fU))) 
            & (IData)(vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__add_sub)))) {
        vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__res1 
            = ((0x7fffffffU & vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__res1) 
               | (0x80000000U & vlTOPp->Core__DOT__A));
        vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__r_m 
            = (vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__a_m 
               + vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__b_m);
    } else {
        if (((((1U & (vlTOPp->Core__DOT__A >> 0x1fU)) 
               != (1U & (vlTOPp->Core__DOT__B >> 0x1fU))) 
              & (~ (IData)(vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__add_sub))) 
             | (((1U & (vlTOPp->Core__DOT__A >> 0x1fU)) 
                 == (1U & (vlTOPp->Core__DOT__B >> 0x1fU))) 
                & (IData)(vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__add_sub)))) {
            if ((0U == (IData)(vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__mag))) {
                vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__r_m 
                    = (vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__a_m 
                       - vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__b_m);
                vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__res1 
                    = ((0x7fffffffU & vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__res1) 
                       | (0x80000000U & (((~ (IData)(vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__add_sub)) 
                                          << 0x1fU) 
                                         & vlTOPp->Core__DOT__A)));
            } else {
                if ((1U == (IData)(vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__mag))) {
                    vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__r_m 
                        = (vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__b_m 
                           - vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__a_m);
                    vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__res1 
                        = ((0x7fffffffU & vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__res1) 
                           | (0x80000000U & (((IData)(vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__add_sub)
                                               ? (~ 
                                                  (vlTOPp->Core__DOT__B 
                                                   >> 0x1fU))
                                               : (vlTOPp->Core__DOT__B 
                                                  >> 0x1fU)) 
                                             << 0x1fU)));
                } else {
                    if ((2U == (IData)(vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__mag))) {
                        if ((vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__a_m 
                             >= vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__b_m)) {
                            vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__r_m 
                                = (vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__a_m 
                                   - vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__b_m);
                            vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__res1 
                                = ((0x7fffffffU & vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__res1) 
                                   | (0x80000000U & 
                                      (((~ (IData)(vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__add_sub)) 
                                        << 0x1fU) & vlTOPp->Core__DOT__A)));
                        } else {
                            if ((vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__a_m 
                                 < vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__b_m)) {
                                vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__r_m 
                                    = (vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__b_m 
                                       - vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__a_m);
                                vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__res1 
                                    = ((0x7fffffffU 
                                        & vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__res1) 
                                       | (0x80000000U 
                                          & (((IData)(vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__add_sub)
                                               ? (~ 
                                                  (vlTOPp->Core__DOT__B 
                                                   >> 0x1fU))
                                               : (vlTOPp->Core__DOT__B 
                                                  >> 0x1fU)) 
                                             << 0x1fU)));
                            } else {
                                vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__r_m 
                                    = (vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__b_m 
                                       - vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__a_m);
                                vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__res1 
                                    = (0x7fffffffU 
                                       & vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__res1);
                            }
                        }
                    } else {
                        vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__r_m 
                            = (vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__b_m 
                               - vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__a_m);
                        vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__res1 
                            = (0x7fffffffU & vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__res1);
                    }
                }
            }
        } else {
            vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__r_m 
                = (vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__b_m 
                   - vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__a_m);
            vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__res1 
                = (0x7fffffffU & vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__res1);
        }
    }
    vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__state = 1U;
    vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__i = 0x1fU;
    while (vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__state) {
        if ((1U & ((vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__r_m 
                    >> (0x1fU & vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__i)) 
                   | (0U == vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__i)))) {
            vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__state = 0U;
        }
        vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__i 
            = (vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__i 
               - (IData)(1U));
    }
    vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__r_exp 
        = (0xffU & (((IData)(vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__a_exp) 
                     + vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__i) 
                    - (IData)(0x16U)));
    vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__prm 
        = (VL_LTS_III(1,32,32, 0U, (vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__i 
                                    - (IData)(0x16U)))
            ? ((0x1fU >= (vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__i 
                          - (IData)(0x16U))) ? (vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__r_m 
                                                >> 
                                                (vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__i 
                                                 - (IData)(0x16U)))
                : 0U) : (VL_GTS_III(1,32,32, 0U, (vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__i 
                                                  - (IData)(0x16U)))
                          ? ((0x1fU >= ((IData)(0x16U) 
                                        - vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__i))
                              ? (vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__r_m 
                                 << ((IData)(0x16U) 
                                     - vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__i))
                              : 0U) : vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__r_m));
    vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__res1 
        = ((0x807fffffU & vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__res1) 
           | ((IData)(vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__r_exp) 
              << 0x17U));
    vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__res1 
        = ((0xff800000U & vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__res1) 
           | (0x7fffffU & vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__prm));
    vlTOPp->Core__DOT__pcALU_inst__DOT__alu = ((1U 
                                                & ((vlTOPp->Core__DOT__instruction_pipe_id 
                                                    >> 6U) 
                                                   & ((vlTOPp->Core__DOT__instruction_pipe_id 
                                                       >> 5U) 
                                                      & ((~ 
                                                          (vlTOPp->Core__DOT__instruction_pipe_id 
                                                           >> 4U)) 
                                                         & ((~ 
                                                             (vlTOPp->Core__DOT__instruction_pipe_id 
                                                              >> 3U)) 
                                                            & ((vlTOPp->Core__DOT__instruction_pipe_id 
                                                                >> 2U) 
                                                               & ((vlTOPp->Core__DOT__instruction_pipe_id 
                                                                   >> 1U) 
                                                                  & vlTOPp->Core__DOT__instruction_pipe_id)))))))
                                                ? (vlTOPp->Core__DOT__A_out 
                                                   + vlTOPp->Core__DOT__imm)
                                                : (vlTOPp->Core__DOT__A_out 
                                                   + 
                                                   (vlTOPp->Core__DOT__imm 
                                                    << 1U)));
    vlTOPp->Core__DOT__pc_sel = (1U & ((vlTOPp->Core__DOT__instruction_pipe_id 
                                        >> 6U) & ((vlTOPp->Core__DOT__instruction_pipe_id 
                                                   >> 5U) 
                                                  & ((~ 
                                                      (vlTOPp->Core__DOT__instruction_pipe_id 
                                                       >> 4U)) 
                                                     & ((8U 
                                                         & vlTOPp->Core__DOT__instruction_pipe_id)
                                                         ? 
                                                        ((vlTOPp->Core__DOT__instruction_pipe_id 
                                                          >> 2U) 
                                                         & ((vlTOPp->Core__DOT__instruction_pipe_id 
                                                             >> 1U) 
                                                            & vlTOPp->Core__DOT__instruction_pipe_id))
                                                         : 
                                                        ((4U 
                                                          & vlTOPp->Core__DOT__instruction_pipe_id)
                                                          ? 
                                                         ((vlTOPp->Core__DOT__instruction_pipe_id 
                                                           >> 1U) 
                                                          & vlTOPp->Core__DOT__instruction_pipe_id)
                                                          : 
                                                         ((vlTOPp->Core__DOT__instruction_pipe_id 
                                                           >> 1U) 
                                                          & (vlTOPp->Core__DOT__instruction_pipe_id 
                                                             & ((0x4000U 
                                                                 & vlTOPp->Core__DOT__instruction_pipe_id)
                                                                 ? 
                                                                ((0x2000U 
                                                                  & vlTOPp->Core__DOT__instruction_pipe_id)
                                                                  ? 
                                                                 ((0x1000U 
                                                                   & vlTOPp->Core__DOT__instruction_pipe_id)
                                                                   ? 
                                                                  (~ (IData)(vlTOPp->Core__DOT__BrLT))
                                                                   : (IData)(vlTOPp->Core__DOT__BrLT))
                                                                  : 
                                                                 ((0x1000U 
                                                                   & vlTOPp->Core__DOT__instruction_pipe_id)
                                                                   ? 
                                                                  (~ (IData)(vlTOPp->Core__DOT__BrLT))
                                                                   : (IData)(vlTOPp->Core__DOT__BrLT)))
                                                                 : 
                                                                ((0x2000U 
                                                                  & vlTOPp->Core__DOT__instruction_pipe_id)
                                                                  ? (IData)(vlTOPp->Core__DOT__BrEq)
                                                                  : 
                                                                 ((0x1000U 
                                                                   & vlTOPp->Core__DOT__instruction_pipe_id)
                                                                   ? 
                                                                  (~ (IData)(vlTOPp->Core__DOT__BrEq))
                                                                   : (IData)(vlTOPp->Core__DOT__BrEq))))))))))));
    vlTOPp->Core__DOT__alu__DOT__fpuout = (((((((((0U 
                                                   == 
                                                   (0x1fU 
                                                    & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie))) 
                                                  | (1U 
                                                     == 
                                                     (0x1fU 
                                                      & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie)))) 
                                                 | (2U 
                                                    == 
                                                    (0x1fU 
                                                     & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie)))) 
                                                | (3U 
                                                   == 
                                                   (0x1fU 
                                                    & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie)))) 
                                               | (4U 
                                                  == 
                                                  (0x1fU 
                                                   & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie)))) 
                                              | (5U 
                                                 == 
                                                 (0x1fU 
                                                  & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie)))) 
                                             | (6U 
                                                == 
                                                (0x1fU 
                                                 & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie)))) 
                                            | (7U == 
                                               (0x1fU 
                                                & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie))))
                                            ? ((0U 
                                                == 
                                                (0x1fU 
                                                 & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie)))
                                                ? vlTOPp->Core__DOT__A
                                                : (
                                                   (1U 
                                                    == 
                                                    (0x1fU 
                                                     & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie)))
                                                    ? vlTOPp->Core__DOT__B
                                                    : 
                                                   ((2U 
                                                     == 
                                                     (0x1fU 
                                                      & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie)))
                                                     ? 
                                                    ((0x80000000U 
                                                      & ((~ 
                                                          (vlTOPp->Core__DOT__A 
                                                           >> 0x1fU)) 
                                                         << 0x1fU)) 
                                                     | (0x7fffffffU 
                                                        & vlTOPp->Core__DOT__A))
                                                     : 
                                                    ((3U 
                                                      == 
                                                      (0x1fU 
                                                       & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie)))
                                                      ? 
                                                     ((0x80000000U 
                                                       & ((~ 
                                                           (vlTOPp->Core__DOT__B 
                                                            >> 0x1fU)) 
                                                          << 0x1fU)) 
                                                      | (0x7fffffffU 
                                                         & vlTOPp->Core__DOT__B))
                                                      : 
                                                     ((4U 
                                                       == 
                                                       (0x1fU 
                                                        & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie)))
                                                       ? vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__res1
                                                       : 
                                                      ((5U 
                                                        == 
                                                        (0x1fU 
                                                         & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie)))
                                                        ? vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__res1
                                                        : 
                                                       ((6U 
                                                         == 
                                                         (0x1fU 
                                                          & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie)))
                                                         ? 
                                                        ((0x80U 
                                                          > (IData)(vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__multiply_inst__DOT__pre_prod_exp))
                                                          ? 0U
                                                          : 
                                                         ((0U 
                                                           == 
                                                           (0xffU 
                                                            & (vlTOPp->Core__DOT__B 
                                                               >> 0x17U)))
                                                           ? 0U
                                                           : 
                                                          ((0U 
                                                            == 
                                                            (0xffU 
                                                             & (vlTOPp->Core__DOT__A 
                                                                >> 0x17U)))
                                                            ? 0U
                                                            : 
                                                           ((0x80000000U 
                                                             & (vlTOPp->Core__DOT__A 
                                                                ^ vlTOPp->Core__DOT__B)) 
                                                            | ((0x7f800000U 
                                                                & (((1U 
                                                                     & (IData)(
                                                                               (vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__multiply_inst__DOT__pre_prod_frac 
                                                                                >> 0x2dU)))
                                                                     ? 
                                                                    ((IData)(vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__multiply_inst__DOT__pre_prod_exp) 
                                                                     - (IData)(0x7eU))
                                                                     : 
                                                                    ((IData)(vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__multiply_inst__DOT__pre_prod_exp) 
                                                                     - (IData)(0x7fU))) 
                                                                   << 0x17U)) 
                                                               | (0x7fffffU 
                                                                  & ((1U 
                                                                      & (IData)(
                                                                                (vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__multiply_inst__DOT__pre_prod_frac 
                                                                                >> 0x2dU)))
                                                                      ? (IData)(
                                                                                (vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__multiply_inst__DOT__pre_prod_frac 
                                                                                >> 0x16U))
                                                                      : (IData)(
                                                                                (vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__multiply_inst__DOT__pre_prod_frac 
                                                                                >> 0x15U)))))))))
                                                         : 
                                                        ((1U 
                                                          == (IData)(vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__res3))
                                                          ? vlTOPp->Core__DOT__A
                                                          : vlTOPp->Core__DOT__B))))))))
                                            : (((((
                                                   ((((8U 
                                                       == 
                                                       (0x1fU 
                                                        & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie))) 
                                                      | (9U 
                                                         == 
                                                         (0x1fU 
                                                          & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie)))) 
                                                     | (0xaU 
                                                        == 
                                                        (0x1fU 
                                                         & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie)))) 
                                                    | (0xbU 
                                                       == 
                                                       (0x1fU 
                                                        & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie)))) 
                                                   | (0xcU 
                                                      == 
                                                      (0x1fU 
                                                       & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie)))) 
                                                  | (0xdU 
                                                     == 
                                                     (0x1fU 
                                                      & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie)))) 
                                                 | (0xeU 
                                                    == 
                                                    (0x1fU 
                                                     & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie)))) 
                                                | (0xfU 
                                                   == 
                                                   (0x1fU 
                                                    & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie))))
                                                ? (
                                                   (8U 
                                                    == 
                                                    (0x1fU 
                                                     & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie)))
                                                    ? 
                                                   ((0U 
                                                     == (IData)(vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__res3))
                                                     ? vlTOPp->Core__DOT__A
                                                     : vlTOPp->Core__DOT__B)
                                                    : 
                                                   ((9U 
                                                     == 
                                                     (0x1fU 
                                                      & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie)))
                                                     ? 
                                                    ((2U 
                                                      == (IData)(vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__res3))
                                                      ? 1U
                                                      : 0U)
                                                     : 
                                                    ((0xaU 
                                                      == 
                                                      (0x1fU 
                                                       & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie)))
                                                      ? 
                                                     ((1U 
                                                       == (IData)(vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__res3))
                                                       ? 1U
                                                       : 0U)
                                                      : 
                                                     ((0xbU 
                                                       == 
                                                       (0x1fU 
                                                        & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie)))
                                                       ? 
                                                      (((1U 
                                                         == (IData)(vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__res3)) 
                                                        | (2U 
                                                           == (IData)(vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__res3)))
                                                        ? 1U
                                                        : 0U)
                                                       : 
                                                      ((0xcU 
                                                        == 
                                                        (0x1fU 
                                                         & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie)))
                                                        ? vlTOPp->Core__DOT__A
                                                        : 
                                                       ((0xdU 
                                                         == 
                                                         (0x1fU 
                                                          & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie)))
                                                         ? vlTOPp->Core__DOT__A
                                                         : 
                                                        ((0xeU 
                                                          == 
                                                          (0x1fU 
                                                           & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie)))
                                                          ? vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__res4
                                                          : 
                                                         ((0x80000000U 
                                                           & vlTOPp->Core__DOT__A)
                                                           ? 
                                                          ((IData)(1U) 
                                                           + 
                                                           (~ vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__fp2int_inst__DOT__abs_int))
                                                           : vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__fp2int_inst__DOT__abs_int))))))))
                                                : 0U));
    vlTOPp->inst_addr = ((IData)(vlTOPp->Core__DOT__pc_sel)
                          ? vlTOPp->Core__DOT__pcALU_inst__DOT__alu
                          : vlTOPp->Core__DOT__pc_out);
    vlTOPp->Core__DOT__pc_in = ((IData)(vlTOPp->Core__DOT__pc_sel)
                                 ? ((IData)(4U) + vlTOPp->Core__DOT__pcALU_inst__DOT__alu)
                                 : ((IData)(4U) + vlTOPp->Core__DOT__pc_out));
}

VL_INLINE_OPT void VCore::_combo__TOP__4(VCore__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCore::_combo__TOP__4\n"); );
    VCore* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->Core__DOT__stall_core = ((IData)(vlTOPp->avl_waitrequest) 
                                     & (~ (IData)(vlTOPp->reset)));
    vlTOPp->Core__DOT__clk1 = ((IData)(vlTOPp->Core__DOT__enable) 
                               & (IData)(vlTOPp->clk));
}

VL_INLINE_OPT void VCore::_sequent__TOP__5(VCore__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCore::_sequent__TOP__5\n"); );
    VCore* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*4:0*/ __Vdlyvdim0__Core__DOT__regfile__DOT__regfile__v0;
    CData/*0:0*/ __Vdlyvset__Core__DOT__regfile__DOT__regfile__v0;
    CData/*4:0*/ __Vdlyvdim0__Core__DOT__genblk1__DOT__regfile_float__DOT__regfile__v0;
    CData/*0:0*/ __Vdlyvset__Core__DOT__genblk1__DOT__regfile_float__DOT__regfile__v0;
    IData/*31:0*/ __Vdlyvval__Core__DOT__regfile__DOT__regfile__v0;
    IData/*31:0*/ __Vdlyvval__Core__DOT__genblk1__DOT__regfile_float__DOT__regfile__v0;
    // Body
    __Vdlyvset__Core__DOT__genblk1__DOT__regfile_float__DOT__regfile__v0 = 0U;
    __Vdlyvset__Core__DOT__regfile__DOT__regfile__v0 = 0U;
    vlTOPp->Core__DOT__rs2_pipe_imem = ((IData)(vlTOPp->reset)
                                         ? 0U : vlTOPp->Core__DOT__fb_out);
    vlTOPp->Core__DOT__imm_pipe_ie = ((IData)(vlTOPp->reset)
                                       ? 0U : vlTOPp->Core__DOT__imm);
    vlTOPp->Core__DOT__rs1_pipe_ie = ((IData)(vlTOPp->reset)
                                       ? 0U : vlTOPp->Core__DOT__rs1_br);
    vlTOPp->Core__DOT__rs2_pipe_ie = ((IData)(vlTOPp->reset)
                                       ? 0U : vlTOPp->Core__DOT__rs2_br);
    vlTOPp->Core__DOT__memWrite_pipe_imem = ((IData)(vlTOPp->reset)
                                              ? 0U : (IData)(vlTOPp->Core__DOT__memWrite_pipe_ie));
    vlTOPp->Core__DOT__rs1add_pipe_ie = ((IData)(vlTOPp->reset)
                                          ? 0U : (0x1fU 
                                                  & (vlTOPp->Core__DOT__instruction_pipe_id 
                                                     >> 0xfU)));
    vlTOPp->Core__DOT__rs2add_pipe_ie = ((IData)(vlTOPp->reset)
                                          ? 0U : (0x1fU 
                                                  & (vlTOPp->Core__DOT__instruction_pipe_id 
                                                     >> 0x14U)));
    vlTOPp->Core__DOT__aluop_pipe_ie = ((IData)(vlTOPp->Core__DOT__reset_ie)
                                         ? 0U : ((0x40U 
                                                  & (((~ 
                                                       (vlTOPp->Core__DOT__instruction_pipe_id 
                                                        >> 6U)) 
                                                      << 6U) 
                                                     & (((~ 
                                                          (vlTOPp->Core__DOT__instruction_pipe_id 
                                                           >> 5U)) 
                                                         << 6U) 
                                                        & ((vlTOPp->Core__DOT__instruction_pipe_id 
                                                            << 2U) 
                                                           & (((~ 
                                                                (vlTOPp->Core__DOT__instruction_pipe_id 
                                                                 >> 3U)) 
                                                               << 6U) 
                                                              & ((vlTOPp->Core__DOT__instruction_pipe_id 
                                                                  << 4U) 
                                                                 & ((vlTOPp->Core__DOT__instruction_pipe_id 
                                                                     << 5U) 
                                                                    & (vlTOPp->Core__DOT__instruction_pipe_id 
                                                                       << 6U)))))))) 
                                                 | (((IData)(vlTOPp->Core__DOT__Bsel) 
                                                     << 5U) 
                                                    | (IData)(vlTOPp->Core__DOT__ALUsel))));
    vlTOPp->Core__DOT__pc_out_pipe_imem = ((IData)(vlTOPp->reset)
                                            ? 0U : 
                                           ((IData)(4U) 
                                            + vlTOPp->Core__DOT__pc_out_pipe_ie));
    if ((((IData)(vlTOPp->Core__DOT__wbsel_pipe_imem) 
          & (IData)(vlTOPp->Core__DOT__fpu_imem)) & 
         (0U != (IData)(vlTOPp->Core__DOT__rdadd_pipe_imem)))) {
        __Vdlyvval__Core__DOT__genblk1__DOT__regfile_float__DOT__regfile__v0 
            = vlTOPp->Core__DOT__rd;
        __Vdlyvset__Core__DOT__genblk1__DOT__regfile_float__DOT__regfile__v0 = 1U;
        __Vdlyvdim0__Core__DOT__genblk1__DOT__regfile_float__DOT__regfile__v0 
            = vlTOPp->Core__DOT__rdadd_pipe_imem;
    }
    if ((((IData)(vlTOPp->Core__DOT__wbsel_pipe_imem) 
          & (~ (IData)(vlTOPp->Core__DOT__fpu_imem))) 
         & (0U != (IData)(vlTOPp->Core__DOT__rdadd_pipe_imem)))) {
        __Vdlyvval__Core__DOT__regfile__DOT__regfile__v0 
            = vlTOPp->Core__DOT__rd;
        __Vdlyvset__Core__DOT__regfile__DOT__regfile__v0 = 1U;
        __Vdlyvdim0__Core__DOT__regfile__DOT__regfile__v0 
            = vlTOPp->Core__DOT__rdadd_pipe_imem;
    }
    vlTOPp->Core__DOT__mode_imem = ((IData)(vlTOPp->reset)
                                     ? 0U : (IData)(vlTOPp->Core__DOT__mode_ie));
    vlTOPp->Core__DOT__aluout_pipe_imem = ((IData)(vlTOPp->reset)
                                            ? 0U : 
                                           ((8U & (IData)(vlTOPp->Core__DOT__fpu_ie))
                                             ? vlTOPp->Core__DOT__alu__DOT__fpuout
                                             : vlTOPp->Core__DOT__alu__DOT__ALUout));
    if (__Vdlyvset__Core__DOT__genblk1__DOT__regfile_float__DOT__regfile__v0) {
        vlTOPp->Core__DOT__genblk1__DOT__regfile_float__DOT__regfile[__Vdlyvdim0__Core__DOT__genblk1__DOT__regfile_float__DOT__regfile__v0] 
            = __Vdlyvval__Core__DOT__genblk1__DOT__regfile_float__DOT__regfile__v0;
    }
    if (__Vdlyvset__Core__DOT__regfile__DOT__regfile__v0) {
        vlTOPp->Core__DOT__regfile__DOT__regfile[__Vdlyvdim0__Core__DOT__regfile__DOT__regfile__v0] 
            = __Vdlyvval__Core__DOT__regfile__DOT__regfile__v0;
    }
    vlTOPp->avl_read = (1U & ((IData)(vlTOPp->Core__DOT__memWrite_pipe_imem) 
                              >> 1U));
    vlTOPp->avl_write = (1U & (IData)(vlTOPp->Core__DOT__memWrite_pipe_imem));
    vlTOPp->Core__DOT__memWrite_pipe_ie = ((IData)(vlTOPp->Core__DOT__reset_ie)
                                            ? 0U : 
                                           ((0x40U 
                                             & vlTOPp->Core__DOT__instruction_pipe_id)
                                             ? 0U : 
                                            ((0x20U 
                                              & vlTOPp->Core__DOT__instruction_pipe_id)
                                              ? ((0x10U 
                                                  & vlTOPp->Core__DOT__instruction_pipe_id)
                                                  ? 0U
                                                  : 
                                                 ((8U 
                                                   & vlTOPp->Core__DOT__instruction_pipe_id)
                                                   ? 0U
                                                   : 
                                                  ((4U 
                                                    & vlTOPp->Core__DOT__instruction_pipe_id)
                                                    ? 
                                                   ((2U 
                                                     & vlTOPp->Core__DOT__instruction_pipe_id)
                                                     ? 
                                                    ((1U 
                                                      & vlTOPp->Core__DOT__instruction_pipe_id)
                                                      ? 1U
                                                      : 0U)
                                                     : 0U)
                                                    : 
                                                   ((2U 
                                                     & vlTOPp->Core__DOT__instruction_pipe_id)
                                                     ? 
                                                    ((1U 
                                                      & vlTOPp->Core__DOT__instruction_pipe_id)
                                                      ? 1U
                                                      : 0U)
                                                     : 0U))))
                                              : ((0x10U 
                                                  & vlTOPp->Core__DOT__instruction_pipe_id)
                                                  ? 0U
                                                  : 
                                                 ((8U 
                                                   & vlTOPp->Core__DOT__instruction_pipe_id)
                                                   ? 0U
                                                   : 
                                                  ((4U 
                                                    & vlTOPp->Core__DOT__instruction_pipe_id)
                                                    ? 
                                                   ((2U 
                                                     & vlTOPp->Core__DOT__instruction_pipe_id)
                                                     ? 
                                                    ((1U 
                                                      & vlTOPp->Core__DOT__instruction_pipe_id)
                                                      ? 2U
                                                      : 0U)
                                                     : 0U)
                                                    : 
                                                   ((2U 
                                                     & vlTOPp->Core__DOT__instruction_pipe_id)
                                                     ? 
                                                    ((1U 
                                                      & vlTOPp->Core__DOT__instruction_pipe_id)
                                                      ? 2U
                                                      : 0U)
                                                     : 0U)))))));
    vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__add_sub 
        = (((((((((0U == (0x1fU & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie))) 
                  | (1U == (0x1fU & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie)))) 
                 | (2U == (0x1fU & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie)))) 
                | (3U == (0x1fU & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie)))) 
               | (4U == (0x1fU & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie)))) 
              | (5U == (0x1fU & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie)))) 
             | (6U == (0x1fU & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie)))) 
            | (7U == (0x1fU & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie)))) 
           & ((0U != (0x1fU & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie))) 
              & ((1U != (0x1fU & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie))) 
                 & ((2U != (0x1fU & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie))) 
                    & ((3U != (0x1fU & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie))) 
                       & ((4U != (0x1fU & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie))) 
                          & (5U == (0x1fU & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie)))))))));
    vlTOPp->Core__DOT__pc_out_pipe_ie = ((IData)(vlTOPp->reset)
                                          ? 0U : vlTOPp->Core__DOT__pc_out_pipe_id);
    vlTOPp->Core__DOT__wbsel_pipe_imem = ((IData)(vlTOPp->reset)
                                           ? 0U : (IData)(vlTOPp->Core__DOT__wbsel_pipe_ie));
    vlTOPp->Core__DOT__rdadd_pipe_imem = ((IData)(vlTOPp->reset)
                                           ? 0U : (IData)(vlTOPp->Core__DOT__rdadd_pipe_ie));
    vlTOPp->Core__DOT__fpu_imem = (1U & ((~ (IData)(vlTOPp->reset)) 
                                         & ((IData)(vlTOPp->Core__DOT__fpu_ie) 
                                            >> 2U)));
    vlTOPp->Core__DOT__mode_ie = ((IData)(vlTOPp->reset)
                                   ? 0U : (7U & (vlTOPp->Core__DOT__instruction_pipe_id 
                                                 >> 0xcU)));
    vlTOPp->avl_address = vlTOPp->Core__DOT__aluout_pipe_imem;
    vlTOPp->Core__DOT__core2avl_inst__DOT__byt = (3U 
                                                  & ((0U 
                                                      == 
                                                      (vlTOPp->Core__DOT__aluout_pipe_imem 
                                                       >> 2U))
                                                      ? vlTOPp->Core__DOT__aluout_pipe_imem
                                                      : 
                                                     (vlTOPp->Core__DOT__aluout_pipe_imem 
                                                      - 
                                                      ((0x1fU 
                                                        >= 
                                                        (vlTOPp->Core__DOT__aluout_pipe_imem 
                                                         >> 2U))
                                                        ? 
                                                       ((IData)(2U) 
                                                        << 
                                                        (vlTOPp->Core__DOT__aluout_pipe_imem 
                                                         >> 2U))
                                                        : 0U))));
    if ((0U == (IData)(vlTOPp->Core__DOT__core2avl_inst__DOT__byt))) {
        vlTOPp->avl_writedata = vlTOPp->Core__DOT__rs2_pipe_imem;
    } else {
        if ((1U == (IData)(vlTOPp->Core__DOT__core2avl_inst__DOT__byt))) {
            vlTOPp->avl_writedata = (vlTOPp->Core__DOT__rs2_pipe_imem 
                                     << 8U);
        } else {
            if ((2U == (IData)(vlTOPp->Core__DOT__core2avl_inst__DOT__byt))) {
                vlTOPp->avl_writedata = (vlTOPp->Core__DOT__rs2_pipe_imem 
                                         << 0x10U);
            } else {
                if ((3U == (IData)(vlTOPp->Core__DOT__core2avl_inst__DOT__byt))) {
                    vlTOPp->avl_writedata = (vlTOPp->Core__DOT__rs2_pipe_imem 
                                             << 0x18U);
                }
            }
        }
    }
    vlTOPp->__Vtableidx1 = (((IData)(vlTOPp->Core__DOT__core2avl_inst__DOT__byt) 
                             << 3U) | (IData)(vlTOPp->Core__DOT__mode_imem));
    vlTOPp->Core__DOT__core2avl_inst__DOT__be = vlTOPp->__Vtable1_Core__DOT__core2avl_inst__DOT__be
        [vlTOPp->__Vtableidx1];
    if (vlTOPp->reset) {
        vlTOPp->Core__DOT__pc_out_pipe_id = 0U;
    } else {
        if ((1U & (~ (IData)(vlTOPp->Core__DOT__br_stall)))) {
            vlTOPp->Core__DOT__pc_out_pipe_id = ((IData)(vlTOPp->Core__DOT__pc_sel)
                                                  ? vlTOPp->Core__DOT__pcALU_inst__DOT__alu
                                                  : vlTOPp->Core__DOT__pc_out);
        }
    }
    vlTOPp->Core__DOT__wbsel_pipe_ie = ((IData)(vlTOPp->Core__DOT__reset_ie)
                                         ? 0U : (((IData)(vlTOPp->Core__DOT__wbSel) 
                                                  << 1U) 
                                                 | (IData)(vlTOPp->Core__DOT__RegWEn)));
    vlTOPp->Core__DOT__rdadd_pipe_ie = ((IData)(vlTOPp->reset)
                                         ? 0U : (0x1fU 
                                                 & (vlTOPp->Core__DOT__instruction_pipe_id 
                                                    >> 7U)));
    vlTOPp->Core__DOT__fpu_ie = ((IData)(vlTOPp->Core__DOT__reset_ie)
                                  ? 0U : ((8U & ((vlTOPp->Core__DOT__instruction_pipe_id 
                                                  >> 3U) 
                                                 & (((~ 
                                                      (vlTOPp->Core__DOT__instruction_pipe_id 
                                                       >> 5U)) 
                                                     << 3U) 
                                                    & ((vlTOPp->Core__DOT__instruction_pipe_id 
                                                        >> 1U) 
                                                       & (((~ 
                                                            (vlTOPp->Core__DOT__instruction_pipe_id 
                                                             >> 3U)) 
                                                           << 3U) 
                                                          & (((~ 
                                                               (vlTOPp->Core__DOT__instruction_pipe_id 
                                                                >> 2U)) 
                                                              << 3U) 
                                                             & ((vlTOPp->Core__DOT__instruction_pipe_id 
                                                                 << 2U) 
                                                                & (vlTOPp->Core__DOT__instruction_pipe_id 
                                                                   << 3U)))))))) 
                                          | (((IData)(vlTOPp->Core__DOT__float_write) 
                                              << 2U) 
                                             | (IData)(vlTOPp->Core__DOT__float_read))));
    vlTOPp->avl_byteenable = vlTOPp->Core__DOT__core2avl_inst__DOT__be;
    if (vlTOPp->reset) {
        vlTOPp->Core__DOT__pc_out = 0U;
    } else {
        if ((1U & (~ (IData)(vlTOPp->Core__DOT__br_stall)))) {
            vlTOPp->Core__DOT__pc_out = vlTOPp->Core__DOT__pc_in;
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->Core__DOT__instruction_pipe_id = 0U;
    } else {
        if ((1U & (~ (IData)(vlTOPp->Core__DOT__br_stall)))) {
            vlTOPp->Core__DOT__instruction_pipe_id 
                = vlTOPp->inst_data;
        }
    }
    vlTOPp->Core__DOT__Bsel = (1U & ((0x40U & vlTOPp->Core__DOT__instruction_pipe_id)
                                      ? ((vlTOPp->Core__DOT__instruction_pipe_id 
                                          >> 5U) & 
                                         ((~ (vlTOPp->Core__DOT__instruction_pipe_id 
                                              >> 4U)) 
                                          & ((8U & vlTOPp->Core__DOT__instruction_pipe_id)
                                              ? ((vlTOPp->Core__DOT__instruction_pipe_id 
                                                  >> 2U) 
                                                 & ((vlTOPp->Core__DOT__instruction_pipe_id 
                                                     >> 1U) 
                                                    & vlTOPp->Core__DOT__instruction_pipe_id))
                                              : ((4U 
                                                  & vlTOPp->Core__DOT__instruction_pipe_id)
                                                  ? 
                                                 ((vlTOPp->Core__DOT__instruction_pipe_id 
                                                   >> 1U) 
                                                  & vlTOPp->Core__DOT__instruction_pipe_id)
                                                  : 
                                                 ((vlTOPp->Core__DOT__instruction_pipe_id 
                                                   >> 1U) 
                                                  & vlTOPp->Core__DOT__instruction_pipe_id)))))
                                      : ((0x20U & vlTOPp->Core__DOT__instruction_pipe_id)
                                          ? ((0x10U 
                                              & vlTOPp->Core__DOT__instruction_pipe_id)
                                              ? ((~ 
                                                  (vlTOPp->Core__DOT__instruction_pipe_id 
                                                   >> 3U)) 
                                                 & ((vlTOPp->Core__DOT__instruction_pipe_id 
                                                     >> 2U) 
                                                    & ((vlTOPp->Core__DOT__instruction_pipe_id 
                                                        >> 1U) 
                                                       & vlTOPp->Core__DOT__instruction_pipe_id)))
                                              : ((~ 
                                                  (vlTOPp->Core__DOT__instruction_pipe_id 
                                                   >> 3U)) 
                                                 & ((4U 
                                                     & vlTOPp->Core__DOT__instruction_pipe_id)
                                                     ? 
                                                    ((vlTOPp->Core__DOT__instruction_pipe_id 
                                                      >> 1U) 
                                                     & vlTOPp->Core__DOT__instruction_pipe_id)
                                                     : 
                                                    ((vlTOPp->Core__DOT__instruction_pipe_id 
                                                      >> 1U) 
                                                     & vlTOPp->Core__DOT__instruction_pipe_id))))
                                          : ((0x10U 
                                              & vlTOPp->Core__DOT__instruction_pipe_id)
                                              ? ((~ 
                                                  (vlTOPp->Core__DOT__instruction_pipe_id 
                                                   >> 3U)) 
                                                 & ((4U 
                                                     & vlTOPp->Core__DOT__instruction_pipe_id)
                                                     ? 
                                                    ((vlTOPp->Core__DOT__instruction_pipe_id 
                                                      >> 1U) 
                                                     & vlTOPp->Core__DOT__instruction_pipe_id)
                                                     : 
                                                    ((vlTOPp->Core__DOT__instruction_pipe_id 
                                                      >> 1U) 
                                                     & vlTOPp->Core__DOT__instruction_pipe_id)))
                                              : ((~ 
                                                  (vlTOPp->Core__DOT__instruction_pipe_id 
                                                   >> 3U)) 
                                                 & ((4U 
                                                     & vlTOPp->Core__DOT__instruction_pipe_id)
                                                     ? 
                                                    ((vlTOPp->Core__DOT__instruction_pipe_id 
                                                      >> 1U) 
                                                     & vlTOPp->Core__DOT__instruction_pipe_id)
                                                     : 
                                                    ((vlTOPp->Core__DOT__instruction_pipe_id 
                                                      >> 1U) 
                                                     & vlTOPp->Core__DOT__instruction_pipe_id)))))));
    vlTOPp->Core__DOT__RegWEn = (1U & ((0x40U & vlTOPp->Core__DOT__instruction_pipe_id)
                                        ? ((0x20U & vlTOPp->Core__DOT__instruction_pipe_id)
                                            ? ((~ (vlTOPp->Core__DOT__instruction_pipe_id 
                                                   >> 4U)) 
                                               & ((8U 
                                                   & vlTOPp->Core__DOT__instruction_pipe_id)
                                                   ? 
                                                  ((vlTOPp->Core__DOT__instruction_pipe_id 
                                                    >> 2U) 
                                                   & ((vlTOPp->Core__DOT__instruction_pipe_id 
                                                       >> 1U) 
                                                      & vlTOPp->Core__DOT__instruction_pipe_id))
                                                   : 
                                                  ((vlTOPp->Core__DOT__instruction_pipe_id 
                                                    >> 2U) 
                                                   & ((vlTOPp->Core__DOT__instruction_pipe_id 
                                                       >> 1U) 
                                                      & vlTOPp->Core__DOT__instruction_pipe_id))))
                                            : ((vlTOPp->Core__DOT__instruction_pipe_id 
                                                >> 4U) 
                                               & ((~ 
                                                   (vlTOPp->Core__DOT__instruction_pipe_id 
                                                    >> 3U)) 
                                                  & ((~ 
                                                      (vlTOPp->Core__DOT__instruction_pipe_id 
                                                       >> 2U)) 
                                                     & ((vlTOPp->Core__DOT__instruction_pipe_id 
                                                         >> 1U) 
                                                        & vlTOPp->Core__DOT__instruction_pipe_id)))))
                                        : ((0x20U & vlTOPp->Core__DOT__instruction_pipe_id)
                                            ? ((vlTOPp->Core__DOT__instruction_pipe_id 
                                                >> 4U) 
                                               & ((~ 
                                                   (vlTOPp->Core__DOT__instruction_pipe_id 
                                                    >> 3U)) 
                                                  & ((4U 
                                                      & vlTOPp->Core__DOT__instruction_pipe_id)
                                                      ? 
                                                     ((vlTOPp->Core__DOT__instruction_pipe_id 
                                                       >> 1U) 
                                                      & vlTOPp->Core__DOT__instruction_pipe_id)
                                                      : 
                                                     ((vlTOPp->Core__DOT__instruction_pipe_id 
                                                       >> 1U) 
                                                      & vlTOPp->Core__DOT__instruction_pipe_id))))
                                            : ((0x10U 
                                                & vlTOPp->Core__DOT__instruction_pipe_id)
                                                ? (
                                                   (~ 
                                                    (vlTOPp->Core__DOT__instruction_pipe_id 
                                                     >> 3U)) 
                                                   & ((4U 
                                                       & vlTOPp->Core__DOT__instruction_pipe_id)
                                                       ? 
                                                      ((vlTOPp->Core__DOT__instruction_pipe_id 
                                                        >> 1U) 
                                                       & vlTOPp->Core__DOT__instruction_pipe_id)
                                                       : 
                                                      ((vlTOPp->Core__DOT__instruction_pipe_id 
                                                        >> 1U) 
                                                       & vlTOPp->Core__DOT__instruction_pipe_id)))
                                                : (
                                                   (~ 
                                                    (vlTOPp->Core__DOT__instruction_pipe_id 
                                                     >> 3U)) 
                                                   & ((4U 
                                                       & vlTOPp->Core__DOT__instruction_pipe_id)
                                                       ? 
                                                      ((vlTOPp->Core__DOT__instruction_pipe_id 
                                                        >> 1U) 
                                                       & vlTOPp->Core__DOT__instruction_pipe_id)
                                                       : 
                                                      ((vlTOPp->Core__DOT__instruction_pipe_id 
                                                        >> 1U) 
                                                       & vlTOPp->Core__DOT__instruction_pipe_id)))))));
    vlTOPp->Core__DOT__ALUsel = ((0x40U & vlTOPp->Core__DOT__instruction_pipe_id)
                                  ? ((0x20U & vlTOPp->Core__DOT__instruction_pipe_id)
                                      ? ((0x10U & vlTOPp->Core__DOT__instruction_pipe_id)
                                          ? 0U : ((8U 
                                                   & vlTOPp->Core__DOT__instruction_pipe_id)
                                                   ? 
                                                  ((4U 
                                                    & vlTOPp->Core__DOT__instruction_pipe_id)
                                                    ? 
                                                   ((2U 
                                                     & vlTOPp->Core__DOT__instruction_pipe_id)
                                                     ? 
                                                    ((1U 
                                                      & vlTOPp->Core__DOT__instruction_pipe_id)
                                                      ? 2U
                                                      : 0U)
                                                     : 0U)
                                                    : 0U)
                                                   : 
                                                  ((4U 
                                                    & vlTOPp->Core__DOT__instruction_pipe_id)
                                                    ? 
                                                   ((2U 
                                                     & vlTOPp->Core__DOT__instruction_pipe_id)
                                                     ? 
                                                    ((1U 
                                                      & vlTOPp->Core__DOT__instruction_pipe_id)
                                                      ? 2U
                                                      : 0U)
                                                     : 0U)
                                                    : 
                                                   ((2U 
                                                     & vlTOPp->Core__DOT__instruction_pipe_id)
                                                     ? 
                                                    ((1U 
                                                      & vlTOPp->Core__DOT__instruction_pipe_id)
                                                      ? 2U
                                                      : 0U)
                                                     : 0U))))
                                      : ((0x10U & vlTOPp->Core__DOT__instruction_pipe_id)
                                          ? ((8U & vlTOPp->Core__DOT__instruction_pipe_id)
                                              ? 0U : 
                                             ((4U & vlTOPp->Core__DOT__instruction_pipe_id)
                                               ? 0U
                                               : ((2U 
                                                   & vlTOPp->Core__DOT__instruction_pipe_id)
                                                   ? 
                                                  ((1U 
                                                    & vlTOPp->Core__DOT__instruction_pipe_id)
                                                    ? 
                                                   ((0x80000000U 
                                                     & vlTOPp->Core__DOT__instruction_pipe_id)
                                                     ? 
                                                    ((0x40000000U 
                                                      & vlTOPp->Core__DOT__instruction_pipe_id)
                                                      ? 
                                                     ((0x20000000U 
                                                       & vlTOPp->Core__DOT__instruction_pipe_id)
                                                       ? 
                                                      ((0x10000000U 
                                                        & vlTOPp->Core__DOT__instruction_pipe_id)
                                                        ? 
                                                       ((0x8000000U 
                                                         & vlTOPp->Core__DOT__instruction_pipe_id)
                                                         ? 0U
                                                         : 0xcU)
                                                        : 
                                                       ((0x8000000U 
                                                         & vlTOPp->Core__DOT__instruction_pipe_id)
                                                         ? 0U
                                                         : 0xdU))
                                                       : 
                                                      ((0x10000000U 
                                                        & vlTOPp->Core__DOT__instruction_pipe_id)
                                                        ? 
                                                       ((0x8000000U 
                                                         & vlTOPp->Core__DOT__instruction_pipe_id)
                                                         ? 0U
                                                         : 0xeU)
                                                        : 
                                                       ((0x8000000U 
                                                         & vlTOPp->Core__DOT__instruction_pipe_id)
                                                         ? 0U
                                                         : 0xfU)))
                                                      : 
                                                     ((0x20000000U 
                                                       & vlTOPp->Core__DOT__instruction_pipe_id)
                                                       ? 
                                                      ((0x10000000U 
                                                        & vlTOPp->Core__DOT__instruction_pipe_id)
                                                        ? 0U
                                                        : 
                                                       ((0x8000000U 
                                                         & vlTOPp->Core__DOT__instruction_pipe_id)
                                                         ? 0U
                                                         : 
                                                        ((0U 
                                                          == 
                                                          (7U 
                                                           & (vlTOPp->Core__DOT__instruction_pipe_id 
                                                              >> 0xcU)))
                                                          ? 0xbU
                                                          : 
                                                         ((1U 
                                                           == 
                                                           (7U 
                                                            & (vlTOPp->Core__DOT__instruction_pipe_id 
                                                               >> 0xcU)))
                                                           ? 0xaU
                                                           : 
                                                          ((2U 
                                                            == 
                                                            (7U 
                                                             & (vlTOPp->Core__DOT__instruction_pipe_id 
                                                                >> 0xcU)))
                                                            ? 9U
                                                            : 0U)))))
                                                       : 0U))
                                                     : 
                                                    ((0x40000000U 
                                                      & vlTOPp->Core__DOT__instruction_pipe_id)
                                                      ? 0U
                                                      : 
                                                     ((0x20000000U 
                                                       & vlTOPp->Core__DOT__instruction_pipe_id)
                                                       ? 
                                                      ((0x10000000U 
                                                        & vlTOPp->Core__DOT__instruction_pipe_id)
                                                        ? 0U
                                                        : 
                                                       ((0x8000000U 
                                                         & vlTOPp->Core__DOT__instruction_pipe_id)
                                                         ? 
                                                        ((0U 
                                                          == 
                                                          (7U 
                                                           & (vlTOPp->Core__DOT__instruction_pipe_id 
                                                              >> 0xcU)))
                                                          ? 7U
                                                          : 8U)
                                                         : 0U))
                                                       : 
                                                      ((0x10000000U 
                                                        & vlTOPp->Core__DOT__instruction_pipe_id)
                                                        ? 
                                                       ((0x8000000U 
                                                         & vlTOPp->Core__DOT__instruction_pipe_id)
                                                         ? 0U
                                                         : 6U)
                                                        : 
                                                       ((0x8000000U 
                                                         & vlTOPp->Core__DOT__instruction_pipe_id)
                                                         ? 5U
                                                         : 4U)))))
                                                    : 0U)
                                                   : 0U)))
                                          : 0U)) : 
                                 ((0x20U & vlTOPp->Core__DOT__instruction_pipe_id)
                                   ? ((0x10U & vlTOPp->Core__DOT__instruction_pipe_id)
                                       ? ((8U & vlTOPp->Core__DOT__instruction_pipe_id)
                                           ? 0U : (
                                                   (4U 
                                                    & vlTOPp->Core__DOT__instruction_pipe_id)
                                                    ? 
                                                   ((2U 
                                                     & vlTOPp->Core__DOT__instruction_pipe_id)
                                                     ? 
                                                    ((1U 
                                                      & vlTOPp->Core__DOT__instruction_pipe_id)
                                                      ? 1U
                                                      : 0U)
                                                     : 0U)
                                                    : 
                                                   ((2U 
                                                     & vlTOPp->Core__DOT__instruction_pipe_id)
                                                     ? 
                                                    ((1U 
                                                      & vlTOPp->Core__DOT__instruction_pipe_id)
                                                      ? 
                                                     ((1U 
                                                       == 
                                                       (0x7fU 
                                                        & (vlTOPp->Core__DOT__instruction_pipe_id 
                                                           >> 0x19U)))
                                                       ? 
                                                      ((0x4000U 
                                                        & vlTOPp->Core__DOT__instruction_pipe_id)
                                                        ? 
                                                       ((0x2000U 
                                                         & vlTOPp->Core__DOT__instruction_pipe_id)
                                                         ? 
                                                        ((0x1000U 
                                                          & vlTOPp->Core__DOT__instruction_pipe_id)
                                                          ? 0x14U
                                                          : 0x13U)
                                                         : 
                                                        ((0x1000U 
                                                          & vlTOPp->Core__DOT__instruction_pipe_id)
                                                          ? 0x12U
                                                          : 0x11U))
                                                        : 
                                                       ((0x2000U 
                                                         & vlTOPp->Core__DOT__instruction_pipe_id)
                                                         ? 
                                                        ((0x1000U 
                                                          & vlTOPp->Core__DOT__instruction_pipe_id)
                                                          ? 0x10U
                                                          : 0U)
                                                         : 
                                                        ((0x1000U 
                                                          & vlTOPp->Core__DOT__instruction_pipe_id)
                                                          ? 0xfU
                                                          : 8U)))
                                                       : 
                                                      ((0x4000U 
                                                        & vlTOPp->Core__DOT__instruction_pipe_id)
                                                        ? 
                                                       ((0x2000U 
                                                         & vlTOPp->Core__DOT__instruction_pipe_id)
                                                         ? 
                                                        ((0x1000U 
                                                          & vlTOPp->Core__DOT__instruction_pipe_id)
                                                          ? 0xaU
                                                          : 0xbU)
                                                         : 
                                                        ((0x1000U 
                                                          & vlTOPp->Core__DOT__instruction_pipe_id)
                                                          ? 
                                                         ((0x40000000U 
                                                           & vlTOPp->Core__DOT__instruction_pipe_id)
                                                           ? 9U
                                                           : 7U)
                                                          : 0xcU))
                                                        : 
                                                       ((0x2000U 
                                                         & vlTOPp->Core__DOT__instruction_pipe_id)
                                                         ? 
                                                        ((0x1000U 
                                                          & vlTOPp->Core__DOT__instruction_pipe_id)
                                                          ? 0xdU
                                                          : 0xeU)
                                                         : 
                                                        ((0x1000U 
                                                          & vlTOPp->Core__DOT__instruction_pipe_id)
                                                          ? 6U
                                                          : 
                                                         ((0x40000000U 
                                                           & vlTOPp->Core__DOT__instruction_pipe_id)
                                                           ? 3U
                                                           : 2U)))))
                                                      : 0U)
                                                     : 0U)))
                                       : ((8U & vlTOPp->Core__DOT__instruction_pipe_id)
                                           ? 0U : (
                                                   (4U 
                                                    & vlTOPp->Core__DOT__instruction_pipe_id)
                                                    ? 
                                                   ((2U 
                                                     & vlTOPp->Core__DOT__instruction_pipe_id)
                                                     ? 
                                                    ((1U 
                                                      & vlTOPp->Core__DOT__instruction_pipe_id)
                                                      ? 2U
                                                      : 0U)
                                                     : 0U)
                                                    : 
                                                   ((2U 
                                                     & vlTOPp->Core__DOT__instruction_pipe_id)
                                                     ? 
                                                    ((1U 
                                                      & vlTOPp->Core__DOT__instruction_pipe_id)
                                                      ? 2U
                                                      : 0U)
                                                     : 0U))))
                                   : ((0x10U & vlTOPp->Core__DOT__instruction_pipe_id)
                                       ? ((8U & vlTOPp->Core__DOT__instruction_pipe_id)
                                           ? 0U : (
                                                   (4U 
                                                    & vlTOPp->Core__DOT__instruction_pipe_id)
                                                    ? 
                                                   ((2U 
                                                     & vlTOPp->Core__DOT__instruction_pipe_id)
                                                     ? 
                                                    ((1U 
                                                      & vlTOPp->Core__DOT__instruction_pipe_id)
                                                      ? 2U
                                                      : 0U)
                                                     : 0U)
                                                    : 
                                                   ((2U 
                                                     & vlTOPp->Core__DOT__instruction_pipe_id)
                                                     ? 
                                                    ((1U 
                                                      & vlTOPp->Core__DOT__instruction_pipe_id)
                                                      ? 
                                                     ((0x4000U 
                                                       & vlTOPp->Core__DOT__instruction_pipe_id)
                                                       ? 
                                                      ((0x2000U 
                                                        & vlTOPp->Core__DOT__instruction_pipe_id)
                                                        ? 
                                                       ((0x1000U 
                                                         & vlTOPp->Core__DOT__instruction_pipe_id)
                                                         ? 0xaU
                                                         : 0xbU)
                                                        : 
                                                       ((0x1000U 
                                                         & vlTOPp->Core__DOT__instruction_pipe_id)
                                                         ? 
                                                        ((0x40000000U 
                                                          & vlTOPp->Core__DOT__instruction_pipe_id)
                                                          ? 9U
                                                          : 7U)
                                                         : 0xcU))
                                                       : 
                                                      ((0x2000U 
                                                        & vlTOPp->Core__DOT__instruction_pipe_id)
                                                        ? 
                                                       ((0x1000U 
                                                         & vlTOPp->Core__DOT__instruction_pipe_id)
                                                         ? 0xdU
                                                         : 0xeU)
                                                        : 
                                                       ((0x1000U 
                                                         & vlTOPp->Core__DOT__instruction_pipe_id)
                                                         ? 6U
                                                         : 2U)))
                                                      : 0U)
                                                     : 0U)))
                                       : ((8U & vlTOPp->Core__DOT__instruction_pipe_id)
                                           ? 0U : (
                                                   (4U 
                                                    & vlTOPp->Core__DOT__instruction_pipe_id)
                                                    ? 
                                                   ((2U 
                                                     & vlTOPp->Core__DOT__instruction_pipe_id)
                                                     ? 
                                                    ((1U 
                                                      & vlTOPp->Core__DOT__instruction_pipe_id)
                                                      ? 2U
                                                      : 0U)
                                                     : 0U)
                                                    : 
                                                   ((2U 
                                                     & vlTOPp->Core__DOT__instruction_pipe_id)
                                                     ? 
                                                    ((1U 
                                                      & vlTOPp->Core__DOT__instruction_pipe_id)
                                                      ? 2U
                                                      : 0U)
                                                     : 0U))))));
    vlTOPp->Core__DOT__wbSel = ((0x40U & vlTOPp->Core__DOT__instruction_pipe_id)
                                 ? ((0x20U & vlTOPp->Core__DOT__instruction_pipe_id)
                                     ? ((0x10U & vlTOPp->Core__DOT__instruction_pipe_id)
                                         ? 0U : ((8U 
                                                  & vlTOPp->Core__DOT__instruction_pipe_id)
                                                  ? 
                                                 ((4U 
                                                   & vlTOPp->Core__DOT__instruction_pipe_id)
                                                   ? 
                                                  ((2U 
                                                    & vlTOPp->Core__DOT__instruction_pipe_id)
                                                    ? 
                                                   ((1U 
                                                     & vlTOPp->Core__DOT__instruction_pipe_id)
                                                     ? 1U
                                                     : 0U)
                                                    : 0U)
                                                   : 0U)
                                                  : 
                                                 ((4U 
                                                   & vlTOPp->Core__DOT__instruction_pipe_id)
                                                   ? 
                                                  ((2U 
                                                    & vlTOPp->Core__DOT__instruction_pipe_id)
                                                    ? 
                                                   ((1U 
                                                     & vlTOPp->Core__DOT__instruction_pipe_id)
                                                     ? 1U
                                                     : 0U)
                                                    : 0U)
                                                   : 0U)))
                                     : 0U) : ((0x20U 
                                               & vlTOPp->Core__DOT__instruction_pipe_id)
                                               ? 0U
                                               : ((0x10U 
                                                   & vlTOPp->Core__DOT__instruction_pipe_id)
                                                   ? 0U
                                                   : 
                                                  ((8U 
                                                    & vlTOPp->Core__DOT__instruction_pipe_id)
                                                    ? 0U
                                                    : 
                                                   ((4U 
                                                     & vlTOPp->Core__DOT__instruction_pipe_id)
                                                     ? 
                                                    ((2U 
                                                      & vlTOPp->Core__DOT__instruction_pipe_id)
                                                      ? 
                                                     ((1U 
                                                       & vlTOPp->Core__DOT__instruction_pipe_id)
                                                       ? 2U
                                                       : 0U)
                                                      : 0U)
                                                     : 
                                                    ((2U 
                                                      & vlTOPp->Core__DOT__instruction_pipe_id)
                                                      ? 
                                                     ((1U 
                                                       & vlTOPp->Core__DOT__instruction_pipe_id)
                                                       ? 2U
                                                       : 0U)
                                                      : 0U))))));
    vlTOPp->Core__DOT__float_write = (1U & ((0x40U 
                                             & vlTOPp->Core__DOT__instruction_pipe_id)
                                             ? ((~ 
                                                 (vlTOPp->Core__DOT__instruction_pipe_id 
                                                  >> 5U)) 
                                                & ((vlTOPp->Core__DOT__instruction_pipe_id 
                                                    >> 4U) 
                                                   & ((~ 
                                                       (vlTOPp->Core__DOT__instruction_pipe_id 
                                                        >> 3U)) 
                                                      & ((~ 
                                                          (vlTOPp->Core__DOT__instruction_pipe_id 
                                                           >> 2U)) 
                                                         & ((vlTOPp->Core__DOT__instruction_pipe_id 
                                                             >> 1U) 
                                                            & (vlTOPp->Core__DOT__instruction_pipe_id 
                                                               & ((0x80000000U 
                                                                   & vlTOPp->Core__DOT__instruction_pipe_id)
                                                                   ? 
                                                                  ((vlTOPp->Core__DOT__instruction_pipe_id 
                                                                    >> 0x1eU) 
                                                                   & ((0x20000000U 
                                                                       & vlTOPp->Core__DOT__instruction_pipe_id)
                                                                       ? 
                                                                      ((vlTOPp->Core__DOT__instruction_pipe_id 
                                                                        >> 0x1cU) 
                                                                       & (~ 
                                                                          (vlTOPp->Core__DOT__instruction_pipe_id 
                                                                           >> 0x1bU)))
                                                                       : 
                                                                      ((vlTOPp->Core__DOT__instruction_pipe_id 
                                                                        >> 0x1cU) 
                                                                       & (~ 
                                                                          (vlTOPp->Core__DOT__instruction_pipe_id 
                                                                           >> 0x1bU)))))
                                                                   : 
                                                                  ((~ 
                                                                    (vlTOPp->Core__DOT__instruction_pipe_id 
                                                                     >> 0x1eU)) 
                                                                   & ((0x20000000U 
                                                                       & vlTOPp->Core__DOT__instruction_pipe_id)
                                                                       ? 
                                                                      ((~ 
                                                                        (vlTOPp->Core__DOT__instruction_pipe_id 
                                                                         >> 0x1cU)) 
                                                                       & (vlTOPp->Core__DOT__instruction_pipe_id 
                                                                          >> 0x1bU))
                                                                       : 
                                                                      ((~ 
                                                                        (vlTOPp->Core__DOT__instruction_pipe_id 
                                                                         >> 0x1cU)) 
                                                                       | (~ 
                                                                          (vlTOPp->Core__DOT__instruction_pipe_id 
                                                                           >> 0x1bU))))))))))))
                                             : ((~ 
                                                 (vlTOPp->Core__DOT__instruction_pipe_id 
                                                  >> 5U)) 
                                                & ((~ 
                                                    (vlTOPp->Core__DOT__instruction_pipe_id 
                                                     >> 4U)) 
                                                   & ((~ 
                                                       (vlTOPp->Core__DOT__instruction_pipe_id 
                                                        >> 3U)) 
                                                      & ((vlTOPp->Core__DOT__instruction_pipe_id 
                                                          >> 2U) 
                                                         & ((vlTOPp->Core__DOT__instruction_pipe_id 
                                                             >> 1U) 
                                                            & vlTOPp->Core__DOT__instruction_pipe_id)))))));
    vlTOPp->Core__DOT__immsel = ((0x40U & vlTOPp->Core__DOT__instruction_pipe_id)
                                  ? ((0x20U & vlTOPp->Core__DOT__instruction_pipe_id)
                                      ? ((0x10U & vlTOPp->Core__DOT__instruction_pipe_id)
                                          ? 0U : ((8U 
                                                   & vlTOPp->Core__DOT__instruction_pipe_id)
                                                   ? 
                                                  ((4U 
                                                    & vlTOPp->Core__DOT__instruction_pipe_id)
                                                    ? 
                                                   ((2U 
                                                     & vlTOPp->Core__DOT__instruction_pipe_id)
                                                     ? 
                                                    ((1U 
                                                      & vlTOPp->Core__DOT__instruction_pipe_id)
                                                      ? 3U
                                                      : 0U)
                                                     : 0U)
                                                    : 0U)
                                                   : 
                                                  ((4U 
                                                    & vlTOPp->Core__DOT__instruction_pipe_id)
                                                    ? 0U
                                                    : 
                                                   ((2U 
                                                     & vlTOPp->Core__DOT__instruction_pipe_id)
                                                     ? 
                                                    ((1U 
                                                      & vlTOPp->Core__DOT__instruction_pipe_id)
                                                      ? 2U
                                                      : 0U)
                                                     : 0U))))
                                      : 0U) : ((0x20U 
                                                & vlTOPp->Core__DOT__instruction_pipe_id)
                                                ? (
                                                   (0x10U 
                                                    & vlTOPp->Core__DOT__instruction_pipe_id)
                                                    ? 
                                                   ((8U 
                                                     & vlTOPp->Core__DOT__instruction_pipe_id)
                                                     ? 0U
                                                     : 
                                                    ((4U 
                                                      & vlTOPp->Core__DOT__instruction_pipe_id)
                                                      ? 
                                                     ((2U 
                                                       & vlTOPp->Core__DOT__instruction_pipe_id)
                                                       ? 
                                                      ((1U 
                                                        & vlTOPp->Core__DOT__instruction_pipe_id)
                                                        ? 4U
                                                        : 0U)
                                                       : 0U)
                                                      : 0U))
                                                    : 
                                                   ((8U 
                                                     & vlTOPp->Core__DOT__instruction_pipe_id)
                                                     ? 0U
                                                     : 
                                                    ((4U 
                                                      & vlTOPp->Core__DOT__instruction_pipe_id)
                                                      ? 
                                                     ((2U 
                                                       & vlTOPp->Core__DOT__instruction_pipe_id)
                                                       ? 
                                                      ((1U 
                                                        & vlTOPp->Core__DOT__instruction_pipe_id)
                                                        ? 1U
                                                        : 0U)
                                                       : 0U)
                                                      : 
                                                     ((2U 
                                                       & vlTOPp->Core__DOT__instruction_pipe_id)
                                                       ? 
                                                      ((1U 
                                                        & vlTOPp->Core__DOT__instruction_pipe_id)
                                                        ? 1U
                                                        : 0U)
                                                       : 0U))))
                                                : (
                                                   (0x10U 
                                                    & vlTOPp->Core__DOT__instruction_pipe_id)
                                                    ? 
                                                   ((8U 
                                                     & vlTOPp->Core__DOT__instruction_pipe_id)
                                                     ? 0U
                                                     : 
                                                    ((4U 
                                                      & vlTOPp->Core__DOT__instruction_pipe_id)
                                                      ? 
                                                     ((2U 
                                                       & vlTOPp->Core__DOT__instruction_pipe_id)
                                                       ? 
                                                      ((1U 
                                                        & vlTOPp->Core__DOT__instruction_pipe_id)
                                                        ? 4U
                                                        : 0U)
                                                       : 0U)
                                                      : 0U))
                                                    : 0U)));
    vlTOPp->Core__DOT__BrUn = (1U & ((vlTOPp->Core__DOT__instruction_pipe_id 
                                      >> 6U) & ((vlTOPp->Core__DOT__instruction_pipe_id 
                                                 >> 5U) 
                                                & ((~ 
                                                    (vlTOPp->Core__DOT__instruction_pipe_id 
                                                     >> 4U)) 
                                                   & ((~ 
                                                       (vlTOPp->Core__DOT__instruction_pipe_id 
                                                        >> 3U)) 
                                                      & ((~ 
                                                          (vlTOPp->Core__DOT__instruction_pipe_id 
                                                           >> 2U)) 
                                                         & ((vlTOPp->Core__DOT__instruction_pipe_id 
                                                             >> 1U) 
                                                            & (vlTOPp->Core__DOT__instruction_pipe_id 
                                                               & ((~ 
                                                                   (vlTOPp->Core__DOT__instruction_pipe_id 
                                                                    >> 0xeU)) 
                                                                  | (vlTOPp->Core__DOT__instruction_pipe_id 
                                                                     >> 0xdU))))))))));
    vlTOPp->Core__DOT__float_read = ((0x40U & vlTOPp->Core__DOT__instruction_pipe_id)
                                      ? ((0x20U & vlTOPp->Core__DOT__instruction_pipe_id)
                                          ? 0U : ((0x10U 
                                                   & vlTOPp->Core__DOT__instruction_pipe_id)
                                                   ? 
                                                  ((8U 
                                                    & vlTOPp->Core__DOT__instruction_pipe_id)
                                                    ? 0U
                                                    : 
                                                   ((4U 
                                                     & vlTOPp->Core__DOT__instruction_pipe_id)
                                                     ? 0U
                                                     : 
                                                    ((2U 
                                                      & vlTOPp->Core__DOT__instruction_pipe_id)
                                                      ? 
                                                     ((1U 
                                                       & vlTOPp->Core__DOT__instruction_pipe_id)
                                                       ? 
                                                      ((0x80000000U 
                                                        & vlTOPp->Core__DOT__instruction_pipe_id)
                                                        ? 
                                                       ((0x40000000U 
                                                         & vlTOPp->Core__DOT__instruction_pipe_id)
                                                         ? 
                                                        ((0x20000000U 
                                                          & vlTOPp->Core__DOT__instruction_pipe_id)
                                                          ? 
                                                         ((0x10000000U 
                                                           & vlTOPp->Core__DOT__instruction_pipe_id)
                                                           ? 0U
                                                           : 
                                                          ((0x8000000U 
                                                            & vlTOPp->Core__DOT__instruction_pipe_id)
                                                            ? 0U
                                                            : 2U))
                                                          : 
                                                         ((0x10000000U 
                                                           & vlTOPp->Core__DOT__instruction_pipe_id)
                                                           ? 0U
                                                           : 
                                                          ((0x8000000U 
                                                            & vlTOPp->Core__DOT__instruction_pipe_id)
                                                            ? 0U
                                                            : 2U)))
                                                         : 
                                                        ((0x20000000U 
                                                          & vlTOPp->Core__DOT__instruction_pipe_id)
                                                          ? 
                                                         ((0x10000000U 
                                                           & vlTOPp->Core__DOT__instruction_pipe_id)
                                                           ? 0U
                                                           : 
                                                          ((0x8000000U 
                                                            & vlTOPp->Core__DOT__instruction_pipe_id)
                                                            ? 0U
                                                            : 3U))
                                                          : 0U))
                                                        : 
                                                       ((0x40000000U 
                                                         & vlTOPp->Core__DOT__instruction_pipe_id)
                                                         ? 0U
                                                         : 
                                                        ((0x20000000U 
                                                          & vlTOPp->Core__DOT__instruction_pipe_id)
                                                          ? 
                                                         ((0x10000000U 
                                                           & vlTOPp->Core__DOT__instruction_pipe_id)
                                                           ? 0U
                                                           : 
                                                          ((0x8000000U 
                                                            & vlTOPp->Core__DOT__instruction_pipe_id)
                                                            ? 3U
                                                            : 0U))
                                                          : 
                                                         ((0x10000000U 
                                                           & vlTOPp->Core__DOT__instruction_pipe_id)
                                                           ? 
                                                          ((0x8000000U 
                                                            & vlTOPp->Core__DOT__instruction_pipe_id)
                                                            ? 0U
                                                            : 3U)
                                                           : 3U))))
                                                       : 0U)
                                                      : 0U)))
                                                   : 0U))
                                      : ((0x20U & vlTOPp->Core__DOT__instruction_pipe_id)
                                          ? ((0x10U 
                                              & vlTOPp->Core__DOT__instruction_pipe_id)
                                              ? 0U : 
                                             ((8U & vlTOPp->Core__DOT__instruction_pipe_id)
                                               ? 0U
                                               : ((4U 
                                                   & vlTOPp->Core__DOT__instruction_pipe_id)
                                                   ? 
                                                  ((2U 
                                                    & vlTOPp->Core__DOT__instruction_pipe_id)
                                                    ? 
                                                   ((1U 
                                                     & vlTOPp->Core__DOT__instruction_pipe_id)
                                                     ? 1U
                                                     : 0U)
                                                    : 0U)
                                                   : 0U)))
                                          : 0U));
    vlTOPp->Core__DOT__imm = ((4U & (IData)(vlTOPp->Core__DOT__immsel))
                               ? ((2U & (IData)(vlTOPp->Core__DOT__immsel))
                                   ? 0U : ((1U & (IData)(vlTOPp->Core__DOT__immsel))
                                            ? 0U : 
                                           (0xfffff000U 
                                            & vlTOPp->Core__DOT__instruction_pipe_id)))
                               : ((2U & (IData)(vlTOPp->Core__DOT__immsel))
                                   ? ((1U & (IData)(vlTOPp->Core__DOT__immsel))
                                       ? ((0xfff00000U 
                                           & (VL_NEGATE_I((IData)(
                                                                  (1U 
                                                                   & (vlTOPp->Core__DOT__instruction_pipe_id 
                                                                      >> 0x1fU)))) 
                                              << 0x14U)) 
                                          | ((0x80000U 
                                              & (vlTOPp->Core__DOT__instruction_pipe_id 
                                                 >> 0xcU)) 
                                             | ((0x7f800U 
                                                 & (vlTOPp->Core__DOT__instruction_pipe_id 
                                                    >> 1U)) 
                                                | ((0x400U 
                                                    & (vlTOPp->Core__DOT__instruction_pipe_id 
                                                       >> 0xaU)) 
                                                   | (0x3ffU 
                                                      & (vlTOPp->Core__DOT__instruction_pipe_id 
                                                         >> 0x15U))))))
                                       : ((0xfffff000U 
                                           & (VL_NEGATE_I((IData)(
                                                                  (1U 
                                                                   & (vlTOPp->Core__DOT__instruction_pipe_id 
                                                                      >> 0x1fU)))) 
                                              << 0xcU)) 
                                          | ((0x800U 
                                              & (vlTOPp->Core__DOT__instruction_pipe_id 
                                                 >> 0x14U)) 
                                             | ((0x400U 
                                                 & (vlTOPp->Core__DOT__instruction_pipe_id 
                                                    << 3U)) 
                                                | ((0x3f0U 
                                                    & (vlTOPp->Core__DOT__instruction_pipe_id 
                                                       >> 0x15U)) 
                                                   | (0xfU 
                                                      & (vlTOPp->Core__DOT__instruction_pipe_id 
                                                         >> 8U)))))))
                                   : ((1U & (IData)(vlTOPp->Core__DOT__immsel))
                                       ? ((0xfffff000U 
                                           & (VL_NEGATE_I((IData)(
                                                                  (1U 
                                                                   & (vlTOPp->Core__DOT__instruction_pipe_id 
                                                                      >> 0x1fU)))) 
                                              << 0xcU)) 
                                          | ((0xfe0U 
                                              & (vlTOPp->Core__DOT__instruction_pipe_id 
                                                 >> 0x14U)) 
                                             | (0x1fU 
                                                & (vlTOPp->Core__DOT__instruction_pipe_id 
                                                   >> 7U))))
                                       : ((0xfffff000U 
                                           & (VL_NEGATE_I((IData)(
                                                                  (1U 
                                                                   & (vlTOPp->Core__DOT__instruction_pipe_id 
                                                                      >> 0x1fU)))) 
                                              << 0xcU)) 
                                          | (0xfffU 
                                             & (vlTOPp->Core__DOT__instruction_pipe_id 
                                                >> 0x14U))))));
    vlTOPp->Core__DOT__br_stall = (((((vlTOPp->Core__DOT__instruction_pipe_id 
                                       >> 6U) & ((vlTOPp->Core__DOT__instruction_pipe_id 
                                                  >> 5U) 
                                                 & ((~ 
                                                     (vlTOPp->Core__DOT__instruction_pipe_id 
                                                      >> 4U)) 
                                                    & ((~ 
                                                        (vlTOPp->Core__DOT__instruction_pipe_id 
                                                         >> 3U)) 
                                                       & ((4U 
                                                           & vlTOPp->Core__DOT__instruction_pipe_id)
                                                           ? 
                                                          ((vlTOPp->Core__DOT__instruction_pipe_id 
                                                            >> 1U) 
                                                           & vlTOPp->Core__DOT__instruction_pipe_id)
                                                           : 
                                                          ((vlTOPp->Core__DOT__instruction_pipe_id 
                                                            >> 1U) 
                                                           & vlTOPp->Core__DOT__instruction_pipe_id)))))) 
                                     & (IData)(vlTOPp->Core__DOT__wbsel_pipe_ie)) 
                                    & (0U != (IData)(vlTOPp->Core__DOT__rdadd_pipe_ie))) 
                                   & ((((IData)(vlTOPp->Core__DOT__rdadd_pipe_ie) 
                                        == (0x1fU & 
                                            (vlTOPp->Core__DOT__instruction_pipe_id 
                                             >> 0xfU))) 
                                       & ((1U & ((IData)(vlTOPp->Core__DOT__float_read) 
                                                 >> 1U)) 
                                          == (1U & 
                                              ((IData)(vlTOPp->Core__DOT__fpu_ie) 
                                               >> 2U)))) 
                                      | (((IData)(vlTOPp->Core__DOT__rdadd_pipe_ie) 
                                          == (0x1fU 
                                              & (vlTOPp->Core__DOT__instruction_pipe_id 
                                                 >> 0x14U))) 
                                         & ((1U & (IData)(vlTOPp->Core__DOT__float_read)) 
                                            == (1U 
                                                & ((IData)(vlTOPp->Core__DOT__fpu_ie) 
                                                   >> 2U))))));
}

VL_INLINE_OPT void VCore::_combo__TOP__6(VCore__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCore::_combo__TOP__6\n"); );
    VCore* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->Core__DOT__core2avl_inst__DOT__q1 = ((8U 
                                                  & (IData)(vlTOPp->Core__DOT__core2avl_inst__DOT__be))
                                                  ? 
                                                 ((4U 
                                                   & (IData)(vlTOPp->Core__DOT__core2avl_inst__DOT__be))
                                                   ? 
                                                  ((2U 
                                                    & (IData)(vlTOPp->Core__DOT__core2avl_inst__DOT__be))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(vlTOPp->Core__DOT__core2avl_inst__DOT__be))
                                                     ? vlTOPp->avl_readdata
                                                     : 0U)
                                                    : 
                                                   ((1U 
                                                     & (IData)(vlTOPp->Core__DOT__core2avl_inst__DOT__be))
                                                     ? 0U
                                                     : 
                                                    (0xffffU 
                                                     & (vlTOPp->avl_readdata 
                                                        >> 0x10U))))
                                                   : 
                                                  ((2U 
                                                    & (IData)(vlTOPp->Core__DOT__core2avl_inst__DOT__be))
                                                    ? 0U
                                                    : 
                                                   ((1U 
                                                     & (IData)(vlTOPp->Core__DOT__core2avl_inst__DOT__be))
                                                     ? 0U
                                                     : 
                                                    (0xffU 
                                                     & (vlTOPp->avl_readdata 
                                                        >> 0x18U)))))
                                                  : 
                                                 ((4U 
                                                   & (IData)(vlTOPp->Core__DOT__core2avl_inst__DOT__be))
                                                   ? 
                                                  ((2U 
                                                    & (IData)(vlTOPp->Core__DOT__core2avl_inst__DOT__be))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(vlTOPp->Core__DOT__core2avl_inst__DOT__be))
                                                     ? 0U
                                                     : 
                                                    (0xffffU 
                                                     & (vlTOPp->avl_readdata 
                                                        >> 8U)))
                                                    : 
                                                   ((1U 
                                                     & (IData)(vlTOPp->Core__DOT__core2avl_inst__DOT__be))
                                                     ? 0U
                                                     : 
                                                    (0xffU 
                                                     & (vlTOPp->avl_readdata 
                                                        >> 0x10U))))
                                                   : 
                                                  ((2U 
                                                    & (IData)(vlTOPp->Core__DOT__core2avl_inst__DOT__be))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(vlTOPp->Core__DOT__core2avl_inst__DOT__be))
                                                     ? 
                                                    (0xffffU 
                                                     & vlTOPp->avl_readdata)
                                                     : 
                                                    (0xffU 
                                                     & (vlTOPp->avl_readdata 
                                                        >> 8U)))
                                                    : 
                                                   ((1U 
                                                     & (IData)(vlTOPp->Core__DOT__core2avl_inst__DOT__be))
                                                     ? 
                                                    (0xffU 
                                                     & vlTOPp->avl_readdata)
                                                     : 0U))));
    vlTOPp->inst_stall = ((IData)(vlTOPp->Core__DOT__br_stall) 
                          | (IData)(vlTOPp->Core__DOT__stall_core));
    vlTOPp->Core__DOT__reset_ie = ((IData)(vlTOPp->Core__DOT__br_stall) 
                                   | (IData)(vlTOPp->reset));
    vlTOPp->Core__DOT__rd = ((2U & (IData)(vlTOPp->Core__DOT__wbsel_pipe_imem))
                              ? vlTOPp->Core__DOT__pc_out_pipe_imem
                              : ((4U & (IData)(vlTOPp->Core__DOT__wbsel_pipe_imem))
                                  ? ((4U & (IData)(vlTOPp->Core__DOT__mode_imem))
                                      ? ((2U & (IData)(vlTOPp->Core__DOT__mode_imem))
                                          ? 0U : ((1U 
                                                   & (IData)(vlTOPp->Core__DOT__mode_imem))
                                                   ? 
                                                  (0xffffU 
                                                   & vlTOPp->Core__DOT__core2avl_inst__DOT__q1)
                                                   : 
                                                  (0xffU 
                                                   & vlTOPp->Core__DOT__core2avl_inst__DOT__q1)))
                                      : ((2U & (IData)(vlTOPp->Core__DOT__mode_imem))
                                          ? ((1U & (IData)(vlTOPp->Core__DOT__mode_imem))
                                              ? 0U : vlTOPp->Core__DOT__core2avl_inst__DOT__q1)
                                          : ((1U & (IData)(vlTOPp->Core__DOT__mode_imem))
                                              ? ((0xffff0000U 
                                                  & (VL_NEGATE_I((IData)(
                                                                         (1U 
                                                                          & (vlTOPp->Core__DOT__core2avl_inst__DOT__q1 
                                                                             >> 0xfU)))) 
                                                     << 0x10U)) 
                                                 | (0xffffU 
                                                    & vlTOPp->Core__DOT__core2avl_inst__DOT__q1))
                                              : ((0xffffff00U 
                                                  & (VL_NEGATE_I((IData)(
                                                                         (1U 
                                                                          & (vlTOPp->Core__DOT__core2avl_inst__DOT__q1 
                                                                             >> 7U)))) 
                                                     << 8U)) 
                                                 | (0xffU 
                                                    & vlTOPp->Core__DOT__core2avl_inst__DOT__q1)))))
                                  : vlTOPp->Core__DOT__aluout_pipe_imem));
    vlTOPp->Core__DOT__A = ((0x40U & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie))
                             ? vlTOPp->Core__DOT__pc_out_pipe_ie
                             : (((((IData)(vlTOPp->Core__DOT__wbsel_pipe_imem) 
                                   & (0U != (IData)(vlTOPp->Core__DOT__rdadd_pipe_imem))) 
                                  & ((IData)(vlTOPp->Core__DOT__rdadd_pipe_imem) 
                                     == (IData)(vlTOPp->Core__DOT__rs1add_pipe_ie))) 
                                 & ((1U & ((IData)(vlTOPp->Core__DOT__fpu_ie) 
                                           >> 1U)) 
                                    == (IData)(vlTOPp->Core__DOT__fpu_imem)))
                                 ? vlTOPp->Core__DOT__rd
                                 : vlTOPp->Core__DOT__rs1_pipe_ie));
    vlTOPp->Core__DOT__fb_out = (((((IData)(vlTOPp->Core__DOT__wbsel_pipe_imem) 
                                    & (0U != (IData)(vlTOPp->Core__DOT__rdadd_pipe_imem))) 
                                   & ((IData)(vlTOPp->Core__DOT__rdadd_pipe_imem) 
                                      == (IData)(vlTOPp->Core__DOT__rs2add_pipe_ie))) 
                                  & ((1U & (IData)(vlTOPp->Core__DOT__fpu_ie)) 
                                     == (IData)(vlTOPp->Core__DOT__fpu_imem)))
                                  ? vlTOPp->Core__DOT__rd
                                  : vlTOPp->Core__DOT__rs2_pipe_ie);
    vlTOPp->Core__DOT__rs2_br = (((((IData)(vlTOPp->Core__DOT__wbsel_pipe_imem) 
                                    & (0U != (IData)(vlTOPp->Core__DOT__rdadd_pipe_imem))) 
                                   & ((IData)(vlTOPp->Core__DOT__rdadd_pipe_imem) 
                                      == (0x1fU & (vlTOPp->Core__DOT__instruction_pipe_id 
                                                   >> 0x14U)))) 
                                  & ((1U & (IData)(vlTOPp->Core__DOT__float_read)) 
                                     == (IData)(vlTOPp->Core__DOT__fpu_imem)))
                                  ? vlTOPp->Core__DOT__rd
                                  : ((1U & (IData)(vlTOPp->Core__DOT__float_read))
                                      ? vlTOPp->Core__DOT__genblk1__DOT__regfile_float__DOT__regfile
                                     [(0x1fU & (vlTOPp->Core__DOT__instruction_pipe_id 
                                                >> 0x14U))]
                                      : vlTOPp->Core__DOT__regfile__DOT__regfile
                                     [(0x1fU & (vlTOPp->Core__DOT__instruction_pipe_id 
                                                >> 0x14U))]));
    vlTOPp->Core__DOT__rs1_br = (((((IData)(vlTOPp->Core__DOT__wbsel_pipe_imem) 
                                    & (0U != (IData)(vlTOPp->Core__DOT__rdadd_pipe_imem))) 
                                   & ((IData)(vlTOPp->Core__DOT__rdadd_pipe_imem) 
                                      == (0x1fU & (vlTOPp->Core__DOT__instruction_pipe_id 
                                                   >> 0xfU)))) 
                                  & ((1U & ((IData)(vlTOPp->Core__DOT__float_read) 
                                            >> 1U)) 
                                     == (IData)(vlTOPp->Core__DOT__fpu_imem)))
                                  ? vlTOPp->Core__DOT__rd
                                  : ((2U & (IData)(vlTOPp->Core__DOT__float_read))
                                      ? vlTOPp->Core__DOT__genblk1__DOT__regfile_float__DOT__regfile
                                     [(0x1fU & (vlTOPp->Core__DOT__instruction_pipe_id 
                                                >> 0xfU))]
                                      : vlTOPp->Core__DOT__regfile__DOT__regfile
                                     [(0x1fU & (vlTOPp->Core__DOT__instruction_pipe_id 
                                                >> 0xfU))]));
    vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__fp2int_inst__DOT__abs_int 
        = ((0x7fU <= (0xffU & (vlTOPp->Core__DOT__A 
                               >> 0x17U))) ? ((0x1fU 
                                               >= ((IData)(0x9dU) 
                                                   - 
                                                   (0xffU 
                                                    & (vlTOPp->Core__DOT__A 
                                                       >> 0x17U))))
                                               ? ((0x40000000U 
                                                   | (0x3fffff80U 
                                                      & (vlTOPp->Core__DOT__A 
                                                         << 7U))) 
                                                  >> 
                                                  ((IData)(0x9dU) 
                                                   - 
                                                   (0xffU 
                                                    & (vlTOPp->Core__DOT__A 
                                                       >> 0x17U))))
                                               : 0U)
            : 0U);
    vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__int2fp_inst__DOT__abs 
        = ((0x80000000U & vlTOPp->Core__DOT__A) ? ((IData)(1U) 
                                                   + 
                                                   (~ vlTOPp->Core__DOT__A))
            : vlTOPp->Core__DOT__A);
    if ((0U == (0x7fffffffU & vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__int2fp_inst__DOT__abs))) {
        vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__int2fp_inst__DOT__eout = 0U;
        vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__int2fp_inst__DOT__mout = 0U;
        vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__int2fp_inst__DOT__sign = 0U;
        vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__int2fp_inst__DOT__num_zeros = 0U;
    } else {
        vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__int2fp_inst__DOT__num_zeros 
            = (((((((((0x40000000U == (0x40000000U 
                                       & vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__int2fp_inst__DOT__abs)) 
                      | (0x20000000U == (0x60000000U 
                                         & vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__int2fp_inst__DOT__abs))) 
                     | (0x10000000U == (0x70000000U 
                                        & vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__int2fp_inst__DOT__abs))) 
                    | (0x8000000U == (0x78000000U & vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__int2fp_inst__DOT__abs))) 
                   | (0x4000000U == (0x7c000000U & vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__int2fp_inst__DOT__abs))) 
                  | (0x2000000U == (0x7e000000U & vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__int2fp_inst__DOT__abs))) 
                 | (0x1000000U == (0x7f000000U & vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__int2fp_inst__DOT__abs))) 
                | (0x800000U == (0x7f800000U & vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__int2fp_inst__DOT__abs)))
                ? ((0x40000000U == (0x40000000U & vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__int2fp_inst__DOT__abs))
                    ? 0U : ((0x20000000U == (0x60000000U 
                                             & vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__int2fp_inst__DOT__abs))
                             ? 1U : ((0x10000000U == 
                                      (0x70000000U 
                                       & vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__int2fp_inst__DOT__abs))
                                      ? 2U : ((0x8000000U 
                                               == (0x78000000U 
                                                   & vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__int2fp_inst__DOT__abs))
                                               ? 3U
                                               : ((0x4000000U 
                                                   == 
                                                   (0x7c000000U 
                                                    & vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__int2fp_inst__DOT__abs))
                                                   ? 4U
                                                   : 
                                                  ((0x2000000U 
                                                    == 
                                                    (0x7e000000U 
                                                     & vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__int2fp_inst__DOT__abs))
                                                    ? 5U
                                                    : 
                                                   ((0x1000000U 
                                                     == 
                                                     (0x7f000000U 
                                                      & vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__int2fp_inst__DOT__abs))
                                                     ? 6U
                                                     : 7U)))))))
                : (((((((((0x400000U == (0x7fc00000U 
                                         & vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__int2fp_inst__DOT__abs)) 
                          | (0x200000U == (0x7fe00000U 
                                           & vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__int2fp_inst__DOT__abs))) 
                         | (0x100000U == (0x7ff00000U 
                                          & vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__int2fp_inst__DOT__abs))) 
                        | (0x80000U == (0x7ff80000U 
                                        & vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__int2fp_inst__DOT__abs))) 
                       | (0x40000U == (0x7ffc0000U 
                                       & vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__int2fp_inst__DOT__abs))) 
                      | (0x20000U == (0x7ffe0000U & vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__int2fp_inst__DOT__abs))) 
                     | (0x10000U == (0x7fff0000U & vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__int2fp_inst__DOT__abs))) 
                    | (0x8000U == (0x7fff8000U & vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__int2fp_inst__DOT__abs)))
                    ? ((0x400000U == (0x7fc00000U & vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__int2fp_inst__DOT__abs))
                        ? 8U : ((0x200000U == (0x7fe00000U 
                                               & vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__int2fp_inst__DOT__abs))
                                 ? 9U : ((0x100000U 
                                          == (0x7ff00000U 
                                              & vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__int2fp_inst__DOT__abs))
                                          ? 0xaU : 
                                         ((0x80000U 
                                           == (0x7ff80000U 
                                               & vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__int2fp_inst__DOT__abs))
                                           ? 0xbU : 
                                          ((0x40000U 
                                            == (0x7ffc0000U 
                                                & vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__int2fp_inst__DOT__abs))
                                            ? 0xcU : 
                                           ((0x20000U 
                                             == (0x7ffe0000U 
                                                 & vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__int2fp_inst__DOT__abs))
                                             ? 0xdU
                                             : ((0x10000U 
                                                 == 
                                                 (0x7fff0000U 
                                                  & vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__int2fp_inst__DOT__abs))
                                                 ? 0xeU
                                                 : 0xfU)))))))
                    : (((((((((0x4000U == (0x7fffc000U 
                                           & vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__int2fp_inst__DOT__abs)) 
                              | (0x2000U == (0x7fffe000U 
                                             & vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__int2fp_inst__DOT__abs))) 
                             | (0x1000U == (0x7ffff000U 
                                            & vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__int2fp_inst__DOT__abs))) 
                            | (0x800U == (0x7ffff800U 
                                          & vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__int2fp_inst__DOT__abs))) 
                           | (0x400U == (0x7ffffc00U 
                                         & vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__int2fp_inst__DOT__abs))) 
                          | (0x200U == (0x7ffffe00U 
                                        & vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__int2fp_inst__DOT__abs))) 
                         | (0x100U == (0x7fffff00U 
                                       & vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__int2fp_inst__DOT__abs))) 
                        | (0x80U == (0x7fffff80U & vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__int2fp_inst__DOT__abs)))
                        ? ((0x4000U == (0x7fffc000U 
                                        & vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__int2fp_inst__DOT__abs))
                            ? 0x10U : ((0x2000U == 
                                        (0x7fffe000U 
                                         & vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__int2fp_inst__DOT__abs))
                                        ? 0x11U : (
                                                   (0x1000U 
                                                    == 
                                                    (0x7ffff000U 
                                                     & vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__int2fp_inst__DOT__abs))
                                                    ? 0x12U
                                                    : 
                                                   ((0x800U 
                                                     == 
                                                     (0x7ffff800U 
                                                      & vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__int2fp_inst__DOT__abs))
                                                     ? 0x13U
                                                     : 
                                                    ((0x400U 
                                                      == 
                                                      (0x7ffffc00U 
                                                       & vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__int2fp_inst__DOT__abs))
                                                      ? 0x14U
                                                      : 
                                                     ((0x200U 
                                                       == 
                                                       (0x7ffffe00U 
                                                        & vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__int2fp_inst__DOT__abs))
                                                       ? 0x15U
                                                       : 
                                                      ((0x100U 
                                                        == 
                                                        (0x7fffff00U 
                                                         & vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__int2fp_inst__DOT__abs))
                                                        ? 0x16U
                                                        : 0x17U)))))))
                        : ((0x40U == (0x7fffffc0U & vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__int2fp_inst__DOT__abs))
                            ? 0x18U : ((0x20U == (0x7fffffe0U 
                                                  & vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__int2fp_inst__DOT__abs))
                                        ? 0x19U : (
                                                   (0x10U 
                                                    == 
                                                    (0x7ffffff0U 
                                                     & vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__int2fp_inst__DOT__abs))
                                                    ? 0x1aU
                                                    : 
                                                   ((8U 
                                                     == 
                                                     (0x7ffffff8U 
                                                      & vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__int2fp_inst__DOT__abs))
                                                     ? 0x1bU
                                                     : 
                                                    ((4U 
                                                      == 
                                                      (0x7ffffffcU 
                                                       & vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__int2fp_inst__DOT__abs))
                                                      ? 0x1cU
                                                      : 
                                                     ((2U 
                                                       == 
                                                       (0x7ffffffeU 
                                                        & vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__int2fp_inst__DOT__abs))
                                                       ? 0x1dU
                                                       : 
                                                      ((1U 
                                                        == 
                                                        (0x7fffffffU 
                                                         & vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__int2fp_inst__DOT__abs))
                                                        ? 0x1eU
                                                        : 0x1fU))))))))));
        vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__int2fp_inst__DOT__mout 
            = (0x7fffffU & (((0x1eU >= (IData)(vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__int2fp_inst__DOT__num_zeros))
                              ? (0x7fffffffU & (vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__int2fp_inst__DOT__abs 
                                                << (IData)(vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__int2fp_inst__DOT__num_zeros)))
                              : 0U) >> 7U));
        vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__int2fp_inst__DOT__sign 
            = (1U & (vlTOPp->Core__DOT__A >> 0x1fU));
        vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__int2fp_inst__DOT__eout 
            = (0xffU & ((IData)(0x9dU) - (IData)(vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__int2fp_inst__DOT__num_zeros)));
    }
    vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__res4 
        = (((IData)(vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__int2fp_inst__DOT__sign) 
            << 0x1fU) | (((IData)(vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__int2fp_inst__DOT__eout) 
                          << 0x17U) | vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__int2fp_inst__DOT__mout));
    vlTOPp->Core__DOT__B = ((0x20U & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie))
                             ? vlTOPp->Core__DOT__imm_pipe_ie
                             : vlTOPp->Core__DOT__fb_out);
    vlTOPp->Core__DOT__A_out = ((1U & ((vlTOPp->Core__DOT__instruction_pipe_id 
                                        >> 6U) & ((vlTOPp->Core__DOT__instruction_pipe_id 
                                                   >> 5U) 
                                                  & ((~ 
                                                      (vlTOPp->Core__DOT__instruction_pipe_id 
                                                       >> 4U)) 
                                                     & ((~ 
                                                         (vlTOPp->Core__DOT__instruction_pipe_id 
                                                          >> 3U)) 
                                                        & ((vlTOPp->Core__DOT__instruction_pipe_id 
                                                            >> 2U) 
                                                           & ((vlTOPp->Core__DOT__instruction_pipe_id 
                                                               >> 1U) 
                                                              & vlTOPp->Core__DOT__instruction_pipe_id)))))))
                                 ? vlTOPp->Core__DOT__rs1_br
                                 : vlTOPp->Core__DOT__pc_out_pipe_id);
    vlTOPp->Core__DOT__BrLT = ((IData)(vlTOPp->Core__DOT__BrUn)
                                ? (vlTOPp->Core__DOT__rs1_br 
                                   < vlTOPp->Core__DOT__rs2_br)
                                : VL_LTS_III(1,32,32, vlTOPp->Core__DOT__rs1_br, vlTOPp->Core__DOT__rs2_br));
    vlTOPp->Core__DOT__BrEq = ((IData)(vlTOPp->Core__DOT__BrUn)
                                ? (vlTOPp->Core__DOT__rs1_br 
                                   == vlTOPp->Core__DOT__rs2_br)
                                : (vlTOPp->Core__DOT__rs1_br 
                                   == vlTOPp->Core__DOT__rs2_br));
    vlTOPp->Core__DOT__alu__DOT__ALUout = (((((((((0U 
                                                   == 
                                                   (0x1fU 
                                                    & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie))) 
                                                  | (1U 
                                                     == 
                                                     (0x1fU 
                                                      & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie)))) 
                                                 | (2U 
                                                    == 
                                                    (0x1fU 
                                                     & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie)))) 
                                                | (3U 
                                                   == 
                                                   (0x1fU 
                                                    & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie)))) 
                                               | (4U 
                                                  == 
                                                  (0x1fU 
                                                   & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie)))) 
                                              | (5U 
                                                 == 
                                                 (0x1fU 
                                                  & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie)))) 
                                             | (6U 
                                                == 
                                                (0x1fU 
                                                 & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie)))) 
                                            | (7U == 
                                               (0x1fU 
                                                & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie))))
                                            ? ((0U 
                                                == 
                                                (0x1fU 
                                                 & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie)))
                                                ? vlTOPp->Core__DOT__A
                                                : (
                                                   (1U 
                                                    == 
                                                    (0x1fU 
                                                     & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie)))
                                                    ? vlTOPp->Core__DOT__B
                                                    : 
                                                   ((2U 
                                                     == 
                                                     (0x1fU 
                                                      & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie)))
                                                     ? 
                                                    (vlTOPp->Core__DOT__A 
                                                     + vlTOPp->Core__DOT__B)
                                                     : 
                                                    ((3U 
                                                      == 
                                                      (0x1fU 
                                                       & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie)))
                                                      ? 
                                                     (vlTOPp->Core__DOT__A 
                                                      - vlTOPp->Core__DOT__B)
                                                      : 
                                                     ((4U 
                                                       == 
                                                       (0x1fU 
                                                        & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie)))
                                                       ? 
                                                      (~ vlTOPp->Core__DOT__A)
                                                       : 
                                                      ((5U 
                                                        == 
                                                        (0x1fU 
                                                         & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie)))
                                                        ? 
                                                       (~ vlTOPp->Core__DOT__B)
                                                        : 
                                                       ((6U 
                                                         == 
                                                         (0x1fU 
                                                          & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie)))
                                                         ? 
                                                        (vlTOPp->Core__DOT__A 
                                                         << 
                                                         (0x1fU 
                                                          & vlTOPp->Core__DOT__B))
                                                         : 
                                                        (vlTOPp->Core__DOT__A 
                                                         >> 
                                                         (0x1fU 
                                                          & vlTOPp->Core__DOT__B)))))))))
                                            : (((((
                                                   ((((8U 
                                                       == 
                                                       (0x1fU 
                                                        & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie))) 
                                                      | (9U 
                                                         == 
                                                         (0x1fU 
                                                          & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie)))) 
                                                     | (0xaU 
                                                        == 
                                                        (0x1fU 
                                                         & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie)))) 
                                                    | (0xbU 
                                                       == 
                                                       (0x1fU 
                                                        & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie)))) 
                                                   | (0xcU 
                                                      == 
                                                      (0x1fU 
                                                       & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie)))) 
                                                  | (0xdU 
                                                     == 
                                                     (0x1fU 
                                                      & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie)))) 
                                                 | (0xeU 
                                                    == 
                                                    (0x1fU 
                                                     & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie)))) 
                                                | (0xfU 
                                                   == 
                                                   (0x1fU 
                                                    & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie))))
                                                ? (
                                                   (8U 
                                                    == 
                                                    (0x1fU 
                                                     & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie)))
                                                    ? 
                                                   (vlTOPp->Core__DOT__A 
                                                    * vlTOPp->Core__DOT__B)
                                                    : 
                                                   ((9U 
                                                     == 
                                                     (0x1fU 
                                                      & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie)))
                                                     ? 
                                                    VL_SHIFTRS_III(32,32,5, vlTOPp->Core__DOT__A, 
                                                                   (0x1fU 
                                                                    & vlTOPp->Core__DOT__B))
                                                     : 
                                                    ((0xaU 
                                                      == 
                                                      (0x1fU 
                                                       & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie)))
                                                      ? 
                                                     (vlTOPp->Core__DOT__A 
                                                      & vlTOPp->Core__DOT__B)
                                                      : 
                                                     ((0xbU 
                                                       == 
                                                       (0x1fU 
                                                        & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie)))
                                                       ? 
                                                      (vlTOPp->Core__DOT__A 
                                                       | vlTOPp->Core__DOT__B)
                                                       : 
                                                      ((0xcU 
                                                        == 
                                                        (0x1fU 
                                                         & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie)))
                                                        ? 
                                                       (vlTOPp->Core__DOT__A 
                                                        ^ vlTOPp->Core__DOT__B)
                                                        : 
                                                       ((0xdU 
                                                         == 
                                                         (0x1fU 
                                                          & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie)))
                                                         ? 
                                                        ((vlTOPp->Core__DOT__A 
                                                          < vlTOPp->Core__DOT__B)
                                                          ? 1U
                                                          : 0U)
                                                         : 
                                                        ((0xeU 
                                                          == 
                                                          (0x1fU 
                                                           & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie)))
                                                          ? 
                                                         (VL_LTS_III(1,32,32, vlTOPp->Core__DOT__A, vlTOPp->Core__DOT__B)
                                                           ? 1U
                                                           : 0U)
                                                          : (IData)(
                                                                    (((((QData)((IData)(
                                                                                VL_NEGATE_I((IData)(
                                                                                (1U 
                                                                                & (vlTOPp->Core__DOT__A 
                                                                                >> 0x1fU)))))) 
                                                                        << 0x20U) 
                                                                       | (QData)((IData)(vlTOPp->Core__DOT__A))) 
                                                                      * 
                                                                      (((QData)((IData)(
                                                                                VL_NEGATE_I((IData)(
                                                                                (1U 
                                                                                & (vlTOPp->Core__DOT__B 
                                                                                >> 0x1fU)))))) 
                                                                        << 0x20U) 
                                                                       | (QData)((IData)(vlTOPp->Core__DOT__B)))) 
                                                                     >> 0x20U)))))))))
                                                : (
                                                   (0x10U 
                                                    == 
                                                    (0x1fU 
                                                     & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie)))
                                                    ? (IData)(
                                                              (((QData)((IData)(vlTOPp->Core__DOT__A)) 
                                                                * (QData)((IData)(vlTOPp->Core__DOT__B))) 
                                                               >> 0x20U))
                                                    : 
                                                   ((0x11U 
                                                     == 
                                                     (0x1fU 
                                                      & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie)))
                                                     ? 
                                                    VL_DIVS_III(32, vlTOPp->Core__DOT__A, vlTOPp->Core__DOT__B)
                                                     : 
                                                    ((0x12U 
                                                      == 
                                                      (0x1fU 
                                                       & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie)))
                                                      ? 
                                                     VL_DIV_III(32, vlTOPp->Core__DOT__A, vlTOPp->Core__DOT__B)
                                                      : 
                                                     ((0x13U 
                                                       == 
                                                       (0x1fU 
                                                        & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie)))
                                                       ? 
                                                      VL_MODDIVS_III(32, vlTOPp->Core__DOT__A, vlTOPp->Core__DOT__B)
                                                       : 
                                                      ((0x14U 
                                                        == 
                                                        (0x1fU 
                                                         & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie)))
                                                        ? 
                                                       VL_MODDIV_III(32, vlTOPp->Core__DOT__A, vlTOPp->Core__DOT__B)
                                                        : 0U)))))));
    vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__multiply_inst__DOT__pre_prod_frac 
        = (VL_ULL(0x3fffffffffff) & ((QData)((IData)(
                                                     (0x400000U 
                                                      | (0x3fffffU 
                                                         & (vlTOPp->Core__DOT__A 
                                                            >> 1U))))) 
                                     * (QData)((IData)(
                                                       (0x400000U 
                                                        | (0x3fffffU 
                                                           & (vlTOPp->Core__DOT__B 
                                                              >> 1U)))))));
    vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__multiply_inst__DOT__pre_prod_exp 
        = (0x1ffU & ((0xffU & (vlTOPp->Core__DOT__A 
                               >> 0x17U)) + (0xffU 
                                             & (vlTOPp->Core__DOT__B 
                                                >> 0x17U))));
    vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__a_exp 
        = (0xffU & (vlTOPp->Core__DOT__A >> 0x17U));
    vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__a_m 
        = (0x800000U | (0x7fffffU & vlTOPp->Core__DOT__A));
    vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__b_exp 
        = (0xffU & (vlTOPp->Core__DOT__B >> 0x17U));
    vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__b_m 
        = (0x800000U | (0x7fffffU & vlTOPp->Core__DOT__B));
    if (((IData)(vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__a_exp) 
         > (IData)(vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__b_exp))) {
        vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__b_m 
            = ((0x1fU >= (0xffU & ((IData)(vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__a_exp) 
                                   - (IData)(vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__b_exp))))
                ? (vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__b_m 
                   >> (0xffU & ((IData)(vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__a_exp) 
                                - (IData)(vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__b_exp))))
                : 0U);
        vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__mag = 0U;
        vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__res3 = 0U;
        vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__b_exp 
            = (0xffU & ((IData)(vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__b_exp) 
                        + ((IData)(vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__a_exp) 
                           - (IData)(vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__b_exp))));
    } else {
        if (((IData)(vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__a_exp) 
             < (IData)(vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__b_exp))) {
            vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__a_m 
                = ((0x1fU >= (0xffU & ((IData)(vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__b_exp) 
                                       - (IData)(vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__a_exp))))
                    ? (vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__a_m 
                       >> (0xffU & ((IData)(vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__b_exp) 
                                    - (IData)(vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__a_exp))))
                    : 0U);
            vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__mag = 1U;
            vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__res3 = 1U;
            vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__a_exp 
                = (0xffU & ((IData)(vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__a_exp) 
                            + ((IData)(vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__b_exp) 
                               - (IData)(vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__a_exp))));
        } else {
            vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__mag = 2U;
            vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__res3 
                = ((vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__a_m 
                    > vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__b_m)
                    ? 0U : ((vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__a_m 
                             < vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__b_m)
                             ? 1U : 2U));
        }
    }
    if (((((1U & (vlTOPp->Core__DOT__A >> 0x1fU)) == 
           (1U & (vlTOPp->Core__DOT__B >> 0x1fU))) 
          & (~ (IData)(vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__add_sub))) 
         | (((1U & (vlTOPp->Core__DOT__A >> 0x1fU)) 
             != (1U & (vlTOPp->Core__DOT__B >> 0x1fU))) 
            & (IData)(vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__add_sub)))) {
        vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__res1 
            = ((0x7fffffffU & vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__res1) 
               | (0x80000000U & vlTOPp->Core__DOT__A));
        vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__r_m 
            = (vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__a_m 
               + vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__b_m);
    } else {
        if (((((1U & (vlTOPp->Core__DOT__A >> 0x1fU)) 
               != (1U & (vlTOPp->Core__DOT__B >> 0x1fU))) 
              & (~ (IData)(vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__add_sub))) 
             | (((1U & (vlTOPp->Core__DOT__A >> 0x1fU)) 
                 == (1U & (vlTOPp->Core__DOT__B >> 0x1fU))) 
                & (IData)(vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__add_sub)))) {
            if ((0U == (IData)(vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__mag))) {
                vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__r_m 
                    = (vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__a_m 
                       - vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__b_m);
                vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__res1 
                    = ((0x7fffffffU & vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__res1) 
                       | (0x80000000U & (((~ (IData)(vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__add_sub)) 
                                          << 0x1fU) 
                                         & vlTOPp->Core__DOT__A)));
            } else {
                if ((1U == (IData)(vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__mag))) {
                    vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__r_m 
                        = (vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__b_m 
                           - vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__a_m);
                    vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__res1 
                        = ((0x7fffffffU & vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__res1) 
                           | (0x80000000U & (((IData)(vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__add_sub)
                                               ? (~ 
                                                  (vlTOPp->Core__DOT__B 
                                                   >> 0x1fU))
                                               : (vlTOPp->Core__DOT__B 
                                                  >> 0x1fU)) 
                                             << 0x1fU)));
                } else {
                    if ((2U == (IData)(vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__mag))) {
                        if ((vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__a_m 
                             >= vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__b_m)) {
                            vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__r_m 
                                = (vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__a_m 
                                   - vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__b_m);
                            vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__res1 
                                = ((0x7fffffffU & vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__res1) 
                                   | (0x80000000U & 
                                      (((~ (IData)(vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__add_sub)) 
                                        << 0x1fU) & vlTOPp->Core__DOT__A)));
                        } else {
                            if ((vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__a_m 
                                 < vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__b_m)) {
                                vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__r_m 
                                    = (vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__b_m 
                                       - vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__a_m);
                                vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__res1 
                                    = ((0x7fffffffU 
                                        & vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__res1) 
                                       | (0x80000000U 
                                          & (((IData)(vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__add_sub)
                                               ? (~ 
                                                  (vlTOPp->Core__DOT__B 
                                                   >> 0x1fU))
                                               : (vlTOPp->Core__DOT__B 
                                                  >> 0x1fU)) 
                                             << 0x1fU)));
                            } else {
                                vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__r_m 
                                    = (vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__b_m 
                                       - vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__a_m);
                                vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__res1 
                                    = (0x7fffffffU 
                                       & vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__res1);
                            }
                        }
                    } else {
                        vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__r_m 
                            = (vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__b_m 
                               - vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__a_m);
                        vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__res1 
                            = (0x7fffffffU & vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__res1);
                    }
                }
            }
        } else {
            vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__r_m 
                = (vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__b_m 
                   - vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__a_m);
            vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__res1 
                = (0x7fffffffU & vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__res1);
        }
    }
    vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__state = 1U;
    vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__i = 0x1fU;
    while (vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__state) {
        if ((1U & ((vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__r_m 
                    >> (0x1fU & vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__i)) 
                   | (0U == vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__i)))) {
            vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__state = 0U;
        }
        vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__i 
            = (vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__i 
               - (IData)(1U));
    }
    vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__r_exp 
        = (0xffU & (((IData)(vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__a_exp) 
                     + vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__i) 
                    - (IData)(0x16U)));
    vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__prm 
        = (VL_LTS_III(1,32,32, 0U, (vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__i 
                                    - (IData)(0x16U)))
            ? ((0x1fU >= (vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__i 
                          - (IData)(0x16U))) ? (vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__r_m 
                                                >> 
                                                (vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__i 
                                                 - (IData)(0x16U)))
                : 0U) : (VL_GTS_III(1,32,32, 0U, (vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__i 
                                                  - (IData)(0x16U)))
                          ? ((0x1fU >= ((IData)(0x16U) 
                                        - vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__i))
                              ? (vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__r_m 
                                 << ((IData)(0x16U) 
                                     - vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__i))
                              : 0U) : vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__r_m));
    vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__res1 
        = ((0x807fffffU & vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__res1) 
           | ((IData)(vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__r_exp) 
              << 0x17U));
    vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__res1 
        = ((0xff800000U & vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__res1) 
           | (0x7fffffU & vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__prm));
    vlTOPp->Core__DOT__pcALU_inst__DOT__alu = ((1U 
                                                & ((vlTOPp->Core__DOT__instruction_pipe_id 
                                                    >> 6U) 
                                                   & ((vlTOPp->Core__DOT__instruction_pipe_id 
                                                       >> 5U) 
                                                      & ((~ 
                                                          (vlTOPp->Core__DOT__instruction_pipe_id 
                                                           >> 4U)) 
                                                         & ((~ 
                                                             (vlTOPp->Core__DOT__instruction_pipe_id 
                                                              >> 3U)) 
                                                            & ((vlTOPp->Core__DOT__instruction_pipe_id 
                                                                >> 2U) 
                                                               & ((vlTOPp->Core__DOT__instruction_pipe_id 
                                                                   >> 1U) 
                                                                  & vlTOPp->Core__DOT__instruction_pipe_id)))))))
                                                ? (vlTOPp->Core__DOT__A_out 
                                                   + vlTOPp->Core__DOT__imm)
                                                : (vlTOPp->Core__DOT__A_out 
                                                   + 
                                                   (vlTOPp->Core__DOT__imm 
                                                    << 1U)));
    vlTOPp->Core__DOT__pc_sel = (1U & ((vlTOPp->Core__DOT__instruction_pipe_id 
                                        >> 6U) & ((vlTOPp->Core__DOT__instruction_pipe_id 
                                                   >> 5U) 
                                                  & ((~ 
                                                      (vlTOPp->Core__DOT__instruction_pipe_id 
                                                       >> 4U)) 
                                                     & ((8U 
                                                         & vlTOPp->Core__DOT__instruction_pipe_id)
                                                         ? 
                                                        ((vlTOPp->Core__DOT__instruction_pipe_id 
                                                          >> 2U) 
                                                         & ((vlTOPp->Core__DOT__instruction_pipe_id 
                                                             >> 1U) 
                                                            & vlTOPp->Core__DOT__instruction_pipe_id))
                                                         : 
                                                        ((4U 
                                                          & vlTOPp->Core__DOT__instruction_pipe_id)
                                                          ? 
                                                         ((vlTOPp->Core__DOT__instruction_pipe_id 
                                                           >> 1U) 
                                                          & vlTOPp->Core__DOT__instruction_pipe_id)
                                                          : 
                                                         ((vlTOPp->Core__DOT__instruction_pipe_id 
                                                           >> 1U) 
                                                          & (vlTOPp->Core__DOT__instruction_pipe_id 
                                                             & ((0x4000U 
                                                                 & vlTOPp->Core__DOT__instruction_pipe_id)
                                                                 ? 
                                                                ((0x2000U 
                                                                  & vlTOPp->Core__DOT__instruction_pipe_id)
                                                                  ? 
                                                                 ((0x1000U 
                                                                   & vlTOPp->Core__DOT__instruction_pipe_id)
                                                                   ? 
                                                                  (~ (IData)(vlTOPp->Core__DOT__BrLT))
                                                                   : (IData)(vlTOPp->Core__DOT__BrLT))
                                                                  : 
                                                                 ((0x1000U 
                                                                   & vlTOPp->Core__DOT__instruction_pipe_id)
                                                                   ? 
                                                                  (~ (IData)(vlTOPp->Core__DOT__BrLT))
                                                                   : (IData)(vlTOPp->Core__DOT__BrLT)))
                                                                 : 
                                                                ((0x2000U 
                                                                  & vlTOPp->Core__DOT__instruction_pipe_id)
                                                                  ? (IData)(vlTOPp->Core__DOT__BrEq)
                                                                  : 
                                                                 ((0x1000U 
                                                                   & vlTOPp->Core__DOT__instruction_pipe_id)
                                                                   ? 
                                                                  (~ (IData)(vlTOPp->Core__DOT__BrEq))
                                                                   : (IData)(vlTOPp->Core__DOT__BrEq))))))))))));
    vlTOPp->Core__DOT__alu__DOT__fpuout = (((((((((0U 
                                                   == 
                                                   (0x1fU 
                                                    & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie))) 
                                                  | (1U 
                                                     == 
                                                     (0x1fU 
                                                      & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie)))) 
                                                 | (2U 
                                                    == 
                                                    (0x1fU 
                                                     & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie)))) 
                                                | (3U 
                                                   == 
                                                   (0x1fU 
                                                    & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie)))) 
                                               | (4U 
                                                  == 
                                                  (0x1fU 
                                                   & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie)))) 
                                              | (5U 
                                                 == 
                                                 (0x1fU 
                                                  & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie)))) 
                                             | (6U 
                                                == 
                                                (0x1fU 
                                                 & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie)))) 
                                            | (7U == 
                                               (0x1fU 
                                                & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie))))
                                            ? ((0U 
                                                == 
                                                (0x1fU 
                                                 & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie)))
                                                ? vlTOPp->Core__DOT__A
                                                : (
                                                   (1U 
                                                    == 
                                                    (0x1fU 
                                                     & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie)))
                                                    ? vlTOPp->Core__DOT__B
                                                    : 
                                                   ((2U 
                                                     == 
                                                     (0x1fU 
                                                      & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie)))
                                                     ? 
                                                    ((0x80000000U 
                                                      & ((~ 
                                                          (vlTOPp->Core__DOT__A 
                                                           >> 0x1fU)) 
                                                         << 0x1fU)) 
                                                     | (0x7fffffffU 
                                                        & vlTOPp->Core__DOT__A))
                                                     : 
                                                    ((3U 
                                                      == 
                                                      (0x1fU 
                                                       & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie)))
                                                      ? 
                                                     ((0x80000000U 
                                                       & ((~ 
                                                           (vlTOPp->Core__DOT__B 
                                                            >> 0x1fU)) 
                                                          << 0x1fU)) 
                                                      | (0x7fffffffU 
                                                         & vlTOPp->Core__DOT__B))
                                                      : 
                                                     ((4U 
                                                       == 
                                                       (0x1fU 
                                                        & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie)))
                                                       ? vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__res1
                                                       : 
                                                      ((5U 
                                                        == 
                                                        (0x1fU 
                                                         & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie)))
                                                        ? vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__res1
                                                        : 
                                                       ((6U 
                                                         == 
                                                         (0x1fU 
                                                          & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie)))
                                                         ? 
                                                        ((0x80U 
                                                          > (IData)(vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__multiply_inst__DOT__pre_prod_exp))
                                                          ? 0U
                                                          : 
                                                         ((0U 
                                                           == 
                                                           (0xffU 
                                                            & (vlTOPp->Core__DOT__B 
                                                               >> 0x17U)))
                                                           ? 0U
                                                           : 
                                                          ((0U 
                                                            == 
                                                            (0xffU 
                                                             & (vlTOPp->Core__DOT__A 
                                                                >> 0x17U)))
                                                            ? 0U
                                                            : 
                                                           ((0x80000000U 
                                                             & (vlTOPp->Core__DOT__A 
                                                                ^ vlTOPp->Core__DOT__B)) 
                                                            | ((0x7f800000U 
                                                                & (((1U 
                                                                     & (IData)(
                                                                               (vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__multiply_inst__DOT__pre_prod_frac 
                                                                                >> 0x2dU)))
                                                                     ? 
                                                                    ((IData)(vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__multiply_inst__DOT__pre_prod_exp) 
                                                                     - (IData)(0x7eU))
                                                                     : 
                                                                    ((IData)(vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__multiply_inst__DOT__pre_prod_exp) 
                                                                     - (IData)(0x7fU))) 
                                                                   << 0x17U)) 
                                                               | (0x7fffffU 
                                                                  & ((1U 
                                                                      & (IData)(
                                                                                (vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__multiply_inst__DOT__pre_prod_frac 
                                                                                >> 0x2dU)))
                                                                      ? (IData)(
                                                                                (vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__multiply_inst__DOT__pre_prod_frac 
                                                                                >> 0x16U))
                                                                      : (IData)(
                                                                                (vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__multiply_inst__DOT__pre_prod_frac 
                                                                                >> 0x15U)))))))))
                                                         : 
                                                        ((1U 
                                                          == (IData)(vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__res3))
                                                          ? vlTOPp->Core__DOT__A
                                                          : vlTOPp->Core__DOT__B))))))))
                                            : (((((
                                                   ((((8U 
                                                       == 
                                                       (0x1fU 
                                                        & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie))) 
                                                      | (9U 
                                                         == 
                                                         (0x1fU 
                                                          & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie)))) 
                                                     | (0xaU 
                                                        == 
                                                        (0x1fU 
                                                         & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie)))) 
                                                    | (0xbU 
                                                       == 
                                                       (0x1fU 
                                                        & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie)))) 
                                                   | (0xcU 
                                                      == 
                                                      (0x1fU 
                                                       & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie)))) 
                                                  | (0xdU 
                                                     == 
                                                     (0x1fU 
                                                      & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie)))) 
                                                 | (0xeU 
                                                    == 
                                                    (0x1fU 
                                                     & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie)))) 
                                                | (0xfU 
                                                   == 
                                                   (0x1fU 
                                                    & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie))))
                                                ? (
                                                   (8U 
                                                    == 
                                                    (0x1fU 
                                                     & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie)))
                                                    ? 
                                                   ((0U 
                                                     == (IData)(vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__res3))
                                                     ? vlTOPp->Core__DOT__A
                                                     : vlTOPp->Core__DOT__B)
                                                    : 
                                                   ((9U 
                                                     == 
                                                     (0x1fU 
                                                      & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie)))
                                                     ? 
                                                    ((2U 
                                                      == (IData)(vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__res3))
                                                      ? 1U
                                                      : 0U)
                                                     : 
                                                    ((0xaU 
                                                      == 
                                                      (0x1fU 
                                                       & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie)))
                                                      ? 
                                                     ((1U 
                                                       == (IData)(vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__res3))
                                                       ? 1U
                                                       : 0U)
                                                      : 
                                                     ((0xbU 
                                                       == 
                                                       (0x1fU 
                                                        & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie)))
                                                       ? 
                                                      (((1U 
                                                         == (IData)(vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__res3)) 
                                                        | (2U 
                                                           == (IData)(vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__res3)))
                                                        ? 1U
                                                        : 0U)
                                                       : 
                                                      ((0xcU 
                                                        == 
                                                        (0x1fU 
                                                         & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie)))
                                                        ? vlTOPp->Core__DOT__A
                                                        : 
                                                       ((0xdU 
                                                         == 
                                                         (0x1fU 
                                                          & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie)))
                                                         ? vlTOPp->Core__DOT__A
                                                         : 
                                                        ((0xeU 
                                                          == 
                                                          (0x1fU 
                                                           & (IData)(vlTOPp->Core__DOT__aluop_pipe_ie)))
                                                          ? vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__res4
                                                          : 
                                                         ((0x80000000U 
                                                           & vlTOPp->Core__DOT__A)
                                                           ? 
                                                          ((IData)(1U) 
                                                           + 
                                                           (~ vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__fp2int_inst__DOT__abs_int))
                                                           : vlTOPp->Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__fp2int_inst__DOT__abs_int))))))))
                                                : 0U));
    vlTOPp->inst_addr = ((IData)(vlTOPp->Core__DOT__pc_sel)
                          ? vlTOPp->Core__DOT__pcALU_inst__DOT__alu
                          : vlTOPp->Core__DOT__pc_out);
    vlTOPp->Core__DOT__pc_in = ((IData)(vlTOPp->Core__DOT__pc_sel)
                                 ? ((IData)(4U) + vlTOPp->Core__DOT__pcALU_inst__DOT__alu)
                                 : ((IData)(4U) + vlTOPp->Core__DOT__pc_out));
}

void VCore::_eval(VCore__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCore::_eval\n"); );
    VCore* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((~ (IData)(vlTOPp->clk)) & (IData)(vlTOPp->__Vclklast__TOP__clk))) {
        vlTOPp->_sequent__TOP__2(vlSymsp);
    }
    vlTOPp->_combo__TOP__4(vlSymsp);
    if (((IData)(vlTOPp->Core__DOT__clk1) & (~ (IData)(vlTOPp->__Vclklast__TOP__Core__DOT__clk1)))) {
        vlTOPp->_sequent__TOP__5(vlSymsp);
    }
    vlTOPp->_combo__TOP__6(vlSymsp);
    // Final
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
    vlTOPp->__Vclklast__TOP__Core__DOT__clk1 = vlTOPp->Core__DOT__clk1;
}

void VCore::_eval_initial(VCore__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCore::_eval_initial\n"); );
    VCore* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_initial__TOP__1(vlSymsp);
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
    vlTOPp->__Vclklast__TOP__Core__DOT__clk1 = vlTOPp->Core__DOT__clk1;
}

void VCore::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCore::final\n"); );
    // Variables
    VCore__Syms* __restrict vlSymsp = this->__VlSymsp;
    VCore* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void VCore::_eval_settle(VCore__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCore::_eval_settle\n"); );
    VCore* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__3(vlSymsp);
}

VL_INLINE_OPT QData VCore::_change_request(VCore__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCore::_change_request\n"); );
    VCore* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void VCore::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCore::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((reset & 0xfeU))) {
        Verilated::overWidthError("reset");}
    if (VL_UNLIKELY((avl_waitrequest & 0xfeU))) {
        Verilated::overWidthError("avl_waitrequest");}
}
#endif  // VL_DEBUG

void VCore::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCore::_ctor_var_reset\n"); );
    // Body
    clk = VL_RAND_RESET_I(1);
    reset = VL_RAND_RESET_I(1);
    inst_data = VL_RAND_RESET_I(32);
    inst_addr = VL_RAND_RESET_I(32);
    inst_stall = VL_RAND_RESET_I(1);
    avl_readdata = VL_RAND_RESET_I(32);
    avl_waitrequest = VL_RAND_RESET_I(1);
    avl_address = VL_RAND_RESET_I(32);
    avl_writedata = VL_RAND_RESET_I(32);
    avl_byteenable = VL_RAND_RESET_I(4);
    avl_read = VL_RAND_RESET_I(1);
    avl_write = VL_RAND_RESET_I(1);
    Core__DOT__pc_in = VL_RAND_RESET_I(32);
    Core__DOT__pc_out = VL_RAND_RESET_I(32);
    Core__DOT__pc_sel = VL_RAND_RESET_I(1);
    Core__DOT__RegWEn = VL_RAND_RESET_I(1);
    Core__DOT__rd = VL_RAND_RESET_I(32);
    Core__DOT__rs1_br = VL_RAND_RESET_I(32);
    Core__DOT__rs2_br = VL_RAND_RESET_I(32);
    Core__DOT__fb_out = VL_RAND_RESET_I(32);
    Core__DOT__A = VL_RAND_RESET_I(32);
    Core__DOT__B = VL_RAND_RESET_I(32);
    Core__DOT__imm = VL_RAND_RESET_I(32);
    Core__DOT__A_out = VL_RAND_RESET_I(32);
    Core__DOT__immsel = VL_RAND_RESET_I(3);
    Core__DOT__Bsel = VL_RAND_RESET_I(1);
    Core__DOT__ALUsel = VL_RAND_RESET_I(5);
    Core__DOT__wbSel = VL_RAND_RESET_I(2);
    Core__DOT__BrUn = VL_RAND_RESET_I(1);
    Core__DOT__BrEq = VL_RAND_RESET_I(1);
    Core__DOT__BrLT = VL_RAND_RESET_I(1);
    Core__DOT__instruction_pipe_id = VL_RAND_RESET_I(32);
    Core__DOT__pc_out_pipe_id = VL_RAND_RESET_I(32);
    Core__DOT__memWrite_pipe_ie = VL_RAND_RESET_I(2);
    Core__DOT__wbsel_pipe_ie = VL_RAND_RESET_I(3);
    Core__DOT__aluop_pipe_ie = VL_RAND_RESET_I(7);
    Core__DOT__pc_out_pipe_ie = VL_RAND_RESET_I(32);
    Core__DOT__rs1_pipe_ie = VL_RAND_RESET_I(32);
    Core__DOT__rs2_pipe_ie = VL_RAND_RESET_I(32);
    Core__DOT__imm_pipe_ie = VL_RAND_RESET_I(32);
    Core__DOT__rdadd_pipe_ie = VL_RAND_RESET_I(5);
    Core__DOT__rs1add_pipe_ie = VL_RAND_RESET_I(5);
    Core__DOT__rs2add_pipe_ie = VL_RAND_RESET_I(5);
    Core__DOT__memWrite_pipe_imem = VL_RAND_RESET_I(2);
    Core__DOT__wbsel_pipe_imem = VL_RAND_RESET_I(3);
    Core__DOT__rs2_pipe_imem = VL_RAND_RESET_I(32);
    Core__DOT__aluout_pipe_imem = VL_RAND_RESET_I(32);
    Core__DOT__pc_out_pipe_imem = VL_RAND_RESET_I(32);
    Core__DOT__rdadd_pipe_imem = VL_RAND_RESET_I(5);
    Core__DOT__mode_ie = VL_RAND_RESET_I(3);
    Core__DOT__mode_imem = VL_RAND_RESET_I(3);
    Core__DOT__float_write = VL_RAND_RESET_I(1);
    Core__DOT__fpu_imem = VL_RAND_RESET_I(1);
    Core__DOT__float_read = VL_RAND_RESET_I(2);
    Core__DOT__fpu_ie = VL_RAND_RESET_I(4);
    Core__DOT__clk1 = VL_RAND_RESET_I(1);
    Core__DOT__stall_core = VL_RAND_RESET_I(1);
    Core__DOT__reset_ie = VL_RAND_RESET_I(1);
    Core__DOT__br_stall = VL_RAND_RESET_I(1);
    Core__DOT__enable = VL_RAND_RESET_I(1);
    { int __Vi0=0; for (; __Vi0<32; ++__Vi0) {
            Core__DOT__regfile__DOT__regfile[__Vi0] = VL_RAND_RESET_I(32);
    }}
    Core__DOT__pcALU_inst__DOT__alu = VL_RAND_RESET_I(32);
    Core__DOT__alu__DOT__fpuout = VL_RAND_RESET_I(32);
    Core__DOT__alu__DOT__ALUout = VL_RAND_RESET_I(32);
    Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__res1 = VL_RAND_RESET_I(32);
    Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__res3 = VL_RAND_RESET_I(2);
    Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__res4 = VL_RAND_RESET_I(32);
    Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__add_sub = VL_RAND_RESET_I(1);
    Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__a_exp = VL_RAND_RESET_I(8);
    Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__b_exp = VL_RAND_RESET_I(8);
    Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__r_exp = VL_RAND_RESET_I(8);
    Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__a_m = VL_RAND_RESET_I(32);
    Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__b_m = VL_RAND_RESET_I(32);
    Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__r_m = VL_RAND_RESET_I(32);
    Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__prm = VL_RAND_RESET_I(32);
    Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__mag = VL_RAND_RESET_I(2);
    Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__i = VL_RAND_RESET_I(32);
    Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__adder_inst__DOT__state = VL_RAND_RESET_I(1);
    Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__multiply_inst__DOT__pre_prod_frac = VL_RAND_RESET_Q(46);
    Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__multiply_inst__DOT__pre_prod_exp = VL_RAND_RESET_I(9);
    Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__fp2int_inst__DOT__abs_int = VL_RAND_RESET_I(32);
    Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__int2fp_inst__DOT__abs = VL_RAND_RESET_I(32);
    Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__int2fp_inst__DOT__sign = VL_RAND_RESET_I(1);
    Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__int2fp_inst__DOT__mout = VL_RAND_RESET_I(23);
    Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__int2fp_inst__DOT__eout = VL_RAND_RESET_I(8);
    Core__DOT__alu__DOT__genblk1__DOT__FPU_inst__DOT__int2fp_inst__DOT__num_zeros = VL_RAND_RESET_I(8);
    Core__DOT__core2avl_inst__DOT__byt = VL_RAND_RESET_I(2);
    Core__DOT__core2avl_inst__DOT__be = VL_RAND_RESET_I(4);
    Core__DOT__core2avl_inst__DOT__q1 = VL_RAND_RESET_I(32);
    { int __Vi0=0; for (; __Vi0<32; ++__Vi0) {
            Core__DOT__genblk1__DOT__regfile_float__DOT__regfile[__Vi0] = VL_RAND_RESET_I(32);
    }}
    __Vtableidx1 = 0;
    __Vtable1_Core__DOT__core2avl_inst__DOT__be[0] = 1U;
    __Vtable1_Core__DOT__core2avl_inst__DOT__be[1] = 3U;
    __Vtable1_Core__DOT__core2avl_inst__DOT__be[2] = 0xfU;
    __Vtable1_Core__DOT__core2avl_inst__DOT__be[3] = 0U;
    __Vtable1_Core__DOT__core2avl_inst__DOT__be[4] = 1U;
    __Vtable1_Core__DOT__core2avl_inst__DOT__be[5] = 3U;
    __Vtable1_Core__DOT__core2avl_inst__DOT__be[6] = 0xfU;
    __Vtable1_Core__DOT__core2avl_inst__DOT__be[7] = 0U;
    __Vtable1_Core__DOT__core2avl_inst__DOT__be[8] = 2U;
    __Vtable1_Core__DOT__core2avl_inst__DOT__be[9] = 6U;
    __Vtable1_Core__DOT__core2avl_inst__DOT__be[10] = 0xfU;
    __Vtable1_Core__DOT__core2avl_inst__DOT__be[11] = 0U;
    __Vtable1_Core__DOT__core2avl_inst__DOT__be[12] = 2U;
    __Vtable1_Core__DOT__core2avl_inst__DOT__be[13] = 6U;
    __Vtable1_Core__DOT__core2avl_inst__DOT__be[14] = 0xfU;
    __Vtable1_Core__DOT__core2avl_inst__DOT__be[15] = 0U;
    __Vtable1_Core__DOT__core2avl_inst__DOT__be[16] = 4U;
    __Vtable1_Core__DOT__core2avl_inst__DOT__be[17] = 0xcU;
    __Vtable1_Core__DOT__core2avl_inst__DOT__be[18] = 0xfU;
    __Vtable1_Core__DOT__core2avl_inst__DOT__be[19] = 0U;
    __Vtable1_Core__DOT__core2avl_inst__DOT__be[20] = 4U;
    __Vtable1_Core__DOT__core2avl_inst__DOT__be[21] = 0xcU;
    __Vtable1_Core__DOT__core2avl_inst__DOT__be[22] = 0xfU;
    __Vtable1_Core__DOT__core2avl_inst__DOT__be[23] = 0U;
    __Vtable1_Core__DOT__core2avl_inst__DOT__be[24] = 8U;
    __Vtable1_Core__DOT__core2avl_inst__DOT__be[25] = 0U;
    __Vtable1_Core__DOT__core2avl_inst__DOT__be[26] = 0xfU;
    __Vtable1_Core__DOT__core2avl_inst__DOT__be[27] = 0U;
    __Vtable1_Core__DOT__core2avl_inst__DOT__be[28] = 8U;
    __Vtable1_Core__DOT__core2avl_inst__DOT__be[29] = 0U;
    __Vtable1_Core__DOT__core2avl_inst__DOT__be[30] = 0xfU;
    __Vtable1_Core__DOT__core2avl_inst__DOT__be[31] = 0U;
}
