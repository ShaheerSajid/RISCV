# TCL File Generated by Component Editor 18.1
# Tue Nov 03 22:39:28 PKT 2020
# DO NOT MODIFY


# 
# uart "uart" v1.0
#  2020.11.03.22:39:28
# 
# 

# 
# request TCL package from ACDS 16.1
# 
package require -exact qsys 16.1


# 
# module uart
# 
set_module_property DESCRIPTION ""
set_module_property NAME uart
set_module_property VERSION 1.0
set_module_property INTERNAL false
set_module_property OPAQUE_ADDRESS_MAP true
set_module_property AUTHOR ""
set_module_property DISPLAY_NAME uart
set_module_property INSTANTIATE_IN_SYSTEM_MODULE true
set_module_property EDITABLE true
set_module_property REPORT_TO_TALKBACK false
set_module_property ALLOW_GREYBOX_GENERATION false
set_module_property REPORT_HIERARCHY false


# 
# file sets
# 
add_fileset QUARTUS_SYNTH QUARTUS_SYNTH "" ""
set_fileset_property QUARTUS_SYNTH TOP_LEVEL uart_ip_avalon_interface
set_fileset_property QUARTUS_SYNTH ENABLE_RELATIVE_INCLUDE_PATHS false
set_fileset_property QUARTUS_SYNTH ENABLE_FILE_OVERWRITE_MODE false
add_fileset_file uart_ip.vhd VHDL PATH ../../../../../uart/uart_ip.vhd
add_fileset_file uart_ip_avalon_interface.v VERILOG PATH ../../../../../uart/uart_ip_avalon_interface.v TOP_LEVEL_FILE
add_fileset_file uart_ip_verilog_wrapper.v VERILOG PATH ../../../../../uart/uart_ip_verilog_wrapper.v
add_fileset_file uart_rx.vhd VHDL PATH ../../../../../uart/uart_rx.vhd
add_fileset_file uart_tx.vhd VHDL PATH ../../../../../uart/uart_tx.vhd


# 
# parameters
# 


# 
# display items
# 


# 
# connection point avalon_slave_0
# 
add_interface avalon_slave_0 avalon end
set_interface_property avalon_slave_0 addressUnits WORDS
set_interface_property avalon_slave_0 associatedClock clock
set_interface_property avalon_slave_0 associatedReset reset
set_interface_property avalon_slave_0 bitsPerSymbol 8
set_interface_property avalon_slave_0 burstOnBurstBoundariesOnly false
set_interface_property avalon_slave_0 burstcountUnits WORDS
set_interface_property avalon_slave_0 explicitAddressSpan 0
set_interface_property avalon_slave_0 holdTime 0
set_interface_property avalon_slave_0 linewrapBursts false
set_interface_property avalon_slave_0 maximumPendingReadTransactions 0
set_interface_property avalon_slave_0 maximumPendingWriteTransactions 0
set_interface_property avalon_slave_0 readLatency 0
set_interface_property avalon_slave_0 readWaitTime 1
set_interface_property avalon_slave_0 setupTime 0
set_interface_property avalon_slave_0 timingUnits Cycles
set_interface_property avalon_slave_0 writeWaitTime 0
set_interface_property avalon_slave_0 ENABLED true
set_interface_property avalon_slave_0 EXPORT_OF ""
set_interface_property avalon_slave_0 PORT_NAME_MAP ""
set_interface_property avalon_slave_0 CMSIS_SVD_VARIABLES ""
set_interface_property avalon_slave_0 SVD_ADDRESS_GROUP ""

add_interface_port avalon_slave_0 address address Input 1
add_interface_port avalon_slave_0 writedata writedata Input 32
add_interface_port avalon_slave_0 readdata readdata Output 32
add_interface_port avalon_slave_0 write write Input 1
add_interface_port avalon_slave_0 read read Input 1
add_interface_port avalon_slave_0 chipselect chipselect Input 1
add_interface_port avalon_slave_0 waitrequest waitrequest Output 1
set_interface_assignment avalon_slave_0 embeddedsw.configuration.isFlash 0
set_interface_assignment avalon_slave_0 embeddedsw.configuration.isMemoryDevice 0
set_interface_assignment avalon_slave_0 embeddedsw.configuration.isNonVolatileStorage 0
set_interface_assignment avalon_slave_0 embeddedsw.configuration.isPrintableDevice 0


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

add_interface_port clock clock clk Input 1


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

add_interface_port reset resetn reset Input 1


# 
# connection point rx_tx
# 
add_interface rx_tx conduit end
set_interface_property rx_tx associatedClock ""
set_interface_property rx_tx associatedReset ""
set_interface_property rx_tx ENABLED true
set_interface_property rx_tx EXPORT_OF ""
set_interface_property rx_tx PORT_NAME_MAP ""
set_interface_property rx_tx CMSIS_SVD_VARIABLES ""
set_interface_property rx_tx SVD_ADDRESS_GROUP ""

add_interface_port rx_tx RX_export rx Input 1
add_interface_port rx_tx TX_export tx Output 1

