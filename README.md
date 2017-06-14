# LoRaUART
Arduino library for communication to LoRa module via UART

General convention used in commands of LoRa network<br/>
<ul>
<li>Every command and response through UART should be in String format.</li>
<li>Every command string should end with <CR-LF> ('\r\n').</li>
<li>Every numerical value in command string should be Hexadecimal number in form of single
Byte.</li>
<li>Every terms in command string are separated by ','. If any data consist of more than single
byte then use ',' as separator.</li>
</ul>
<b>Request API Format:</b><br/>
<table>
<tr>
  <th>START,</th>
  <th>Read/Write,</th>
  <th>AT Command,</th>
  <th>Value</th>
  <th><CR-LF></th>
</tr>
<tr>
  <td>"$CMD"</td>
  <td>1 Byte<br/>
  (00 read and 01 write)</td>
  <td>1 Byte</td>
  <td>1 or more Byte separated by ','</td>
  <td>"\r\n"</td>
</tr>
</table>

<b>Response API Format:</b><br/>

<table>
<tr>
    <th>START,</th>
    <th>AT Command,</th>
    <th>Status,</th>
    <th>Value</th>
    <th><CR-LF></th>
</tr>
<tr>
<td>"$RES"</td>
<td>1 Byte</td>
<td>1 Byte<br/>
    00 –success<br/>
    01-invalid parameter<br/>
    02-AT command error<br/></td>
 <td>[Optional]</td>
 <td>"\r\n"</td>
</tr>
</table>

<b>List of Request Api:</b><br/>
<table>
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
