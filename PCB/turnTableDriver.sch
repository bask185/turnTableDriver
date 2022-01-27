EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L MCU_Module:Arduino_Nano_v3.x A1
U 1 1 60D62773
P 3750 3750
F 0 "A1" H 3750 2661 50  0000 C CNN
F 1 "Arduino_Nano_v3.x" H 3750 2570 50  0000 C CNN
F 2 "Module:Arduino_Nano" H 3750 3750 50  0001 C CIN
F 3 "http://www.mouser.com/pdfdocs/Gravitech_Arduino_Nano3_0.pdf" H 3750 3750 50  0001 C CNN
	1    3750 3750
	1    0    0    -1  
$EndComp
$Comp
L Driver_Motor:Pololu_Breakout_A4988 A2
U 1 1 60D63D1E
P 5900 4000
F 0 "A2" H 5950 4881 50  0000 C CNN
F 1 "Pololu_Breakout_A4988" H 5950 4790 50  0000 C CNN
F 2 "Module:Pololu_Breakout-16_15.2x20.3mm" H 6175 3250 50  0001 L CNN
F 3 "https://www.pololu.com/product/2980/pictures" H 6000 3700 50  0001 C CNN
	1    5900 4000
	1    0    0    -1  
$EndComp
$Comp
L customLibrariesBas:DcDc-Banggood DC-DC1
U 1 1 60D64C96
P 4600 1600
F 0 "DC-DC1" H 4675 2025 50  0000 C CNN
F 1 "DcDc-Banggood" H 4675 1934 50  0000 C CNN
F 2 "Arduino:DcDc-Banggood" H 4600 1600 50  0001 C CNN
F 3 "" H 4600 1600 50  0001 C CNN
	1    4600 1600
	-1   0    0    -1  
$EndComp
$Comp
L Connector:Screw_Terminal_01x02 J1
U 1 1 60D655EF
P 1950 1600
F 0 "J1" H 2250 1450 50  0000 L CNN
F 1 "Screw_Terminal_01x02" H 2150 1600 50  0000 L CNN
F 2 "TerminalBlock:TerminalBlock_bornier-2_P5.08mm" H 1950 1600 50  0001 C CNN
F 3 "~" H 1950 1600 50  0001 C CNN
	1    1950 1600
	-1   0    0    1   
$EndComp
$Comp
L Connector:Screw_Terminal_01x02 J2
U 1 1 60D66C5C
P 1950 1800
F 0 "J2" H 2250 1650 50  0000 L CNN
F 1 "Screw_Terminal_01x02" H 2150 1800 50  0000 L CNN
F 2 "TerminalBlock:TerminalBlock_bornier-2_P5.08mm" H 1950 1800 50  0001 C CNN
F 3 "~" H 1950 1800 50  0001 C CNN
	1    1950 1800
	-1   0    0    1   
$EndComp
$Comp
L Connector:Screw_Terminal_01x02 J3
U 1 1 60D673B5
P 1950 2000
F 0 "J3" H 2250 1850 50  0000 L CNN
F 1 "Screw_Terminal_01x02" H 2150 2000 50  0000 L CNN
F 2 "TerminalBlock:TerminalBlock_bornier-2_P5.08mm" H 1950 2000 50  0001 C CNN
F 3 "~" H 1950 2000 50  0001 C CNN
	1    1950 2000
	-1   0    0    1   
$EndComp
$Comp
L Connector:Screw_Terminal_01x02 J4
U 1 1 60D6778E
P 1950 2200
F 0 "J4" H 2250 2050 50  0000 L CNN
F 1 "Screw_Terminal_01x02" H 2150 2200 50  0000 L CNN
F 2 "TerminalBlock:TerminalBlock_bornier-2_P5.08mm" H 1950 2200 50  0001 C CNN
F 3 "~" H 1950 2200 50  0001 C CNN
	1    1950 2200
	-1   0    0    1   
$EndComp
$Comp
L Connector:Screw_Terminal_01x02 J5
U 1 1 60D67A7B
P 1950 2400
F 0 "J5" H 2250 2250 50  0000 L CNN
F 1 "Screw_Terminal_01x02" H 2150 2400 50  0000 L CNN
F 2 "TerminalBlock:TerminalBlock_bornier-2_P5.08mm" H 1950 2400 50  0001 C CNN
F 3 "~" H 1950 2400 50  0001 C CNN
	1    1950 2400
	-1   0    0    1   
$EndComp
Wire Wire Line
	2150 1500 2500 1500
Wire Wire Line
	2150 1600 2500 1600
Wire Wire Line
	2150 1700 2500 1700
Wire Wire Line
	2500 1800 2150 1800
Wire Wire Line
	2150 1900 2500 1900
Wire Wire Line
	2150 2000 2500 2000
Wire Wire Line
	2150 2100 2500 2100
Wire Wire Line
	2150 2200 2500 2200
Wire Wire Line
	2150 2300 2500 2300
Wire Wire Line
	2150 2400 2500 2400
Text Label 2150 1500 0    50   ~ 0
mode
Text Label 2150 1600 0    50   ~ 0
store
Text Label 2150 1800 0    50   ~ 0
CW
Text Label 2150 1700 0    50   ~ 0
CCW
Text Label 2150 1900 0    50   ~ 0
gnd
Text Label 2150 2000 0    50   ~ 0
gnd
Text Label 2150 2100 0    50   ~ 0
sensor
Text Label 2150 2200 0    50   ~ 0
5v
Text Label 2150 2300 0    50   ~ 0
gnd
Text Label 2150 2400 0    50   ~ 0
12V
Entry Wire Line
	2500 1500 2600 1600
Entry Wire Line
	2500 1600 2600 1700
Entry Wire Line
	2500 1700 2600 1800
Entry Wire Line
	2500 1800 2600 1900
Entry Wire Line
	2500 1900 2600 2000
Entry Wire Line
	2500 2000 2600 2100
Entry Wire Line
	2500 2100 2600 2200
Entry Wire Line
	2500 2200 2600 2300
Entry Wire Line
	2500 2300 2600 2400
Entry Wire Line
	2600 2500 2500 2400
$Comp
L Connector:Screw_Terminal_01x02 J7
U 1 1 60D787CC
P 6850 4100
F 0 "J7" H 7150 3950 50  0000 L CNN
F 1 "Screw_Terminal_01x02" H 7050 4100 50  0000 L CNN
F 2 "TerminalBlock:TerminalBlock_bornier-2_P5.08mm" H 6850 4100 50  0001 C CNN
F 3 "~" H 6850 4100 50  0001 C CNN
	1    6850 4100
	1    0    0    -1  
$EndComp
$Comp
L Connector:Screw_Terminal_01x02 J6
U 1 1 60D7983D
P 6850 3900
F 0 "J6" H 7150 3750 50  0000 L CNN
F 1 "Screw_Terminal_01x02" H 7050 3900 50  0000 L CNN
F 2 "TerminalBlock:TerminalBlock_bornier-2_P5.08mm" H 6850 3900 50  0001 C CNN
F 3 "~" H 6850 3900 50  0001 C CNN
	1    6850 3900
	1    0    0    -1  
$EndComp
Wire Wire Line
	6650 4200 6400 4200
Wire Wire Line
	6400 4100 6650 4100
Wire Wire Line
	6650 4000 6400 4000
Wire Wire Line
	6400 3900 6650 3900
Wire Wire Line
	6100 4800 6100 4900
Wire Wire Line
	6100 4900 6000 4900
Wire Wire Line
	5900 4900 5900 4800
$Comp
L power:GND #PWR0101
U 1 1 60D7AC65
P 6000 5000
F 0 "#PWR0101" H 6000 4750 50  0001 C CNN
F 1 "GND" H 6005 4827 50  0000 C CNN
F 2 "" H 6000 5000 50  0001 C CNN
F 3 "" H 6000 5000 50  0001 C CNN
	1    6000 5000
	1    0    0    -1  
$EndComp
Wire Wire Line
	6000 5000 6000 4900
Connection ~ 6000 4900
Wire Wire Line
	6000 4900 5900 4900
Wire Wire Line
	5500 4500 5500 4400
Connection ~ 5500 4400
Wire Wire Line
	5500 4400 5500 4300
$Comp
L power:+5V #PWR0102
U 1 1 60D7B8A9
P 5350 4400
F 0 "#PWR0102" H 5350 4250 50  0001 C CNN
F 1 "+5V" H 5365 4573 50  0000 C CNN
F 2 "" H 5350 4400 50  0001 C CNN
F 3 "" H 5350 4400 50  0001 C CNN
	1    5350 4400
	1    0    0    -1  
$EndComp
Wire Wire Line
	5500 4400 5350 4400
Wire Wire Line
	5500 4100 5250 4100
Wire Wire Line
	5500 4000 5250 4000
Wire Wire Line
	5500 3900 5250 3900
Wire Wire Line
	5500 3700 5400 3700
Wire Wire Line
	5400 3700 5400 3600
Wire Wire Line
	5400 3600 5500 3600
Text Label 5250 4100 0    50   ~ 0
dir
Text Label 5250 4000 0    50   ~ 0
step
Text Label 5250 3900 0    50   ~ 0
enable
Wire Wire Line
	5900 3300 5900 2900
Wire Wire Line
	6100 3300 6100 2900
$Comp
L power:+5V #PWR0103
U 1 1 60D7EA26
P 5900 2900
F 0 "#PWR0103" H 5900 2750 50  0001 C CNN
F 1 "+5V" H 5915 3073 50  0000 C CNN
F 2 "" H 5900 2900 50  0001 C CNN
F 3 "" H 5900 2900 50  0001 C CNN
	1    5900 2900
	1    0    0    -1  
$EndComp
$Comp
L power:+12V #PWR0104
U 1 1 60D7EEE2
P 6100 2900
F 0 "#PWR0104" H 6100 2750 50  0001 C CNN
F 1 "+12V" H 6115 3073 50  0000 C CNN
F 2 "" H 6100 2900 50  0001 C CNN
F 3 "" H 6100 2900 50  0001 C CNN
	1    6100 2900
	1    0    0    -1  
$EndComp
$Comp
L Device:D D1
U 1 1 60D80C3A
P 3800 1400
F 0 "D1" H 3800 1183 50  0000 C CNN
F 1 "D" H 3800 1274 50  0000 C CNN
F 2 "Diode_THT:D_A-405_P7.62mm_Horizontal" H 3800 1400 50  0001 C CNN
F 3 "~" H 3800 1400 50  0001 C CNN
	1    3800 1400
	-1   0    0    1   
$EndComp
Wire Wire Line
	4000 1400 3950 1400
Wire Wire Line
	5050 1700 5150 1700
Wire Wire Line
	5150 1700 5150 1900
Wire Wire Line
	5150 1900 4500 1900
Wire Wire Line
	3850 1900 3850 1700
Wire Wire Line
	3850 1700 4000 1700
$Comp
L power:GND #PWR0105
U 1 1 60D8258B
P 4500 1900
F 0 "#PWR0105" H 4500 1650 50  0001 C CNN
F 1 "GND" H 4505 1727 50  0000 C CNN
F 2 "" H 4500 1900 50  0001 C CNN
F 3 "" H 4500 1900 50  0001 C CNN
	1    4500 1900
	1    0    0    -1  
$EndComp
Connection ~ 4500 1900
Wire Wire Line
	4500 1900 3850 1900
$Comp
L Device:D D2
U 1 1 60D829D3
P 5200 1400
F 0 "D2" H 5200 1183 50  0000 C CNN
F 1 "D" H 5200 1274 50  0000 C CNN
F 2 "Diode_THT:D_A-405_P7.62mm_Horizontal" H 5200 1400 50  0001 C CNN
F 3 "~" H 5200 1400 50  0001 C CNN
	1    5200 1400
	-1   0    0    1   
$EndComp
Wire Wire Line
	5350 1400 5600 1400
$Comp
L power:+5V #PWR0106
U 1 1 60D83C4D
P 5600 1400
F 0 "#PWR0106" H 5600 1250 50  0001 C CNN
F 1 "+5V" H 5615 1573 50  0000 C CNN
F 2 "" H 5600 1400 50  0001 C CNN
F 3 "" H 5600 1400 50  0001 C CNN
	1    5600 1400
	1    0    0    -1  
$EndComp
$Comp
L power:+12V #PWR0107
U 1 1 60D8407F
P 3450 1400
F 0 "#PWR0107" H 3450 1250 50  0001 C CNN
F 1 "+12V" H 3465 1573 50  0000 C CNN
F 2 "" H 3450 1400 50  0001 C CNN
F 3 "" H 3450 1400 50  0001 C CNN
	1    3450 1400
	1    0    0    -1  
$EndComp
Wire Wire Line
	3650 1400 3450 1400
Text Label 3550 1400 0    50   ~ 0
12V
Text Label 4350 1900 0    50   ~ 0
gnd
Wire Wire Line
	3250 3350 2700 3350
Wire Wire Line
	3250 3450 2700 3450
Wire Wire Line
	3250 3550 2700 3550
Entry Wire Line
	2700 3350 2600 3250
Entry Wire Line
	2700 3450 2600 3350
Entry Wire Line
	2700 3550 2600 3450
Text Label 2850 3350 0    50   ~ 0
mode
Text Label 2850 3450 0    50   ~ 0
store
Text Label 2850 3650 0    50   ~ 0
CW
Entry Wire Line
	2700 3650 2600 3550
Wire Wire Line
	2700 3650 3250 3650
Text Label 2850 3550 0    50   ~ 0
CCW
Wire Wire Line
	3250 3750 2700 3750
Entry Wire Line
	2700 3750 2600 3650
Text Label 2850 3750 0    50   ~ 0
sensor
NoConn ~ 3250 3250
NoConn ~ 3250 3150
NoConn ~ 3650 2750
NoConn ~ 3850 2750
$Comp
L power:+5V #PWR0108
U 1 1 60D97830
P 3950 2700
F 0 "#PWR0108" H 3950 2550 50  0001 C CNN
F 1 "+5V" H 3965 2873 50  0000 C CNN
F 2 "" H 3950 2700 50  0001 C CNN
F 3 "" H 3950 2700 50  0001 C CNN
	1    3950 2700
	1    0    0    -1  
$EndComp
Wire Wire Line
	3950 2750 3950 2700
NoConn ~ 4250 3250
NoConn ~ 4250 3150
NoConn ~ 4250 3550
NoConn ~ 4250 3850
NoConn ~ 4250 3950
NoConn ~ 4250 4050
NoConn ~ 4250 4150
NoConn ~ 4250 4250
NoConn ~ 4250 4350
NoConn ~ 4250 4450
$Comp
L Device:R_POT RV1
U 1 1 60DA002A
P 4750 3750
F 0 "RV1" H 4680 3704 50  0000 R CNN
F 1 "R_POT" H 4680 3795 50  0000 R CNN
F 2 "Potentiometer_THT:Potentiometer_Runtron_RM-065_Vertical" H 4750 3750 50  0001 C CNN
F 3 "~" H 4750 3750 50  0001 C CNN
	1    4750 3750
	-1   0    0    1   
$EndComp
Wire Wire Line
	4600 3750 4500 3750
$Comp
L power:+5V #PWR0109
U 1 1 60DA1DE9
P 4750 3550
F 0 "#PWR0109" H 4750 3400 50  0001 C CNN
F 1 "+5V" H 4765 3723 50  0000 C CNN
F 2 "" H 4750 3550 50  0001 C CNN
F 3 "" H 4750 3550 50  0001 C CNN
	1    4750 3550
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0110
U 1 1 60DA2225
P 3800 5050
F 0 "#PWR0110" H 3800 4800 50  0001 C CNN
F 1 "GND" H 3805 4877 50  0000 C CNN
F 2 "" H 3800 5050 50  0001 C CNN
F 3 "" H 3800 5050 50  0001 C CNN
	1    3800 5050
	1    0    0    -1  
$EndComp
Wire Wire Line
	3850 4750 3850 5050
Wire Wire Line
	3850 5050 3800 5050
Wire Wire Line
	3750 5050 3750 4750
Connection ~ 3800 5050
Wire Wire Line
	3800 5050 3750 5050
Wire Wire Line
	4750 3600 4750 3550
$Comp
L power:GND #PWR0111
U 1 1 60DA5665
P 4750 4100
F 0 "#PWR0111" H 4750 3850 50  0001 C CNN
F 1 "GND" H 4755 3927 50  0000 C CNN
F 2 "" H 4750 4100 50  0001 C CNN
F 3 "" H 4750 4100 50  0001 C CNN
	1    4750 4100
	1    0    0    -1  
$EndComp
Wire Wire Line
	3250 4050 2850 4050
Text Label 2850 3950 0    50   ~ 0
dir
Wire Wire Line
	2850 3850 3250 3850
Wire Wire Line
	2850 3950 3250 3950
Text Label 2850 3850 0    50   ~ 0
step
Text Label 2850 4050 0    50   ~ 0
enable
NoConn ~ 3250 4150
NoConn ~ 3250 4250
NoConn ~ 3250 4350
NoConn ~ 3250 4450
$Comp
L Device:C C1
U 1 1 60DCC004
P 4500 3900
F 0 "C1" H 4615 3946 50  0000 L CNN
F 1 "C" H 4615 3855 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D4.7mm_W2.5mm_P5.00mm" H 4538 3750 50  0001 C CNN
F 3 "~" H 4500 3900 50  0001 C CNN
	1    4500 3900
	1    0    0    -1  
$EndComp
Connection ~ 4500 3750
Wire Wire Line
	4500 3750 4250 3750
Wire Wire Line
	4500 4050 4500 4100
Wire Wire Line
	4500 4100 4750 4100
Wire Wire Line
	4750 3900 4750 4100
Connection ~ 4750 4100
Wire Bus Line
	2600 900  2600 3800
$EndSCHEMATC
