# Hi, I'm Alexander Daguob. Below are my favorites!

# fave colors derived from https://en.wikipedia.org/wiki/Web_colors
class FavColors:
    # White colors
    WHITE = "#FFFFFF"
    SNOW = "#FFFAFA"
    IVORY = "#FFFFF0" # Faint yellow-green
    BIEGE = "#F5F5DC" # Faint yellow-brown
    SEASHELL = "#FFF5EE" # Faint orange-brown
    AZURE = "#F0FFFF" # Faint blue-green
    HONEYDEW = "#F0FFF0" # Faint-green
    MISTYROSE = "#FFE4E1" # Faint-rose
    
    # Black and grey colors
    BLACK = "#000000"
    DARKSLATEGRAY = "#2F4F4F"
    SLATEGRAY = "#708090"
    DIMGRAY = "#696969"  # Descending gray family
    GRAY = GREY = "#808080"  # ↓
    DARKGRAY = "#A9A9A9"
    SILVER = "#C0C0C0"
    LIGHTGRAY = "#D3D3D3"
    GAINSBORO = "#DCDCDC"
    
    # Now, ROY-G-BIV of rainbow:
    RED = "#FF0000"
    DARKRED = "#8B0000"
    FIREBRICK = "#B22222"
    CRIMSON = "#DC143C"
    SALMON = "#FA8072"
    ROSE =  "#F08784"
    
    ORANGE = "#FFA500"
    DARKORANGE = "FF8C00"
    ORANGERED = "#FF4500"
    TOMATO = "#FF6347"
    CORAL = "#FF7F50"
    
    YELLOW = "#FFFF00"
    LIGHTYELLOW = "#FFFFE0"
    GOLD = "#FFD700"
    DARKKHAKI = "#BDB76B"
    KHAKI = "#F0E68C"
    PEACHPUFF = "#FFDAB9"
    
    GREEN = "#008000"
    DARKGREEN = "#006400"
    SEAGREEN = "#2E8B57"
    LIMEGREEN = "#32CD32"
    OLIVE = "#808000"  # Gold-green
    LIME = "##00FF00"  # Neon-lightgreen
    YELLOWGREEN = "#9ACD32"
    GREENYELLOW = "#ADFF2F"
        
    BLUE = "#0000FF"
    DARKBLUE = "#00008B"
    NAVY = "#000080"
    DODGERBLUE = "#1E90FF"
    ROYALBLUE = "#4169E1"
    DEEPSKYBLUE = "#00BFFF"

    INDIGO = "#4B0082"
    PURPLE = "#800080"
    VIOLET = "#EE82EE"
    LAVENDER = "#E6E6FA"
    FUCHSIA = MAGENTA = "#FF00FF"
    DEEPPINK = "#FF1493"
    HOTPINK = "#FF69B4"
    PINK = "#FFC0CB"
    
    # Other basic colors
    MAROON = "#800000"
    AQUA = CYAN = "#00FFFF"
    TEAL = "#008080"

    
from time import sleep

class Wait:
    def seconds(s=1):
        sleep(s)
        
        
