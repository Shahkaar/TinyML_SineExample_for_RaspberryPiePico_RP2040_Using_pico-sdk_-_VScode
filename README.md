# TinyML_SineExample_for_RaspberryPiePico_RP2040_Using_pico-sdk_-_VScode

////// Software Needed ///////  

*ARM GCC Compiler

*CMAKE

*Visual Studio Build tools

*Python

*GIT

To start with this project the most important thing to notice is that your visual studio code is properly configured and you have all the 
dependencies installed for pico-sdk. For this the guidline is given in:

[1]https://datasheets.raspberrypi.com/pico/getting-started-with-pico.pdf

[2]https://shawnhymel.com/2096/how-to-set-up-raspberry-pi-pico-c-c-toolchain-on-windows-with-vs-code/

[3]https://www.youtube.com/watch?v=B5rQSoOmR5w

follow the link [1] to first install and set up your vs_code for raspberry pi pico. make sure the version of the softwares are the same and correct paths are added in the system environment. The cmake version i used is 1.6 because in latest version the build bottons disappears.From the bottom and you cannot follow the link [1] and link [2] properly. Make sure that the directories are made in the correct location and same name as the link because they are used in the paths. 
After you are successfully able to build and upload your blink project to raspberry pi pico.

//////////// Model Training /////////////////////

Now its time to train the model using edge impulse:

[4] https://edgeimpulse.com/

complete documentation is also given in the website:

[5] https://docs.edgeimpulse.com/docs/

[6] https://www.youtube.com/watch?v=iCmlKyAp8eQ

you can also find multiple tutorials online. 

I will be providing the complete file sets with the model i have trained but you can visit the link [4] to train your own model by first  generating a csv file for the values of pi from 0-pi. I have used python for this purpose. then upload your csv file to link [4] and understand the tutorial in link [6] and generate your model the only changes you will be needing is the source file i have provided. If you want to use the same model as mine then simple copy the files in a known location. Open that folder in VS_code and build the project after that copy the .uf2 file to your pico and open the serial monitor. Any software for serial monitoring can be used i used arduino. but before using arduino make sure you have installed the pico board through boards manager the following link may help. Set the baud rate to 115200 (9600 can also work). The serial monitor will show the generated value from 0-pi as "feature" then the predicted value as "value" the same value is saved in an array with the name "y" and then the mapped pwm as "pwm". note that the range for the pwm of pico microcontroller is from 0-65535.
