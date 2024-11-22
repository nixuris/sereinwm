// clang-format off
/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 2;        // border pixel of windows
static const unsigned int snap      = 32;       // snap pixel
static const unsigned int gappih    = 40;        // horiz inner gap between windows
static const unsigned int gappiv    = 40;        // vert inner gap between windows
static const unsigned int gappoh    = 40;        // horiz outer gap between windows and screen edge
static const unsigned int gappov    = 40;        // vert outer gap between windows and screen edge
static       int smartgaps          = 0;        // 1 means no outer gap when there is only one window
static const int showbar            = 1;        // 0 means no bar
static const int topbar             = 1;        // 0 means bottom bar
static const char *fonts[]          = { "Jetbrains Mono NerdFont:size=12:style=Bold", "monospace:size=12" };
static const char dmenufont[]       = "Jetbrains Mono NerdFont:size=12:style=Bold";
#include "themes/mhtheme.h"
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
	[SchemeSel]  = { col_gray4, col_accnt, col_accnt  },
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "easyeffects",  NULL,   NULL,       1 << 8,       0,           -1 },	
	{ "Gimp",     NULL,       NULL,       0,            1,           -1 },
	{ "Firefox",  NULL,       NULL,       1 << 8,       0,           -1 },
};

/* layout(s) */
static const float mfact     = 0.5;   /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;     /* number of clients in master area */
static const int resizehints = 0;     /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1;  /* 1 will force focus on the fullscreen window */

#define FORCE_VSPLIT 1  /* nrowgrid layout: force two clients to always split vertically */
#include "vanitygaps.c"
#include "unfloat.c"

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "IRISU",    tile },    /* first entry is default */
	{ "[M]",      monocle },	//2
	{ "[@]",      spiral },		//3
	{ "[\\]",     deck },	//4
	{ "H[]",      dwindle },		//5
	{ "TTT",      bstack },		//6
	{ "===",      bstackhoriz },	//7
	{ "HHH",      grid },		//8
	{ "###",      nrowgrid },	//9
	{ "---",      horizgrid },	//10
	{ ":::",      gaplessgrid },	//11
	{ "|M|",      centeredmaster },	//12
	{ ">M>",      centeredfloatingmaster },	//13
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ NULL,       NULL },
};

/* key definitions */
#define MODKEY Mod4Mask
#define ALTKEY Mod1Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[]   = { "dmenu_run", "-c", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_accnt, "-sf", col_gray4, NULL };
static const char *termcmd[]    = { "st", NULL };
static const char *upvol[] = { "sh", "-c", "/home/irisu/DWM-dot/home/wm/scripts/volume.sh up", NULL };
static const char *downvol[] = { "sh", "-c", "/home/irisu/DWM-dot/home/wm/scripts/volume.sh down", NULL };
static const char *mutevol[] = { "sh", "-c", "/home/irisu/DWM-dot/home/wm/scripts/volume.sh mute", NULL };
//static const char *upvol[]      = { "/usr/bin/wpctl", "set-volume", "@DEFAULT_AUDIO_SINK@", "2%+", NULL };
//static const char *downvol[] 	= { "/usr/bin/wpctl", "set-volume", "@DEFAULT_AUDIO_SINK@", "2%-", NULL };
//static const char *mutevol[] 	= { "/usr/bin/wpctl", "set-mute", "@DEFAULT_AUDIO_SINK@", "toggle", NULL };
static const char *shutdown[]	= { "shutdown now", NULL};
static const char *restart[] 	= { "/sbin/reboot", NULL};
static const char *brightup[]   = { "brightnessctl", "set", "5%+", NULL };
static const char *brightdown[] = { "brightnessctl", "set", "10%-", NULL };
static const char *code[]    	= { "code", NULL};
static const char *monitor[]	= { "st -e htop", NULL};
#include "X11/XF86keysym.h"
#include "movestack.c"
static const Key keys[] = {
	/* modifier                     key                    function        argument */
	//XF86Keys
	
	
	{ MODKEY,                       XK_r,                  spawn,          SHCMD("rofi -show drun") },                                 // open app launcher MOD+r
	{ 0,                          XF86XK_AudioRaiseVolume, spawn,          {.v = upvol   } },
	{ 0,                          XF86XK_AudioLowerVolume, spawn, 	       {.v = downvol } },
	{ 0, 			      XF86XK_AudioMute,        spawn, 	       {.v = mutevol } },
	//{ MODKEY|ShiftMask, 	      XK_BackSpace,	       spawn, 	       {.v = restart} },	
	{ 0,   	                      XF86XK_Launch3,	       spawn, 	       {.v = restart} },	
	{ 0, 			      XF86XK_PowerOff,	       spawn, 	       {.v = shutdown} },	
	{ 0, 		              XF86XK_MonBrightnessDown,spawn, 	       {.v = brightdown} },
	{ 0, 			      XF86XK_MonBrightnessUp,  spawn, 	       {.v = brightup  } },

	//Spawn Keys
	
	{ MODKEY,                       XK_r,                  spawn,          SHCMD("rofi -show drun") },                                 // open app launcher MOD+r
	{ MODKEY,                       XK_Return,             spawn,          {.v = termcmd } },                                 // spawn terminal MOD+return
	
	{ MODKEY,                       XK_period,             spawn,          SHCMD("rofimoji") },                                 // spawn emoji selector
	{ MODKEY,                       XK_v,                  spawn,          SHCMD("copyq toggle") },                                 // spawn clipboard
	
	//Apps
		
	{ MODKEY,			XK_p,		       spawn,	       SHCMD("st -e htop")},				  // sys monitor
	{ ALTKEY,             XK_f,                  spawn,          SHCMD("zen-browser") },
	{ MODKEY|ShiftMask,             XK_s,                  spawn,          SHCMD("flameshot gui") },                     // screenshot MOD+Shift+S
	{ MODKEY,                       XK_t,                  spawn,          SHCMD("st -e ranger") },                      // open file manager (Nautilus) MOD+t
	//{ MODKEY,                       XK_t,                  spawn,          SHCMD("nautilus --new-window") },                      // open file manager (Nautilus) MOD+t
	{ ALTKEY,			XK_s,		       spawn,	       SHCMD("st -e cmus") },			  // music
	{ MODKEY,  			XK_c,		       spawn,	       {.v = code }},					  //vscode
	{ MODKEY,                       XK_b,                  togglebar,      {0} },                                             // show hide bar MOD+b
	{ MODKEY,                       XK_l,                  spawn,          SHCMD("slock") },                             // lockscreen MOD+L
	
	//Navigation
	
	{ MODKEY,                       XK_Down,               focusstack,     {.i = +1 } },                                      // focus window down stack MOD+Down
	{ MODKEY,                       XK_Up,                 focusstack,     {.i = -1 } },                                      // focus window up stack MOD+Up
	{ MODKEY|ControlMask,           XK_Left,               movestack,      {.i = -1 } },                                      // move window left stack MOD+Shift+Left
	{ MODKEY|ControlMask,           XK_Right,              movestack,      {.i = +1 } },                                      // move window up stack MOD+Shift+Right
	{ MODKEY,                       XK_i,                  incnmaster,     {.i = +1 } },                                      // increase windows in master stack MOD+i
	{ MODKEY,                       XK_d,                  incnmaster,     {.i = -1 } },                                      // decrease windows in master stack MOD+d
	{ MODKEY|ShiftMask,             XK_Left,               setmfact,       {.f = -0.05} },                                    // adjust mfact MOD+SHIFT+Left
	{ MODKEY|ShiftMask,             XK_Right,              setmfact,       {.f = +0.05} },                                    // adjust mfact MOD+SHIFT+Right
	{ MODKEY|ShiftMask,             XK_Up,                 setcfact,       {.f = +0.25} },                                    // adjust cfact MOD+SHIFT+Up
	{ MODKEY|ShiftMask,             XK_Down,               setcfact,       {.f = -0.25} },                                    // adjust cfact MOD+SHIFT+Down
	{ MODKEY|ShiftMask,             XK_o,                  setcfact,       {.f =  0.00} },                                    // adjust cfact MOD+O
	{ MODKEY|ShiftMask,             XK_Return,             zoom,           {0} },                                             // MOD+Return
	{ MODKEY|ALTKEY,                XK_u,                  incrgaps,       {.i = +10 } },                                     // adjust gaps MOD+ALT+u
	{ MODKEY|ALTKEY|ShiftMask,      XK_u,                  incrgaps,       {.i = -10 } },                                     // adjust gaps MOD+ALT+U
	{ MODKEY|ShiftMask,             XK_bracketleft,        setborderpx,    {.i = -2 } },                                      // increase border width MOD+{
	{ MODKEY|ShiftMask,             XK_bracketright,       setborderpx,    {.i = +2 } },                                      // decrease border width MOD+}
	{ MODKEY,                       XK_Tab,                view,           {0} },                                             // tab tag MOD+Tab
	{ MODKEY,                       XK_q,                  killclient,     {0} },                                             // close window MOD+c
        { MODKEY,                       XK_f,                  togglefullscr,  {0} },                                             // toggle actualfullscreen MOD+f
	{ MODKEY,             XK_w,                  unfloatvisible, {.v = &layouts[0]} },                              // make floating window tiled MOD+Z
	{ MODKEY|ALTKEY,                XK_1,                  setlayout,      {.v = &layouts[0]} },                              // change layout to tile MOD+ALT+1
	{ MODKEY|ALTKEY,                XK_2,                  setlayout,      {.v = &layouts[11]} },                             // change layout to float MOD+ALT+2
	{ MODKEY|ALTKEY,                XK_3,                  setlayout,      {.v = &layouts[5]} },                              // change layout to monocle MOD+ALT+3
	{ MODKEY|ALTKEY,                XK_4,                  setlayout,      {.v = &layouts[7]} },                             // change layout to centeredmaster MOD+ALT+4
	{ MODKEY|ALTKEY,                XK_5,                  setlayout,      {.v = &layouts[5]} },                              // change layout to bstac MOD+ALT+5
	{ MODKEY|ALTKEY,                XK_6,                  setlayout,      {.v = &layouts[7]} },                              // change layout to grid MOD+ALT+6
	{ MODKEY|ALTKEY,                XK_7,                  setlayout,      {.v = &layouts[4]} },                              // change layout to spiral MOD+ALT+7
	{ MODKEY,                       XK_0,                  view,           {.ui = ~0 } },                                     // view all windows MOD+0
	{ MODKEY|ShiftMask,             XK_0,                  tag,            {.ui = ~0 } },                                     // make window on all tags MOD+SHIFT+0
	{ MODKEY,                       XK_comma,              focusmon,       {.i = -1 } },                                      // move window to monitor MOD+,
	{ MODKEY,                       XK_period,             focusmon,       {.i = +1 } },                                      // move window to monitor MOD+.
	{ MODKEY|ShiftMask,             XK_comma,              tagmon,         {.i = -1 } },                                      // move window to monitor MOD+SHIFT+,
	{ MODKEY|ShiftMask,             XK_period,             tagmon,         {.i = +1 } },                                      // move window to monitor MOD+SHIFT+.
	
	//Workspaces
	
	TAGKEYS(                        XK_1,                                    0)                                               // change tag MOD+[1-9]
	TAGKEYS(                        XK_2,                                    1)
	TAGKEYS(                        XK_3,                                    2)
	TAGKEYS(                        XK_4,                                    3)
	TAGKEYS(                        XK_5,                                    4)
	TAGKEYS(                        XK_6,                                    5)
	TAGKEYS(                        XK_7,                                    6)
	TAGKEYS(                        XK_8,                                    7)
	TAGKEYS(                        XK_9,                                    8)
	
	{ MODKEY,                       XK_BackSpace,          spawn,           SHCMD("pkill dwm") },                                             // quit dwm MOD+backspace
	//{ MODKEY,                       XK_BackSpace,          spawn,           SHCMD("sudo systemctl restart ly") },                                             // quit dwm MOD+backspace
	//{ MODKEY,                       XK_BackSpace,          quit,           {0} },                                             // quit dwm MOD+backspace
};


/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};
