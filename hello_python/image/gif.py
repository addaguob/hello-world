from sys import argv

from PIL import Image
images = []

if len(argv) == 3:
    for arg in argv[1:]:
        try:
            image = Image.open(arg)
            images.append(image)
        except Exception:
            print("Invalid file input")
            exit(1)
        
images[0].save(
    "smiley.gif", save_all=True, append_images=[images[1]], duration=200, loop=0
)