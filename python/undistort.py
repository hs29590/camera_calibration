import sys
import cv2
import numpy as np

DIM = (1080, 607)

K = np.array([[733.6949640731798, 0.0, 544.1965682427837], [0.0, 738.9528747060647, 304.5789049012523], [0.0, 0.0, 1.0]])

D = np.array([[0.02339688532556168], [-0.18761540339895577], [-0.018097291274030963], [0.12231690654648301]])

def undistort(img_path):    
    img = cv2.imread(img_path)
    h,w = img.shape[:2]    
    
    map1, map2 = cv2.fisheye.initUndistortRectifyMap(K, D, np.eye(3), K, DIM, cv2.CV_16SC2)
    
    undistorted_img = cv2.remap(img, map1, map2, interpolation=cv2.INTER_LINEAR, borderMode=cv2.BORDER_CONSTANT)    

    cv2.imshow("undistorted", undistorted_img)
    cv2.imwrite("undistorted.jpg", undistorted_img)
    cv2.waitKey(0)
    
    cv2.destroyAllWindows()

if __name__ == '__main__':    
    for p in sys.argv[1:]:
        undistort(p)
