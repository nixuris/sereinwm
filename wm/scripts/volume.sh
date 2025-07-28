#!/bin/bash

# You can call this script like this:
# $./volume.sh up
# $./volume.sh down
# $./volume.sh mute

function get_volume {
    pactl get-sink-volume @DEFAULT_SINK@ | grep -oP '\d+(?=%)' | head -n 1
}

function is_mute {
    pactl get-sink-mute @DEFAULT_SINK@ | grep -q 'yes'
}

function send_notification {
    DIR=`dirname "$0"`
    volume=`get_volume`
bar=$(seq -s "─" $(($volume/5)) | sed 's/[0-9]//g')
# Send the notification
$DIR/notify-send.sh "Volume $volume%" -i " " -t 2000 -h int:value:"$volume" -h string:synchronous:"$bar" --replace=555
}

case $1 in
    up)
	# Set the volume on (if it was muted)
	pactl set-sink-mute @DEFAULT_SINK@ 0 > /dev/null
	# Up the volume (+ 5%)
	pactl set-sink-volume @DEFAULT_SINK@ +2% > /dev/null
	send_notification
	;;
    down)
	pactl set-sink-mute @DEFAULT_SINK@ 0 > /dev/null
	pactl set-sink-volume @DEFAULT_SINK@ -2% > /dev/null
	send_notification
	;;
    mute)
    	# Toggle mute
	pactl set-sink-mute @DEFAULT_SINK@ toggle > /dev/null
	if is_mute ; then
    DIR=`dirname "$0"`
    $DIR/notify-send.sh -i "" --replace=555 -u normal "Mute" -t 2000
	else
	    send_notification
	fi
	;;
esac
