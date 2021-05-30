#ifndef PLUGIN_MANAGER_H
#define PLUGIN_MANAGER_H
#include "plugin.h"
typedef int (*__PluginInitFunc)(Plugin*);
typedef void (*__voidplugin)();
Plugin* loadplug(char* name);
void destroyplug(Plugin* p);
#endif
