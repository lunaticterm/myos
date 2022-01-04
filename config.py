import dracula.draw
#-------------------------------------------------------------------------------
# Browser Configs

config.load_autoconfig(False)

# Notifications and Other Media Configs per Site
config.set('content.notifications.enabled', False, 'https://www.reddit.com')
config.set('content.notifications.enabled', False, 'https://calendar.google.com')
config.set('content.notifications.enabled', False, 'https://www.facebook.com')
config.set('content.notifications.enabled', False, 'https://www.youtube.com')
config.set('content.notifications.enabled', False, 'https://www.netflix.com')
config.set('content.notifications.enabled', False, 'https://thepiratebay.org')
config.set('content.media.audio_capture', True, 'https://www.meet.google.com')
config.set('content.media.video_capture', True, 'https://www.meet.google.com')
config.set('content.register_protocol_handler', True)
config.set('completion.show', "auto")
# Misc
c.tabs.mode_on_change = 'restore'
c.search.ignore_case = 'always'
c.statusbar.show = 'always'
c.auto_save.session = True
c.confirm_quit = ['downloads']
c.content.tls.certificate_errors = 'block'
c.downloads.location.directory = '/home/moon/Downloads/'
c.editor.command = ['st', 'nvim', '{}']

# Colors & Media
monospace = '6px "Source Code Pro"'
c.colors.webpage.darkmode.enabled = True # requires a restart when changed
c.colors.webpage.preferred_color_scheme = 'dark'
c.colors.webpage.bg = 'black'

# Tabs
c.tabs.title.format = '{index} {current_title}'
c.tabs.show = 'always'
c.tabs.background = True
c.tabs.last_close = "close"
c.tabs.select_on_remove = "prev"
#-------------------------------------------------------------------------------
# Themes

dracula.draw.blood(c, {
    'spacing': {
        'vertical':   2,
        'horizontal': 3
    }
})
#-------------------------------------------------------------------------------
# Search Engines

my_search_engine = 'https://www.searx.be'
# my_search_engine = 'https://search.brave.com'

c.url.start_pages = [my_search_engine]
c.url.default_page = my_search_engine
config.bind('aa', 'set content.proxy socks://localhost:9050')
config.bind('az', 'set content.proxy system')
c.url.searchengines = {
    'DEFAULT': f'{my_search_engine}/search?q=' + '{}',
    ':aw':      'https://wiki.archlinux.org/?search={}',
    ':br':      'https://search.brave.com/search?={}',
    ':col':     'https://www.collinsdictionary.com/us/dictionary/english/{}',
    ':gh':      'https://github.com/search?q={}',
    ':pr':      'https://piratebay.party/search/{}',
    ':prib':    'https://dicionario.priberam.org/{}',
    ':re':      'https://www.reddit.com/search/?q={}',
    ':sx':      'https://www.searx.bar/search?q={}',
    ':ub':      'https://www.urbandictionary.com/define.php?term={}',
    ':yt':      'https://www.yewtu.be/results?search_query={}',
}
#-------------------------------------------------------------------------------
# Shortcuts

toggle_statusbar = 'config-cycle statusbar.show always never'
toggle_tabs      = 'config-cycle tabs.show always never'

player_div =  'document.querySelector("#movie_player")'
player_div_or_elem = 'document.querySelector("#movie_player, video")'
player_elem = 'document.querySelector("video")'

config.bind('<alt+r>',         'restart')
config.bind('(',              f'jseval -q {player_div_or_elem}.focus()')
config.bind(')',              f'jseval -q {player_div_or_elem}.blur()')
config.bind('<ctrl+shift+x>',  'tab-pin')
config.bind('<alt+b>',         'back')
config.bind('<alt+f>',         'forward')
config.bind('yo',              'yank inline "[[{url}][{title}]]"')
config.bind('yml',             'yank inline "[{title}][url][url]: {url}"')
config.bind('t',               'set-cmd-text -s :open -t')
config.bind('M',               'hint links spawn mpv {hint-url}')
config.bind('Z',               'hint links spawn konsole -e youtube-dl {hint-url}')
config.bind('xt',               toggle_tabs)
config.bind('xb',               toggle_statusbar)
config.bind('xx',            f'{toggle_tabs};; {toggle_statusbar}')
config.bind('ba',             'bookmark-add')
config.bind('bd',             'bookmark-del')
config.bind('<alt+t>',        'set-cmd-text :tab-give ')
config.bind('<',             f'jseval {player_elem}.playbackRate-=.25')
config.bind('>',             f'jseval {player_elem}.playbackRate+=.25')
config.bind('ss',             'set-cmd-text -s :session-save -o')
config.unbind('b')
config.unbind('<ctrl+shift+w>')
config.bind('<ctrl+r>',       'reload')
config.bind('K', 'tab-next')
config.bind('J', 'tab-prev')
# Themes Shortcuts
config.bind(',ex', 'config-cycle content.user_stylesheets ~/.config/qutebrowser/experimental.css ""')
config.bind(',ap', 'config-cycle content.user_stylesheets ~/.config/qutebrowser/solarized/css/apprentice/apprentice-all-sites.css ""')
config.bind(',dr', 'config-cycle content.user_stylesheets ~/.config/qutebrowser/solarized/css/darculized/darculized-all-sites.css ""')
config.bind(',gr', 'config-cycle content.user_stylesheets ~/.config/qutebrowser/solarized/css/gruvbox/gruvbox-all-sites.css ""')
config.bind(',sd', 'config-cycle content.user_stylesheets ~/.config/qutebrowser/solarized/css/solarized-dark/solarized-dark-all-sites.css ""')
config.bind(',sl', 'config-cycle content.user_stylesheets ~/.config/qutebrowser/solarized/css/solarized-light/solarized-light-all-sites.css ""')
#-------------------------------------------------------------------------------
