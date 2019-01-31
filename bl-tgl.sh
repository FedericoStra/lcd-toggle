#!/bin/bash

state=$(cat /sys/class/backlight/intel_backlight/bl_power)

echo state is "$state"

case $state in
0)
	notify-send "LCD is on: turning off"
	echo "LCD is on: turning off"
	echo 1 > /sys/class/backlight/intel_backlight/bl_power
	;;
1)
	notify-send "LCD is off: turning on"
	echo "LCD is off: turning on"
	echo 0 > /sys/class/backlight/intel_backlight/bl_power
	;;
esac
