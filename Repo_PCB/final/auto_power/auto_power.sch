<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE eagle SYSTEM "eagle.dtd">
<eagle version="9.2.2">
<drawing>
<settings>
<setting alwaysvectorfont="no"/>
<setting verticaltext="up"/>
</settings>
<grid distance="0.1" unitdist="inch" unit="inch" style="lines" multiple="1" display="no" altdistance="0.01" altunitdist="inch" altunit="inch"/>
<layers>
<layer number="1" name="Top" color="4" fill="1" visible="no" active="no"/>
<layer number="2" name="Route2" color="1" fill="3" visible="no" active="no"/>
<layer number="3" name="Route3" color="4" fill="3" visible="no" active="no"/>
<layer number="4" name="Route4" color="1" fill="4" visible="no" active="no"/>
<layer number="5" name="Route5" color="4" fill="4" visible="no" active="no"/>
<layer number="6" name="Route6" color="1" fill="8" visible="no" active="no"/>
<layer number="7" name="Route7" color="4" fill="8" visible="no" active="no"/>
<layer number="8" name="Route8" color="1" fill="2" visible="no" active="no"/>
<layer number="9" name="Route9" color="4" fill="2" visible="no" active="no"/>
<layer number="10" name="Route10" color="1" fill="7" visible="no" active="no"/>
<layer number="11" name="Route11" color="4" fill="7" visible="no" active="no"/>
<layer number="12" name="Route12" color="1" fill="5" visible="no" active="no"/>
<layer number="13" name="Route13" color="4" fill="5" visible="no" active="no"/>
<layer number="14" name="Route14" color="1" fill="6" visible="no" active="no"/>
<layer number="15" name="Route15" color="4" fill="6" visible="no" active="no"/>
<layer number="16" name="Bottom" color="1" fill="1" visible="no" active="no"/>
<layer number="17" name="Pads" color="2" fill="1" visible="no" active="no"/>
<layer number="18" name="Vias" color="2" fill="1" visible="no" active="no"/>
<layer number="19" name="Unrouted" color="6" fill="1" visible="no" active="no"/>
<layer number="20" name="Dimension" color="15" fill="1" visible="no" active="no"/>
<layer number="21" name="tPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="22" name="bPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="23" name="tOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="24" name="bOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="25" name="tNames" color="7" fill="1" visible="no" active="no"/>
<layer number="26" name="bNames" color="7" fill="1" visible="no" active="no"/>
<layer number="27" name="tValues" color="7" fill="1" visible="no" active="no"/>
<layer number="28" name="bValues" color="7" fill="1" visible="no" active="no"/>
<layer number="29" name="tStop" color="7" fill="3" visible="no" active="no"/>
<layer number="30" name="bStop" color="7" fill="6" visible="no" active="no"/>
<layer number="31" name="tCream" color="7" fill="4" visible="no" active="no"/>
<layer number="32" name="bCream" color="7" fill="5" visible="no" active="no"/>
<layer number="33" name="tFinish" color="6" fill="3" visible="no" active="no"/>
<layer number="34" name="bFinish" color="6" fill="6" visible="no" active="no"/>
<layer number="35" name="tGlue" color="7" fill="4" visible="no" active="no"/>
<layer number="36" name="bGlue" color="7" fill="5" visible="no" active="no"/>
<layer number="37" name="tTest" color="7" fill="1" visible="no" active="no"/>
<layer number="38" name="bTest" color="7" fill="1" visible="no" active="no"/>
<layer number="39" name="tKeepout" color="4" fill="11" visible="no" active="no"/>
<layer number="40" name="bKeepout" color="1" fill="11" visible="no" active="no"/>
<layer number="41" name="tRestrict" color="4" fill="10" visible="no" active="no"/>
<layer number="42" name="bRestrict" color="1" fill="10" visible="no" active="no"/>
<layer number="43" name="vRestrict" color="2" fill="10" visible="no" active="no"/>
<layer number="44" name="Drills" color="7" fill="1" visible="no" active="no"/>
<layer number="45" name="Holes" color="7" fill="1" visible="no" active="no"/>
<layer number="46" name="Milling" color="3" fill="1" visible="no" active="no"/>
<layer number="47" name="Measures" color="7" fill="1" visible="no" active="no"/>
<layer number="48" name="Document" color="7" fill="1" visible="no" active="no"/>
<layer number="49" name="Reference" color="7" fill="1" visible="no" active="no"/>
<layer number="51" name="tDocu" color="7" fill="1" visible="no" active="no"/>
<layer number="52" name="bDocu" color="7" fill="1" visible="no" active="no"/>
<layer number="88" name="SimResults" color="9" fill="1" visible="yes" active="yes"/>
<layer number="89" name="SimProbes" color="9" fill="1" visible="yes" active="yes"/>
<layer number="90" name="Modules" color="5" fill="1" visible="yes" active="yes"/>
<layer number="91" name="Nets" color="2" fill="1" visible="yes" active="yes"/>
<layer number="92" name="Busses" color="1" fill="1" visible="yes" active="yes"/>
<layer number="93" name="Pins" color="2" fill="1" visible="no" active="yes"/>
<layer number="94" name="Symbols" color="4" fill="1" visible="yes" active="yes"/>
<layer number="95" name="Names" color="7" fill="1" visible="yes" active="yes"/>
<layer number="96" name="Values" color="7" fill="1" visible="yes" active="yes"/>
<layer number="97" name="Info" color="7" fill="1" visible="yes" active="yes"/>
<layer number="98" name="Guide" color="6" fill="1" visible="yes" active="yes"/>
</layers>
<schematic xreflabel="%F%N/%S.%C%R" xrefpart="/%S.%C%R">
<libraries>
<library name="pinhead" urn="urn:adsk.eagle:library:325">
<description>&lt;b&gt;Pin Header Connectors&lt;/b&gt;&lt;p&gt;
&lt;author&gt;Created by librarian@cadsoft.de&lt;/author&gt;</description>
<packages>
<package name="1X01" urn="urn:adsk.eagle:footprint:22382/1" library_version="3">
<description>&lt;b&gt;PIN HEADER&lt;/b&gt;</description>
<wire x1="-0.635" y1="1.27" x2="0.635" y2="1.27" width="0.1524" layer="21"/>
<wire x1="0.635" y1="1.27" x2="1.27" y2="0.635" width="0.1524" layer="21"/>
<wire x1="1.27" y1="0.635" x2="1.27" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="1.27" y1="-0.635" x2="0.635" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-1.27" y1="0.635" x2="-1.27" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="-0.635" y1="1.27" x2="-1.27" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-1.27" y1="-0.635" x2="-0.635" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="0.635" y1="-1.27" x2="-0.635" y2="-1.27" width="0.1524" layer="21"/>
<pad name="1" x="0" y="0" drill="1.016" shape="octagon"/>
<text x="-1.3462" y="1.8288" size="1.27" layer="25" ratio="10">&gt;NAME</text>
<text x="-1.27" y="-3.175" size="1.27" layer="27">&gt;VALUE</text>
<rectangle x1="-0.254" y1="-0.254" x2="0.254" y2="0.254" layer="51"/>
</package>
</packages>
<packages3d>
<package3d name="1X01" urn="urn:adsk.eagle:package:22485/2" type="model" library_version="3">
<description>PIN HEADER</description>
<packageinstances>
<packageinstance name="1X01"/>
</packageinstances>
</package3d>
</packages3d>
<symbols>
<symbol name="PINHD1" urn="urn:adsk.eagle:symbol:22381/1" library_version="3">
<wire x1="-6.35" y1="-2.54" x2="1.27" y2="-2.54" width="0.4064" layer="94"/>
<wire x1="1.27" y1="-2.54" x2="1.27" y2="2.54" width="0.4064" layer="94"/>
<wire x1="1.27" y1="2.54" x2="-6.35" y2="2.54" width="0.4064" layer="94"/>
<wire x1="-6.35" y1="2.54" x2="-6.35" y2="-2.54" width="0.4064" layer="94"/>
<text x="-6.35" y="3.175" size="1.778" layer="95">&gt;NAME</text>
<text x="-6.35" y="-5.08" size="1.778" layer="96">&gt;VALUE</text>
<pin name="1" x="-2.54" y="0" visible="pad" length="short" direction="pas" function="dot"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="PINHD-1X1" urn="urn:adsk.eagle:component:22540/2" prefix="JP" uservalue="yes" library_version="3">
<description>&lt;b&gt;PIN HEADER&lt;/b&gt;</description>
<gates>
<gate name="G$1" symbol="PINHD1" x="0" y="0"/>
</gates>
<devices>
<device name="" package="1X01">
<connects>
<connect gate="G$1" pin="1" pad="1"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:22485/2"/>
</package3dinstances>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="supply1" urn="urn:adsk.eagle:library:371">
<description>&lt;b&gt;Supply Symbols&lt;/b&gt;&lt;p&gt;
 GND, VCC, 0V, +5V, -5V, etc.&lt;p&gt;
 Please keep in mind, that these devices are necessary for the
 automatic wiring of the supply signals.&lt;p&gt;
 The pin name defined in the symbol is identical to the net which is to be wired automatically.&lt;p&gt;
 In this library the device names are the same as the pin names of the symbols, therefore the correct signal names appear next to the supply symbols in the schematic.&lt;p&gt;
 &lt;author&gt;Created by librarian@cadsoft.de&lt;/author&gt;</description>
<packages>
</packages>
<symbols>
<symbol name="GND" urn="urn:adsk.eagle:symbol:26925/1" library_version="1">
<wire x1="-1.905" y1="0" x2="1.905" y2="0" width="0.254" layer="94"/>
<text x="-2.54" y="-2.54" size="1.778" layer="96">&gt;VALUE</text>
<pin name="GND" x="0" y="2.54" visible="off" length="short" direction="sup" rot="R270"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="GND" urn="urn:adsk.eagle:component:26954/1" prefix="GND" library_version="1">
<description>&lt;b&gt;SUPPLY SYMBOL&lt;/b&gt;</description>
<gates>
<gate name="1" symbol="GND" x="0" y="0"/>
</gates>
<devices>
<device name="">
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
</libraries>
<attributes>
</attributes>
<variantdefs>
</variantdefs>
<classes>
<class number="0" name="default" width="0" drill="0">
</class>
</classes>
<parts>
<part name="GND" library="pinhead" library_urn="urn:adsk.eagle:library:325" deviceset="PINHD-1X1" device="" package3d_urn="urn:adsk.eagle:package:22485/2"/>
<part name="VCC" library="pinhead" library_urn="urn:adsk.eagle:library:325" deviceset="PINHD-1X1" device="" package3d_urn="urn:adsk.eagle:package:22485/2"/>
<part name="12_1" library="pinhead" library_urn="urn:adsk.eagle:library:325" deviceset="PINHD-1X1" device="" package3d_urn="urn:adsk.eagle:package:22485/2"/>
<part name="GND_1" library="pinhead" library_urn="urn:adsk.eagle:library:325" deviceset="PINHD-1X1" device="" package3d_urn="urn:adsk.eagle:package:22485/2"/>
<part name="12_2" library="pinhead" library_urn="urn:adsk.eagle:library:325" deviceset="PINHD-1X1" device="" package3d_urn="urn:adsk.eagle:package:22485/2"/>
<part name="GND_2" library="pinhead" library_urn="urn:adsk.eagle:library:325" deviceset="PINHD-1X1" device="" package3d_urn="urn:adsk.eagle:package:22485/2"/>
<part name="12_3" library="pinhead" library_urn="urn:adsk.eagle:library:325" deviceset="PINHD-1X1" device="" package3d_urn="urn:adsk.eagle:package:22485/2"/>
<part name="GND_3" library="pinhead" library_urn="urn:adsk.eagle:library:325" deviceset="PINHD-1X1" device="" package3d_urn="urn:adsk.eagle:package:22485/2"/>
<part name="12_4" library="pinhead" library_urn="urn:adsk.eagle:library:325" deviceset="PINHD-1X1" device="" package3d_urn="urn:adsk.eagle:package:22485/2"/>
<part name="GND_4" library="pinhead" library_urn="urn:adsk.eagle:library:325" deviceset="PINHD-1X1" device="" package3d_urn="urn:adsk.eagle:package:22485/2"/>
<part name="IN_1" library="pinhead" library_urn="urn:adsk.eagle:library:325" deviceset="PINHD-1X1" device="" package3d_urn="urn:adsk.eagle:package:22485/2"/>
<part name="OUT_1" library="pinhead" library_urn="urn:adsk.eagle:library:325" deviceset="PINHD-1X1" device="" package3d_urn="urn:adsk.eagle:package:22485/2"/>
<part name="GND_IN_1" library="pinhead" library_urn="urn:adsk.eagle:library:325" deviceset="PINHD-1X1" device="" package3d_urn="urn:adsk.eagle:package:22485/2"/>
<part name="GND_OUT_1" library="pinhead" library_urn="urn:adsk.eagle:library:325" deviceset="PINHD-1X1" device="" package3d_urn="urn:adsk.eagle:package:22485/2"/>
<part name="IN_2" library="pinhead" library_urn="urn:adsk.eagle:library:325" deviceset="PINHD-1X1" device="" package3d_urn="urn:adsk.eagle:package:22485/2"/>
<part name="OUT_2" library="pinhead" library_urn="urn:adsk.eagle:library:325" deviceset="PINHD-1X1" device="" package3d_urn="urn:adsk.eagle:package:22485/2"/>
<part name="GND_IN_2" library="pinhead" library_urn="urn:adsk.eagle:library:325" deviceset="PINHD-1X1" device="" package3d_urn="urn:adsk.eagle:package:22485/2"/>
<part name="GND_OUT_2" library="pinhead" library_urn="urn:adsk.eagle:library:325" deviceset="PINHD-1X1" device="" package3d_urn="urn:adsk.eagle:package:22485/2"/>
<part name="12_5" library="pinhead" library_urn="urn:adsk.eagle:library:325" deviceset="PINHD-1X1" device="" package3d_urn="urn:adsk.eagle:package:22485/2"/>
<part name="GND_5" library="pinhead" library_urn="urn:adsk.eagle:library:325" deviceset="PINHD-1X1" device="" package3d_urn="urn:adsk.eagle:package:22485/2"/>
<part name="12_6" library="pinhead" library_urn="urn:adsk.eagle:library:325" deviceset="PINHD-1X1" device="" package3d_urn="urn:adsk.eagle:package:22485/2"/>
<part name="GND_6" library="pinhead" library_urn="urn:adsk.eagle:library:325" deviceset="PINHD-1X1" device="" package3d_urn="urn:adsk.eagle:package:22485/2"/>
<part name="GND1" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="GND" device=""/>
<part name="5_1" library="pinhead" library_urn="urn:adsk.eagle:library:325" deviceset="PINHD-1X1" device="" package3d_urn="urn:adsk.eagle:package:22485/2"/>
<part name="GND_5_1" library="pinhead" library_urn="urn:adsk.eagle:library:325" deviceset="PINHD-1X1" device="" package3d_urn="urn:adsk.eagle:package:22485/2"/>
<part name="5_2" library="pinhead" library_urn="urn:adsk.eagle:library:325" deviceset="PINHD-1X1" device="" package3d_urn="urn:adsk.eagle:package:22485/2"/>
<part name="GND_5_2" library="pinhead" library_urn="urn:adsk.eagle:library:325" deviceset="PINHD-1X1" device="" package3d_urn="urn:adsk.eagle:package:22485/2"/>
</parts>
<sheets>
<sheet>
<plain>
</plain>
<instances>
<instance part="GND" gate="G$1" x="2.54" y="78.74" smashed="yes">
<attribute name="NAME" x="-3.81" y="81.915" size="1.778" layer="95"/>
<attribute name="VALUE" x="-3.81" y="73.66" size="1.778" layer="96"/>
</instance>
<instance part="VCC" gate="G$1" x="2.54" y="88.9" smashed="yes">
<attribute name="NAME" x="-3.81" y="92.075" size="1.778" layer="95"/>
<attribute name="VALUE" x="-3.81" y="83.82" size="1.778" layer="96"/>
</instance>
<instance part="12_1" gate="G$1" x="35.56" y="88.9" smashed="yes">
<attribute name="NAME" x="29.21" y="92.075" size="1.778" layer="95"/>
<attribute name="VALUE" x="29.21" y="83.82" size="1.778" layer="96"/>
</instance>
<instance part="GND_1" gate="G$1" x="35.56" y="78.74" smashed="yes">
<attribute name="NAME" x="29.21" y="81.915" size="1.778" layer="95"/>
<attribute name="VALUE" x="29.21" y="73.66" size="1.778" layer="96"/>
</instance>
<instance part="12_2" gate="G$1" x="48.26" y="88.9" smashed="yes">
<attribute name="NAME" x="41.91" y="92.075" size="1.778" layer="95"/>
<attribute name="VALUE" x="41.91" y="83.82" size="1.778" layer="96"/>
</instance>
<instance part="GND_2" gate="G$1" x="48.26" y="78.74" smashed="yes">
<attribute name="NAME" x="41.91" y="81.915" size="1.778" layer="95"/>
<attribute name="VALUE" x="41.91" y="73.66" size="1.778" layer="96"/>
</instance>
<instance part="12_3" gate="G$1" x="60.96" y="88.9" smashed="yes">
<attribute name="NAME" x="54.61" y="92.075" size="1.778" layer="95"/>
<attribute name="VALUE" x="54.61" y="83.82" size="1.778" layer="96"/>
</instance>
<instance part="GND_3" gate="G$1" x="60.96" y="78.74" smashed="yes">
<attribute name="NAME" x="54.61" y="81.915" size="1.778" layer="95"/>
<attribute name="VALUE" x="54.61" y="73.66" size="1.778" layer="96"/>
</instance>
<instance part="12_4" gate="G$1" x="73.66" y="88.9" smashed="yes">
<attribute name="NAME" x="67.31" y="92.075" size="1.778" layer="95"/>
<attribute name="VALUE" x="67.31" y="83.82" size="1.778" layer="96"/>
</instance>
<instance part="GND_4" gate="G$1" x="73.66" y="78.74" smashed="yes">
<attribute name="NAME" x="67.31" y="81.915" size="1.778" layer="95"/>
<attribute name="VALUE" x="67.31" y="73.66" size="1.778" layer="96"/>
</instance>
<instance part="IN_1" gate="G$1" x="43.18" y="58.42" smashed="yes">
<attribute name="NAME" x="36.83" y="61.595" size="1.778" layer="95"/>
<attribute name="VALUE" x="36.83" y="53.34" size="1.778" layer="96"/>
</instance>
<instance part="OUT_1" gate="G$1" x="43.18" y="17.78" smashed="yes">
<attribute name="NAME" x="36.83" y="20.955" size="1.778" layer="95"/>
<attribute name="VALUE" x="36.83" y="12.7" size="1.778" layer="96"/>
</instance>
<instance part="GND_IN_1" gate="G$1" x="63.5" y="58.42" smashed="yes">
<attribute name="NAME" x="57.15" y="61.595" size="1.778" layer="95"/>
<attribute name="VALUE" x="57.15" y="53.34" size="1.778" layer="96"/>
</instance>
<instance part="GND_OUT_1" gate="G$1" x="63.5" y="17.78" smashed="yes">
<attribute name="NAME" x="57.15" y="20.955" size="1.778" layer="95"/>
<attribute name="VALUE" x="57.15" y="12.7" size="1.778" layer="96"/>
</instance>
<instance part="IN_2" gate="G$1" x="86.36" y="58.42" smashed="yes">
<attribute name="NAME" x="80.01" y="61.595" size="1.778" layer="95"/>
<attribute name="VALUE" x="80.01" y="53.34" size="1.778" layer="96"/>
</instance>
<instance part="OUT_2" gate="G$1" x="86.36" y="17.78" smashed="yes">
<attribute name="NAME" x="80.01" y="20.955" size="1.778" layer="95"/>
<attribute name="VALUE" x="80.01" y="12.7" size="1.778" layer="96"/>
</instance>
<instance part="GND_IN_2" gate="G$1" x="106.68" y="58.42" smashed="yes">
<attribute name="NAME" x="100.33" y="61.595" size="1.778" layer="95"/>
<attribute name="VALUE" x="100.33" y="53.34" size="1.778" layer="96"/>
</instance>
<instance part="GND_OUT_2" gate="G$1" x="106.68" y="17.78" smashed="yes">
<attribute name="NAME" x="100.33" y="20.955" size="1.778" layer="95"/>
<attribute name="VALUE" x="100.33" y="12.7" size="1.778" layer="96"/>
</instance>
<instance part="12_5" gate="G$1" x="86.36" y="88.9" smashed="yes">
<attribute name="NAME" x="80.01" y="92.075" size="1.778" layer="95"/>
<attribute name="VALUE" x="80.01" y="83.82" size="1.778" layer="96"/>
</instance>
<instance part="GND_5" gate="G$1" x="86.36" y="78.74" smashed="yes">
<attribute name="NAME" x="80.01" y="81.915" size="1.778" layer="95"/>
<attribute name="VALUE" x="80.01" y="73.66" size="1.778" layer="96"/>
</instance>
<instance part="12_6" gate="G$1" x="99.06" y="88.9" smashed="yes">
<attribute name="NAME" x="92.71" y="92.075" size="1.778" layer="95"/>
<attribute name="VALUE" x="92.71" y="83.82" size="1.778" layer="96"/>
</instance>
<instance part="GND_6" gate="G$1" x="99.06" y="78.74" smashed="yes">
<attribute name="NAME" x="92.71" y="81.915" size="1.778" layer="95"/>
<attribute name="VALUE" x="92.71" y="73.66" size="1.778" layer="96"/>
</instance>
<instance part="GND1" gate="1" x="60.96" y="-2.54" smashed="yes">
<attribute name="VALUE" x="58.42" y="-5.08" size="1.778" layer="96"/>
</instance>
<instance part="5_1" gate="G$1" x="43.18" y="-25.4" smashed="yes">
<attribute name="NAME" x="36.83" y="-22.225" size="1.778" layer="95"/>
<attribute name="VALUE" x="36.83" y="-30.48" size="1.778" layer="96"/>
</instance>
<instance part="GND_5_1" gate="G$1" x="63.5" y="-25.4" smashed="yes">
<attribute name="NAME" x="57.15" y="-22.225" size="1.778" layer="95"/>
<attribute name="VALUE" x="57.15" y="-30.48" size="1.778" layer="96"/>
</instance>
<instance part="5_2" gate="G$1" x="86.36" y="-25.4" smashed="yes">
<attribute name="NAME" x="80.01" y="-22.225" size="1.778" layer="95"/>
<attribute name="VALUE" x="80.01" y="-30.48" size="1.778" layer="96"/>
</instance>
<instance part="GND_5_2" gate="G$1" x="106.68" y="-25.4" smashed="yes">
<attribute name="NAME" x="100.33" y="-22.225" size="1.778" layer="95"/>
<attribute name="VALUE" x="100.33" y="-30.48" size="1.778" layer="96"/>
</instance>
</instances>
<busses>
</busses>
<nets>
<net name="N$3" class="0">
<segment>
<pinref part="VCC" gate="G$1" pin="1"/>
<pinref part="12_1" gate="G$1" pin="1"/>
<wire x1="0" y1="88.9" x2="33.02" y2="88.9" width="0.1524" layer="91"/>
<pinref part="12_2" gate="G$1" pin="1"/>
<wire x1="33.02" y1="88.9" x2="40.64" y2="88.9" width="0.1524" layer="91"/>
<junction x="33.02" y="88.9"/>
<pinref part="12_3" gate="G$1" pin="1"/>
<wire x1="40.64" y1="88.9" x2="45.72" y2="88.9" width="0.1524" layer="91"/>
<wire x1="45.72" y1="88.9" x2="58.42" y2="88.9" width="0.1524" layer="91"/>
<junction x="45.72" y="88.9"/>
<pinref part="12_4" gate="G$1" pin="1"/>
<wire x1="58.42" y1="88.9" x2="71.12" y2="88.9" width="0.1524" layer="91"/>
<junction x="58.42" y="88.9"/>
<pinref part="12_5" gate="G$1" pin="1"/>
<pinref part="12_6" gate="G$1" pin="1"/>
<wire x1="83.82" y1="88.9" x2="96.52" y2="88.9" width="0.1524" layer="91"/>
<junction x="83.82" y="88.9"/>
<wire x1="71.12" y1="88.9" x2="83.82" y2="88.9" width="0.1524" layer="91"/>
<junction x="71.12" y="88.9"/>
<pinref part="IN_1" gate="G$1" pin="1"/>
<wire x1="40.64" y1="58.42" x2="40.64" y2="88.9" width="0.1524" layer="91"/>
<junction x="40.64" y="88.9"/>
</segment>
</net>
<net name="GND" class="0">
<segment>
<pinref part="GND1" gate="1" pin="GND"/>
<pinref part="GND_1" gate="G$1" pin="1"/>
<pinref part="GND_2" gate="G$1" pin="1"/>
<wire x1="60.96" y1="17.78" x2="60.96" y2="0" width="0.1524" layer="91"/>
<wire x1="33.02" y1="78.74" x2="45.72" y2="78.74" width="0.1524" layer="91"/>
<pinref part="GND_3" gate="G$1" pin="1"/>
<wire x1="45.72" y1="78.74" x2="58.42" y2="78.74" width="0.1524" layer="91"/>
<junction x="45.72" y="78.74"/>
<pinref part="GND_4" gate="G$1" pin="1"/>
<junction x="58.42" y="78.74"/>
<pinref part="GND_IN_1" gate="G$1" pin="1"/>
<wire x1="60.96" y1="78.74" x2="71.12" y2="78.74" width="0.1524" layer="91"/>
<wire x1="60.96" y1="58.42" x2="60.96" y2="78.74" width="0.1524" layer="91"/>
<wire x1="60.96" y1="78.74" x2="58.42" y2="78.74" width="0.1524" layer="91"/>
<pinref part="GND_OUT_1" gate="G$1" pin="1"/>
<wire x1="60.96" y1="17.78" x2="60.96" y2="45.72" width="0.1524" layer="91"/>
<junction x="60.96" y="58.42"/>
<pinref part="GND_IN_2" gate="G$1" pin="1"/>
<pinref part="GND_OUT_2" gate="G$1" pin="1"/>
<wire x1="60.96" y1="45.72" x2="60.96" y2="58.42" width="0.1524" layer="91"/>
<wire x1="104.14" y1="58.42" x2="104.14" y2="45.72" width="0.1524" layer="91"/>
<wire x1="104.14" y1="45.72" x2="104.14" y2="17.78" width="0.1524" layer="91"/>
<wire x1="60.96" y1="45.72" x2="104.14" y2="45.72" width="0.1524" layer="91"/>
<junction x="104.14" y="45.72"/>
<pinref part="GND" gate="G$1" pin="1"/>
<wire x1="0" y1="78.74" x2="33.02" y2="78.74" width="0.1524" layer="91"/>
<junction x="33.02" y="78.74"/>
<pinref part="GND_5" gate="G$1" pin="1"/>
<pinref part="GND_6" gate="G$1" pin="1"/>
<wire x1="83.82" y1="78.74" x2="96.52" y2="78.74" width="0.1524" layer="91"/>
<junction x="83.82" y="78.74"/>
<wire x1="86.36" y1="78.74" x2="83.82" y2="78.74" width="0.1524" layer="91"/>
<wire x1="71.12" y1="78.74" x2="83.82" y2="78.74" width="0.1524" layer="91"/>
<junction x="71.12" y="78.74"/>
<junction x="60.96" y="45.72"/>
<junction x="60.96" y="78.74"/>
<pinref part="IN_2" gate="G$1" pin="1"/>
<wire x1="83.82" y1="58.42" x2="83.82" y2="78.74" width="0.1524" layer="91"/>
<junction x="60.96" y="17.78"/>
<pinref part="GND_5_2" gate="G$1" pin="1"/>
<wire x1="60.96" y1="0" x2="104.14" y2="0" width="0.1524" layer="91"/>
<wire x1="104.14" y1="0" x2="104.14" y2="-10.16" width="0.1524" layer="91"/>
<junction x="60.96" y="0"/>
<pinref part="GND_5_1" gate="G$1" pin="1"/>
<wire x1="104.14" y1="-10.16" x2="104.14" y2="-25.4" width="0.1524" layer="91"/>
<wire x1="60.96" y1="-25.4" x2="60.96" y2="-10.16" width="0.1524" layer="91"/>
<wire x1="60.96" y1="-10.16" x2="104.14" y2="-10.16" width="0.1524" layer="91"/>
<junction x="104.14" y="-10.16"/>
</segment>
</net>
<net name="N$1" class="0">
<segment>
<pinref part="5_1" gate="G$1" pin="1"/>
<pinref part="OUT_1" gate="G$1" pin="1"/>
<wire x1="40.64" y1="-25.4" x2="40.64" y2="17.78" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$2" class="0">
<segment>
<pinref part="5_2" gate="G$1" pin="1"/>
<pinref part="OUT_2" gate="G$1" pin="1"/>
<wire x1="83.82" y1="-25.4" x2="83.82" y2="17.78" width="0.1524" layer="91"/>
</segment>
</net>
</nets>
</sheet>
</sheets>
</schematic>
</drawing>
<compatibility>
<note version="8.2" severity="warning">
Since Version 8.2, EAGLE supports online libraries. The ids
of those online libraries will not be understood (or retained)
with this version.
</note>
<note version="8.3" severity="warning">
Since Version 8.3, EAGLE supports URNs for individual library
assets (packages, symbols, and devices). The URNs of those assets
will not be understood (or retained) with this version.
</note>
<note version="8.3" severity="warning">
Since Version 8.3, EAGLE supports the association of 3D packages
with devices in libraries, schematics, and board files. Those 3D
packages will not be understood (or retained) with this version.
</note>
</compatibility>
</eagle>
