# Chess Clock
Programmable arduino chess clock with LCD and membrane keypad

## Features
- Easy to use
- 3d design similar to professional chess clocks such as DGT or LEAP
- Starts with a default time of 3:02 minutes and 2 seconds of increment
- Maximum time of 59:59 minutes

## How to use the chess clock
- To pause/resume just click the "C" button on the membrane keypad
- To modify each player's time first you have to pause it ("C") and then click "A" or "B" to modify white or black's time respectively, 
  then enter the new time, for example, if you want to set the time to 12:30 minutes just click "1" then "2" and finally "3". When
  something finishes with "0" it isn't necessary to enter "0" but you can type it if you want.
- To change the increment(remember that starts with 2 seconds) of each player first the time has to be paused. Next you have to click the "D" 
 button and click " * "  or "#", whether you want to add seconds or minutes. Once this is done you will be able to type the increment. When you finish 
 press "D" and then you will be able to resume the match. 
 
 # Parts required

## Electronic parts
- 16x2 LCD  --> 1 unit
- Arduino UNO board --> 1 unit
- USB 2.0 cable type A/B --> 1 unit
- 4x4 matrix membrane keypad --> 1 unit
- pushbuttons (I used the micro limit switch pushbuttons, link at the end) --> 2 units
- 10kΩ potentiometer --> 1 unit
- switch --> 1 unit
- 4 x AA battery holder --> 1 unit
- wire to connect everything

## 3D parts

If you want to assembly all the parts into a compact chess clock, you can print the 3d parts. Read before the recommendations below to make sure
the design fits correctly to your electronic components. 

- You will need a specific pushbutton, otherwise it won't fit into the case, you have more information in the link below.
```
https://www.amazon.es/GTIWUNG-Interruptor-enrutador-Impresora-125V-250/dp/B08LD68FYQ/ref=sr_1_1_sspa?crid=3E748LCIT7XJA&dchild=1&keywords=pulsador+final+carrera&qid=1631032868&sr=8-1-spons&psc=1&spLa=ZW5jcnlwdGVkUXVhbGlmaWVyPUExQUxVMzlMTVhMSDJTJmVuY3J5cHRlZElkPUEwNzA2NjIxM1ZQTzk4Qk5CWTVLMSZlbmNyeXB0ZWRBZElkPUEwNTMwMjk1MVlZWDZTVko4VU0ySCZ3aWRnZXROYW1lPXNwX2F0ZiZhY3Rpb249Y2xpY2tSZWRpcmVjdCZkb05vdExvZ0NsaWNrPXRydWU=
```
- Your battery holder must be like in the image.

  ![unnamed](https://user-images.githubusercontent.com/46027448/132381881-5b495abc-3de3-4f5f-8fcc-58ae0cdd8d09.jpg)

- 
