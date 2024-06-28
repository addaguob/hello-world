print("init bpy...")

def bfunc():
    print("bpy.bfunc called")


from adir import apy
def afunc_via_b():
    print("bpy.afunc_via_b: ", end="")
    apy.afunc()
    # So far, if this function is imported and called via modu, its parent package,
    # it works fine
    # BUT NOT as a script or like below:
    
if __name__ == "__main__":
    bfunc()
    afunc_via_b()
