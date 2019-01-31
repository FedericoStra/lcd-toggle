#!/usr/bin/python3

import os


def get_device_path():
    backlight = os.path.join('/', 'sys', 'class', 'backlight')
    devices = os.listdir(backlight)
    return os.path.join(backlight, devices[0])


def main():
    device_path = get_device_path()
    brightness_path = os.path.join(device_path, 'brightness')
    power_path = os.path.join(device_path, 'bl_power')

    with open(brightness_path, 'r') as brightness_file:
        print(brightness_file.read(), end='')

    with open(power_path, 'r+') as power_file:
        content = power_file.read()
        power_file.seek(0)

        #  print(content, end='')
        power = int(content)
        if power == 0:
            new_power = 1
        else:
            new_power = 0

        power_file.write(str(new_power))


if __name__ == '__main__':
    import sys
    sys.exit(main())
