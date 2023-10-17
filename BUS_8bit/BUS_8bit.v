// Copyright (C) 2018  Intel Corporation. All rights reserved.
// Your use of Intel Corporation's design tools, logic functions 
// and other software and tools, and its AMPP partner logic 
// functions, and any output files from any of the foregoing 
// (including device programming or simulation files), and any 
// associated documentation or information are expressly subject 
// to the terms and conditions of the Intel Program License 
// Subscription Agreement, the Intel Quartus Prime License Agreement,
// the Intel FPGA IP License Agreement, or other applicable license
// agreement, including, without limitation, that your use is for
// the sole purpose of programming logic devices manufactured by
// Intel and sold by Intel or its authorized distributors.  Please
// refer to the applicable agreement for further details.

module BUS_8bit
(
// {ALTERA_ARGS_BEGIN} DO NOT REMOVE THIS LINE!

	EX_CLK,
	GPIO0,
	GPIO1,
	GPIO2,
	GPIO3,
	GPIO4,
	GPIO5,
	GPIO6,
	GPIO7,
	GPIO10,
	GPIO11,
	GPIO12,
	GPIO13,
	GPIO14,
	GPIO15,
	GPIO16,
	GPIO17,
	LEDR,
	MAX_CLK,
	SW
// {ALTERA_ARGS_END} DO NOT REMOVE THIS LINE!

);

// {ALTERA_IO_BEGIN} DO NOT REMOVE THIS LINE!
input			EX_CLK;
input			GPIO0;
input			GPIO1;
input			GPIO2;
input			GPIO3;
input			GPIO4;
input			GPIO5;
input			GPIO6;
input			GPIO7;
input			GPIO10;
input			GPIO11;
input			GPIO12;
input			GPIO13;
input			GPIO14;
input			GPIO15;
input			GPIO16;
input			GPIO17;
output	[9:0]	LEDR;
input			MAX_CLK;
input	[1:0]	SW;

// {ALTERA_IO_END} DO NOT REMOVE THIS LINE!
// {ALTERA_MODULE_BEGIN} DO NOT REMOVE THIS LINE!
// {ALTERA_MODULE_END} DO NOT REMOVE THIS LINE!
endmodule
