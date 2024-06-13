# importing the python open cv library
import cv2

# intialize the webcam and pass a constant which is 0
cam = cv2.VideoCapture(0)
# while loop
while True:
    # intializing the frame, ret
    ret, frame = cam.read()
    # the frame will show with the title of test
    cv2.imshow("test", frame)
    cv2.imwrite(filename='saved_img.jpg', img=frame)
    cam.release()
    # stops the camera window
##cv2.destoryAllWindows()




