# Custom-DW1000-PCB-for-hardware-evaluation

This repo contains the hardware and software files used to accompany the paper "Hardware Development and Performance Analysis of Ultra-Wideband Positioning Systems" by Harry Petter, see https://drive.google.com/file/d/1XKwOa9XYvF2y-BIo_fEk8SgJ67fw8Stb/view?usp=drivesdk

The design files contain PCB layouts designed for the Decawave DW1000 UWB transceiver and may be adapted to suit your hardware needs. The intention of this project is to enable users to develop their own PCB designs rapidly at a lower cost than investing in commercial modules. The performance of the designs in this repo are intentionally variable; for the best performance (positioning accuracy of 7cm, total range of 100m) please refer to "Version 2 FR4". You may wish to edit dimensions or large parts of these layouts, but they exist to provide a starting point for custom PCBs with the DW1000 IC. Please note 0603 SMD packages are used, apart from the balun capacitors which are 0402 SMD packages.

***These boards were tested with Thotro's Arduino-DW1000 repo. All software sketches in this repo are adapted versions of his orignal work (to use the sketches in this repo you need Thotro's source files)***




The contents of this repo are as follows:
# Hardware: 
  -Bill of materials for all boards

  -Version 1 PCB (layout and LPKF export files)
    ~Prototype board, Arduino Uno pin mapping, unmatched antenna traces, sub-optimal component placement
    
  -Version 2 FR4 (layout and LPKF export files)
    ~Optimised board for FR4 substrate, Arduino Pro Mini pin mapping, matched antenna traces, improved component placement
    
  -Version 2 Rogers (layout and LPKF export files)
    ~Optimised board for RO4350B substrate, Arduino Pro Mini pin mapping, matched antenna traces, improved component placement
   
# Software:

  -TAG (Prints recieved distances from 3 tags side by side for easy export to .csv or .txt)
  -ANCHOR (to be used in conjunction with TAG)

