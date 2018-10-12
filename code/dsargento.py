#!/usr/bin/env python3
import random

color_collection = (
    '\33[31m',  # Red
    '\33[91m',  # Red 2
    '\33[32m',  # Green
    '\33[92m',  # Green 2
    '\33[33m',  # Yellow
    '\33[93m',  # Yellow 2
    '\33[34m',  # Blue
    '\33[94m',  # Blue 2
    '\33[35m',  # Violet
    '\33[95m',  # Violet 2
    '\33[36m',  # Beige
    '\33[96m',  # Beige 2
    '\33[37m',  # White
    '\33[97m',  # White 2
)

string = "Hello world!"

for char in string:
    print(color_collection[random.randrange(len(color_collection))] + char + "\033[0m", end='')
print()
