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
Now there are two things you can do:
1. Use the model I trained.
2. Build your own model.
   
# Using My Model files
You just need to download the files from [TinyML_SineExample_for_Raspberry-Pi-Pico_RP2040_Using_pico-sdk_-_VScode](https://github.com/Shahkaar/TinyML_SineExample_for_RaspberryPiePico_RP2040_Using_pico-sdk_-_VScode) and from [Edge-impluse-sinewave-model](https://github.com/Shahkaar/Edge-impluse-sinewave-model) and do a bit file formating for which you can follow this video [Machine Learning Inference on Raspberry Pico 2040 via Edge Impulse](https://www.youtube.com/watch?v=BrRKcEQxrv4&t=744s). Once your files are in correct formate. Also set up your Arduino IDE to work with raspberry pi pico like [this](https://www.youtube.com/watch?v=IZKpCz6LEdg). Open the folder that has all your files in Visual Studio Code. Generate the build folder and build the project. The copy the `.uf2` file to you Raspberry pi pico. Open the Arduino IDE Serial monitor and you will be see the values from 0-pi as `features` then the predicted output as `value`. The same set of values are saved in the array `y` and then those values are mapped to the pico's PWM range of 0-65535.
After all the prediction are done (A total of 200 iteration) the Built-in LED of the pico will show half sine wave.

# Building Your Own Model
Start by generating a `.csv` file using python and then upload it to [Edge Impulse](https://edgeimpulse.com/). Select the C++ option in the `Deployment` tab and download the files. My `source` file and `CMakeList.txt` should be used if you are willing to use the pwm functionality of Raspberry pi pico. In case of errors cross check the `edge-impulse-sdk` with [Edge-impluse-sinewave-model](https://github.com/Shahkaar/Edge-impluse-sinewave-model). Hopefully things should work now. For the file formating follow [Machine Learning Inference on Raspberry Pico 2040 via Edge Impulse](https://www.youtube.com/watch?v=BrRKcEQxrv4&t=744s)

The directory structure should look like the one used in the following tutorial:
main folder
   * source
   * CMakeLists.txt
   * pico_sdk_import.cmake
   * edge-impulse-sdk
   * model-parameters
   * tflite-model/

