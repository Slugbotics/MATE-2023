''' Runs the driver station GUI

displays:
- camera / opencv output
- network info
- last input sent
- thruster data

This program will ask for permission to read the webcam (popup)'''

import PySimpleGUI as sg

import cv2

import numpy as np

import time


def main():

    sg.theme("DarkBlack")


    # Define the window layout

    layout = [
        [sg.Push(), sg.Image(filename="", key="-IMAGE-"), sg.Push()],
        [sg.StatusBar("Network Status"), sg.StatusBar("Last Input Sent")],
        [sg.StatusBar("Thruster 1 status"), sg.StatusBar("Thruster 2 status")],
        [sg.StatusBar("Thruster 3 status"), sg.StatusBar("Thruster 4 status")],
        [sg.Push(), sg.Button("Exit", size=(10, 1))],

    ]



    window = sg.Window("Slugbotics Driver Station", layout, location=(0, 0), resizable=True)

    cap = cv2.VideoCapture(0)
    if not cap.isOpened():
        print("Camera cannot be accessed")
        exit()

    cap.set(cv2.CAP_PROP_FRAME_WIDTH, 1280)
    cap.set(cv2.CAP_PROP_FRAME_HEIGHT, 720)
    cap.set(cv2.CAP_PROP_FPS, 60)
    window_maximized = False
    # Event loop
    while True:

        event, values = window.read(timeout=20)

        if not window_maximized:
            window.maximize()
        
        if event == "Exit" or event == sg.WIN_CLOSED:
            break


        ret, frame = cap.read()

        frame = cv2.resize(frame, (round(1920 * 0.85), round(1080 * 0.85)))
        imgbytes = cv2.imencode(".png", frame)[1].tobytes()
        window["-IMAGE-"].update(data=imgbytes)


    window.close()
    cv2.VideoCapture(2).release()


if __name__ == "__main__":
    main()
