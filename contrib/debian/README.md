
Debian
====================
This directory contains files used to package spectrad/spectra-qt
for Debian-based Linux systems. If you compile spectrad/spectra-qt yourself, there are some useful files here.

## spectra: URI support ##


spectra-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install spectra-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your spectra-qt binary to `/usr/bin`
and the `../../share/pixmaps/spectra128.png` to `/usr/share/pixmaps`

spectra-qt.protocol (KDE)

