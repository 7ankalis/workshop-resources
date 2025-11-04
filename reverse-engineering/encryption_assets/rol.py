#!/usr/bin/env python3
import sys

def rol8(v, r):
    r &= 7
    return ((v << r) | (v >> (8 - r))) & 0xFF

def rol_xor_encrypt(data: bytes, key_base: int=0x5A):
    out = []
    for i, b in enumerate(data):
        rot = rol8(b, i % 5)
        enc = rot ^ (key_base ^ (i & 0xFF))
        out.append(enc)
    return bytes(out)

def to_c_array(bts, name="enc"):
    parts = ", ".join(f"0x{x:02X}" for x in bts)
    return f"static const unsigned char {name}[] = {{ {parts} }};"

if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("Usage: encrypt_rol_xor.py <flag string> [key_base_hex]")
        sys.exit(1)
    flag = sys.argv[1].encode('utf-8')
    key_base = int(sys.argv[2], 16) if len(sys.argv) > 2 else 0x5A
    enc = rol_xor_encrypt(flag, key_base)
    print("/* key_base: 0x%02X */" % key_base)
    print(to_c_array(enc, "enc"))
    print("size =", len(enc))

