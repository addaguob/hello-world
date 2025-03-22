class UnsignedInt:
    """A class to enforce unsigned integers (≥ 0)"""
    def __init__(self, value: int):
        if not isinstance(value, int):
            raise TypeError(f"Expected an integer, received {type(value).__name__}")
        if value < 0:
            raise ValueError("Only non-negative values are allowed")
        self.value = value

    def __repr__(self):
        return f"UnsignedInt({self.value})"

# ✅ Valid usage
x = UnsignedInt(100)
print(x)  # Output: UnsignedInt(100)
print(str(x))  # Output: 100

# ❌ Throws an error for negative numbers
y = UnsignedInt(-5)  # ValueError: Only non-negative values are allowed

# ❌ Throws an error for non-integer types
z = UnsignedInt(10.5)  # TypeError: Expected an integer, received float3