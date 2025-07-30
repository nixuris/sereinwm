# sereinwm
---

## Installation

1. Clone the repository

```bash
git clone --depth=1 https://github.com/nixuris/sereinwm.git  ~/.config/sereinwm
```

2. Manually copy other configs (not sereinwm) to .config

3. Compile sereinwm

```bash
cd ~/.config/sereinwm/config/sereinwm
sudo make clean install
```

When recompile, do the same but remember to remove config.h

## Run with startx (or sx)

```bash
startx ~/.config/sereinwm/start.sh
```
