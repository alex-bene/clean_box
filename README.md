# Clean Box

The project is aimed at creating a performant, beautifull and easy to build [CR box](https://en.wikipedia.org/wiki/Corsi%E2%80%93Rosenthal_Box) with up to seven 12V computer fans.

This repository _will_ house everything you would need to build and use this device, as well as develop it further.
* **Firmware:** Arduino code for controlling and monitoring the system (e.g., fan speed).
* **CAD Files:** 3D models of the enclosure and any custom parts (STL, STEP, etc.).
* **Bill of Materials (BOM):** List of all components needed for the project.
* **PCB Design Files:** KiCad project files for any custom printed circuit boards.

## Current Status
The project is currently in the **proof of concept** stage. There is a working esp32 code that can be used to control the fan speed and monitor it.

Additionally, there is an initial [KiCad](https://www.kicad.org/) project including two custom PCB designs. (to be shared soon)

Finally, you can find some initial CAD files for the box designed in [OnShape](https://cad.onshape.com/) at [this](https://cad.onshape.com/documents/6d453f35fc642d9b64dbcdc5/w/0809d4e059a1eabdd68f1644/e/77eb02521beb188d0e60653c?configuration=default&renderMode=0&uiState=6782944e8e79605cb32d3ebf) project.

## TODOs
* [ ] Add speed control switch.
* [ ] Add CAD files and BOM.
* [ ] Finalize and add KiCAD pcb files.
* [ ] Integrate with [Home Assistant](https://www.home-assistant.io/) through [ESPHome](https://esphome.io/)
