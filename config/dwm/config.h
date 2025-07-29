/* See LICENSE file for copyright and license details. */

/* Helper macros for spawning commands */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }
#define CMD(...)   { .v = (const char*[]){ __VA_ARGS__, NULL } }

/* appearance */
#if ROUNDED_CORNERS_PATCH
static const unsigned int borderpx       = 2;   /* border pixel of windows */
static const int corner_radius           = 10;
#else
static const unsigned int borderpx       = 1;   /* border pixel of windows */
#endif // ROUNDED_CORNERS_PATCH
#if BAR_BORDER_PATCH
/* This allows the bar border size to be explicitly set separately from borderpx.
 * If left as 0 then it will default to the borderpx value of the monitor and will
 * automatically update with setborderpx. */
static const unsigned int barborderpx    = 0;  /* border pixel of bar */
#endif // BAR_BORDER_PATCH
static const unsigned int snap           = 32;  /* snap pixel */
#if SWALLOW_PATCH
static const int swallowfloating         = 0;   /* 1 means swallow floating windows by default */
#endif // SWALLOW_PATCH
#if BAR_TAGPREVIEW_PATCH
static const int scalepreview            = 4;        /* Tag preview scaling */
#endif // BAR_TAGPREVIEW_PATCH
#if NO_MOD_BUTTONS_PATCH
static int nomodbuttons                  = 1;   /* allow client mouse button bindings that have no modifier */
#endif // NO_MOD_BUTTONS_PATCH
#if VANITYGAPS_PATCH
static const unsigned int gappih         = 40;  /* horiz inner gap between windows */
static const unsigned int gappiv         = 40;  /* vert inner gap between windows */
static const unsigned int gappoh         = 40;  /* horiz outer gap between windows and screen edge */
static const unsigned int gappov         = 40;  /* vert outer gap between windows and screen edge */
static const int smartgaps_fact          = 0;   /* gap factor when there is only one client; 0 = no gaps, 3 = 3x outer gaps */
#endif // VANITYGAPS_PATCH
#if AUTOSTART_PATCH
static const char autostartblocksh[]     = "autostart_blocking.sh";
static const char autostartsh[]          = "autostart.sh";
static const char dwmdir[]               = "dwm";
static const char localshare[]           = ".local/share";
#endif // AUTOSTART_PATCH
#if BAR_ANYBAR_PATCH
static const int usealtbar               = 1;        /* 1 means use non-dwm status bar */
static const char *altbarclass           = "Polybar"; /* Alternate bar class name */
static const char *altbarcmd             = "$HOME/bar.sh"; /* Alternate bar launch command */
#endif // BAR_ANYBAR_PATCH
#if BAR_HOLDBAR_PATCH
static const int showbar                 = 0;   /* 0 means no bar */
#else
static const int showbar                 = 1;   /* 0 means no bar */
#endif // BAR_HOLDBAR_PATCH
static const int topbar                  = 1;   /* 0 means bottom bar */
#if TAB_PATCH
/*  Display modes of the tab bar: never shown, always shown, shown only in  */
/*  monocle mode in the presence of several windows.                        */
/*  Modes after showtab_nmodes are disabled.                                */
enum showtab_modes { showtab_never, showtab_auto, showtab_nmodes, showtab_always};
static const int showtab                 = showtab_auto;        /* Default tab bar show mode */
static const int toptab                  = False;               /* False means bottom tab bar */
#endif // TAB_PATCH
#if BAR_HEIGHT_PATCH
static const int bar_height              = 0;   /* 0 means derive from font, >= 1 explicit height */
#endif // BAR_HEIGHT_PATCH
#if BAR_PADDING_PATCH
static const int vertpad                 = 10;  /* vertical padding of bar */
static const int sidepad                 = 10;  /* horizontal padding of bar */
#endif // BAR_PADDING_PATCH
#if BAR_WINICON_PATCH
#define ICONSIZE 20    /* icon size */
#define ICONSPACING 5  /* space between icon and title */
#endif // BAR_WINICON_PATCH
#if FOCUSONCLICK_PATCH
static const int focusonwheel            = 0;
#endif // FOCUSONCLICK_PATCH
#if FLOATPOS_PATCH
static int floatposgrid_x                = 5;  /* float grid columns */
static int floatposgrid_y                = 5;  /* float grid rows */
#endif // FLOATPOS_PATCH
#if RIODRAW_PATCH
static const char slopspawnstyle[]       = "-t 0 -c 0.92,0.85,0.69,0.3 -o"; /* do NOT define -f (format) here */
static const char slopresizestyle[]      = "-t 0 -c 0.92,0.85,0.69,0.3"; /* do NOT define -f (format) here */
static const int riodraw_borders         = 0;  /* 0 or 1, indicates whether the area drawn using slop includes the window borders */
#if SWALLOW_PATCH
static const int riodraw_matchpid        = 1;  /* 0 or 1, indicates whether to match the PID of the client that was spawned with riospawn */
#endif // SWALLOW_PATCH
#endif // RIODRAW_PATCH
/* Status is to be shown on: -1 (all monitors), 0 (a specific monitor by index), 'A' (active monitor) */
#if BAR_STATUSALLMONS_PATCH
static const int statusmon               = -1;
#elif BAR_STATICSTATUS_PATCH
static const int statusmon               = 0;
#else
static const int statusmon               = 'A';
#endif // BAR_STATUSALLMONS_PATCH | BAR_STATICSTATUS_PATCH
#if BAR_STATUSPADDING_PATCH
static const int horizpadbar             = 2;   /* horizontal padding for statusbar */
static const int vertpadbar              = 0;   /* vertical padding for statusbar */
#endif // BAR_STATUSPADDING_PATCH
#if BAR_STATUSBUTTON_PATCH
static const char buttonbar[]            = "<O>";
#endif // BAR_STATUSBUTTON_PATCH
#if BAR_SYSTRAY_PATCH
static const unsigned int systrayspacing = 2;   /* systray spacing */
static const int showsystray             = 1;   /* 0 means no systray */
#endif // BAR_SYSTRAY_PATCH
#if BAR_TAGLABELS_PATCH
static const char ptagf[] = "[%s %s]";          /* format of a tag label */
static const char etagf[] = "[%s]";             /* format of an empty tag */
static const int lcaselbl = 0;                  /* 1 means make tag label lowercase */
#endif // BAR_TAGLABELS_PATCH
#if BAR_UNDERLINETAGS_PATCH
static const unsigned int ulinepad = 5;         /* horizontal padding between the underline and tag */
static const unsigned int ulinestroke  = 2;     /* thickness / height of the underline */
static const unsigned int ulinevoffset = 0;     /* how far above the bottom of the bar the line should appear */
static const int ulineall = 0;                  /* 1 to show underline on all tags, 0 for just the active ones */
#endif // BAR_UNDERLINETAGS_PATCH

#if NAMETAG_PATCH
#if NAMETAG_PREPEND_PATCH
/* The format in which the tag is written when named. E.g. %d: %.12s will write the tag number
 * followed the first 12 characters of the given string. You can also just use "%d: %s" here. */
#define NAMETAG_FORMAT "%d: %.12s"
#else
#define NAMETAG_FORMAT "%s"
#endif // NAMETAG_PREPEND_PATCH
/* The maximum amount of bytes reserved for each tag text. */
#define MAX_TAGLEN 16
/* The command to run (via popen). This can be tailored by adding a prompt, passing other command
 * line arguments or providing name options. Optionally you can use other dmenu like alternatives
 * like rofi -dmenu. */
#define NAMETAG_COMMAND "dmenu < /dev/null"
#endif // NAMETAG_PATCH

#if ALT_TAB_PATCH
/* alt-tab configuration */
static const unsigned int tabmodkey        = 0x40; /* (Alt) when this key is held down the alt-tab functionality stays active. Must be the same modifier as used to run alttabstart */
static const unsigned int tabcyclekey      = 0x17; /* (Tab) when this key is hit the menu moves one position forward in client stack. Must be the same key as used to run alttabstart */
static const unsigned int tabposy          = 1;    /* tab position on Y axis, 0 = top, 1 = center, 2 = bottom */
static const unsigned int tabposx          = 1;    /* tab position on X axis, 0 = left, 1 = center, 2 = right */
static const unsigned int maxwtab          = 600;  /* tab menu width */
static const unsigned int maxhtab          = 200;  /* tab menu height */
#endif // ALT_TAB_PATCH

/* Indicators: see patch/bar_indicators.h for options */
static int tagindicatortype              = INDICATOR_TOP_LEFT_SQUARE;
static int tiledindicatortype            = INDICATOR_NONE;
static int floatindicatortype            = INDICATOR_TOP_LEFT_SQUARE;
#if FAKEFULLSCREEN_CLIENT_PATCH && !FAKEFULLSCREEN_PATCH
static int fakefsindicatortype           = INDICATOR_PLUS;
static int floatfakefsindicatortype      = INDICATOR_PLUS_AND_LARGER_SQUARE;
#endif // FAKEFULLSCREEN_CLIENT_PATCH
#if ALWAYSONTOP_PATCH
static int aotindicatortype              = INDICATOR_TOP_LEFT_LARGER_SQUARE;
#endif // ALWAYSONTOP_PATCH
#if ONLYQUITONEMPTY_PATCH
static const int quit_empty_window_count = 0;   /* only allow dwm to quit if no (<= count) windows are open */
#endif // ONLYQUITONEMPTY_PATCH
#if BAR_EXTRASTATUS_PATCH
static const char statussep              = ';'; /* separator between status bars */
#endif // BAR_EXTRASTATUS_PATCH
#if BAR_TABGROUPS_PATCH
#if MONOCLE_LAYOUT
static void (*bartabmonfns[])(Monitor *) = { monocle /* , customlayoutfn */ };
#else
static void (*bartabmonfns[])(Monitor *) = { NULL /* , customlayoutfn */ };
#endif // MONOCLE_LAYOUT
#endif // BAR_TABGROUPS_PATCH
#if BAR_PANGO_PATCH
static const char font[]                 = "Jetbrains Mono NerdFont:size=12:style=SemiBold";
#else
static const char *fonts[]               = { "Jetbrains Mono NerdFont:size=12:style=SemiBold" };
#endif // BAR_PANGO_PATCH
static const char dmenufont[]            = "Jetbrains Mono NerdFont:size=12:style=SemiBold";

static char c000000[]                    = "#000000"; // placeholder value

static char normfgcolor[]                = "#bbbbbb";
static char normbgcolor[]                = "#222222";
static char normbordercolor[]            = "#444444";
static char normfloatcolor[]             = "#db8fd9";

static char selfgcolor[]                 = "#eeeeee";
static char selbgcolor[]                 = "#005577";
static char selbordercolor[]             = "#005577";
static char selfloatcolor[]              = "#005577";

static char titlenormfgcolor[]           = "#bbbbbb";
static char titlenormbgcolor[]           = "#222222";
static char titlenormbordercolor[]       = "#444444";
static char titlenormfloatcolor[]        = "#db8fd9";

static char titleselfgcolor[]            = "#eeeeee";
static char titleselbgcolor[]            = "#005577";
static char titleselbordercolor[]        = "#005577";
static char titleselfloatcolor[]         = "#005577";

static char tagsnormfgcolor[]            = "#bbbbbb";
static char tagsnormbgcolor[]            = "#222222";
static char tagsnormbordercolor[]        = "#444444";
static char tagsnormfloatcolor[]         = "#db8fd9";

static char tagsselfgcolor[]             = "#eeeeee";
static char tagsselbgcolor[]             = "#005577";
static char tagsselbordercolor[]         = "#005577";
static char tagsselfloatcolor[]          = "#005577";

static char hidnormfgcolor[]             = "#005577";
static char hidselfgcolor[]              = "#227799";
static char hidnormbgcolor[]             = "#222222";
static char hidselbgcolor[]              = "#222222";

static char urgfgcolor[]                 = "#bbbbbb";
static char urgbgcolor[]                 = "#222222";
static char urgbordercolor[]             = "#ff0000";
static char urgfloatcolor[]              = "#db8fd9";

#if BAR_LTSYMBOL_SCHEME_PATCH
static char ltsymbolfgcolor[]            = "#222222";
static char ltsymbolbgcolor[]            = "#fe9877";
#endif // BAR_LTSYMBOL_SCHEME_PATCH

#if RENAMED_SCRATCHPADS_PATCH
static char scratchselfgcolor[]          = "#FFF7D4";
static char scratchselbgcolor[]          = "#77547E";
static char scratchselbordercolor[]      = "#894B9F";
static char scratchselfloatcolor[]       = "#894B9F";

static char scratchnormfgcolor[]         = "#FFF7D4";
static char scratchnormbgcolor[]         = "#664C67";
static char scratchnormbordercolor[]     = "#77547E";
static char scratchnormfloatcolor[]      = "#77547E";
#endif // RENAMED_SCRATCHPADS_PATCH

#if BAR_FLEXWINTITLE_PATCH
static char normTTBbgcolor[]             = "#330000";
static char normLTRbgcolor[]             = "#330033";
static char normMONObgcolor[]            = "#000033";
static char normGRIDbgcolor[]            = "#003300";
static char normGRD1bgcolor[]            = "#003300";
static char normGRD2bgcolor[]            = "#003300";
static char normGRDMbgcolor[]            = "#506600";
static char normHGRDbgcolor[]            = "#b96600";
static char normDWDLbgcolor[]            = "#003333";
static char normSPRLbgcolor[]            = "#333300";
static char normfloatbgcolor[]           = "#115577";
static char actTTBbgcolor[]              = "#440000";
static char actLTRbgcolor[]              = "#440044";
static char actMONObgcolor[]             = "#000044";
static char actGRIDbgcolor[]             = "#004400";
static char actGRD1bgcolor[]             = "#004400";
static char actGRD2bgcolor[]             = "#004400";
static char actGRDMbgcolor[]             = "#507711";
static char actHGRDbgcolor[]             = "#b97711";
static char actDWDLbgcolor[]             = "#004444";
static char actSPRLbgcolor[]             = "#444400";
static char actfloatbgcolor[]            = "#116688";
static char selTTBbgcolor[]              = "#550000";
static char selLTRbgcolor[]              = "#550055";
static char selMONObgcolor[]             = "#212171";
static char selGRIDbgcolor[]             = "#005500";
static char selGRD1bgcolor[]             = "#005500";
static char selGRD2bgcolor[]             = "#005500";
static char selGRDMbgcolor[]             = "#508822";
static char selHGRDbgcolor[]             = "#b98822";
static char selDWDLbgcolor[]             = "#005555";
static char selSPRLbgcolor[]             = "#555500";
static char selfloatbgcolor[]            = "#117799";
#endif // BAR_FLEXWINTITLE_PATCH

#if BAR_ALPHA_PATCH
static const unsigned int baralpha = 0xd0;
static const unsigned int borderalpha = OPAQUE;
static const unsigned int alphas[][3] = {
	/*                       fg      bg        border     */
	[SchemeNorm]         = { OPAQUE, baralpha, borderalpha },
	[SchemeSel]          = { OPAQUE, baralpha, borderalpha },
	[SchemeTitleNorm]    = { OPAQUE, baralpha, borderalpha },
	[SchemeTitleSel]     = { OPAQUE, baralpha, borderalpha },
	[SchemeTagsNorm]     = { OPAQUE, baralpha, borderalpha },
	[SchemeTagsSel]      = { OPAQUE, baralpha, borderalpha },
	[SchemeHidNorm]      = { OPAQUE, baralpha, borderalpha },
	[SchemeHidSel]       = { OPAQUE, baralpha, borderalpha },
	[SchemeUrg]          = { OPAQUE, baralpha, borderalpha },
	#if BAR_LTSYMBOL_SCHEME_PATCH
	[SchemeLtSymbol]     = { OPAQUE, baralpha, borderalpha },
	#endif // BAR_LTSYMBOL_SCHEME_PATCH
	#if RENAMED_SCRATCHPADS_PATCH
	[SchemeScratchSel]  = { OPAQUE, baralpha, borderalpha },
	[SchemeScratchNorm] = { OPAQUE, baralpha, borderalpha },
	#endif // RENAMED_SCRATCHPADS_PATCH
	#if BAR_FLEXWINTITLE_PATCH
	[SchemeFlexActTTB]   = { OPAQUE, baralpha, borderalpha },
	[SchemeFlexActLTR]   = { OPAQUE, baralpha, borderalpha },
	[SchemeFlexActMONO]  = { OPAQUE, baralpha, borderalpha },
	[SchemeFlexActGRID]  = { OPAQUE, baralpha, borderalpha },
	[SchemeFlexActGRD1]  = { OPAQUE, baralpha, borderalpha },
	[SchemeFlexActGRD2]  = { OPAQUE, baralpha, borderalpha },
	[SchemeFlexActGRDM]  = { OPAQUE, baralpha, borderalpha },
	[SchemeFlexActHGRD]  = { OPAQUE, baralpha, borderalpha },
	[SchemeFlexActDWDL]  = { OPAQUE, baralpha, borderalpha },
	[SchemeFlexActSPRL]  = { OPAQUE, baralpha, borderalpha },
	[SchemeFlexActFloat] = { OPAQUE, baralpha, borderalpha },
	[SchemeFlexInaTTB]   = { OPAQUE, baralpha, borderalpha },
	[SchemeFlexInaLTR]   = { OPAQUE, baralpha, borderalpha },
	[SchemeFlexInaMONO]  = { OPAQUE, baralpha, borderalpha },
	[SchemeFlexInaGRID]  = { OPAQUE, baralpha, borderalpha },
	[SchemeFlexInaGRD1]  = { OPAQUE, baralpha, borderalpha },
	[SchemeFlexInaGRD2]  = { OPAQUE, baralpha, borderalpha },
	[SchemeFlexInaGRDM]  = { OPAQUE, baralpha, borderalpha },
	[SchemeFlexInaHGRD]  = { OPAQUE, baralpha, borderalpha },
	[SchemeFlexInaDWDL]  = { OPAQUE, baralpha, borderalpha },
	[SchemeFlexInaSPRL]  = { OPAQUE, baralpha, borderalpha },
	[SchemeFlexInaFloat] = { OPAQUE, baralpha, borderalpha },
	[SchemeFlexSelTTB]   = { OPAQUE, baralpha, borderalpha },
	[SchemeFlexSelLTR]   = { OPAQUE, baralpha, borderalpha },
	[SchemeFlexSelMONO]  = { OPAQUE, baralpha, borderalpha },
	[SchemeFlexSelGRID]  = { OPAQUE, baralpha, borderalpha },
	[SchemeFlexSelGRD1]  = { OPAQUE, baralpha, borderalpha },
	[SchemeFlexSelGRD2]  = { OPAQUE, baralpha, borderalpha },
	[SchemeFlexSelGRDM]  = { OPAQUE, baralpha, borderalpha },
	[SchemeFlexSelHGRD]  = { OPAQUE, baralpha, borderalpha },
	[SchemeFlexSelDWDL]  = { OPAQUE, baralpha, borderalpha },
	[SchemeFlexSelSPRL]  = { OPAQUE, baralpha, borderalpha },
	[SchemeFlexSelFloat] = { OPAQUE, baralpha, borderalpha },
	#endif // BAR_FLEXWINTITLE_PATCH
};
#endif // BAR_ALPHA_PATCH
#if BAR_VTCOLORS_PATCH
static const char title_bg_dark[]   = "#303030";
static const char title_bg_light[]  = "#fdfdfd";
static const int color_ptrs[][ColCount] = {
	/*                       fg      bg      border  float */
	[SchemeNorm]         = { -1,     -1,     5,      12 },
	[SchemeSel]          = { -1,     -1,     11,     13 },
	[SchemeTitleNorm]    = { 6,      -1,     -1,     -1 },
	[SchemeTitleSel]     = { 6,      -1,     -1,     -1 },
	[SchemeTagsNorm]     = { 2,      0,      0,      -1 },
	[SchemeTagsSel]      = { 6,      5,      5,      -1 },
	[SchemeHidNorm]      = { 5,      0,      0,      -1 },
	[SchemeHidSel]       = { 6,      -1,     -1,     -1 },
	[SchemeUrg]          = { 7,      9,      9,      15 },
	#if BAR_LTSYMBOL_SCHEME_PATCH
	[SchemeLtSymbol]     = { -1,     3,      0,       0 },
	#endif // BAR_LTSYMBOL_SCHEME_PATCH
};
#endif // BAR_VTCOLORS_PATCH

static char *colors[][ColCount] = {
	/*                       fg                bg                border                float */
	[SchemeNorm]         = { normfgcolor,      normbgcolor,      normbordercolor,      normfloatcolor },
	[SchemeSel]          = { selfgcolor,       selbgcolor,       selbordercolor,       selfloatcolor },
	[SchemeTitleNorm]    = { titlenormfgcolor, titlenormbgcolor, titlenormbordercolor, titlenormfloatcolor },
	[SchemeTitleSel]     = { titleselfgcolor,  titleselbgcolor,  titleselbordercolor,  titleselfloatcolor },
	[SchemeTagsNorm]     = { tagsnormfgcolor,  tagsnormbgcolor,  tagsnormbordercolor,  tagsnormfloatcolor },
	[SchemeTagsSel]      = { tagsselfgcolor,   tagsselbgcolor,   tagsselbordercolor,   tagsselfloatcolor },
	[SchemeHidNorm]      = { hidnormfgcolor,   hidnormbgcolor,   c000000,              c000000 },
	[SchemeHidSel]       = { hidselfgcolor,    hidselbgcolor,    c000000,              c000000 },
	[SchemeUrg]          = { urgfgcolor,       urgbgcolor,       urgbordercolor,       urgfloatcolor },
	#if BAR_LTSYMBOL_SCHEME_PATCH
	[SchemeLtSymbol]     = { ltsymbolfgcolor,  ltsymbolbgcolor,  c000000,              c000000 },
	#endif // BAR_LTSYMBOL_SCHEME_PATCH
	#if RENAMED_SCRATCHPADS_PATCH
	[SchemeScratchSel]  = { scratchselfgcolor, scratchselbgcolor, scratchselbordercolor, scratchselfloatcolor },
	[SchemeScratchNorm] = { scratchnormfgcolor, scratchnormbgcolor, scratchnormbordercolor, scratchnormfloatcolor },
	#endif // RENAMED_SCRATCHPADS_PATCH
	#if BAR_FLEXWINTITLE_PATCH
	[SchemeFlexActTTB]   = { titleselfgcolor,  actTTBbgcolor,    actTTBbgcolor,        c000000 },
	[SchemeFlexActLTR]   = { titleselfgcolor,  actLTRbgcolor,    actLTRbgcolor,        c000000 },
	[SchemeFlexActMONO]  = { titleselfgcolor,  actMONObgcolor,   actMONObgcolor,       c000000 },
	[SchemeFlexActGRID]  = { titleselfgcolor,  actGRIDbgcolor,   actGRIDbgcolor,       c000000 },
	[SchemeFlexActGRD1]  = { titleselfgcolor,  actGRD1bgcolor,   actGRD1bgcolor,       c000000 },
	[SchemeFlexActGRD2]  = { titleselfgcolor,  actGRD2bgcolor,   actGRD2bgcolor,       c000000 },
	[SchemeFlexActGRDM]  = { titleselfgcolor,  actGRDMbgcolor,   actGRDMbgcolor,       c000000 },
	[SchemeFlexActHGRD]  = { titleselfgcolor,  actHGRDbgcolor,   actHGRDbgcolor,       c000000 },
	[SchemeFlexActDWDL]  = { titleselfgcolor,  actDWDLbgcolor,   actDWDLbgcolor,       c000000 },
	[SchemeFlexActSPRL]  = { titleselfgcolor,  actSPRLbgcolor,   actSPRLbgcolor,       c000000 },
	[SchemeFlexActFloat] = { titleselfgcolor,  actfloatbgcolor,  actfloatbgcolor,      c000000 },
	[SchemeFlexInaTTB]   = { titlenormfgcolor, normTTBbgcolor,   normTTBbgcolor,       c000000 },
	[SchemeFlexInaLTR]   = { titlenormfgcolor, normLTRbgcolor,   normLTRbgcolor,       c000000 },
	[SchemeFlexInaMONO]  = { titlenormfgcolor, normMONObgcolor,  normMONObgcolor,      c000000 },
	[SchemeFlexInaGRID]  = { titlenormfgcolor, normGRIDbgcolor,  normGRIDbgcolor,      c000000 },
	[SchemeFlexInaGRD1]  = { titlenormfgcolor, normGRD1bgcolor,  normGRD1bgcolor,      c000000 },
	[SchemeFlexInaGRD2]  = { titlenormfgcolor, normGRD2bgcolor,  normGRD2bgcolor,      c000000 },
	[SchemeFlexInaGRDM]  = { titlenormfgcolor, normGRDMbgcolor,  normGRDMbgcolor,      c000000 },
	[SchemeFlexInaHGRD]  = { titlenormfgcolor, normHGRDbgcolor,  normHGRDbgcolor,      c000000 },
	[SchemeFlexInaDWDL]  = { titlenormfgcolor, normDWDLbgcolor,  normDWDLbgcolor,      c000000 },
	[SchemeFlexInaSPRL]  = { titlenormfgcolor, normSPRLbgcolor,  normSPRLbgcolor,      c000000 },
	[SchemeFlexInaFloat] = { titlenormfgcolor, normfloatbgcolor, normfloatbgcolor,     c000000 },
	[SchemeFlexSelTTB]   = { titleselfgcolor,  selTTBbgcolor,    selTTBbgcolor,        c000000 },
	[SchemeFlexSelLTR]   = { titleselfgcolor,  selLTRbgcolor,    selLTRbgcolor,        c000000 },
	[SchemeFlexSelMONO]  = { titleselfgcolor,  selMONObgcolor,   selMONObgcolor,       c000000 },
	[SchemeFlexSelGRID]  = { titleselfgcolor,  selGRIDbgcolor,   selGRIDbgcolor,       c000000 },
	[SchemeFlexSelGRD1]  = { titleselfgcolor,  selGRD1bgcolor,   selGRD1bgcolor,       c000000 },
	[SchemeFlexSelGRD2]  = { titleselfgcolor,  selGRD2bgcolor,   selGRD2bgcolor,       c000000 },
	[SchemeFlexSelGRDM]  = { titleselfgcolor,  selGRDMbgcolor,   selGRDMbgcolor,       c000000 },
	[SchemeFlexSelHGRD]  = { titleselfgcolor,  selHGRDbgcolor,   selHGRDbgcolor,       c000000 },
	[SchemeFlexSelDWDL]  = { titleselfgcolor,  selDWDLbgcolor,   selDWDLbgcolor,       c000000 },
	[SchemeFlexSelSPRL]  = { titleselfgcolor,  selSPRLbgcolor,   selSPRLbgcolor,       c000000 },
	[SchemeFlexSelFloat] = { titleselfgcolor,  selfloatbgcolor,  selfloatbgcolor,      c000000 },
	#endif // BAR_FLEXWINTITLE_PATCH
};

#if BAR_POWERLINE_STATUS_PATCH
static char *statuscolors[][ColCount] = {
	/*                       fg                bg                border                float */
	[SchemeNorm]         = { normfgcolor,      normbgcolor,      normbordercolor,      normfloatcolor },
	[SchemeSel]          = { selfgcolor,       selbgcolor,       selbordercolor,       selfloatcolor },
	[SchemeTitleNorm]    = { titlenormfgcolor, titlenormbgcolor, titlenormbordercolor, titlenormfloatcolor },
	[SchemeTitleSel]     = { titleselfgcolor,  titleselbgcolor,  titleselbordercolor,  titleselfloatcolor },
	[SchemeTagsNorm]     = { tagsnormfgcolor,  tagsnormbgcolor,  tagsnormbordercolor,  tagsnormfloatcolor },
	[SchemeTagsSel]      = { tagsselfgcolor,   tagsselbgcolor,   tagsselbordercolor,   tagsselfloatcolor },
	[SchemeHidNorm]      = { hidnormfgcolor,   hidnormbgcolor,   c000000,              c000000 },
	[SchemeHidSel]       = { hidselfgcolor,    hidselbgcolor,    c000000,              c000000 },
	[SchemeUrg]          = { urgfgcolor,       urgbgcolor,       urgbordercolor,       urgfloatcolor },
};
#endif // BAR_POWERLINE_STATUS_PATCH

#if BAR_LAYOUTMENU_PATCH
static const char *layoutmenu_cmd = "layoutmenu.sh";
#endif

#if BAR_LAUNCHER_PATCH
static const Launcher launchers[] = {
	/* icon to display      command        */
	{ "surf",               CMD("surf", "duckduckgo.com") },
};
#endif // BAR_LAUNCHER_PATCH

#if COOL_AUTOSTART_PATCH
static const char *const autostart[] = {
	"st", NULL,
	NULL /* terminate */
};
#endif // COOL_AUTOSTART_PATCH

#if RENAMED_SCRATCHPADS_PATCH
static const char *scratchpadcmd[] = {"s", "st", "-n", "spterm", NULL};
#elif SCRATCHPADS_PATCH
const char *spcmd1[] = {"st", "-n", "spterm", "-g", "120x34", NULL };
static Sp scratchpads[] = {
   /* name          cmd  */
   {"spterm",      spcmd1},
};
#endif // SCRATCHPADS_PATCH

/* Tags
 * In a traditional dwm the number of tags in use can be changed simply by changing the number
 * of strings in the tags array. This build does things a bit different which has some added
 * benefits. If you need to change the number of tags here then change the NUMTAGS macro in dwm.c.
 *
 * Examples:
 *
 *  1) static char *tagicons[][NUMTAGS*2] = {
 *         [DEFAULT_TAGS] = { "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E", "F", "G", "H", "I" },
 *     }
 *
 *  2) static char *tagicons[][1] = {
 *         [DEFAULT_TAGS] = { "•" },
 *     }
 *
 * The first example would result in the tags on the first monitor to be 1 through 9, while the
 * tags for the second monitor would be named A through I. A third monitor would start again at
 * 1 through 9 while the tags on a fourth monitor would also be named A through I. Note the tags
 * count of NUMTAGS*2 in the array initialiser which defines how many tag text / icon exists in
 * the array. This can be changed to *3 to add separate icons for a third monitor.
 *
 * For the second example each tag would be represented as a bullet point. Both cases work the
 * same from a technical standpoint - the icon index is derived from the tag index and the monitor
 * index. If the icon index is is greater than the number of tag icons then it will wrap around
 * until it an icon matches. Similarly if there are two tag icons then it would alternate between
 * them. This works seamlessly with alternative tags and alttagsdecoration patches.
 */
#if NAMETAG_PATCH
static char tagicons[][NUMTAGS][MAX_TAGLEN] =
#else
static char *tagicons[][NUMTAGS] =
#endif // NAMETAG_PATCH
{
	[DEFAULT_TAGS]        = { "1", "2", "3", "4", "5", "6", "7", "8", "9" },
	[ALTERNATIVE_TAGS]    = { "A", "B", "C", "D", "E", "F", "G", "H", "I" },
	[ALT_TAGS_DECORATION] = { "<1>", "<2>", "<3>", "<4>", "<5>", "<6>", "<7>", "<8>", "<9>" },
};

#if BAR_TAGGRID_PATCH
/* grid of tags */
#define SWITCHTAG_UP                1 << 0
#define SWITCHTAG_DOWN              1 << 1
#define SWITCHTAG_LEFT              1 << 2
#define SWITCHTAG_RIGHT             1 << 3
#define SWITCHTAG_TOGGLETAG         1 << 4
#define SWITCHTAG_TAG               1 << 5
#define SWITCHTAG_VIEW              1 << 6
#define SWITCHTAG_TOGGLEVIEW        1 << 7

static const int tagrows = 2;
#endif // BAR_TAGGRID_PATCH

/* There are two options when it comes to per-client rules:
 *  - a typical struct table or
 *  - using the RULE macro
 *
 * A traditional struct table looks like this:
 *    // class      instance  title  wintype  tags mask  isfloating  monitor
 *    { "Gimp",     NULL,     NULL,  NULL,    1 << 4,    0,          -1 },
 *    { "Firefox",  NULL,     NULL,  NULL,    1 << 7,    0,          -1 },
 *
 * The RULE macro has the default values set for each field allowing you to only
 * specify the values that are relevant for your rule, e.g.
 *
 *    RULE(.class = "Gimp", .tags = 1 << 4)
 *    RULE(.class = "Firefox", .tags = 1 << 7)
 *
 * Refer to the Rule struct definition for the list of available fields depending on
 * the patches you enable.
 */
static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 *	WM_WINDOW_ROLE(STRING) = role
	 *	_NET_WM_WINDOW_TYPE(ATOM) = wintype
	 */
	RULE(.wintype = WTYPE "DIALOG", .isfloating = 1)
	RULE(.wintype = WTYPE "UTILITY", .isfloating = 1)
	RULE(.wintype = WTYPE "TOOLBAR", .isfloating = 1)
	RULE(.wintype = WTYPE "SPLASH", .isfloating = 1)
	RULE(.class = "Gimp", .tags = 1 << 4)
	RULE(.class = "Firefox", .tags = 1 << 7)
	#if RENAMED_SCRATCHPADS_PATCH
	RULE(.instance = "spterm", .scratchkey = 's', .isfloating = 1)
	#elif SCRATCHPADS_PATCH
	RULE(.instance = "spterm", .tags = SPTAG(0), .isfloating = 1)
	#endif // SCRATCHPADS_PATCH
};

#if MONITOR_RULES_PATCH
#if PERTAG_PATCH
static const MonitorRule monrules[] = {
	/* monitor  tag   layout  mfact  nmaster  showbar  topbar */
	{  1,       -1,   2,      -1,    -1,      -1,      -1     }, // use a different layout for the second monitor
	{  -1,      -1,   0,      -1,    -1,      -1,      -1     }, // default
};
#else
static const MonitorRule monrules[] = {
	/* monitor  layout  mfact  nmaster  showbar  topbar */
	{  1,       2,      -1,    -1,      -1,      -1     }, // use a different layout for the second monitor
	{  -1,      0,      -1,    -1,      -1,      -1     }, // default
};
#endif // PERTAG_PATCH
#endif // MONITOR_RULES_PATCH

#if INSETS_PATCH
static const Inset default_inset = {
	.x = 0,
	.y = 30,
	.w = 0,
	.h = 0,
};
#endif // INSETS_PATCH

/* Bar rules allow you to configure what is shown where on the bar, as well as
 * introducing your own bar modules.
 *
 *    monitor:
 *      -1  show on all monitors
 *       0  show on monitor 0
 *      'A' show on active monitor (i.e. focused / selected) (or just -1 for active?)
 *    bar - bar index, 0 is default, 1 is extrabar
 *    alignment - how the module is aligned compared to other modules
 *    widthfunc, drawfunc, clickfunc - providing bar module width, draw and click functions
 *    name - does nothing, intended for visual clue and for logging / debugging
 */
static const BarRule barrules[] = {
     /* monitor   bar    alignment         	widthfunc                 	drawfunc                clickfunc                hoverfunc                name */
	{ 'A',	   0,	 BAR_ALIGN_RIGHT, 	width_status2d, 		draw_status2d, 		click_statuscmd,	    NULL,                 "status2d"},
    { -1 }
};
#define STATUSBAR "status2d"
/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int nstack      = 0;    /* number of clients in primary stack area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */
#if DECORATION_HINTS_PATCH
static const int decorhints  = 1;    /* 1 means respect decoration hints */
#endif // DECORATION_HINTS_PATCH

#define FORCE_VSPLIT 1

#if TAPRESIZE_PATCH
/* mouse scroll resize */
static const int scrollsensetivity = 30; /* 1 means resize window by 1 pixel for each scroll event */
/* resizemousescroll direction argument list */
static const int scrollargs[][2] = {
	/* width change         height change */
	{ +scrollsensetivity,	0 },
	{ -scrollsensetivity,	0 },
	{ 0, 				  	+scrollsensetivity },
	{ 0, 					-scrollsensetivity },
};
#endif // TAPRESIZE_PATCH

static const Layout layouts[] = {
	/* symbol     arrange function, { nmaster, nstack, layout, master axis, stack axis, secondary stack axis, symbol func } */
	{ "[]=",      flextile,         { -1, -1, SPLIT_VERTICAL, TOP_TO_BOTTOM, TOP_TO_BOTTOM, 0, NULL } }, // default tile layout
 	{ "><>",      NULL,             {0} },    /* no layout function means floating behavior */
	{ "[M]",      flextile,         { -1, -1, NO_SPLIT, MONOCLE, MONOCLE, 0, NULL } }, // monocle
	{ "|||",      flextile,         { -1, -1, SPLIT_VERTICAL, LEFT_TO_RIGHT, TOP_TO_BOTTOM, 0, NULL } }, // columns (col) layout
	{ ">M>",      flextile,         { -1, -1, FLOATING_MASTER, LEFT_TO_RIGHT, LEFT_TO_RIGHT, 0, NULL } }, // floating master
	{ "[D]",      flextile,         { -1, -1, SPLIT_VERTICAL, TOP_TO_BOTTOM, MONOCLE, 0, NULL } }, // deck
	{ "TTT",      flextile,         { -1, -1, SPLIT_HORIZONTAL, LEFT_TO_RIGHT, LEFT_TO_RIGHT, 0, NULL } }, // bstack
	{ "===",      flextile,         { -1, -1, SPLIT_HORIZONTAL, LEFT_TO_RIGHT, TOP_TO_BOTTOM, 0, NULL } }, // bstackhoriz
	{ "|M|",      flextile,         { -1, -1, SPLIT_CENTERED_VERTICAL, LEFT_TO_RIGHT, TOP_TO_BOTTOM, TOP_TO_BOTTOM, NULL } }, // centeredmaster
	{ "-M-",      flextile,         { -1, -1, SPLIT_CENTERED_HORIZONTAL, TOP_TO_BOTTOM, LEFT_TO_RIGHT, LEFT_TO_RIGHT, NULL } }, // centeredmaster horiz
	{ ":::",      flextile,         { -1, -1, NO_SPLIT, GAPPLESSGRID, GAPPLESSGRID, 0, NULL } }, // gappless grid
	{ "[\\]",     flextile,         { -1, -1, NO_SPLIT, DWINDLE, DWINDLE, 0, NULL } }, // fibonacci dwindle
	{ "(@)",      flextile,         { -1, -1, NO_SPLIT, SPIRAL, SPIRAL, 0, NULL } }, // fibonacci spiral
	{ "[T]",      flextile,         { -1, -1, SPLIT_VERTICAL, LEFT_TO_RIGHT, TATAMI, 0, NULL } }, // tatami mats
	#if TILE_LAYOUT
	{ "[]=",      tile,             {0} },
	#endif
	#if MONOCLE_LAYOUT
	{ "[M]",      monocle,          {0} },
	#endif
	#if BSTACK_LAYOUT
	{ "TTT",      bstack,           {0} },
	#endif
	#if BSTACKHORIZ_LAYOUT
	{ "===",      bstackhoriz,      {0} },
	#endif
	#if CENTEREDMASTER_LAYOUT
	{ "|M|",      centeredmaster,   {0} },
	#endif
	#if CENTEREDFLOATINGMASTER_LAYOUT
	{ ">M>",      centeredfloatingmaster, {0} },
	#endif
	#if COLUMNS_LAYOUT
	{ "|||",      col,              {0} },
	#endif
	#if DECK_LAYOUT
	{ "[D]",      deck,             {0} },
	#endif
	#if FIBONACCI_SPIRAL_LAYOUT
	{ "(@)",      spiral,           {0} },
	#endif
	#if FIBONACCI_DWINDLE_LAYOUT
	{ "[\\]",     dwindle,          {0} },
	#endif
	#if GRIDMODE_LAYOUT
	{ "HHH",      grid,             {0} },
	#endif
	#if HORIZGRID_LAYOUT
	{ "---",      horizgrid,        {0} },
	#endif
	#if GAPPLESSGRID_LAYOUT
	{ ":::",      gaplessgrid,      {0} },
	#endif
	#if NROWGRID_LAYOUT
	{ "###",      nrowgrid,         {0} },
	#endif
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
static const char *termcmd[]    = { "kitty", NULL };
static const char *upvol[] = { "sh", "-c", "/home/irisu/DWM-dot/home/wm/scripts/volume.sh up", NULL };
static const char *downvol[] = { "sh", "-c", "/home/irisu/DWM-dot/home/wm/scripts/volume.sh down", NULL };
static const char *mutevol[] = { "sh", "-c", "/home/irisu/DWM-dot/home/wm/scripts/volume.sh mute", NULL };
//static const char *upvol[]      = { "/usr/bin/wpctl", "set-volume", "@DEFAULT_AUDIO_SINK@", "2%+", NULL };
//static const char *downvol[] 	= { "/usr/bin/wpctl", "set-volume", "@DEFAULT_AUDIO_SINK@", "2%-", NULL };
//static const char *mutevol[] 	= { "/usr/bin/wpctl", "set-mute", "@DEFAULT_AUDIO_SINK@", "toggle", NULL };
static const char *brightup[]   = { "brightnessctl", "set", "5%+", NULL };
static const char *brightdown[] = { "brightnessctl", "set", "10%-", NULL };
static const char *code[]    	= { "code", NULL};
static const char *monitor[]	= { "kitty -e btm", NULL};
#include "X11/XF86keysym.h"
static const Key keys[] = {
	/* modifier                     key                    function        argument */
	//XF86Keys
	
	
	{ MODKEY,                       XK_r,                  spawn,          SHCMD("rofi -show drun") },                                 // open app launcher MOD+r
	{ 0,                          XF86XK_AudioRaiseVolume, spawn,          {.v = upvol   } },
	{ 0,                          XF86XK_AudioLowerVolume, spawn, 	       {.v = downvol } },
	{ 0, 			      XF86XK_AudioMute,        spawn, 	       {.v = mutevol } },
	{ 0, 		              XF86XK_MonBrightnessDown,spawn, 	       {.v = brightdown} },
	{ 0, 			      XF86XK_MonBrightnessUp,  spawn, 	       {.v = brightup  } },

	//Spawn Keys
	
	{ MODKEY,                       XK_r,                  spawn,          SHCMD("rofi -show drun") },                                 // open app launcher MOD+r
	{ MODKEY,                       XK_Return,             spawn,          {.v = termcmd } },                                 // spawn terminal MOD+return
	
	{ MODKEY,                       XK_period,             spawn,          SHCMD("rofimoji -a copy") },                                 // spawn emoji selector
	{ MODKEY,                       XK_v,                  spawn,          SHCMD("copyq toggle") },                                 // spawn clipboard
	
	//Apps
		
	{ MODKEY,			XK_p,		       spawn,	       {.v = monitor }},				  // sys monitor
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
        { MODKEY,                       XK_f,                  togglefullscreen,  {0} },                                             // toggle actualfullscreen MOD+f
	{ MODKEY,             		XK_w,                  unfloatvisible, {.v = &layouts[0]} },                              // make floating window tiled MOD+W
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
