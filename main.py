import tensorflow as tf
import time
import numpy as np
import warnings
warnings.filterwarnings('ignore')
from PIL import Image
# from object_detection.utils import label_map_util
# from object_detection.utils import visualization_utils as viz_utils

PATH_TO_SAVED_MODEL="saved_models/car_detect/saved_model"
print('Loading model...', end='')

# Load saved model and build the detection function
detect_fn=tf.saved_model.load(PATH_TO_SAVED_MODEL)
print('Done!')
