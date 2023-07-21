# TinyML_SineExample_for_Raspberry-Pi-Pico_RP2040_Using_pico-sdk_-_VScode

# Software Needed 

* ARM GCC Compiler

* CMAKE

* Visual Studio Build tools

* Python

* GIT

# Let's Start

To start with this project the most important thing to notice is that your visual studio code is properly configured and you have all the 
dependencies installed for pico-sdk. Follow [How to Set Up Raspberry Pi Pico C/C++ Toolchain on Windows with VS Code](https://shawnhymel.com/2096/how-to-set-up-raspberry-pi-pico-c-c-toolchain-on-windows-with-vs-code/)
.After this build your first project and blink an LED by following [Intro to Raspberry Pi Pico and RP2040 - C/C++ Part 1: VS Code and Blink | Digi-Key Electronics](https://www.youtube.com/watch?v=B5rQSoOmR5w).Make sure the version of the softwares are the same and correct paths are added in the system environment. The cmake version I used is 1.6 because in latest version the build buttons disappears. Make sure that the directories are made in the correct location and same name as the link because they are used in the paths. 
After this you will be able to build and upload your blink project to raspberry pi pico.

# Model Training
The model is trained and tested using [Edge Impulse](https://edgeimpulse.com/). For learning more about it go to [Arduino Machine Learning Tutorial: Introduction to TinyML with Wio Terminal](https://www.youtube.com/watch?v=iCmlKyAp8eQ) and you can also check out there documentation too[Documentation Edge-Impulse](https://docs.edgeimpulse.com/docs/) you can also find multiple tutorials online.
Now there are three things you can do:
1. Use the model I trained.
2. Build your own model.
3. Upload a tensorflowlite model to edge-impulse
# Using My Model files
You just need to download the files from [TinyML_SineExample_for_Raspberry-Pi-Pico_RP2040_Using_pico-sdk_-_VScode](https://github.com/Shahkaar/TinyML_SineExample_for_RaspberryPiePico_RP2040_Using_pico-sdk_-_VScode) and from [Edge-impluse-sinewave-model](https://github.com/Shahkaar/Edge-impluse-sinewave-model) and do a bit file formating for which you can follow this video [Machine Learning Inference on Raspberry Pico 2040 via Edge Impulse](https://www.youtube.com/watch?v=BrRKcEQxrv4&t=744s). Once your files are in correct formate. Also set up your Arduino IDE to work with raspberry pi pico like [this](https://www.youtube.com/watch?v=IZKpCz6LEdg). Open the folder that has all your files in Visual Studio Code. Generate the build folder and build the project. The copy the `.uf2` file to you Raspberry pi pico. Open the Arduino IDE Serial monitor and you will be see the values from 0-pi as `features` then the predicted output as `value`. The same set of values are saved in the array `y` and then those values are mapped to the pico's PWM range of 0-65535.
After all the prediction are done (A total of 200 iteration) the Built-in LED of the pico will show half sine wave.

# Building Your Own Model
Start by generating a `.csv` file using python and then upload it to [Edge Impulse]

[7] https://www.hackster.io/dmitrywat/machine-learning-inference-on-raspberry-pico-2040-e6e874

I will be providing the complete file sets with the model I have trained but you can visit the link [4] to train your own model by first  generating a csv file for the values of pi from 0-pi. I have used python for this purpose. Then upload your csv file to link [4] and understand the tutorial in link [6] and generate your model. The only changes you will be needing are the source files that I have provided. If you want to use the same model as mine then simply copy the files in a known location. Open that folder in VS_code and build the project. After that copy the .uf2 file to your pico and open the serial monitor. Any software for serial monitoring can be used, I used Arduino, but before using Arduino make sure you have installed the Pico board through boards manager. The following link may help. Set the baud rate to 115200 (9600 can also work). The serial monitor will show the generated value from 0-pi as "feature" then the predicted value as "value" the same value is saved in an array with the name "y" and then the mapped pwm as "pwm". note that the range for the pwm of pico microcontroller is from 0-65535.

NOTE: You can find the model I use at:
https://github.com/Shahkaar/Edge-impluse-sinewave-model

I have made few changes in the file edge-impulse-sdk/porting/raspberry/ei_classifier_porting.cpp. so if you are using my trained model with this source code everything should hopefully work.

The directory structure should look like the one used in the following tutorial:
https://www.youtube.com/watch?v=BrRKcEQxrv4&t=744s

main folder/
     source
     CMakeLists.txt
     pico_sdk_import.cmake
     edge-impulse-sdk
     model-parameters
     tflite-model

