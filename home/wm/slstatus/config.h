// clang-format off
/* See LICENSE file for copyright and license details. */



/* interval between updates (in ms) */
const unsigned int interval = 80;

/* text to show if no value can be retrieved */
static const char unknown_str[] = "?";

/* maximum output string length */
#define MAXLEN 2048

/*
 * function            description                     argument (example)
 *
 * battery_perc        battery percentage              battery name (BAT0)
 *                                                     NULL on OpenBSD/FreeBSD
 * battery_remaining   battery remaining HH:MM         battery name (BAT0)
 *                                                     NULL on OpenBSD/FreeBSD
 * battery_state       battery charging state          battery name (BAT0)
 *                                                     NULL on OpenBSD/FreeBSD
 * cat                 read arbitrary file             path
 * cpu_freq            cpu frequency in MHz            NULL
 * cpu_perc            cpu usage in percent            NULL
 * datetime            date and time                   format string (%F %T)
 * disk_free           free disk space in GB           mountpoint path (/)
 * disk_perc           disk usage in percent           mountpoint path (/)
 * disk_total          total disk space in GB          mountpoint path (/)
 * disk_used           used disk space in GB           mountpoint path (/)
 * entropy             available entropy               NULL
 * gid                 GID of current user             NULL
 * hostname            hostname                        NULL
 * ipv4                IPv4 address                    interface name (eth0)
 * ipv6                IPv6 address                    interface name (eth0)
 * kernel_release      `uname -r`                      NULL
 * keyboard_indicators caps/num lock indicators        format string (c?n?)
 *                                                     see keyboard_indicators.c
 * keymap              layout (variant) of current     NULL
 *                     keymap
 * load_avg            load average                    NULL
 * netspeed_rx         receive network speed           interface name (wlan0)
 * netspeed_tx         transfer network speed          interface name (wlan0)
 * num_files           number of files in a directory  path
 *                                                     (/home/foo/Inbox/cur)
 * ram_free            free memory in GB               NULL
 * ram_perc            memory usage in percent         NULL
 * ram_total           total memory size in GB         NULL
 * ram_used            used memory in GB               NULL
 * run_command         custom shell command            command (echo foo)
 * swap_free           free swap in GB                 NULL
 * swap_perc           swap usage in percent           NULL
 * swap_total          total swap size in GB           NULL
 * swap_used           used swap in GB                 NULL
 * temp                temperature in degree celsius   sensor file
 *                                                     (/sys/class/thermal/...)
 *                                                     NULL on OpenBSD
 *                                                     thermal zone on FreeBSD
 *                                                     (tz0, tz1, etc.)
 * uid                 UID of current user             NULL
 * uptime              system uptime                   NULL
 * username            username of current user        NULL
 * vol_perc            OSS/ALSA volume in percent      mixer file (/dev/mixer)
 *                                                     NULL on OpenBSD/FreeBSD
 * wifi_essid          WiFi ESSID                      interface name (wlan0)
 * wifi_perc           WiFi signal in percent          interface name (wlan0)
 */
static const char vol[]		= "[ amixer sget Master | tail -n 1 | awk '{print $6;}' = \"[on]\" ] \
                                   && printf \"`amixer sget Master | tail -n 1 | awk '{print $5;}' | grep -Po '\\[\\K[^%]*'`%%\" \
                                   || printf 'Off'";
const char *downspeed(const char *iface) {
    static char path[64];
    static char buf[16];
    static uint64_t rx_old;
    uint64_t rx_new;
    FILE *fp;

    snprintf(path, sizeof(path), "/sys/class/net/%s/statistics/rx_bytes", iface);
    fp = fopen(path, "r");
    if (fp == NULL) {
        return NULL;
    }
    if (fgets(buf, sizeof(buf), fp) == NULL) {
        fclose(fp);
        return NULL;
    }
    fclose(fp);

    rx_new = strtoull(buf, NULL, 10);
    snprintf(buf, sizeof(buf), "%.2f MB/s", (rx_new - rx_old) / 1e6);
    rx_old = rx_new;

    return buf;
}
static const char *brightness_perc(const char *unused)
{
    static char perc[4];
    FILE *fp = popen("~/DWM-dot/scripts/brightness.sh", "r");
    if (fp == NULL) {
        warn("popen 'brightness.sh'");
        return NULL;
    }
    fscanf(fp, "%3s", perc);
    pclose(fp);
    return perc;
}


static const struct arg args[] = {
    // uses https://dwm.suckless.org/patches/status2d patch ^c#[HEX]^ to set color and ^d^ to reset color

    /* function       format                          argument */

	  { cpu_perc,		    " ^c#ffffff^ %s%%^d^ ",        NULL },
	  { ram_used,               "^c#ffffff^󰫗 %s%%^d^ ",	    NULL },
	  
	  //{ keymap,		    "^c#ffffff^ %s^d^ ",	    NULL },
	  //{ brightness_perc, ":%s%% ", NULL }, 
	  { wifi_essid,		    "%s:",			   "wlo1"},
	  
	  { downspeed, 		    " %s ",   		   "wlo1" },
	 { run_command, "Vol:%s ", "wpctl get-volume @DEFAULT_AUDIO_SINK@ | awk '{print int($2 * 100)}'" },
 
	  //{ run_command, "[V]:%s ", "amixer sget Master | tail -1 | awk '{print $5 }' | sed 's@\\(\\[\\|\\]\\)@@g'" },
	  //{ vol_perc,	    "∢:%s%% ",	            NULL},
    // { battery_state,  "^c#f43f5e^%s^d^ ",           "BAT0" },
    // { battery_perc,   "^c#f43f5e^ %s%%^d^",         "BAT1" },
    // { battery_state,  "^c#f43f5e^%s^d^ ",           "BAT1" },
    { datetime,       "^c#ffffff^%s^d^",            "%I:%M:%S %p" },
    { battery_perc,   " ^c#f43f5e^ %s%%^d^",         "BAT0" },
};
