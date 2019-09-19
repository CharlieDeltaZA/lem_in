#!/bin/sh

if [[ $(command -v brew) == "" ]]; then
    echo "Installing Homebrew"
    sh -c "$(curl -fsSL https://raw.githubusercontent.com/Tolsadus/42homebrewfix/master/install.sh)"
else
    echo "Updating Homebrew"
    brew update
fi

if [[ $(command -v brew) != "" ]]; then
    echo "Installing Dependencies"
	brew install SDL2 SDL2_gfx SDL2_image SDL2_ttf
fi
