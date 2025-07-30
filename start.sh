#!/bin/sh
clipmenud &
picom -b --config ~/.config/sereinwm/config/picom.conf
xset r rate 200 50 &
export XMODIFIERS=@im=fcitx
export GTK_IM_MODULE=fcitx
export QT_IM_MODULE=fcitx
export SDL_IM_MODULE=fcitx
export GLFW_IM_MODULE=fcitx
feh --bg-scale ~/.config/sereinwm/config/sereinwm/pics/wave.png &
fcitx5 &
dunst &
blueman-applet &
mpris-discord-rpc &
udiskie &
dash ~/.config/sereinwm/config/sereinwm/scripts/bar.sh &
#while type sereinwm >/dev/null; do sereinwm && continue || break; done
exec sereinwm
