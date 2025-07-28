#!/bin/sh 
feh --bg-scale ~/Pictures/Colourful/cloud &
slstatus &
copyq &
export XMODIFIERS=@im=fcitx
export GTK_IM_MODULE=fcitx
export QT_IM_MODULE=fcitx
export SDL_IM_MODULE=fcitx
export GLFW_IM_MODULE=fcitx
easyeffects &
fcitx5 &
dunst &
exec dwm
