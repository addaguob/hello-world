print("init bpy...")

def bfunc():
    print("bpy.bfunc called")


from ..adir import apy
from ..adir.apy import afunc

def afunc_via_b():
    print("bpy.afunc_via_b:", afunc())
    
if __name__ == "__main__":
    bfunc()
    afunc_via_b()
