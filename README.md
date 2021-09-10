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

If you want to assembly all the parts into a compact chess clock, you can print my 3d parts. Read before the recommendations below to make sure
the design fits correctly to your electronic components. 

- You will need a specific pushbutton, otherwise it won't fit into the case, you have more information in the link below.
```
https://www.amazon.es/GTIWUNG-Interruptor-enrutador-Impresora-125V-250/dp/B08LD68FYQ/ref=sr_1_1_sspa?crid=3E748LCIT7XJA&dchild=1&keywords=pulsador+final+carrera&qid=1631032868&sr=8-1-spons&psc=1&spLa=ZW5jcnlwdGVkUXVhbGlmaWVyPUExQUxVMzlMTVhMSDJTJmVuY3J5cHRlZElkPUEwNzA2NjIxM1ZQTzk4Qk5CWTVLMSZlbmNyeXB0ZWRBZElkPUEwNTMwMjk1MVlZWDZTVko4VU0ySCZ3aWRnZXROYW1lPXNwX2F0ZiZhY3Rpb249Y2xpY2tSZWRpcmVjdCZkb05vdExvZ0NsaWNrPXRydWU=
```
- Your battery holder must be like in the image.

![IMG_9815](https://user-images.githubusercontent.com/46027448/132489578-8f637a92-c98f-4861-bc2c-1f6b10585c44.jpg)

- The screws must be self-trapping, as the 3D printer isn't accurate enough to print the thread.

![IMG_9817](https://user-images.githubusercontent.com/46027448/132489835-6c594173-6d43-40c8-b02a-0e2fcbb32e87.jpg)

- There is a battery cover which you can disassemble it as many times as you want, but inside, there are 2 slots where you have to put 2 metric 3 square nuts.


![1](https://user-images.githubusercontent.com/46027448/132491277-471b6c14-eac2-403d-87c8-7946557ffba7.png)
![2](https://user-images.githubusercontent.com/46027448/132491298-76463989-5719-4609-b2b3-4750a6a18241.png)
![IMG_9816](https://user-images.githubusercontent.com/46027448/132491618-8c83377f-2fdf-44ef-bb96-061e6b49ad3e.jpg)

- Depending on the arduino board and the LCD you use, all holes may not be concentric, so first I recommend you to check the 3D design to ensure that all holes 
are as concentric as possible.

- In order to fix the lever which you press to change turn, you will need 2 washers and a 2 mm diameter metal bar (57,5mm length). The metal bar has to be
inserted inside the lever and then put the lever inside the case with the washers, finally you will be able to fix the lever with 2 small covers, like is
shown in the next images.

![IMG_9819](https://user-images.githubusercontent.com/46027448/132500136-91360c68-3ed3-4884-8100-cc3b59bfb1e9.jpg)
![Captura de pantalla 2021-09-08 130120](https://user-images.githubusercontent.com/46027448/132498140-71d5d31a-adcc-413e-8313-0bfdce8661a7.png)
![Captura de pantalla 2021-09-08 130120](https://user-images.githubusercontent.com/46027448/132498368-46380743-a3be-42d2-9043-41b44f4880b7.png)
![Captura de pantalla 2021-09-08 130120](https://user-images.githubusercontent.com/46027448/132498833-6a35b1ec-cb66-49e8-a2bb-bdb6a61f0b7b.png)

- The yellow plate is used to help the lever return to its initial position, as the pushbutton shouldn't pe pressed all time. It has to be flexible, 
  but not too much, and the dimensions are 35x47,75x0,5 mm. 

- The green parts which hold the battery have to be glued into the grooves of the base.
