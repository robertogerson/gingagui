#ifndef UTIL_H
#define UTIL_H

#include <QString>
extern int SCREEN_HEIGHT;
extern int SCREEN_WIDTH;

const QString GINGA_PATH = "/usr/bin/ginga"; //Ginga's binary path

const QString USER_ACCOUNT_PATH = "/usr/etc/ginga/files/contextmanager/users.ini"; //Users' file info

const QString USER_PREFERENCES_PATH = "/usr/etc/ginga/files/contextmanager/contexts.ini"; //Ginga's global variables

const QString USB_XML_FILE = "/var/run/gingagui/usb.xml"; //USB default xml file

const QString USB_XML_PARENT_DIR = "/var/run/gingagui/"; //USB default xml parent directory

#endif // UTIL_H
