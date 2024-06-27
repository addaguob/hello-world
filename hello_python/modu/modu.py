print("init modu...")

from adir import apy
from bdir import bpy


apy.afunc()
bpy.bfunc()

from bdir.bpy import afunc_via_b

afunc_via_b()