
--
-- Generated by VASY
--
LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;
USE IEEE.numeric_std.ALL;

ENTITY a3_x4 IS
PORT(
  i0	: IN STD_LOGIC;
  i1	: IN STD_LOGIC;
  i2	: IN STD_LOGIC;
  q	: OUT STD_LOGIC
);
END a3_x4;

ARCHITECTURE RTL OF a3_x4 IS
BEGIN
  q <= ((i0 AND i1) AND i2);
END RTL;