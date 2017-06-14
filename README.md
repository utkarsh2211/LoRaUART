# LoRaUART
Arduino library for communication to LoRa module via UART

LORA UART PROTOCOL
 Every command and response through UART should be in String format.
 Every command string should end with <CR-LF> (􀍞\r\n􀍟).
 Every numerical value in command string should be Hexadecimal number in form of single
Byte.
 Every terms in command string are separated by 􀍚,􀍛. If any data consist of more than single
byte then use 􀍚,􀍛 as separator.
Request API Format:
START, Read/Write, AT Command, Value <CR-LF>
􀍞$CMD􀍟 1 Byte
(00 read and 01
write)
1 Byte 1 or more Byte
separated by 􀍚,􀍛
􀍞\r\n􀍟
Response API Format:
START, AT Command, Status, Value <CR-LF>
􀍞$RES􀍟 1 Byte 1Byte
00 –success
01-invalid
parameter
02-AT command
error
[Optional] 􀍞\r\n􀍟
List of Request Api:
API COMMAND DESCRIPTION PARAMETER DEFAULTS
$CMD,00,00<CR-LF> Restore defaults _ _
$CMD,00,01<CR-LF> Initialize LoraWan _ _
$CMD,00,02<CR-LF> Deactivate
LoRAWan
_ _
$CMD,00,03<CR-LF> Activate LoraWan _ _
$CMD,00,04<CR-LF> (to read)
$CMD,01,04,<val><CR-LF>( to
change)
Baud Rate 00-04 01
00(4800), 01(9600),
02(19200), 03(57600)
04(115200)
$CMD,00,05<CR-LF> (to
$CMD,01,05,<val><CR-LF>( to
Device EUI 8 Bytes 01,02,03,04,05,06,07,08
