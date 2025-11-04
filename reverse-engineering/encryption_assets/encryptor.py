#!/usr/bin/env python3
import sys

def xor_encrypt(data: bytes, key: int):
    return bytes(b ^ key for b in data)

def to_c_array(bts, name="enc"):
    parts = ", ".join(f"0x{x:02X}" for x in bts)
    return f"static const unsigned char {name}[] = {{ {parts} }};"

if __name__ == "__main__":
    if len(sys.argv) < 3:
        print("Usage: encrypt_xor.py <key_hex, e.g. AB> <flag string>")
        sys.exit(1)
    key = int(sys.argv[1], 16)
    flag = sys.argv[2].encode('utf-8')
    enc = xor_encrypt(flag, key)
    print("/* XOR key: 0x%02X */" % key)
    print(to_c_array(enc, "enc"))
    print("size =", len(enc))

