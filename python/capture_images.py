import cv2
import imutils
from threading import Thread
import numpy as np

class ThreadedCamera(object):
    def __init__(self, source = 0):

        self.capture = cv2.VideoCapture(source)

        self.thread = Thread(target = self.update, args = ())
        self.thread.daemon = True
        self.thread.start()

        self.status = False
        self.frame  = None

    def update(self):
        while True:
            if self.capture.isOpened():
                (self.status, self.frame) = self.capture.read()

    def grab_frame(self):
        if self.status:
            return self.frame
        return None

stream_link = "rtsp://admin:Robro123@192.168.1.64:554/Streaming/Channels/101"
#stream_link = 0
streamer = ThreadedCamera(stream_link)

i = 0
while True:

    frame = streamer.grab_frame()

    if frame is not None:
            
        frame = imutils.resize(frame, width=1080)
        cv2.imshow("Frame", frame)
        height, width, layers = frame.shape
        size = (width,height)
        print("Size of the frame : ", size)

    key = cv2.waitKey(1) & 0xFF
    if key == ord(" "):
        cv2.imwrite("./image-{}.jpg".format(i), frame)
        i += 1

    if key == ord("q") :
        break
