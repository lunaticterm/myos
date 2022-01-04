/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 2;        /* border pixel size of windows */
static const unsigned int gappx     = 5;        /* gaps size between windows */
static const unsigned int snap      = 1;       /* snap pixel */
static int swallowfloating          = 0;
static int showbar = 1;
static int topbar = 1;
static const char *fonts[]          = { "Source Code Pro:size=9", "FontAwesome:size=12" };
static const char dmenufont[]       = "Source Code Pro:size=9";
//background color
static const char col_gray1[] = "#282a36";
static const char col_gray2[] = "#ffb86c";
static const char col_gray3[] = "#ff79c6";
static const char col_gray4[] = "#ffb86c";
static const char col_cyan[]  = "#282a36";
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_gray3, col_gray1, col_cyan},
	[SchemeSel]  = { col_gray4, col_cyan,  col_gray2},
};

/* tagging */
//tag names (upper left)
static const char *tags[] = { "1", "2", "3", "4", "5" };

static const Rule rules[] = {
/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class     instance  title           tags mask  isfloating  isterminal  noswallow  monitor */
	{ "Gimp",    NULL,     NULL,           0,         1,          0,           0,        -1 },
	{ "Firefox", NULL,     NULL,           1 << 8,    0,          0,          -1,        -1 },
	{ "St",      NULL,     NULL,           0,         0,          1,           0,        -1 },
	{ NULL,      NULL,     "Event Tester", 0,         0,          0,           1,        -1 }, /* xev */
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \ { MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \ { MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \ { MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} }, 
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } } 
static char dmenumon[2] = "0"; 
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray4, NULL }; 
static const char *termcmd[]  = { "st", "-e", "zsh" };  
static const char *browser[] = { "qutebrowser", NULL };
static const char *img[]     = { "vimiv", NULL };
static const char *filemanager[] = {"st", "-e", "vifm", NULL};
static const char *upvol[] = { "/usr/bin/pactl", "set-sink-volume", "@DEFAULT_SINK@", "+5%",    NULL };
static const char *downvol[] = { "/usr/bin/pactl", "set-sink-volume", "@DEFAULT_SINK@" ,"-5%",  NULL };
static const char *mutevol[] = { "/usr/bin/pactl", "set-sink-mute",  "@DEFAULT_SINK@", "toggle", NULL};
static const char *poweroff[] = {"poweroff", NULL}; 
static const char *reboot[] = {"reboot", NULL};
#include "shiftview.c"
#include "movestack.c"
static char *lock[] = { "slock"};
static char *pdf[]  = {"zathura", NULL};
static char *vim[]  = {"st", "-e", "nvim", NULL};
static char *net[] = {"st", "-e", "nmtui", NULL};
static char *ar[] = {"setxkbmap", "ar", NULL};
static char	*en[] = {"setxkbmap", "fr", NULL};
static char *hidecur[] = {"unclutter", "-idle", "0"};
static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_d,      spawn,          {.v = dmenucmd } },
	{ MODKEY,												XK_x,			 spawn,					 {.v = poweroff} },
	{ MODKEY|ShiftMask,							XK_x,			 spawn,					 {.v = reboot} },
	{ MODKEY|ShiftMask,	          	XK_j,	   movestack,	   {.i = +1} },
	{ MODKEY,       	              XK_F11, spawn, {.v = downvol } },
	{ MODKEY,   	                  XK_F10, spawn, {.v = mutevol } },
	{ MODKEY,           	 	        XK_F12, spawn, {.v = upvol   } },
	{ MODKEY|ShiftMask,							XK_k,	   movestack,	   {.i = -1} },
	{ MODKEY,	             			    XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY,												XK_p,	   spawn,	   {.v = pdf }},
	{ MODKEY,												XK_e,	   spawn,	   {.v = vim} },
	{ MODKEY,												XK_r,	   spawn,	   {.v = filemanager} },
	{ MODKEY,												XK_v,	   spawn,	   {.v = img} },
	{ MODKEY,                       XK_t,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY, 											XK_w,	   spawn,	   {.v = browser} },
	{ MODKEY,                       XK_u,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.01} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.01} },
	{ MODKEY|ShiftMask,							XK_l,	   spawn,	   {.v = lock} },
	{ MODKEY,                       XK_z,	   zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY,	                   	  XK_q,      killclient,     {0} },
	{ MODKEY|ShiftMask,             XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY|ShiftMask,             XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY|ShiftMask,             XK_m,      setlayout,      {.v = &layouts[2] } },
	{ MODKEY|ShiftMask,             XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{MODKEY|ShiftMask,							XK_n,			 spawn,					 {.v = net}},
	{MODKEY|ShiftMask,							XK_a,			 spawn,					 {.v = ar}},
	{MODKEY|ShiftMask,							XK_e,			 spawn,					 {.v = en}},
//{ MODKEY,                       XK_minus,  setgaps,        {.i = -1 } },
//{ MODKEY,                       XK_equal,  setgaps,        {.i = +1 } },
//{ MODKEY|ShiftMask,             XK_equal,  setgaps,        {.i = 0  } },
	{MODKEY,												XK_y,			 spawn,					 {.v = hidecur}},
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	{ MODKEY,              		    XK_n,      shiftview,  	   { .i = +1 } },
	{ MODKEY,              		    XK_b,      shiftview,      { .i = -1 } },
  { MODKEY,                       XK_F8,     spawn,          {.v = upvol   } },
	{ MODKEY,                       XK_F7,     spawn,          {.v = downvol } },
	{ MODKEY,                       XK_F5,     spawn,          {.v = mutevol } },
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
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

