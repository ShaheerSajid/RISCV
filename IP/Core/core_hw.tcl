# TCL File Generated by Component Editor 18.1
# Fri Dec 04 19:30:49 PKT 2020
# DO NOT MODIFY


# 
# core "core" v1.0
#  2020.12.04.19:30:49
# 
# 

# 
# request TCL package from ACDS 16.1
# 
package require -exact qsys 16.1


# 
# module core
# 
set_module_property DESCRIPTION ""
set_module_property NAME core
set_module_property VERSION 1.0
set_module_property INTERNAL false
set_module_property OPAQUE_ADDRESS_MAP true
set_module_property AUTHOR ""
set_module_property DISPLAY_NAME core
set_module_property INSTANTIATE_IN_SYSTEM_MODULE true
set_module_property EDITABLE true
set_module_property REPORT_TO_TALKBACK false
set_module_property ALLOW_GREYBOX_GENERATION false
set_module_property REPORT_HIERARCHY false


# 
# file sets
# 
add_fileset QUARTUS_SYNTH QUARTUS_SYNTH "" ""
set_fileset_property QUARTUS_SYNTH TOP_LEVEL Core
set_fileset_property QUARTUS_SYNTH ENABLE_RELATIVE_INCLUDE_PATHS false
set_fileset_property QUARTUS_SYNTH ENABLE_FILE_OVERWRITE_MODE false
add_fileset_file ALU.v VERILOG PATH ALU.v
add_fileset_file Branch_comp.v VERILOG PATH Branch_comp.v
add_fileset_file Control_Path.v VERILOG PATH Control_Path.v
add_fileset_file Core.v VERILOG PATH Core.v TOP_LEVEL_FILE
add_fileset_file FPU.v VERILOG PATH FPU.v
add_fileset_file IMM_gen.v VERILOG PATH IMM_gen.v
add_fileset_file Program_Counter.v VERILOG PATH Program_Counter.v
add_fileset_file REG_FILE.v VERILOG PATH REG_FILE.v
add_fileset_file core2avl.v VERILOG PATH core2avl.v
add_fileset_file forward_mem.v VERILOG PATH forward_mem.v
add_fileset_file forwarding_br.v VERILOG PATH forwarding_br.v
add_fileset_file mux2to1.v VERILOG PATH mux2to1.v
add_fileset_file mux5to1.v VERILOG PATH mux5to1.v
add_fileset_file pcALU.v VERILOG PATH pcALU.v
add_fileset_file reg.v VERILOG PATH reg.v
add_fileset_file regfile.txt OTHER PATH regfile.txt
add_fileset_file register_stall.v VERILOG PATH register_stall.v
add_fileset_file stall_line.v VERILOG PATH stall_line.v


# 
# parameters
# 
add_parameter M_Extension BOOLEAN false "Enable M extension"
set_parameter_property M_Extension DEFAULT_VALUE false
set_parameter_property M_Extension DISPLAY_NAME M_Extension
set_parameter_property M_Extension WIDTH ""
set_parameter_property M_Extension TYPE BOOLEAN
set_parameter_property M_Extension UNITS None
set_parameter_property M_Extension DESCRIPTION "Enable M extension"
set_parameter_property M_Extension HDL_PARAMETER true
add_parameter M_Extension_DIV BOOLEAN false "Enable single cycle division module"
set_parameter_property M_Extension_DIV DEFAULT_VALUE false
set_parameter_property M_Extension_DIV DISPLAY_NAME M_Extension_DIV
set_parameter_property M_Extension_DIV WIDTH ""
set_parameter_property M_Extension_DIV TYPE BOOLEAN
set_parameter_property M_Extension_DIV UNITS None
set_parameter_property M_Extension_DIV DESCRIPTION "Enable single cycle division module"
set_parameter_property M_Extension_DIV HDL_PARAMETER true
add_parameter F_Extension BOOLEAN false "Enable F extension. There is no floating divide"
set_parameter_property F_Extension DEFAULT_VALUE false
set_parameter_property F_Extension DISPLAY_NAME F_Extension
set_parameter_property F_Extension WIDTH ""
set_parameter_property F_Extension TYPE BOOLEAN
set_parameter_property F_Extension UNITS None
set_parameter_property F_Extension DESCRIPTION "Enable F extension. There is no floating divide"
set_parameter_property F_Extension HDL_PARAMETER true


# 
# display items
# 
add_display_item "" Multiply GROUP ""
add_display_item "" Floating GROUP ""
add_display_item Multiply M_Extension PARAMETER ""
add_display_item Multiply M_Extension_DIV PARAMETER ""
add_display_item Float F_Extension PARAMETER ""


# 
# connection point clock
# 
add_interface clock clock end
set_interface_property clock clockRate 0
set_interface_property clock ENABLED true
set_interface_property clock EXPORT_OF ""
set_interface_property clock PORT_NAME_MAP ""
set_interface_property clock CMSIS_SVD_VARIABLES ""
set_interface_property clock SVD_ADDRESS_GROUP ""

add_interface_port clock clk clk Input 1


# 
# connection point reset
# 
add_interface reset reset end
set_interface_property reset associatedClock clock
set_interface_property reset synchronousEdges DEASSERT
set_interface_property reset ENABLED true
set_interface_property reset EXPORT_OF ""
set_interface_property reset PORT_NAME_MAP ""
set_interface_property reset CMSIS_SVD_VARIABLES ""
set_interface_property reset SVD_ADDRESS_GROUP ""

add_interface_port reset reset reset Input 1


# 
# connection point Data_Master
# 
add_interface Data_Master avalon start
set_interface_property Data_Master addressUnits SYMBOLS
set_interface_property Data_Master associatedClock clock
set_interface_property Data_Master associatedReset reset
set_interface_property Data_Master bitsPerSymbol 8
set_interface_property Data_Master burstOnBurstBoundariesOnly false
set_interface_property Data_Master burstcountUnits WORDS
set_interface_property Data_Master doStreamReads false
set_interface_property Data_Master doStreamWrites false
set_interface_property Data_Master holdTime 0
set_interface_property Data_Master linewrapBursts false
set_interface_property Data_Master maximumPendingReadTransactions 0
set_interface_property Data_Master maximumPendingWriteTransactions 0
set_interface_property Data_Master readLatency 0
set_interface_property Data_Master readWaitTime 1
set_interface_property Data_Master setupTime 0
set_interface_property Data_Master timingUnits Cycles
set_interface_property Data_Master writeWaitTime 0
set_interface_property Data_Master ENABLED true
set_interface_property Data_Master EXPORT_OF ""
set_interface_property Data_Master PORT_NAME_MAP ""
set_interface_property Data_Master CMSIS_SVD_VARIABLES ""
set_interface_property Data_Master SVD_ADDRESS_GROUP ""

add_interface_port Data_Master avl_address address Output 32
add_interface_port Data_Master avl_byteenable byteenable Output 4
add_interface_port Data_Master avl_read read Output 1
add_interface_port Data_Master avl_readdata readdata Input 32
add_interface_port Data_Master avl_waitrequest waitrequest Input 1
add_interface_port Data_Master avl_write write Output 1
add_interface_port Data_Master avl_writedata writedata Output 32


# 
# connection point conduit_end
# 
add_interface conduit_end conduit end
set_interface_property conduit_end associatedClock ""
set_interface_property conduit_end associatedReset ""
set_interface_property conduit_end ENABLED true
set_interface_property conduit_end EXPORT_OF ""
set_interface_property conduit_end PORT_NAME_MAP ""
set_interface_property conduit_end CMSIS_SVD_VARIABLES ""
set_interface_property conduit_end SVD_ADDRESS_GROUP ""

add_interface_port conduit_end inst_addr addr Output 32
add_interface_port conduit_end inst_data data Input 32
add_interface_port conduit_end inst_stall stall Output 1
