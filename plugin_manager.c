#include <linux/input.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <dirent.h>
#include <dlfcn.h>
#include <stdint.h>
#include <stdio.h>
#include "plugin_manager.h"

__voidplugin __destroyplug(Plugin* p, void* libhandle) {
	void ___internaldplug() {
		dlclose(libhandle);
		free(p);
	}
	return ___internaldplug;
}

Plugin* loadplug(char* name) {
	// Attempt to open the plugin DSO
	void* libhandle = dlopen(name, RTLD_NOW);
	if (!libhandle) {
	    printf("Error loading DSO: %s\n", dlerror());
	    return NULL;
	}
	__PluginInitFunc initfunc = (__PluginInitFunc)
    		(intptr_t) dlsym(libhandle, "initplug");
	if (!initfunc) {
	    printf("Error loading init function: %s\n", dlerror());
	    dlclose(libhandle);
	    return NULL;
	}
	Plugin* p = malloc(sizeof(Plugin));
	int rc = initfunc(p);
	p->destroy = __destroyplug(p, libhandle);
	if (rc < 0) {
		printf("Plugin returned failure, destroying it again...");
		p->destroy();
		return NULL;
	}
	return p;
}
