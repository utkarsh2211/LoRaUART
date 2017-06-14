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
  <th>&ltCR-LF&gt</th>
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
    <th>&ltCR-LF&gt</th>
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
<tr>
<th>API COMMAND</th>
<th>DESCRIPTION</th>
<th>PARAMETER</th>
<th>DEFAULTS</th>
</tr>
<tr>
<td>$CMD,00,00&ltCR-LF&gt</td>
<td>Restore defaults</td>
<td>_</td>
<td>_</td>
</tr>
<tr>
<td>$CMD,00,01&ltCR-LF&gt</td>
<td>Initialize LoraWan</td>
<td>_</td>
<td>_</td>
</tr>
<tr>
<td>$CMD,00,02&ltCR-LF&gt</td>
<td>Deactivate LoRAWan</td>
<td>_</td>
<td>_</td>
</tr>
<tr>
<td>$CMD,00,03&ltCR-LF&gt</td>
<td>Activate LoraWan</td>
<td>_</td>
<td>_</td>
</tr>
<tr>
<td>$CMD,00,04&ltCR-LF&gt (to read)<br/>$CMD,01,04,&ltval&gt&ltCR-LF&gt (to change)</td>
<td>Baud Rate</td>
<td>00-04</td>
<td> 01<br/> 00(4800), 01(9600), 02(19200), 03(57600), 04(115200)</td>
</tr>
<tr>
<td>$CMD,00,05&ltCR-LF&gt (to read) <br/>$CMD,01,05,&ltval&gt&ltCR-LF&gt (to change)</td>
<td>Device EUI</td>
<td>8 Bytes</td>
<td>01,02,03,04,05,06,07,08</td>
</tr>
<tr>
<td>$CMD,00,06&ltCR-LF&gt (to read) <br/>$CMD,01,06,&ltval&gt&ltCR-LF&gt (to change)</td>
<td>Application EUI</td>
<td>8 Bytes</td>
<td>0F,0E,0D,0C,0B,0A,09,08</td>
</tr>
<tr>
<td>$CMD,00,07&ltCR-LF&gt</td>
<td>Application KEY</td>
<td>16 Bytes</td>
<td>01,11,21,31,41,51,61,71,81,91,A1,B1,C1,D1,E1,F1</td>
</tr>
<tr>
<td>$CMD,00,08&ltCR-LF&gt</td>
<td>Network Key</td>
<td>16 Bytes</td>
<td>00,10,20,30,40,50,60,70,80,90,A0,B0,C0,D0,E0,F0</td>
</tr>
<tr>
<td>$CMD,00,09&ltCR-LF&gt</td>
<td>Device Address</td>
<td>4 Bytes</td>
<td>01,02,03,04</td>
</tr>
<tr>
<td>$CMD,00,0A&ltCR-LF&gt</td>
<td>Network Connection Type</td>
<td>00-ABP,<br/>01-OTAA</td>
<td>00</td>
</tr> 
<tr>
<td>$CMD,00,0B&ltCR-LF&gt</td>
<td>Network Id</td>
<td>4 Bytes</td>
<td>00,00,00,01</td>
</tr> 
<tr>
<td>$CMD,00,0C&ltCR-LF&gt</td>
<td>ADR ON/OFF</td>
<td>00 ON<br/>01 OFF</td>
<td>01</td>
</tr> 
<tr>
<td>$CMD,00,0D&ltCR-LF&gt</td>
<td>Uplink Ack</td>
<td>ON/OFF<br/>00 ON<br/>01 OFF</td>
<td>00</td>
</tr> 
<tr>
<td>$CMD,00,0E&ltCR-LF&gt</td>
<td>Data Confirmation Retries</td>
<td>1 Byte</td>
<td>05</td>
</tr>
<tr>
<td>$CMD,00,0F&ltCR-LF&gt</td>
<td>Default Datarate</td>
<td>00 to 05</td>
<td>00</td>
</tr>
<tr>
<td>$CMD,00,10&ltCR-LF&gt</td>
<td>Power Saving Mode</td>
<td>00 ON<br/>01 OFF</td>
<td>01</td>
</tr> 
<tr>
<td>$CMD,00,11&ltCR-LF&gt</td>
<td>Class Selection A/C</td>
<td>00 C<br/>01 A</td>
<td>00</td>
</tr>
<tr>
<td>$CMD,00,12&ltCR-LF&gt</td>
<td>Save all configurations to EEPROM</td>
<td>_</td>
<td>_</td>
</tr> 
<tr>
<td>$CMD,00,13&ltCR-LF&gt</td>
<td>Retrieve all configurations from EEPROM</td>
<td>_</td>
<td>_</td>
</tr>
<tr>
<td>$CMD,00,FF&ltCR-LF&gt</td>
<td>Module test command</td>
<td>_</td>
<td>_</td>
</tr>
</table>

<b>Uplink API Format:</b><br/>
<table>
<tr>
<th></th>
<th>Start,</th>
<th>Port Number,</th>
<th>Data Length,</th>
<th>Data,</th>
<th>&ltCR-LF&gt</th>
</tr>
<tr>
<td>For Uplink</td>
<td>"$UP"</td>
<td>1 Byte</td>
<td>1 Byte</td>
<td>1 or More Bytes separated by ','</td>
<td>"\r\n"</td>
</tr>
<tr>
<td>Response from Device</td>
<td>"$UP"</td>
<td>00</td>
<td>00-success<br/>01-failure</td>
<td></td>
<td></td>
</tr>
</table>
If ack is enable then it will send "$UP,01,00\r\n" whenever it receives an acknowledgement from
lora server.<br/><br/>

<b>Downlink API Format:</b><br/>
<table>
<tr>
<th>Start,</th>
<th>Port Number,</th>
<th>Data Length,</th>
<th>Data,</th>
<th>&ltCR-LF&gt</th>
</tr>
<tr>
<td>"$DOWN"</td>
<td>1 Byte</td>
<td>1 Byte</td>
<td>1 or More Bytes separated by ','</td>
<td>"\r\n"</td>
</tr>
</table>