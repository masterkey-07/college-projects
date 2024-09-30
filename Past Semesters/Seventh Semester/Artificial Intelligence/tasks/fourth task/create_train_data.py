import os, shutil


UNSPLITTED_IMAGES = './images/'
SPLITTED_IMAGES = './splitted_images/'
TRAIN_IMAGES = './splitted_images/train/'
VALID_IMAGES = './splitted_images/valid/'

HAS_SPLITTED_IMAGES = len(os.listdir(SPLITTED_IMAGES)) > 0

if not HAS_SPLITTED_IMAGES:
    os.mkdir(TRAIN_IMAGES)
    os.mkdir(VALID_IMAGES)

    subfolders = os.listdir(UNSPLITTED_IMAGES)
    
    for subfolder in subfolders:
        os.mkdir(TRAIN_IMAGES + subfolder)
        os.mkdir(VALID_IMAGES + subfolder)
        
        images = os.listdir(UNSPLITTED_IMAGES + subfolder)
        
        valid_images = images[:20]
        train_images = images[20:]
        
        for valid_image in valid_images:
            source = UNSPLITTED_IMAGES + subfolder + '/' + valid_image
            
            dest = VALID_IMAGES + subfolder + '/' + valid_image
            
            shutil.copy(source, dest)

        for train_image in train_images:
            source = UNSPLITTED_IMAGES + subfolder + '/' + train_image
            
            dest = TRAIN_IMAGES + subfolder + '/' + train_image
            
            shutil.copy(source, dest)
